#ifndef FILE_METEO_IO_H
#define FILE_METEO_IO_H

#include "meteo_struct.h"

#include <memory>

#include <QFile>

class FileMeteoIO
{
    std::shared_ptr<METEO_DATA> readFile(QFile& file_);
public:
    std::shared_ptr<METEO_DATA> loadFile();                 //read meteo from file
    void saveFile(METEO_DATA* meteo_data_); //write meteo to file
};

#endif // FILEIO_H
