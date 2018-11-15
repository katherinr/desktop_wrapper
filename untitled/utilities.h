#ifndef UTILITIES_H
#define UTILITIES_H

#include "meteo_struct.h"
#include "qdebug.h"

inline void printAeroData(const _AirportData *_data)
{
    qDebug() <<"airoports_lights_data->packet_id"<< _data->packet_id;
    qDebug() <<"ARRIVAL_AIRPORT_LIGHTS_ILLUMINATION" <<  (int)_data->ARRIVAL_AIRPORT_LIGHTS_ILLUMINATION;
    qDebug() <<"ARRIVAL_AIRPORT_LIGHTS_TAXIING"<< (int) _data->ARRIVAL_AIRPORT_LIGHTS_TAXIING;
    qDebug() <<"ARRIVAL_AIRPORT_OTHER_LIGHTS" << (int)_data->ARRIVAL_AIRPORT_OTHER_LIGHTS;
    qDebug() <<"DEPARTURE_AIRPORT_LIGHTS_ILLUMINATION" << (int) _data->DEPARTURE_AIRPORT_LIGHTS_ILLUMINATION;
    qDebug() <<"DEPARTURE_AIRPORT_LIGHTS_TAXIING"<< (int)_data->DEPARTURE_AIRPORT_LIGHTS_TAXIING;
    qDebug() <<"DEPARTURE_AIRPORT_OTHER_LIGHTS"<< (int) _data->DEPARTURE_AIRPORT_OTHER_LIGHTS;
    qDebug() <<"TAKEOFF_RUNWAY_BORDER_LIGHTS" << (int) _data->TAKEOFF_RUNWAY_BORDER_LIGHTS;
    qDebug() <<"LANDING_RUNWAY_BORDER_LIGHTS" << (int) _data->LANDING_RUNWAY_BORDER_LIGHTS;
    qDebug() << "LANDING_RUNWAY_CODE"<<  _data->LANDING_RUNWAY_BORDER_LIGHTS;
    qDebug() << "TAKEOFF_RUNWAY_CODE"<<_data->TAKEOFF_RUNWAY_CODE;
    qDebug() << "DEPARTURE_AIRPORT_CODE"<<  _data->DEPARTURE_AIRPORT_CODE;;
    qDebug() << "ARRIVAL_AIRPORT_CODE"<<_data->TAKEOFF_RUNWAY_CODE;
    qDebug() << "time now"<<(int)_data->model_simulation_time;
}

inline void printMeteo(const _MeteoData *meteo_data)
{
    qDebug() << "packet_id = " << meteo_data->packet_id;
    qDebug() << "Visibility = " << meteo_data->visibility ;
    qDebug() << "CloudBase = " << meteo_data->cloudBase;
    qDebug() << "CloudUpper = " << meteo_data->cloudUpper << ";\n";
    qDebug() << "CloudSize = " << meteo_data->cloudSize ;
    qDebug() << "cloudsType = " << (int)meteo_data->cloudsType;
    qDebug() << "cloudsSecondLay = " <<(int) meteo_data->cloudsSecondLay;
    qDebug() << "SecLayHeight = " << meteo_data->SecLayHeight;
    qDebug() << "Day = " << meteo_data->Day;
    qDebug() << "Month = " << meteo_data->Month ;
    qDebug() << "Hours = " << meteo_data->Hours;
    qDebug() << "Minutes = " << meteo_data->Minutes;
    qDebug() << "local_visibility = " << meteo_data->local_visibility;
    qDebug() << "rain = " << meteo_data->rain;
    qDebug() << "snow = " << meteo_data->snow ;
    qDebug() << "hmist = " << meteo_data->hmist ;
    qDebug() << "wind_speed = " << meteo_data->wind_speed ;
    qDebug() << "wind_psi  = " << meteo_data->wind_psi;
    qDebug() << "StarBright = " << meteo_data->starBright ;
}


inline void printVisualData(_MainVisualData *set_data)
{
    qDebug()<< "p_coord.X" << set_data->p_coord.X;
    qDebug()<< "p_coord.Z" << set_data->p_coord.Z;
    qDebug() << "p_coord.H"<< set_data->p_coord.H;
    qDebug() << "p_coord.C"<< set_data->p_angle.C;
    qDebug()<< "p_coord.P" << set_data->p_angle.P;
    qDebug() << "p_coord.R"<< set_data->p_angle.R;

    //обороты
    qDebug()<< "N2_L" <<set_data->N2_L ;
    qDebug()<< "N2_R" <<set_data->N2_R ;

    //stabs, mechs
    qDebug()<< "Flaps" <<set_data->Flaps;
    qDebug() << "Stabilizer"<< set_data->Stabilizer ;
    qDebug()<< "Slats" <<set_data->Slats ;

    qDebug()<< "Elevator_L" << set_data->Elevator_L;
    qDebug() << "Elevator_R"<< set_data->Elevator_R ;
    qDebug()<< "Aileron_L" << set_data->Aileron_L;
    qDebug() << "Aileron_R"<<  set_data->Aileron_R ;
    qDebug() << "Rudder"<<  set_data->Rudder;

    qDebug() << "Spoiler_L_CE" << set_data->Spoiler_L_CE ;
    qDebug()  << "Spoiler_L_IN"<<  set_data->Spoiler_L_IN;
    qDebug()  << "Spoiler_L_OB"<< set_data->Spoiler_L_OB ;
    qDebug()  << "Spoiler_R_CE"<< set_data->Spoiler_R_CE ;
    qDebug() << "Spoiler_R_IN" << set_data->Spoiler_R_IN ;
    qDebug()  << "Spoiler_R_OB"<<set_data->Spoiler_R_OB ;

    qDebug() << "GroudSpoiler_L_IB"<<set_data->GroudSpoiler_L_IB ;
    qDebug()<< "GroudSpoiler_L_OB" << set_data->GroudSpoiler_L_OB ;
    qDebug() << "GroudSpoiler_R_IB"<< set_data->GroudSpoiler_R_IB;
    qDebug() << "GroudSpoiler_R_OB"<< set_data->GroudSpoiler_R_OB ;

    qDebug()<< "Gear_N" << set_data->Gear_N ;
    qDebug() << "Gear_L"<< set_data->Gear_L;
    qDebug() << "Gear_R"<< set_data->Gear_R ;

    //бортовые огни

    qDebug() << "LandingLights" << (int)set_data->LandingLights ;
    qDebug() << "TaxiLight" << set_data->TaxiLight  ;
    qDebug() << "RunwayTurnoffLights" << set_data->RunwayTurnoffLights ;

    qDebug()  << "NavigationLightGreen"<< set_data->NavigationLightGreen;
    qDebug() << "NavigationLightRed" << set_data->NavigationLightRed ;
    qDebug() << "NavigationLightWhite" << set_data->NavigationLightWhite ;

    qDebug() << "AntiCollisionBeaconWhite" <<  set_data->AntiCollisionBeaconWhite ;
    qDebug()  << "AntiCollisionBeaconRed"<< set_data->AntiCollisionBeaconRed;
    qDebug()  << "InternalLights"<< set_data->InternalLights;

}
inline void deep_meteo_copy(const _MeteoData *_data, _MeteoData *data )
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
#endif // UTILITIES_H
