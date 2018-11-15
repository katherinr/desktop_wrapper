#include "meteo_form.h"
#include <QApplication>
//#include <meteo_struct.h>
#include "mainwindow.h"
#include <qdebug.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
 //   w.setWindowFlags(Qt::WindowStaysOnTopHint);
    w.show();

    return a.exec();
}
