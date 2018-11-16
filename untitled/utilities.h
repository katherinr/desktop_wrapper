#ifndef UTILITIES_H
#define UTILITIES_H

#include "meteo_struct.h"
#include "qdebug.h"

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

	qDebug() << "received backward";
	qDebug() << "packet_id" << _data->packet_id;
	qDebug() << "p_coord.H" << _data->p_coord.H;
	qDebug() << "p_coord.X" << _data->p_coord.X;
	qDebug() << "p_coord.Z" << _data->p_coord.Z;
	qDebug() << "simulation_time" << _data->simulation_time;
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
