#include "meteo_struct.h"

void deep_meteo_copy(METEO_DATA *_data,METEO_DATA *data )
{
    data->message = _data->message;
    data->Visibility = _data->Visibility;
    data->CloudBase = _data->CloudBase;
    data->CloudUpper = _data->CloudUpper;
    data->CloudSize = _data->CloudSize;
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
    data->StarBright = _data->StarBright;
}
