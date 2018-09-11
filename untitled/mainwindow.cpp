#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QValidator>
#include <qdebug.h>

meteoWindow::meteoWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::meteoWindow)
{
    ui->setupUi(this);
    connect(ui->cloudBase_inp, SIGNAL(clicked()), this, SLOT(on_cloudBase_inp_editingFinished()));
}

meteoWindow::~meteoWindow()
{
    delete ui;
}

void meteoWindow::on_cloudBase_inp_editingFinished()
{
    data->CloudBase = ui->cloudBase_inp->text().toShort();
    qDebug()<<"data->CloudBase" <<data->CloudBase<<"\n";
}

void meteoWindow::on_cloudUpper_inp_editingFinished()
{
     data->CloudUpper = ui->cloudUpper_inp->text().toShort();
     qDebug()<<"data->CloudUpper" <<data->CloudUpper<<"\n";
}

void meteoWindow::on_localVis_inp_editingFinished()
{
    data->local_visibility = ui->localVis_inp->text().toFloat();
    qDebug()<<"data->local_visibility" <<data->local_visibility<<"\n";
}

void meteoWindow::on_rain_inp_editingFinished()
{
    data->rain = ui->rain_inp->text().toFloat();
    qDebug()<<"data->rain" <<data->rain<<"\n";
}

void meteoWindow::on_snow_inp_editingFinished()
{
    data->snow = ui->snow_inp->text().toFloat();
    qDebug()<<"data->snow" <<data->snow<<"\n";
}

void meteoWindow::on_hmist_inp_editingFinished()
{
    data->hmist = ui->hmist_inp->text().toFloat();
    qDebug()<<"data->hmist" <<data->hmist<<"\n";
}

void meteoWindow::on_windSpeed_inp_editingFinished()
{
    data->wind_speed = ui->windSpeed_inp->text().toFloat();
    qDebug()<<"data->wind_speed" <<data->wind_speed<<"\n";
}

void meteoWindow::on_windSpeedPsi_inp_editingFinished()
{
     data->wind_psi = ui->windSpeedPsi_inp->text().toFloat();
     qDebug()<<"data->wind_psi" <<data->wind_psi<<"\n";
}

void meteoWindow::on_visibility_inp_editingFinished()
{
    data->Visibility = ui->visibility_inp->text().toFloat();
    qDebug()<<"data->Visibility" <<data->Visibility<<"\n";
}

void meteoWindow::on_starsBright_inp_editingFinished()
{
    data->StarBright = ui->starsBright_inp->text().toFloat();
    qDebug()<<"data->StarBright" <<data->StarBright<<"\n";
}
