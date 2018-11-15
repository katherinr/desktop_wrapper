#include "file_meteo_io.h"
#include "meteo_struct.h"
#include <QFileDialog>
#include <qdebug.h>

std::shared_ptr<_MeteoData> FileMeteoIO::readFile(QFile& file_)
{
    //TODO: This shit code
     std::shared_ptr<_MeteoData> p_meteo_data(new _MeteoData());

     QTextStream in(&file_);
     QStringList line;
     QString str_val;
    /* if(!in.atEnd())
     {
        line = in.readLine().split(' ');
        str_val = line.first();
       if(str_val != "_MeteoData.message")
        {
            return nullptr;
        }
        str_val = line.last();
        auto delim_pos =  str_val.indexOf(';');
        p_meteo_data->packet_id = str_val.left(delim_pos).toInt();
     }*/

     if(!in.atEnd())
     {
        line = in.readLine().split(' ');
        str_val = line.last();
        auto delim_pos =  str_val.indexOf(';');
        p_meteo_data->visibility = str_val.left(delim_pos).toFloat();
        qDebug()<<"Visibility file "<< p_meteo_data->visibility;
        qDebug()<<"Visibility file str "<< str_val;
     }

     if(!in.atEnd())
     {
        line = in.readLine().split(' ');
        str_val = line.last();
        auto delim_pos =  str_val.indexOf(';');
        p_meteo_data->cloudBase = str_val.left(delim_pos).toShort();
        qDebug()<<"cloud base file "<< p_meteo_data->cloudBase;
        qDebug()<<"cloud base str val "<< str_val;
     }

     if(!in.atEnd())
     {
        line = in.readLine().split(' ');
        str_val = line.last();
        auto delim_pos =  str_val.indexOf(';');
        p_meteo_data->cloudUpper = str_val.left(delim_pos).toShort();
     }

     if(!in.atEnd())
     {
        line = in.readLine().split(' ');
        str_val = line.last();
        auto delim_pos =  str_val.indexOf(';');
        p_meteo_data->cloudSize = str_val.left(delim_pos).toShort();
        qDebug()<<"cloud size file "<< p_meteo_data->cloudSize;
        qDebug()<<"cloud size str val "<< str_val;
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
        p_meteo_data->cloudsSecondLay = str_val.left(delim_pos).toShort();

     }

     if(!in.atEnd())
     {
        line = in.readLine().split(' ');
        str_val = line.last();
        auto delim_pos =  str_val.indexOf(';');
        p_meteo_data->SecLayHeight = str_val.left(delim_pos).toFloat();
        qDebug()<<"cSecLayHeight file "<< p_meteo_data->SecLayHeight;
        qDebug()<<"SecLayHeight str val "<< str_val;
     }

     if(!in.atEnd())
     {
        line = in.readLine().split(' ');
        str_val = line.last();
        auto delim_pos =  str_val.indexOf(';');
        p_meteo_data->Day = str_val.left(delim_pos).toShort();
        qDebug()<<"Day file "<< p_meteo_data->Day;
        qDebug()<<"Day str val "<< str_val;
     }

     if(!in.atEnd())
     {
        line = in.readLine().split(' ');
        str_val = line.last();
        auto delim_pos =  str_val.indexOf(';');
        p_meteo_data->Month = str_val.left(delim_pos).toShort();
        qDebug()<<"Month file "<< p_meteo_data->Month;
        qDebug()<<"Month str val "<< str_val;
     }

     if(!in.atEnd())
     {
        line = in.readLine().split(' ');
        str_val = line.last();
        auto delim_pos =  str_val.indexOf(';');
        p_meteo_data->Hours = str_val.left(delim_pos).toShort();
        qDebug()<<"Hours file "<< p_meteo_data->Hours;
        qDebug()<<"Hours str val "<< str_val;

     }

     if(!in.atEnd())
     {
        line = in.readLine().split(' ');
        str_val = line.last();
        auto delim_pos =  str_val.indexOf(';');
        p_meteo_data->Minutes = str_val.left(delim_pos).toShort();
        qDebug()<<"Minutes file "<< p_meteo_data->Minutes;
        qDebug()<<"Minutes str val "<< str_val;
     }

     if(!in.atEnd())
     {
        line = in.readLine().split(' ');
        str_val = line.last();
        auto delim_pos =  str_val.indexOf(';');
        p_meteo_data->local_visibility = str_val.left(delim_pos).toFloat();
        qDebug()<<"local_visibility file "<< p_meteo_data->local_visibility;
        qDebug()<<"local_visibility str val "<< str_val;
     }

     if(!in.atEnd())
     {
        line = in.readLine().split(' ');
        str_val = line.last();
        auto delim_pos =  str_val.indexOf(';');
        p_meteo_data->rain = str_val.left(delim_pos).toFloat();
        qDebug()<<"rain file "<< p_meteo_data->rain;
        qDebug()<<"rain str val "<< str_val;
     }

     if(!in.atEnd())
     {
        line = in.readLine().split(' ');
        str_val = line.last();
        auto delim_pos =  str_val.indexOf(';');
        p_meteo_data->snow = str_val.left(delim_pos).toFloat();
        qDebug()<<"snow file "<< p_meteo_data->snow;
        qDebug()<<"snow str val "<< str_val;
     }

     if(!in.atEnd())
     {
        line = in.readLine().split(' ');
        str_val = line.last();
        auto delim_pos =  str_val.indexOf(';');
        p_meteo_data->hmist = str_val.left(delim_pos).toFloat();
        qDebug()<<"hmist file "<< p_meteo_data->hmist;
        qDebug()<<"hmist str val "<< str_val;
     }

     if(!in.atEnd())
     {
        line = in.readLine().split(' ');
        str_val = line.last();
        auto delim_pos =  str_val.indexOf(';');
        p_meteo_data->wind_speed = str_val.left(delim_pos).toFloat();
        qDebug()<<"wind_speed file "<< p_meteo_data->wind_speed;
        qDebug()<<"wind_speed str val "<< str_val;
     }

     if(!in.atEnd())
     {
        line = in.readLine().split(' ');
        str_val = line.last();
        auto delim_pos =  str_val.indexOf(';');
        p_meteo_data->wind_psi = str_val.left(delim_pos).toFloat();
        qDebug()<<"wind_psi file "<< p_meteo_data->wind_psi;
        qDebug()<<"wind_psi str val "<< str_val;
     }

     if(!in.atEnd())
     {
        line = in.readLine().split(' ');
        str_val = line.last();
        auto delim_pos =  str_val.indexOf(';');
        p_meteo_data->starBright = str_val.left(delim_pos).toFloat();
        qDebug()<<"starBright file "<< p_meteo_data->starBright;
        qDebug()<<"starBright str val "<< str_val;
     }

     return p_meteo_data;
}

std::shared_ptr<_MeteoData> FileMeteoIO::loadFile()
{
    QString str = QFileDialog::getOpenFileName(nullptr, "Open Dialog", "", "*.txt");    //#include <QFileDialog>
    if(str.size())
    {
        QFile file_for_reading(str);                    //#include <QFile>
        if(file_for_reading.open(QIODevice::ReadOnly))
        {
            auto res = readFile(file_for_reading);
            file_for_reading.close();
            return res;
        }
    }
    return nullptr;
}

void FileMeteoIO::saveFile(_MeteoData* meteo_data_)
{
    QString str = QFileDialog::getSaveFileName(nullptr, "Save File", QString(), "*.txt");
    qDebug() << str;
    if(str.size())
    {
        QFile file_for_writing(str);
        if(file_for_writing.open(QIODevice::WriteOnly))
        {
            QTextStream stream(&file_for_writing);
            //stream << "_MeteoData.message = " << (int)meteo_data_->packet_id << ";\n";
            stream << "Visibility = " << meteo_data_->visibility << ";\n";
            stream << "CloudBase = " << meteo_data_->cloudBase << ";\n";
            stream << "CloudUpper = " << meteo_data_->cloudUpper << ";\n";
            stream << "CloudSize = " << meteo_data_->cloudSize << ";\n";
            stream << "cloudsType = " << (int)meteo_data_->cloudsType << ";\n";
            stream << "cloudsSecondLay = " <<(int) meteo_data_->cloudsSecondLay << ";\n";
            stream << "SecLayHeight = " << meteo_data_->SecLayHeight << ";\n";
            stream << "Day = " << meteo_data_->Day << ";\n";
            stream << "Month = " << meteo_data_->Month << ";\n";
            stream << "Hours = " << meteo_data_->Hours << ";\n";
            stream << "Minutes = " << meteo_data_->Minutes << ";\n";
            stream << "local_visibility = " << meteo_data_->local_visibility << ";\n";
            stream << "rain = " << meteo_data_->rain << ";\n";
            stream << "snow = " << meteo_data_->snow << ";\n";
            stream << "hmist = " << meteo_data_->hmist << ";\n";
            stream << "wind_speed = " << meteo_data_->wind_speed << ";\n";
            stream << "wind_psi  = " << meteo_data_->wind_psi  << ";\n";
            stream << "StarBright = " << meteo_data_->starBright << ";\n";
            file_for_writing.close();
        }
    }
}
