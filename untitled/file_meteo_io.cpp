#include "file_meteo_io.h"

#include <QFileDialog>
#include <qdebug.h>

std::shared_ptr<METEO_DATA> FileMeteoIO::readFile(QFile& file_)
{
    //TODO: This shit code
     std::shared_ptr<METEO_DATA> p_meteo_data(new METEO_DATA());

     QTextStream in(&file_);
     QStringList line;
     QString str_val;
     if(!in.atEnd())
     {
        line = in.readLine().split(' ');
        str_val = line.first();
        if(str_val != "METEO_DATA.message")
        {
            return nullptr;
        }
        str_val = line.last();
        auto delim_pos =  str_val.indexOf(';');
        p_meteo_data->message = str_val.left(delim_pos).toInt();
     }

     if(!in.atEnd())
     {
        line = in.readLine().split(' ');
        str_val = line.last();
        auto delim_pos =  str_val.indexOf(';');
        p_meteo_data->Visibility = str_val.left(delim_pos).toFloat();
     }

     if(!in.atEnd())
     {
        line = in.readLine().split(' ');
        str_val = line.last();
        auto delim_pos =  str_val.indexOf(';');
        p_meteo_data->CloudBase = str_val.left(delim_pos).toShort();
     }

     if(!in.atEnd())
     {
        line = in.readLine().split(' ');
        str_val = line.last();
        auto delim_pos =  str_val.indexOf(';');
        p_meteo_data->CloudUpper = str_val.left(delim_pos).toShort();
     }

     if(!in.atEnd())
     {
        line = in.readLine().split(' ');
        str_val = line.last();
        auto delim_pos =  str_val.indexOf(';');
        p_meteo_data->CloudSize = str_val.left(delim_pos).toShort();
     }

     if(!in.atEnd())
     {
        line = in.readLine().split(' ');
        str_val = line.last();
        auto delim_pos =  str_val.indexOf(';');
        p_meteo_data->cloudsType = str_val.left(delim_pos).toInt();
     }

     if(!in.atEnd())
     {
        line = in.readLine().split(' ');
        str_val = line.last();
        auto delim_pos =  str_val.indexOf(';');
        p_meteo_data->cloudsSecondLay = str_val.left(delim_pos).toInt();
     }

     if(!in.atEnd())
     {
        line = in.readLine().split(' ');
        str_val = line.last();
        auto delim_pos =  str_val.indexOf(';');
        p_meteo_data->SecLayHeight = str_val.left(delim_pos).toFloat();
     }

     if(!in.atEnd())
     {
        line = in.readLine().split(' ');
        str_val = line.last();
        auto delim_pos =  str_val.indexOf(';');
        p_meteo_data->Day = str_val.left(delim_pos).toShort();
     }

     if(!in.atEnd())
     {
        line = in.readLine().split(' ');
        str_val = line.last();
        auto delim_pos =  str_val.indexOf(';');
        p_meteo_data->Month = str_val.left(delim_pos).toShort();
     }

     if(!in.atEnd())
     {
        line = in.readLine().split(' ');
        str_val = line.last();
        auto delim_pos =  str_val.indexOf(';');
        p_meteo_data->Hours = str_val.left(delim_pos).toShort();
     }

     if(!in.atEnd())
     {
        line = in.readLine().split(' ');
        str_val = line.last();
        auto delim_pos =  str_val.indexOf(';');
        p_meteo_data->Minutes = str_val.left(delim_pos).toShort();
     }

     if(!in.atEnd())
     {
        line = in.readLine().split(' ');
        str_val = line.last();
        auto delim_pos =  str_val.indexOf(';');
        p_meteo_data->local_visibility = str_val.left(delim_pos).toFloat();
     }

     if(!in.atEnd())
     {
        line = in.readLine().split(' ');
        str_val = line.last();
        auto delim_pos =  str_val.indexOf(';');
        p_meteo_data->rain = str_val.left(delim_pos).toFloat();
     }

     if(!in.atEnd())
     {
        line = in.readLine().split(' ');
        str_val = line.last();
        auto delim_pos =  str_val.indexOf(';');
        p_meteo_data->snow = str_val.left(delim_pos).toFloat();
     }

     if(!in.atEnd())
     {
        line = in.readLine().split(' ');
        str_val = line.last();
        auto delim_pos =  str_val.indexOf(';');
        p_meteo_data->hmist = str_val.left(delim_pos).toFloat();
     }

     if(!in.atEnd())
     {
        line = in.readLine().split(' ');
        str_val = line.last();
        auto delim_pos =  str_val.indexOf(';');
        p_meteo_data->wind_speed = str_val.left(delim_pos).toFloat();
     }

     if(!in.atEnd())
     {
        line = in.readLine().split(' ');
        str_val = line.last();
        auto delim_pos =  str_val.indexOf(';');
        p_meteo_data->wind_psi = str_val.left(delim_pos).toFloat();
     }

     if(!in.atEnd())
     {
        line = in.readLine().split(' ');
        str_val = line.last();
        auto delim_pos =  str_val.indexOf(';');
        p_meteo_data->StarBright = str_val.left(delim_pos).toFloat();
     }

     return p_meteo_data;
}

std::shared_ptr<METEO_DATA> FileMeteoIO::loadFile()
{
    QString str = QFileDialog::getOpenFileName(nullptr, "Open Dialog", "", "*.txt");    //#include <QFileDialog>
    if(str.size())
    {
        QFile file_for_reading(str);                    //#include <QFile>
        if(file_for_reading.open(QIODevice::ReadOnly))
        {
            return readFile(file_for_reading);
        }
    }
    return nullptr;
}

void FileMeteoIO::saveFile(METEO_DATA* meteo_data_)
{
    QString str = QFileDialog::getSaveFileName(nullptr, "Save File", QString(), "*.txt");
    qDebug() << str;
    if(str.size())
    {
        QFile file_for_writing(str);
        if(file_for_writing.open(QIODevice::WriteOnly))
        {

        }
    }
}
