#include "file_meteo_io.h"

#include <QFileDialog>

std::shared_ptr<METEO_DATA> readFile(QFile& file_)
{
    //TODO: This shit code
     std::shared_ptr<METEO_DATA> p_meteo_data(new METEO_DATA());
     QString str;
     //file_ >> str;
     p_meteo_data->message = 11;
     p_meteo_data->Visibility = 50000;
     p_meteo_data->CloudBase = 10000;
     p_meteo_data->CloudUpper = 2000;
     p_meteo_data->CloudSize = 4;
     p_meteo_data->cloudsType = 0;
     p_meteo_data->cloudsSecondLay = 1;
     p_meteo_data->SecLayHeight = 21000;
     p_meteo_data->Day = 15;
     p_meteo_data->Month = 5;
     p_meteo_data->Hours = 12;
     p_meteo_data->Minutes = 0;
     p_meteo_data->local_visibility = 1000000;
     p_meteo_data->rain = 0;
     p_meteo_data->snow = 0;
     p_meteo_data->hmist = 0;
     p_meteo_data->wind_speed = 5;
     p_meteo_data->wind_psi = 216;
     p_meteo_data->StarBright = 100;

     return p_meteo_data;
}

std::shared_ptr<METEO_DATA> FileMeteoIO::loadFile()
{
    QString str = QFileDialog::getOpenFileName(nullptr, "Open Dialog", "", "*.txt");    //#include <QFileDialog>
    //qDebug() << str;
    if(str.size())
    {
        QFile file_for_reading(str);                    //#include <QFile>
        if(file_for_reading.open(QIODevice::ReadOnly))
        {
            std::shared_ptr<METEO_DATA> p_meteo_data(new METEO_DATA());
        }
    }
    return nullptr;
}
