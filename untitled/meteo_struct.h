#ifndef METEO_STRUCT_H
#define METEO_STRUCT_H

#include <string.h>

#define NUMBER_OF_AC_IN_TRAFFIC  10
#pragma pack ( push, 1 )
//-------------------------------------------------------------------------
// МЕТЕО:

struct METEO_DATA
{
	METEO_DATA()
	{
		memset(this, 0, sizeof(*this));
	}

	char  message   ;                                                       // Признак метеопакета = 11

    
    // Главная часть погодных данных (18 входных сигналов?)
	float Visibility;                                                       // Глобальная дальность видимости, [км], примерные знач. 0...200                                                
	
    short CloudBase;                                                        // Высота нижней кромки облаков над уровнем моря, [м], примерные знач. 3000.                                                        
	short CloudUpper;                                                       // Толщина слоя облаков, [м], примерные знач. 2000                                                
	short CloudSize ;                                                       // Бальность облаков, [ед], 0...10                                                      
	char  cloudsType;                                                       // Тип облаков: 0- обычные, 1- грозовые
    
	char  cloudsSecondLay;                                                  // Наличие второго слоя облаков (перистые облака), 0/1                                               		                                        
	float SecLayHeight;                                                     // Высота второго слоя облаков над уровнем моря, [м], примерные знач. 15000
	
    short Day;
	short Month;
	short Hours;                                                                               
	short Minutes;                                                        

    float local_visibility;                                                 // Локальная дальность видимости внутри зоны снега, дождя, тумана, [м], 500
	float rain;                                                             // Интенсивность дождя, 0...1
	float snow;                                                             // Интенсивность снега, 0...1
	float hmist;                                                            // Высота дымки тумана над уровнем моря, [м], примерные знач. 0...1000   
	
    float wind_speed;                                                       // Скорость ветра, [м/c]
	float wind_psi;                                                         // Направление ветра (отсчет как у модельного курса), [град]

    float StarBright;                                                       // Яркость звезд, 0...1  или 0...100 
    
};

void deep_meteo_copy(METEO_DATA *_data,METEO_DATA *data );

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
     _AirportData(){}

};

struct DATA_FROM_KD {

    char  message; // Признак пакета ЛА = 10
    double lat;
    double lon;
    double H;
    unsigned long surf;

    unsigned long time;
    float r_sign;

    double h_gear[4];

};

struct D3_POINT
{
    double X;
    double Z;
    float  H;
};

struct _DataToModel
{
    unsigned char   	packet_id;                              // Признак пакета (постоянное число = 205)

    // Для контроля обмена (запаздывания и т.д.):
    double 	simulation_time;                        // Текущее время,                           [мс]

    D3_POINT p_coord;								// Широта [град], Долгота [град], Высота подст. поверхности под ц.м. самолета [м]

    // Резерв:
    float	Reserved[8];

};

#pragma pack ( pop )
#endif
