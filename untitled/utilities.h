#ifndef UTILITIES_H
#define UTILITIES_H

#include "meteo_struct.h"
#include "qdebug.h"
#include "qstring.h"

struct codes
{
	
	QString iata;
	QString icao;
};
struct route_point
{

	double routeLat;
	double routeLon;
	float routeAlt;
};

struct camera_part
{
	/*camera_part()
	{
		memset(this, 0, sizeof(*this));
	}  */
	bool isShowingWindow;	 //
	bool showCurTraj;	//
	bool showRoute; //
	bool followMainPlane;	//	
	bool isOrientingCamera;	  //
	
	//double centerLat;
	//double centerLon;
	//float centerH;
	
	quint8 currWPT;
	int updateRoute;
};

inline QMap<QString, codes>  fill_aeroport_codes()
{
	QMap<QString, codes>  aeroports_codes;
	QString s = QString::fromLocal8Bit("Шереметьево (SVO/UUEE)");

	aeroports_codes[QString::fromLocal8Bit("Шереметьево (SVO/UUEE)")].icao = "UUEE";
	aeroports_codes[QString::fromLocal8Bit("Шереметьево (SVO/UUEE)")].iata = "SVO";

	aeroports_codes[QString::fromLocal8Bit("Домодедово (DME/UUDD)")].icao = "UUDD";
	aeroports_codes[QString::fromLocal8Bit("Домодедово (DME/UUDD)")].iata = "DME";

	aeroports_codes[QString::fromLocal8Bit("Внуково (VKO/UUWW)")].icao = "UUWW";
	aeroports_codes[QString::fromLocal8Bit("Внуково (VKO/UUWW)")].iata = "SVO";

	aeroports_codes[QString::fromLocal8Bit("Жуковский (ZIA/UUBW)")].icao = "UUBW";
	aeroports_codes[QString::fromLocal8Bit("Жуковский (ZIA/UUBW)")].iata = "ZIA";

	aeroports_codes[QString::fromLocal8Bit("Остафьево (OSF/UUMO)")].icao = "UUMO";
	aeroports_codes[QString::fromLocal8Bit("Остафьево (OSF/UUMO)")].iata = "OSF";

	aeroports_codes[QString::fromLocal8Bit("Лондон (LCY/EGLC)")].iata = "LCY";
	aeroports_codes[QString::fromLocal8Bit("Лондон (LCY/EGLC)")].icao = "EGLC";

	aeroports_codes[QString::fromLocal8Bit("Карловы Вары (KLV/LKKV)")].iata = "KLV";
	aeroports_codes[QString::fromLocal8Bit("Карловы Вары (KLV/LKKV)")].icao = "LKKV";

	aeroports_codes[QString::fromLocal8Bit("Тиват (TIV/LYTV)")].iata = "TIV";
	aeroports_codes[QString::fromLocal8Bit("Тиват (TIV/LYTV)")].icao = "LYTV";

	aeroports_codes[QString::fromLocal8Bit("Брюссель (BRU/EBBR)")].iata = "BRU";
	aeroports_codes[QString::fromLocal8Bit("Брюссель (BRU/EBBR)")].icao = "EBBR";

	aeroports_codes[QString::fromLocal8Bit("Венеция (VCE/LIPZ)")].iata = "VCE";
	aeroports_codes[QString::fromLocal8Bit("Венеция (VCE/LIPZ)")].icao = "LIPZ";

	aeroports_codes[QString::fromLocal8Bit("Дублин (DUB/EIBW)")].iata = "DUB";
	aeroports_codes[QString::fromLocal8Bit("Дублин (DUB/EIBW)")].icao = "EIDW";

	aeroports_codes[QString::fromLocal8Bit("Инсбрук (INN/LOWI)")].iata = "INN";
	aeroports_codes[QString::fromLocal8Bit("Инсбрук (INN/LOWI)")].icao = "LOWI";

	aeroports_codes[QString::fromLocal8Bit("Кеблавик (KEF/BIKF)")].iata = "KEF";
	aeroports_codes[QString::fromLocal8Bit("Кеблавик (KEF/BIKF)")].icao = "BIKF";

	aeroports_codes[QString::fromLocal8Bit("Комсомольск (KXK/UHKK)")].iata = "KXK";
	aeroports_codes[QString::fromLocal8Bit("Комсомольск (KXK/UHKK)")].icao = "UHKK";

	aeroports_codes[QString::fromLocal8Bit("Пулково (LED/ULLI)")].iata = "LED";
	aeroports_codes[QString::fromLocal8Bit("Пулково (LED/ULLI)")].icao = "ULLI";

	aeroports_codes[QString::fromLocal8Bit("Сочи (AER/URSS)")].iata = "AER";
	aeroports_codes[QString::fromLocal8Bit("Сочи (AER/URSS)")].icao = "URSS";

	aeroports_codes[QString::fromLocal8Bit("Толука (TLC/MMTO)")].iata = "TLC";
	aeroports_codes[QString::fromLocal8Bit("Толука (TLC/MMTO)")].icao = "MMTO";

	aeroports_codes[QString::fromLocal8Bit("Хельсинки (HEL/EFHK)")].iata = "HEL";
	aeroports_codes[QString::fromLocal8Bit("Хельсинки (HEL/EFHK)")].icao = "EFHK";

	//   qDebug()<<aeroports_codes["Шереметьево (SVO/UUEE)"].iata;
	 //  qDebug()<<aeroports_codes["Шереметьево (SVO/UUEE)"].icao;
	return aeroports_codes;
}

inline void fill_flights_strips(QMap<QString, std::vector <QString>> &flight_strips)
{
	std::vector <QString> tmp{ "07L","25R","07R","25L" };

	flight_strips[QString::fromLocal8Bit("Шереметьево (SVO/UUEE)")].insert
	(flight_strips[QString::fromLocal8Bit("Шереметьево (SVO/UUEE)")].begin(),
		tmp.begin(), tmp.end());
	//qDebug()<<flight_strips[QString::fromLocal8Bit("Шереметьево (SVO/UUEE)")];
	tmp.clear();
	tmp = { "32L","14R","32R","14L" };
	flight_strips[QString::fromLocal8Bit("Домодедово (DME/UUDD)")].insert
	(flight_strips[QString::fromLocal8Bit("Домодедово (DME/UUDD)")].begin(),
		tmp.begin(), tmp.end());

	tmp.clear();
	tmp = { "06","24","01","19" };
	flight_strips[QString::fromLocal8Bit("Внуково (VKO/UUWW)")].insert
	(flight_strips[QString::fromLocal8Bit("Внуково (VKO/UUWW)")].begin(),
		tmp.begin(), tmp.end());

	tmp.clear();
	tmp = { "12","30" };
	flight_strips[QString::fromLocal8Bit("Жуковский (ZIA/UUBW)")].insert
	(flight_strips[QString::fromLocal8Bit("Жуковский (ZIA/UUBW)")].begin(),
		tmp.begin(), tmp.end());

	tmp.clear();
	tmp = { "26","08" };
	flight_strips[QString::fromLocal8Bit("Остафьево (OSF/UUMO)")].insert
	(flight_strips[QString::fromLocal8Bit("Остафьево (OSF/UUMO)")].begin(),
		tmp.begin(), tmp.end());

	tmp.clear();
	tmp = { "09","27" };
	flight_strips[QString::fromLocal8Bit("Лондон (LCY/EGLC)")].insert
	(flight_strips[QString::fromLocal8Bit("Лондон (LCY/EGLC)")].begin(),
		tmp.begin(), tmp.end());

	tmp.clear();
	tmp = { "11","29" };
	flight_strips[QString::fromLocal8Bit("Карловы Вары (KLV/LKKV)")].insert
	(flight_strips[QString::fromLocal8Bit("Карловы Вары (KLV/LKKV)")].begin(),
		tmp.begin(), tmp.end());

	tmp.clear();
	tmp = { "14","32" };
	flight_strips[QString::fromLocal8Bit("Тиват (TIV/LYTV)")].insert
	(flight_strips[QString::fromLocal8Bit("Тиват (TIV/LYTV)")].begin(),
		tmp.begin(), tmp.end());

	tmp.clear();
	tmp = { "07L","25R","07R","25L","02","20" };
	flight_strips[QString::fromLocal8Bit("Брюссель (BRU/EBBR)")].insert
	(flight_strips[QString::fromLocal8Bit("Брюссель (BRU/EBBR)")].begin(),
		tmp.begin(), tmp.end());
	tmp.clear();
	tmp = { "04L","22R","04R","22L" };
	flight_strips[QString::fromLocal8Bit("Венеция (VCE/LIPZ)")].insert
	(flight_strips[QString::fromLocal8Bit("Венеция (VCE/LIPZ)")].begin(),
		tmp.begin(), tmp.end());

	tmp.clear();
	tmp = { "10","28","16","34","11","29" };
	flight_strips[QString::fromLocal8Bit("Дублин (DUB/EIBW)")].insert
	(flight_strips[QString::fromLocal8Bit("Дублин (DUB/EIBW)")].begin(),
		tmp.begin(), tmp.end());

	tmp.clear();
	tmp = { "08","26" };
	flight_strips[QString::fromLocal8Bit("Инсбрук (INN/LOWI)")].insert
	(flight_strips[QString::fromLocal8Bit("Инсбрук (INN/LOWI)")].begin(),
		tmp.begin(), tmp.end());

	tmp.clear();
	tmp = { "11","29","02","20" };
	flight_strips[QString::fromLocal8Bit("Кеблавик (KEF/BIKF)")].insert
	(flight_strips[QString::fromLocal8Bit("Кеблавик (KEF/BIKF)")].begin(),
		tmp.begin(), tmp.end());

	tmp.clear();
	tmp = { "36","18" };
	flight_strips[QString::fromLocal8Bit("Комсомольск (KXK/UHKK)")].insert
	(flight_strips[QString::fromLocal8Bit("Комсомольск (KXK/UHKK)")].begin(),
		tmp.begin(), tmp.end());

	tmp.clear();
	tmp = { "10L","10R","28R","28L" };
	flight_strips[QString::fromLocal8Bit("Пулково (LED/ULLI)")].insert
	(flight_strips[QString::fromLocal8Bit("Пулково (LED/ULLI)")].begin(),
		tmp.begin(), tmp.end());

	tmp.clear();
	tmp = { "06","24","02","20" };
	flight_strips[QString::fromLocal8Bit("Сочи (AER/URSS)")].insert
	(flight_strips[QString::fromLocal8Bit("Сочи (AER/URSS)")].begin(),
		tmp.begin(), tmp.end());

	tmp.clear();
	tmp = { "15","33" };
	flight_strips[QString::fromLocal8Bit("Толука (TLC/MMTO)")].insert
	(flight_strips[QString::fromLocal8Bit("Толука (TLC/MMTO)")].begin(),
		tmp.begin(), tmp.end());

	tmp.clear();
	tmp = { "04L","22R","04R","22L","15","33" };
	flight_strips[QString::fromLocal8Bit("Хельсинки (HEL/EFHK)")].insert
	(flight_strips[QString::fromLocal8Bit("Хельсинки (HEL/EFHK)")].begin(),
		tmp.begin(), tmp.end());
}


inline QMap <QString, route_point> fillRouteByICAO()
{
	QMap <QString, route_point> answer;

	answer["UUDD"].routeLat = 55.410222;
	answer["UUDD"].routeLon = 37.902443;

	answer["UUEE"].routeLat = 55.973607;
	answer["UUEE"].routeLon = 37.412512;

	answer["UUWW"].routeLat = 55.599611;
	answer["UUWW"].routeLon = 37.271236;

	answer["UUBW"].routeLat = 55.564917;
	answer["UUBW"].routeLon = 37.412512;

	answer["UUMO"].routeLat = 55.513190;
	answer["UUMO"].routeLon = 38.137015;

	answer["EGLC"].routeLat = 51.505523;
	answer["EGLC"].routeLon = 0.045733;

	answer["LKKV"].routeLat = 50.202978000000;
	answer["LKKV"].routeLon = 12.914983000000;

	answer["LYTV"].routeLat = 42.404778;
	answer["LYTV"].routeLon = 18.723146;

	answer["EBBR"].routeLat = 50.901389000000;
	answer["EBBR"].routeLon = 4.484444000000;

	answer["LIPZ"].routeLat = 45.505278;
	answer["LIPZ"].routeLon = 12.351944;

	answer["EIDW"].routeLat = 53.421389000000;
	answer["EIDW"].routeLon = -6.270000000000;

	answer["LOWI"].routeLat = 47.2602005004883;
	answer["LOWI"].routeLon = 11.3439998626709;

	answer["BIKF"].routeLat = 63.985000000000;
	answer["BIKF"].routeLon = -22.605556000000;

	answer["UHKK"].routeLat = 50.409444000000;
	answer["UHKK"].routeLon = 136.934167000000;

	answer["ULLI"].routeLat = 59.800292000000;
	answer["ULLI"].routeLon = 30.262503000000;

	answer["URSS"].routeLat = 43.449928000000;
	answer["URSS"].routeLon = 39.956589000000;

	answer["MMTO"].routeLat = 19.337072000000;
	answer["MMTO"].routeLon = -99.566008000000;

	answer["EFHK"].routeLat = 60.317222000000;
	answer["EFHK"].routeLon = 24.963333000000;

	return answer;
}

inline void get_coords_by_aeroport_code(const char aeroport_code[4], const QMap <QString, route_point> &database, D3_POINT &answer)
{
	char tmp[5] = { '\0' };
	tmp[0] = aeroport_code[0];
	tmp[1] = aeroport_code[1];
	tmp[2] = aeroport_code[2];
	tmp[3] = aeroport_code[3];
	QString city_string = QString::fromUtf8(tmp);

	answer.X = database[city_string].routeLat;
	answer.Z = database[city_string].routeLon;
	answer.H = 300;//database[city_string].routeLat;

}
inline void MAP_fill_route(UDP_data_t * map_data_, _MainVisualData *vis_data, _AirportData *airp_data)// , camera_part *part)
{
	// map data

	/*map_data_->isOrientingCamera = part->isOrientingCamera;
	map_data_->isShowingWindow = part->isShowingWindow;
	map_data_->showCurTraj = part->showCurTraj;
	map_data_->showRoute = part->showRoute;
	map_data_->followMainPlane = part->followMainPlane;

	map_data_->currWPT = part->currWPT;		  */
	map_data_->curLat = vis_data->p_coord.X;
	map_data_->curLon = vis_data->p_coord.Z;
	map_data_->curH = vis_data->p_coord.H;

	map_data_->curGamma = vis_data->p_angle.R;
	map_data_->curPsi = vis_data->p_angle.C;
	map_data_->curTheta = vis_data->p_angle.P;
	//map_data_->updateRoute = part->updateRoute;
	//route

	const auto &route_points_by_icao = fillRouteByICAO();
	
	char tmp[5] = { '\0' };
	tmp[0] = airp_data->ARRIVAL_AIRPORT_CODE[0];
	tmp[1] = airp_data->ARRIVAL_AIRPORT_CODE[1];
	tmp[2] = airp_data->ARRIVAL_AIRPORT_CODE[2];
	tmp[3] = airp_data->ARRIVAL_AIRPORT_CODE[3];
	QString arrCity = QString::fromUtf8(tmp);


	tmp[0] = airp_data->DEPARTURE_AIRPORT_CODE[0];
	tmp[1] = airp_data->DEPARTURE_AIRPORT_CODE[1];
	tmp[2] = airp_data->DEPARTURE_AIRPORT_CODE[2];
	tmp[3] = airp_data->DEPARTURE_AIRPORT_CODE[3];

	QString depCity = QString::fromUtf8(tmp);
	map_data_->routeLat[0] = route_points_by_icao[depCity].routeLat;
	map_data_->routeLon[0] = route_points_by_icao[depCity].routeLon;
	map_data_->routeAlt[0] = route_points_by_icao[depCity].routeAlt;

	map_data_->routeLat[1] = route_points_by_icao[arrCity].routeLat;
	map_data_->routeLon[1] = route_points_by_icao[arrCity].routeLon;
	map_data_->routeAlt[1] = route_points_by_icao[arrCity].routeAlt;

	for (size_t i = 2; i < 53; ++i)
	{
		map_data_->routeLat[i] = map_data_->routeLat[1];
		map_data_->routeLon[i] = map_data_->routeLon[1];
		map_data_->routeAlt[i] = map_data_->routeAlt[1];
	}
	//bots
	for (auto & bot : map_data_->bots)
	{
		bot.H = 0;
		bot.lat = 0;
		bot.psi = 0;
		bot.visibility = 0;
	}
}


inline QMap <QString, QString> fillICAObyRus(QMap<QString, codes> &aeroports_codes)
{
	QMap<QString, QString> answer;
	//QMap<QString, codes> &aeroports_codes;
	foreach(QString key, aeroports_codes.keys())
	{
		QString value = aeroports_codes.value(key).icao;
		answer[value] = key;
	}

	return answer;
}
inline void printAeroData(const _AirportData *_data)
{
	qDebug() << "airoports_lights_data->packet_id" << _data->packet_id;
	qDebug() << "ARRIVAL_AIRPORT_LIGHTS_ILLUMINATION" << (int)_data->ARRIVAL_AIRPORT_LIGHTS_ILLUMINATION;
	qDebug() << "ARRIVAL_AIRPORT_LIGHTS_TAXIING" << (int)_data->ARRIVAL_AIRPORT_LIGHTS_TAXIING;
	qDebug() << "ARRIVAL_AIRPORT_OTHER_LIGHTS" << (int)_data->ARRIVAL_AIRPORT_OTHER_LIGHTS;
	qDebug() << "DEPARTURE_AIRPORT_LIGHTS_ILLUMINATION" << (int)_data->DEPARTURE_AIRPORT_LIGHTS_ILLUMINATION;
	qDebug() << "DEPARTURE_AIRPORT_LIGHTS_TAXIING" << (int)_data->DEPARTURE_AIRPORT_LIGHTS_TAXIING;
	qDebug() << "DEPARTURE_AIRPORT_OTHER_LIGHTS" << (int)_data->DEPARTURE_AIRPORT_OTHER_LIGHTS;
	qDebug() << "TAKEOFF_RUNWAY_BORDER_LIGHTS" << (int)_data->TAKEOFF_RUNWAY_BORDER_LIGHTS;
	qDebug() << "LANDING_RUNWAY_BORDER_LIGHTS" << (int)_data->LANDING_RUNWAY_BORDER_LIGHTS;
	qDebug() << "LANDING_RUNWAY_CODE" << _data->LANDING_RUNWAY_BORDER_LIGHTS;
	qDebug() << "TAKEOFF_RUNWAY_CODE" << _data->TAKEOFF_RUNWAY_CODE;
	qDebug() << "DEPARTURE_AIRPORT_CODE" << _data->DEPARTURE_AIRPORT_CODE;;
	qDebug() << "ARRIVAL_AIRPORT_CODE" << _data->TAKEOFF_RUNWAY_CODE;
	qDebug() << "time now" << (int)_data->model_simulation_time;	
}

inline void printMeteo(const _MeteoData *meteo_data)
{
	qDebug() << "packet_id = " << meteo_data->packet_id;
	qDebug() << "Visibility = " << meteo_data->visibility;
	qDebug() << "CloudBase = " << meteo_data->cloudBase;
	qDebug() << "CloudUpper = " << meteo_data->cloudUpper << ";\n";
	qDebug() << "CloudSize = " << meteo_data->cloudSize;
	qDebug() << "cloudsType = " << (int)meteo_data->cloudsType;
	qDebug() << "cloudsSecondLay = " << (int)meteo_data->cloudsSecondLay;
	qDebug() << "SecLayHeight = " << meteo_data->SecLayHeight;
	qDebug() << "Day = " << meteo_data->Day;
	qDebug() << "Month = " << meteo_data->Month;
	qDebug() << "Hours = " << meteo_data->Hours;
	qDebug() << "Minutes = " << meteo_data->Minutes;
	qDebug() << "local_visibility = " << meteo_data->local_visibility;
	qDebug() << "rain = " << meteo_data->rain;
	qDebug() << "snow = " << meteo_data->snow;
	qDebug() << "hmist = " << meteo_data->hmist;
	qDebug() << "wind_speed = " << meteo_data->wind_speed;
	qDebug() << "wind_psi  = " << meteo_data->wind_psi;
	qDebug() << "StarBright = " << meteo_data->starBright;
}


inline void printVisualData(_MainVisualData *set_data)
{
	qDebug() << "p_coord.X" << set_data->p_coord.X;
	qDebug() << "p_coord.Z" << set_data->p_coord.Z;
	qDebug() << "p_coord.H" << set_data->p_coord.H;
	qDebug() << "p_coord.C" << set_data->p_angle.C;
	qDebug() << "p_coord.P" << set_data->p_angle.P;
	qDebug() << "p_coord.R" << set_data->p_angle.R;

	//обороты
	qDebug() << "N2_L" << set_data->N2_L;
	qDebug() << "N2_R" << set_data->N2_R;

	//stabs, mechs
	qDebug() << "Flaps" << set_data->Flaps;
	qDebug() << "Stabilizer" << set_data->Stabilizer;
	qDebug() << "Slats" << set_data->Slats;

	qDebug() << "Elevator_L" << set_data->Elevator_L;
	qDebug() << "Elevator_R" << set_data->Elevator_R;
	qDebug() << "Aileron_L" << set_data->Aileron_L;
	qDebug() << "Aileron_R" << set_data->Aileron_R;
	qDebug() << "Rudder" << set_data->Rudder;

	qDebug() << "Spoiler_L_CE" << set_data->Spoiler_L_CE;
	qDebug() << "Spoiler_L_IN" << set_data->Spoiler_L_IN;
	qDebug() << "Spoiler_L_OB" << set_data->Spoiler_L_OB;
	qDebug() << "Spoiler_R_CE" << set_data->Spoiler_R_CE;
	qDebug() << "Spoiler_R_IN" << set_data->Spoiler_R_IN;
	qDebug() << "Spoiler_R_OB" << set_data->Spoiler_R_OB;

	qDebug() << "GroudSpoiler_L_IB" << set_data->GroudSpoiler_L_IB;
	qDebug() << "GroudSpoiler_L_OB" << set_data->GroudSpoiler_L_OB;
	qDebug() << "GroudSpoiler_R_IB" << set_data->GroudSpoiler_R_IB;
	qDebug() << "GroudSpoiler_R_OB" << set_data->GroudSpoiler_R_OB;

	qDebug() << "Gear_N" << set_data->Gear_N;
	qDebug() << "Gear_L" << set_data->Gear_L;
	qDebug() << "Gear_R" << set_data->Gear_R;

	//бортовые огни

	qDebug() << "LandingLights" << (int)set_data->LandingLights;
	qDebug() << "TaxiLight" << set_data->TaxiLight;
	qDebug() << "RunwayTurnoffLights" << set_data->RunwayTurnoffLights;

	qDebug() << "NavigationLightGreen" << set_data->NavigationLightGreen;
	qDebug() << "NavigationLightRed" << set_data->NavigationLightRed;
	qDebug() << "NavigationLightWhite" << set_data->NavigationLightWhite;

	qDebug() << "AntiCollisionBeaconWhite" << set_data->AntiCollisionBeaconWhite;
	qDebug() << "AntiCollisionBeaconRed" << set_data->AntiCollisionBeaconRed;
	qDebug() << "InternalLights" << set_data->InternalLights;

}
inline void deep_meteo_copy(const _MeteoData *_data, _MeteoData *data)
{
	data->packet_id = _data->packet_id;
	data->visibility = _data->visibility;
	data->cloudBase = _data->cloudBase;
	data->cloudUpper = _data->cloudUpper;
	data->cloudSize = _data->cloudSize;
	data->cloudsType = _data->cloudsType;
	data->cloudsSecondLay = _data->cloudsSecondLay;
	data->SecLayHeight = _data->SecLayHeight;
	data->Day = _data->Day;
	data->Month = _data->Month;
	data->Hours = _data->Hours;
	data->Minutes = _data->Minutes;
	data->local_visibility = _data->local_visibility;
	data->rain = _data->rain;
	data->snow = _data->snow;
	data->hmist = _data->hmist;
	data->wind_speed = _data->wind_speed;
	data->wind_psi = _data->wind_psi;
	data->starBright = _data->starBright;
}

inline void deepAeroportcopy(const _AirportData *_data, _AirportData *airoports_lights_data)
{
	airoports_lights_data->packet_id = NPR_PACKET_TYPE_AIRPORT_DATA;
	airoports_lights_data->ARRIVAL_AIRPORT_LIGHTS_ILLUMINATION = _data->ARRIVAL_AIRPORT_LIGHTS_ILLUMINATION;
	airoports_lights_data->ARRIVAL_AIRPORT_LIGHTS_TAXIING = _data->ARRIVAL_AIRPORT_LIGHTS_TAXIING;
	airoports_lights_data->ARRIVAL_AIRPORT_OTHER_LIGHTS = _data->ARRIVAL_AIRPORT_OTHER_LIGHTS;
	airoports_lights_data->DEPARTURE_AIRPORT_LIGHTS_ILLUMINATION = _data->DEPARTURE_AIRPORT_LIGHTS_ILLUMINATION;
	airoports_lights_data->DEPARTURE_AIRPORT_LIGHTS_TAXIING = _data->DEPARTURE_AIRPORT_LIGHTS_TAXIING;
	airoports_lights_data->DEPARTURE_AIRPORT_OTHER_LIGHTS = _data->DEPARTURE_AIRPORT_OTHER_LIGHTS;
	airoports_lights_data->TAKEOFF_RUNWAY_BORDER_LIGHTS = _data->TAKEOFF_RUNWAY_BORDER_LIGHTS;
	airoports_lights_data->LANDING_RUNWAY_BORDER_LIGHTS = _data->LANDING_RUNWAY_BORDER_LIGHTS;

	airoports_lights_data->TAKEOFF_RUNWAY_CODE[0] = _data->TAKEOFF_RUNWAY_CODE[0];
	airoports_lights_data->TAKEOFF_RUNWAY_CODE[1] = _data->TAKEOFF_RUNWAY_CODE[1];
	airoports_lights_data->TAKEOFF_RUNWAY_CODE[2] = _data->TAKEOFF_RUNWAY_CODE[2];
	airoports_lights_data->TAKEOFF_RUNWAY_CODE[3] = _data->TAKEOFF_RUNWAY_CODE[3];

	airoports_lights_data->ARRIVAL_AIRPORT_CODE[0] = _data->ARRIVAL_AIRPORT_CODE[0];
	airoports_lights_data->ARRIVAL_AIRPORT_CODE[1] = _data->ARRIVAL_AIRPORT_CODE[1];
	airoports_lights_data->ARRIVAL_AIRPORT_CODE[2] = _data->ARRIVAL_AIRPORT_CODE[2];
	airoports_lights_data->ARRIVAL_AIRPORT_CODE[3] = _data->ARRIVAL_AIRPORT_CODE[3];

	airoports_lights_data->DEPARTURE_AIRPORT_CODE[0] = _data->DEPARTURE_AIRPORT_CODE[0];
	airoports_lights_data->DEPARTURE_AIRPORT_CODE[1] = _data->DEPARTURE_AIRPORT_CODE[1];
	airoports_lights_data->DEPARTURE_AIRPORT_CODE[2] = _data->DEPARTURE_AIRPORT_CODE[2];
	airoports_lights_data->DEPARTURE_AIRPORT_CODE[3] = _data->DEPARTURE_AIRPORT_CODE[3];

	airoports_lights_data->LANDING_RUNWAY_CODE[0] = _data->LANDING_RUNWAY_CODE[0];
	airoports_lights_data->LANDING_RUNWAY_CODE[1] = _data->LANDING_RUNWAY_CODE[1];
	airoports_lights_data->LANDING_RUNWAY_CODE[2] = _data->LANDING_RUNWAY_CODE[2];
	airoports_lights_data->LANDING_RUNWAY_CODE[3] = _data->LANDING_RUNWAY_CODE[3];
	airoports_lights_data->model_simulation_time = _data->model_simulation_time;
/*	qstrcpy(airoports_lights_data->TAKEOFF_RUNWAY_CODE, _data->TAKEOFF_RUNWAY_CODE);
	qstrcpy(airoports_lights_data->LANDING_RUNWAY_CODE, _data->LANDING_RUNWAY_CODE);
	qstrcpy(airoports_lights_data->DEPARTURE_AIRPORT_CODE, _data->DEPARTURE_AIRPORT_CODE);
	qstrcpy(airoports_lights_data->ARRIVAL_AIRPORT_CODE, _data->ARRIVAL_AIRPORT_CODE);	  */
}

inline void deepVisualCopy(const _MainVisualData *data, _MainVisualData *visual_data)
{
	visual_data->packet_id = NPR_PACKET_TYPE_VISUAL_DATA;

	visual_data->num_correct = data->num_correct;
	visual_data->p_coord.X = data->p_coord.X;
	visual_data->p_coord.Z = data->p_coord.Z;
	visual_data->p_coord.H = data->p_coord.H;

	visual_data->p_angle.C = data->p_angle.C;
	visual_data->p_angle.P = data->p_angle.P;
	visual_data->p_angle.R = data->p_angle.R;

	//обороты
	visual_data->N2_L = data->N2_L;
	visual_data->N2_R = data->N2_R;

	//stabs, mechs
	visual_data->Flaps = data->Flaps;
	visual_data->Stabilizer = data->Stabilizer;
	visual_data->Slats = data->Slats;

	visual_data->Elevator_L = data->Elevator_L;
	visual_data->Elevator_R = data->Elevator_R;
	visual_data->Aileron_L = data->Aileron_L;
	visual_data->Aileron_R = data->Aileron_R;
	visual_data->Rudder = data->Rudder;

	visual_data->Spoiler_L_CE = data->Spoiler_L_CE;
	visual_data->Spoiler_L_IN = data->Spoiler_L_IN;
	visual_data->Spoiler_L_OB = data->Spoiler_L_OB;
	visual_data->Spoiler_R_CE = data->Spoiler_R_CE;
	visual_data->Spoiler_R_IN = data->Spoiler_R_IN;
	visual_data->Spoiler_R_OB = data->Spoiler_R_OB;

	visual_data->GroudSpoiler_L_IB = data->GroudSpoiler_L_IB;
	visual_data->GroudSpoiler_L_OB = data->GroudSpoiler_L_OB;
	visual_data->GroudSpoiler_R_IB = data->GroudSpoiler_R_IB;
	visual_data->GroudSpoiler_R_OB = data->GroudSpoiler_R_OB;
	visual_data->Spoiler_R_IN = data->Spoiler_R_IN;
	visual_data->Gear_N = data->Gear_N;
	visual_data->Gear_L = data->Gear_L;
	visual_data->Gear_R = data->Gear_R;
	visual_data->Gear_SteeringAngle = data->Gear_SteeringAngle;

	//бортовые огни
	visual_data->LandingLights = data->LandingLights;
	visual_data->TaxiLight = data->TaxiLight;
	visual_data->RunwayTurnoffLights = data->RunwayTurnoffLights;
	visual_data->NavigationLightGreen = data->NavigationLightGreen;
	visual_data->NavigationLightRed = data->NavigationLightRed;
	visual_data->NavigationLightWhite = data->NavigationLightWhite;
	visual_data->AntiCollisionBeaconWhite = data->AntiCollisionBeaconWhite;
	visual_data->AntiCollisionBeaconRed = data->AntiCollisionBeaconRed;
	visual_data->InternalLights = data->InternalLights;


	// ход расчетов
	visual_data->SimulationRunning = data->SimulationRunning;               // Признак того, что моделирование (расчет) идёт
	visual_data->SimulationReset = data->SimulationReset;                           // Признак перезапуска моделирования

	// дополнительная информация для графиков

	visual_data->Alpha = data->Alpha;
	visual_data->Beta = data->Beta;
	visual_data->wx = data->wx;
	visual_data->wy = data->wy;
	visual_data->wz = data->wz;
	visual_data->nx = data->nx;
	visual_data->ny = data->ny;
	visual_data->nz = data->nz;
	visual_data->Vx_ef = data->Vx_ef;

	visual_data->VCAS = data->VCAS;
	visual_data->VTAS = data->VTAS;
	visual_data->M = data->M;
	visual_data->RadioAltitude = data->RadioAltitude;
	visual_data->WOW_L = data->WOW_L;
	visual_data->WOW_R = data->WOW_R;
	visual_data->WOW_N = data->WOW_N;
	visual_data->model_simulation_time = data->model_simulation_time;
}
inline void flushVISUALData(_MainVisualData visual_data)
{
	visual_data.packet_id = NPR_PACKET_TYPE_VISUAL_DATA;
	visual_data.num_correct = 0;
	visual_data.p_coord.X = 0;;
	visual_data.p_coord.Z = 0;
	visual_data.p_coord.H = 0;

	visual_data.p_angle.C = 0;
	visual_data.p_angle.P = 0;
	visual_data.p_angle.R = 0;

	//обороты
	visual_data.N2_L = 0;
	visual_data.N2_R = 0;

	//stabs, mechs
	visual_data.Flaps = 0;
	visual_data.Stabilizer = 0;
	visual_data.Slats = 0;

	visual_data.Elevator_L = 0;
	visual_data.Elevator_R = 0;
	visual_data.Aileron_L = 0;
	visual_data.Aileron_R = 0;
	visual_data.Rudder = 0;

	visual_data.Spoiler_L_CE = 0;;
	visual_data.Spoiler_L_IN = 0;
	visual_data.Spoiler_L_OB = 0;
	visual_data.Spoiler_R_CE = 0;
	visual_data.Spoiler_R_IN = 0;
	visual_data.Spoiler_R_OB = 0;

	visual_data.GroudSpoiler_L_IB = 0;
	visual_data.GroudSpoiler_L_OB = 0;
	visual_data.GroudSpoiler_R_IB = 0;
	visual_data.GroudSpoiler_R_OB = 0;
	visual_data.Spoiler_R_IN = 0;
	visual_data.Gear_N = 0;
	visual_data.Gear_L = 0;
	visual_data.Gear_R = 0;;
	visual_data.Gear_SteeringAngle = 0;

	//бортовые огни
	visual_data.LandingLights = 0;
	visual_data.TaxiLight = 0;
	visual_data.RunwayTurnoffLights = 0;;
	visual_data.NavigationLightGreen = 0;;
	visual_data.NavigationLightRed = 0;;
	visual_data.NavigationLightWhite = 0;
	visual_data.AntiCollisionBeaconWhite = 0;
	visual_data.AntiCollisionBeaconRed = 0;
	visual_data.InternalLights = 0;

	visual_data.SimulationRunning = 0;
	visual_data.SimulationReset = 0;
	visual_data.Alpha = 0;;
	visual_data.Beta = 0;;
	visual_data.wx = 0;;
	visual_data.wy = 0;
	visual_data.wz = 0;
	visual_data.nx = 0;
	visual_data.ny = 0;
	visual_data.nz = 0;;
	visual_data.Vx_ef = 0;
	visual_data.VCAS = 0;
	visual_data.VTAS = 0;
	visual_data.M = 0;
	visual_data.RadioAltitude = 0;

	visual_data.WOW_L = 0;
	visual_data.WOW_R = 0;
	visual_data.WOW_N = 0;

}
inline void flushaEROData(_AirportData *airoports_lights_data)
{
	airoports_lights_data->packet_id = NPR_PACKET_TYPE_AIRPORT_DATA;
	airoports_lights_data->ARRIVAL_AIRPORT_LIGHTS_ILLUMINATION = 0;
	airoports_lights_data->ARRIVAL_AIRPORT_LIGHTS_TAXIING = 0;
	airoports_lights_data->ARRIVAL_AIRPORT_OTHER_LIGHTS = 0;
	airoports_lights_data->DEPARTURE_AIRPORT_LIGHTS_ILLUMINATION = 0;
	airoports_lights_data->DEPARTURE_AIRPORT_LIGHTS_TAXIING = 0;
	airoports_lights_data->DEPARTURE_AIRPORT_OTHER_LIGHTS = 0;
	airoports_lights_data->TAKEOFF_RUNWAY_BORDER_LIGHTS = 0;
	airoports_lights_data->LANDING_RUNWAY_BORDER_LIGHTS = 0;

	qstrcpy(airoports_lights_data->TAKEOFF_RUNWAY_CODE, "0");
	qstrcpy(airoports_lights_data->LANDING_RUNWAY_CODE, "0");
	qstrcpy(airoports_lights_data->DEPARTURE_AIRPORT_CODE, "0");
	qstrcpy(airoports_lights_data->ARRIVAL_AIRPORT_CODE, "0");
}
inline void flushMeteoData(_MeteoData *data)
{
	//flush data
	data->visibility=0;
   data->cloudBase=0;
   data->cloudUpper=0;
   data->cloudSize=0;
   data->cloudsType=0;
   data->cloudsSecondLay=0;
   data->SecLayHeight=0;

   data->Month=0;
   data->Day=0;
   data->Hours=0;
   data->Minutes=0;

   data->local_visibility=0;
   data->rain=0;
   data->snow=0;
   data->hmist=0;
   data->wind_speed=0;
   data->wind_psi=0;
   data->starBright=0;
}

inline void backwardDeepCopy(const _DataToModel * _data, _DataToModel  *backward_data)
{
	backward_data->packet_id = NPR_PACKET_TYPE_BACK_DATA;
	backward_data->p_coord.H = _data->p_coord.H;
	backward_data->p_coord.X = _data->p_coord.X;
	backward_data->p_coord.Z = _data->p_coord.Z;
	backward_data->simulation_time = _data->simulation_time;

	/*qDebug() << "received backward";
	qDebug() << "packet_id" << _data->packet_id;
	qDebug() << "p_coord.H" << _data->p_coord.H;
	qDebug() << "p_coord.X" << _data->p_coord.X;
	qDebug() << "p_coord.Z" << _data->p_coord.Z;
	qDebug() << "simulation_time" << _data->simulation_time;	   */
}

inline void flushBackwardData(const _DataToModel * _data, _DataToModel  *backward_data)
{
	backward_data->packet_id = NPR_PACKET_TYPE_BACK_DATA;
	backward_data->p_coord.H = 0;
	backward_data->p_coord.X = 0;
	backward_data->p_coord.Z =0;
//	backward_data.simulation_time = 0;

	qDebug() << "received backward";
	qDebug() << "packet_id" << _data->packet_id;
	qDebug() << "p_coord.H" << _data->p_coord.H;
	qDebug() << "p_coord.X" << _data->p_coord.X;
	qDebug() << "p_coord.Z" << _data->p_coord.Z;
	qDebug() << "simulation_time" << _data->simulation_time;
}


#endif // UTILITIES_H
