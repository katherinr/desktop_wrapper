#include "mainwindow.h"
#include <QApplication>
#include <meteo_struct.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    meteoWindow w;
    w.show();
    return a.exec();
}
