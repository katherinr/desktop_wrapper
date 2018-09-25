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
        qDebug()<<"Visibility file "<< p_meteo_data->Visibility;
        qDebug()<<"Visibility file str "<< str_val;
     }

     if(!in.atEnd())
     {
        line = in.readLine().split(' ');
        str_val = line.last();
        auto delim_pos =  str_val.indexOf(';');
        p_meteo_data->CloudBase = str_val.left(delim_pos).toShort();
        qDebug()<<"cloud base file "<< p_meteo_data->CloudBase;
        qDebug()<<"cloud base str val "<< str_val;
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
        qDebug()<<"cloud size file "<< p_meteo_data->CloudSize;
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
            auto res = readFile(file_for_reading);
            file_for_reading.close();
            return res;
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
            QTextStream stream(&file_for_writing);
            stream << "METEO_DATA.message = " << (int)meteo_data_->message << ";\n";
            stream << "METEO_DATA.Visibility = " << meteo_data_->Visibility << ";\n";
            stream << "METEO_DATA.CloudBase = " << meteo_data_->CloudBase << ";\n";
            stream << "METEO_DATA.CloudUpper = " << meteo_data_->CloudUpper << ";\n";
            stream << "METEO_DATA.CloudSize = " << meteo_data_->CloudSize << ";\n";
            stream << "METEO_DATA.cloudsType = " << (int)meteo_data_->cloudsType << ";\n";
            stream << "METEO_DATA.cloudsSecondLay = " <<(int) meteo_data_->cloudsSecondLay << ";\n";
            stream << "METEO_DATA.SecLayHeight = " << meteo_data_->SecLayHeight << ";\n";
            stream << "METEO_DATA.Day = " << meteo_data_->Day << ";\n";
            stream << "METEO_DATA.Month = " << meteo_data_->Month << ";\n";
            stream << "METEO_DATA.Hours = " << meteo_data_->Hours << ";\n";
            stream << "METEO_DATA.Minutes = " << meteo_data_->Minutes << ";\n";
            stream << "METEO_DATA.local_visibility = " << meteo_data_->local_visibility << ";\n";
            stream << "METEO_DATA.rain = " << meteo_data_->rain << ";\n";
            stream << "METEO_DATA.snow = " << meteo_data_->snow << ";\n";
            stream << "METEO_DATA.hmist = " << meteo_data_->hmist << ";\n";
            stream << "METEO_DATA.wind_speed = " << meteo_data_->wind_speed << ";\n";
            stream << "METEO_DATA.wind_psi  = " << meteo_data_->wind_psi  << ";\n";
            stream << "METEO_DATA.StarBright = " << meteo_data_->StarBright << ";\n";
            file_for_writing.close();
        }
    }
}
