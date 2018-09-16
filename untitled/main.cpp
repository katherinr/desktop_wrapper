#include "mainwindow.h"
#include <QApplication>
#include <meteo_struct.h>
#include <qdebug.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    meteoWindow w;
    w.setWindowFlags(Qt::WindowStaysOnTopHint);
    w.show();
   // w.activateWindow();

    qDebug()<<"wshow";
    return a.exec();
}
