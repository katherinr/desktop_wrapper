#ifndef METEOSTRUCT_H
#define METEOSTRUCT_H
#define NPR_PACKET_TYPE_VISUAL_DATA         201
#define NPR_PACKET_TYPE_METEO_DATA          202
#define NPR_PACKET_TYPE_AIRPORT_DATA        203
#define NPR_PACKET_TYPE_CORRECT_DATA        204
#define NPR_PACKET_TYPE_BACK_DATA           205

#pragma pack ( push, 1 )

struct D3_POINT
{
    double X;
    double Z;
    float  H;
};

struct D3_ANGLE
{
    float  C;
    float  P;
    float  R;
};

// ПРИМЕР ПАКЕТА ОСНОВНЫХ ДАННЫХ:

struct _MainVisualData
{
    unsigned char    packet_id;                              // Отличительный признак пакета (постоянное число = 201)

    double  model_simulation_time;                  // Текущее время в модели,                  [мс]

    // Коррекция изображения в кабине пилота: 0 - центр, 1 - для левого кресла, 2 - для правого кресла
    int     num_correct;

    // Основное
    D3_POINT p_coord;								// Координаты:  Широта [град], Долгота [град], Высота над уровнем моря  [м]
    D3_ANGLE p_angle;                               // Угловое положение: углы курса (против часовой +), тангажа, крена, [град]

    // Обороты (нужны для имитации звуков отдельно от системы визуализации):
    float   N2_L;                                   // Обороты левого двигателя,                [0...max%]
    float   N2_R;                                   // Обороты правого двигателя РУД,           [0...max%]

    // Механизация, органы управления
    float   Flaps;                                  // Положение закрылков,                     [град]
    float   Slats;                                  // Положение левого предкрылков,            [град]
    float   Stabilizer;                             // Положение стабилизатора,                 [град]

    float   Elevator_L;                             // Положение руля высоты (лев.секц),        [град]
    float   Elevator_R;                             // Положение руля высоты (прав.секц),       [град]
    float   Aileron_L;                              // Положение левого элерона,                [град]
    float   Aileron_R;                              // Положение правого элерона,               [град]
    float   Rudder;                                 // Положение руля направления,              [град]

    // Спойлеры, воздушный тормоз:      АБСОЛЮТНЫЕ ВЕЛИЧИНЫ, Т.Е. ВСЕГДА ПЛЮС
    float   Spoiler_L_OB;                           // Положение левого внеш. интерцептора,     [град]
    float   Spoiler_L_CE;                           // Положение левого цент. интерцептора,     [град]
    float   Spoiler_L_IN;                           // Положение левого внутр. интерцептора,    [град]
    float   Spoiler_R_OB;                           // Положение правого внеш. интерцептора,    [град]
    float   Spoiler_R_CE;                           // Положение правого цент. интерцептора,    [град]
    float   Spoiler_R_IN;                           // Положение правого внутр. интерцептора,   [град]
    float   GroudSpoiler_L_OB;                      // Положение левого внеш. торм. щитка,      [град]
    float   GroudSpoiler_L_IB;                      // Положение левого внутр. торм. щитка,     [град]
    float   GroudSpoiler_R_OB;                      // Положение правого внеш. торм. щитка,     [град]
    float   GroudSpoiler_R_IB;                      // Положение правого внутр. торм. щитка,    [град]

    // Шасси (положение)
    float   Gear_N;                                 // Положение носовой опоры,                 [0/1]
    float   Gear_L;                                 // Положение левой опоры,                   [0/1]
    float   Gear_R;                                 // Положение правой опоры,                  [0/1]

    // Угол поворота носового колеса    (ПОЛОЖИТЕЛЬНОЕ ОТКЛОНЕНИЕ - ДЛЯ ПОВОРОТА НАПРАВО)
    float   Gear_SteeringAngle;                     // Угол поворота носового колеса,           [град]

    // Самолетные (бортовые) огни       (ЕСЛИ ЕСТЬ ВОЗМОЖНОСТЬ, СДЕЛАТЬ В % ДЛЯ РЕГУЛИРОВКИ ЯРКОСТИ, ЕСЛИ НЕТ, ТО НЕТ)
    char    LandingLights;                          // Посадочные фары,                         [0...100%]
    char    TaxiLight;                              // Рулежная фара,                           [0...100%]
    char    RunwayTurnoffLights;                    // Фары поворота с ВПП,                     [0...100%]
    char    NavigationLightRed;                     // Навигационный огонь красный,             [0...100%]
    char    NavigationLightGreen;                   // Навигационный огонь зеленый,             [0...100%]
    char    NavigationLightWhite;                   // Навигационный огонь белый,               [0...100%]
    char    AntiCollisionBeaconRed;                 // Красные проблесковые маяки сверху,снизу, [0...100%]
    char    AntiCollisionBeaconWhite;               // Белые проблесковые маяки (крылья, хвост),[0...100%]
    char    InternalLights;			                // Освещение кабины и салона самолёта,		[0...100%]

    // Резерв:
    float   Reserved[8];

};



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ПРИМЕР ПАКЕТА ДАННЫХ О ПОГОДЕ И ВРЕМЕНИ:

struct _MeteoData
{

    unsigned char    packet_id;                              // Отличительный признак пакета (постоянное число = 202)

    double  model_simulation_time;                  // Текущее время в модели,                  [мс]

    float   visibility;                             // Глобальная дальность видимости,          [км], примерные знач. 0...200

    short   cloudBase;                              // Высота нижней кромки облаков над уровнем моря, [м], пример. знач. 3000.
    short   cloudUpper;                             // Толщина слоя облаков,                    [м], примерные знач. 2000
    short   cloudSize ;                             // Балл облаков, [ед],                      [0...10]
    char    cloudsType;                         	// Тип облаков:                             0- обычные, 1- грозовые
    char    cloudsSecondLay;                        // Наличие второго слоя облаков (перистые облака), 0/1
    float   SecLayHeight;                           // Высота второго слоя облаков над уровнем моря, [м], пример. знач. 15000

    short   Day;
    short   Month;
    short   Hours;
    short   Minutes;

    float   local_visibility;                       // Локал. дальность видимости внутри зоны снега, дождя, тумана, [м]
    float   rain;                                   // Интенсивность дождя,                     [0...100%]
    float   snow;                                   // Интенсивность снега,                     [0...100%]
    float   hmist;                                  // Высота дымки тумана над уровнем моря,    [м], примерные знач. 0...1000

    float   wind_speed;                             // Скорость ветра,                          [м/c]
    float   wind_psi;                               // Направление ветра (отсчет как у модельного курса), [град]

    float   starBright;                             // Яркость звезд,                           [0...100%]

    // Резерв:
    float   Reserved[8];

};


void deep_meteo_copy(_MeteoData *_data,_MeteoData *data );
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ПРИМЕР ПАКЕТА ДАННЫХ ОБ АЭРОДРОМЕ И ПОЛОСЕ:


struct _AirportData
{
    unsigned char 	packet_id;                              // Отличительный признак пакета (постоянное число = 203)

    double  model_simulation_time;                  // Текущее время в модели,                  [мс]

    // Аэропорт и ВВП взлета:
    char 	DEPARTURE_AIRPORT_CODE[4];              // идентификатор аэропорта взлета           (4 символа - код аэропорта по ICAO, например "LIPZ")
    char 	TAKEOFF_RUNWAY_CODE[4];                 // идентификатор полосы взлета              (например "16  ", "25L ", "01  ")
    char 	TAKEOFF_RUNWAY_BORDER_LIGHTS;           // Боковые огни полосы,                     [0...100%]
    char 	DEPARTURE_AIRPORT_LIGHTS_TAXIING;       // Рулежные огни аэродрома,                 [0...100%]
    char 	DEPARTURE_AIRPORT_LIGHTS_ILLUMINATION;  // Огни подсвета стоянок аэродрома,         [0...100%]
    char 	DEPARTURE_AIRPORT_OTHER_LIGHTS;         // Уровень яркости всех остальных огней,    [0...100%]

    // Аэропорт и ВВП посадки:
    char 	ARRIVAL_AIRPORT_CODE[4];                // идентификатор аэропорта посадки          4 символа - код аэропорта по ICAO, например "LIPZ")
    char 	LANDING_RUNWAY_CODE[4];                 // идентификатор полосы посадки             (например "16  ", "25R ", "01  ")
    char 	LANDING_RUNWAY_BORDER_LIGHTS;           // Боковые огни полосы,                     [0...100%]
    char 	ARRIVAL_AIRPORT_LIGHTS_TAXIING;         // Рулежные огни аэродрома,                 [0...100%]
    char 	ARRIVAL_AIRPORT_LIGHTS_ILLUMINATION;    // Огни подсвета стоянок аэродрома,         [0...100%]
    char 	ARRIVAL_AIRPORT_OTHER_LIGHTS;           // Уровень яркости всех остальных огней,    [0...100%]

    // Резерв:
    char 	Reserved[16];

};



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ПРИМЕР ОБРАТНОГО ПАКЕТА (ДЛЯ ОТПРАВКИ В МОДЕЛЬ):

struct _DataToModel
{
    unsigned char   	packet_id;                              // Признак пакета (постоянное число = 205)

    // Для контроля обмена (запаздывания и т.д.):
    double 	simulation_time;                        // Текущее время,                           [мс]

    D3_POINT p_coord;								// Широта [град], Долгота [град], Высота подст. поверхности под ц.м. самолета [м]

    // Резерв:
    float	Reserved[8];

};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ПАКЕТ КОРРЕКЦИИ:
struct _CorrectData
{
    unsigned char   message;                                                         // Признак пакета Correct = 204

    int num_correct;                                                        // коррекция: 0 - центр, 1 - левая, 2 - правая
};

#pragma pack ( pop )
#endif
