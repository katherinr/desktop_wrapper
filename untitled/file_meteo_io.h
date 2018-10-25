#ifndef FILE_METEO_IO_H
#define FILE_METEO_IO_H

//#include "sfun_gss2kd_2017_visual_send_v22.h"

#include <memory>

#include <QFile>

struct _MeteoData;
class FileMeteoIO
{
    std::shared_ptr<_MeteoData> readFile(QFile& file_);
public:
    std::shared_ptr<_MeteoData> loadFile();                 //read meteo from file
    void saveFile(_MeteoData* meteo_data_); //write meteo to file
};

#endif // FILEIO_H
