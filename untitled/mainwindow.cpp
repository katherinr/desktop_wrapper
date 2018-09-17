﻿#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QValidator>
#include <qdebug.h>
#include <QDate>

meteoWindow::meteoWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::meteoWindow),
    data(new METEO_DATA)
{
    ui->setupUi(this);
    setLimitsToScrolls();
    setLimitsToLines();
    qDebug()<<"constructor";
}

void meteoWindow::setLimitsToScrolls()
{
    //cloud height
    ui->cloudHeightScroll->setMinimum(0);
    ui->cloudHeightScroll->setMaximum(3000);
    ui->cloudHeightScroll->setSingleStep(10);
    ui->cloudHeightScroll->setPageStep(10);
    //cloud thickness
    ui->cloudThickScroll->setMinimum(0);
    ui->cloudThickScroll->setMaximum(2000);
    ui->cloudThickScroll->setSingleStep(10);
    ui->cloudThickScroll->setPageStep(10);
    //second layer height
    ui->cloudSecLvlScroll->setMinimum(0);
    ui->cloudSecLvlScroll->setMaximum(15000);
    ui->cloudSecLvlScroll->setSingleStep(100);
    ui->cloudSecLvlScroll->setPageStep(100);
    //precipation
    //local visibility in rain
    ui->localVisScroll->setMinimum(0);
    ui->localVisScroll->setMaximum(500);
    ui->localVisScroll->setSingleStep(10);
    ui->localVisScroll->setPageStep(10);
    //rain density
    ui->rainScroll->setMinimum(0);
    ui->rainScroll->setMaximum(100);
    ui->rainScroll->setSingleStep(1);
    ui->rainScroll->setPageStep(10);
    //snow density
    ui->snowScroll->setMinimum(0);
    ui->snowScroll->setMaximum(100);
    ui->snowScroll->setSingleStep(1);
    ui->snowScroll->setPageStep(10);
    //mist density
    ui->mistScroll->setMinimum(0);
    ui->mistScroll->setMaximum(1000);
    ui->mistScroll->setSingleStep(50);
    ui->mistScroll->setPageStep(50);
    //wind
    //speed
    ui->windSpeedScroll->setMinimum(0);
    ui->windSpeedScroll->setMaximum(50);
    ui->windSpeedScroll->setSingleStep(1);
    ui->windSpeedScroll->setPageStep(1);
    //psi
    ui->windPsiScroll->setMinimum(0);
    ui->windPsiScroll->setMaximum(360);
    ui->windPsiScroll->setSingleStep(1);
    ui->windPsiScroll->setPageStep(1);
    //stars
    //brightness
    ui->starsBrightScroll->setMinimum(0);
    ui->starsBrightScroll->setMaximum(100);
    ui->starsBrightScroll->setSingleStep(1);
    ui->starsBrightScroll->setPageStep(1);
    //global visibility
    ui->visScroll->setMinimum(0);
    ui->visScroll->setMaximum(200000);
    ui->visScroll->setSingleStep(1000);
    ui->visScroll->setPageStep(10);
}

void meteoWindow::setLimitsToLines()
{
    // interval validators from meteo_struct
    //clouds
    ui->cloudBase_inp->setValidator(new QIntValidator(0, 3000));
    ui->cloudSecLayer_inp->setValidator(new QIntValidator(0, 15000));
    ui->cloudSize_inp->setValidator(new QIntValidator(0, 10));
    ui->cloudThick_inp->setValidator(new QIntValidator(0, 2000));
    //wind
    ui->windSpeedPsi_inp->setValidator(new QIntValidator(0, 360));
    ui->windSpeed_inp->setValidator(new QIntValidator(0, 50));
    //precipation
    ui->snow_inp->setValidator(new QIntValidator(0, 100));
    ui->rain_inp->setValidator(new QIntValidator(0, 100));
    ui->localVis_inp->setValidator(new QIntValidator(0, 500));
    ui->hmist_inp->setValidator(new QIntValidator(0, 1000));
    //stars
    ui->starsBright_inp->setValidator(new QIntValidator(0, 100));
    ui->visibility_inp->setValidator(new QIntValidator(0, 200000));
}

meteoWindow::~meteoWindow()
{
    delete ui;
    qDebug()<<"destructor";
}

/*----------------------------------------------------*/
/*----time----*/
void meteoWindow::on_month_cmbB_editTextChanged(const QString &arg1)
{
    data->Month = ui->month_cmbB->currentText().toShort();
    qDebug()<<"data->Month" <<data->Month<<"\n";
}

void meteoWindow::on_mDayPushB_pressed()
{
    ui->mNightPushB->setChecked(false);
    ui->time_spnB->setTimeRange(QTime(7,0,0,0),QTime(23,59,0,0));
    ui->time_spnB->update();
}

void meteoWindow::on_mNightPushB_pressed()
{
    ui->mDayPushB->setChecked(false);
    ui->time_spnB->setTimeRange(QTime(0,0,0,0),QTime(6,59,0,0));
    ui->time_spnB->update();
}

void meteoWindow::on_time_spnB_timeChanged(const QTime &time)
{
    data->Hours = short(time.hour());
    data->Minutes = short(time.minute());
    qDebug()<<"data->Hours " << data->Hours<<"ddata->Minutes " << data->Minutes<<"\n";
}

void meteoWindow::on_mWinterPushB_pressed()
{
    ui->month_cmbB->setAutoCompletion(11);
    ui->mAutumnPushB->setChecked(false);
    ui->mSpringPushB->setChecked(false);
    ui->mSummerPushB->setChecked(false);
    data->Month = 1+short(ui->month_cmbB->currentIndex());
    qDebug()<<"data->month_cmbB"<<data->Month;
}

/*void meteoWindow::on_mWinterPushB_clicked(bool checked)
{
  ui->mWinterPushB->setChecked(true);
  ui->mAutumnPushB->setChecked(false);
  ui->mSpringPushB->setChecked(false);
  ui->mSummerPushB->setChecked(false);
  ui->month_cmbB->setCurrentIndex(11);
}*/

void meteoWindow::on_month_cmbB_currentIndexChanged(int index)
{
    if(ui->mSummerPushB->isDown() )
        if (index<5 ||
                index>8)
        {
            return;
        }
    if(ui->mSpringPushB->isDown() )
        if (ui->month_cmbB->currentIndex()<2 ||
                ui->month_cmbB->currentIndex()>4)
            return;
    if(ui->mWinterPushB->isDown() )
        if (ui->month_cmbB->currentIndex()!=11 ||
                ui->month_cmbB->currentIndex()!=1 ||  ui->month_cmbB->currentIndex()!=0 )
            return;

    data->Month =  ui->month_cmbB->currentIndex();
    qDebug()<<"data->Month " << data->Month;
}

/*void meteoWindow::on_mSpringPushB_clicked()
{
    ui->mSpringPushB->setChecked(true);
    ui->day_spnb->setMinimum(1);
    ui->day_spnb->setMaximum(31);
    ui->day_spnb->update();

    ui->mAutumnPushB->setChecked(false);
    ui->mWinterPushB->setChecked(false);
    ui->mSummerPushB->setChecked(false);

    ui->month_cmbB->setCurrentIndex(2);
    qDebug()<<"data->Month " << data->Month;
}*/

void meteoWindow::on_mSummerPushB_clicked()
{
    ui->mSummerPushB->setChecked(true);
    ui->mAutumnPushB->setChecked(false);
    ui->mSpringPushB->setChecked(false);
    ui->mWinterPushB->setChecked(false);
    ui->month_cmbB->setCurrentIndex(5);
    qDebug()<<"data->Month " << data->Month;
}

void meteoWindow::on_mAutumnPushB_clicked()
{
    ui->mAutumnPushB->setChecked(true);
    ui->mSummerPushB->setChecked(false);
    ui->mSpringPushB->setChecked(false);
    ui->mWinterPushB->setChecked(false);
    ui->month_cmbB->setCurrentIndex(8);
    qDebug()<<"data->Month " << data->Month;
}

void meteoWindow::on_mSpringPushB_pressed()
{
    ui->mSpringPushB->setChecked(true);
    ui->day_spnb->setMinimum(1);
    ui->day_spnb->setMaximum(31);
    ui->day_spnb->update();

    ui->mAutumnPushB->setChecked(false);
    ui->mWinterPushB->setChecked(false);
    ui->mSummerPushB->setChecked(false);

    ui->month_cmbB->setCurrentIndex(2);
}

void meteoWindow::on_cloudSize_spnB_valueChanged(int arg1)
{
    data->CloudSize = ui->cloudSize_inp->text().toShort();
    qDebug()<<"data->CloudSize" <<data->CloudSize<<"\n";
}

void meteoWindow::on_mSpringPushB_clicked(bool checked)
{

}
/*----------------------------------------------------*/
/*----cloudness----*/



void meteoWindow::on_cloudThick_inp_editingFinished()
{
    short thick=ui->cloudThick_inp->text().toShort();
    data->CloudUpper = thick;
    ui->cloudThickScroll->setValue(thick);
    qDebug()<<"data->CloudUpper" <<data->CloudUpper<<"\n";
}

void meteoWindow::on_cloudHeightScroll_valueChanged(int value)
{
    qDebug()<<"cloud height" <<value;
    qDebug()<<"cloud height val" <<ui->cloudHeightScroll->value();
    short height=ui->cloudHeightScroll->value();
    ui->cloudBase_inp->setText(QString::number(height));
    data->CloudBase = height;
}

void meteoWindow::on_cloudHeightScroll_sliderPressed()
{
    data->CloudSize= ui->cloudHeightScroll->value();
}

void meteoWindow::on_cloudThickScroll_valueChanged(int value)
{
    qDebug()<<"cloud thick" <<value;
    qDebug()<<"cloud thick val" <<ui->cloudHeightScroll->value();
    short thick=ui->cloudThickScroll->value();
    ui->cloudThick_inp->setText(QString::number(thick));
    data->CloudSize = thick;
}

void meteoWindow::on_cloudBase_inp_editingFinished()
{
    short val = ui->cloudBase_inp->text().toShort();
    data->CloudBase = val;
    ui->cloudHeightScroll->setValue(val);
    qDebug()<<"data->CloudBase" <<data->CloudBase<<"\n";
    qDebug()<<"----cloud height val" <<ui->cloudHeightScroll->value();
}

void meteoWindow::on_cloudUpper_inp_editingFinished()
{
    data->CloudUpper = ui->cloudThick_inp->text().toShort();
    qDebug()<<"data->CloudUpper" <<data->CloudUpper<<"\n";
}
//scrolls
void meteoWindow::on_cloudSecLayer_inp_editingFinished()
{
    float val = ui->cloudSecLayer_inp->text().toFloat();
    data->cloudsSecondLay = val;
    ui->cloudSecLvlScroll->setValue(val);
    qDebug()<<"data->cloudsSecondLay" <<data->cloudsSecondLay<<"\n";
}

void meteoWindow::on_cloudsSecLay_cmbB_currentIndexChanged(int index)
{
    qDebug()<<"isSecondLayerClouds"<<index;
    char isSecLay = char(index);
    data->cloudsSecondLay = isSecLay;
    ui->cloudSecLayer_inp->setEnabled(bool(index));
    ui->cloudSecLvlScroll->setEnabled(bool(index));
}

void meteoWindow::on_cloudSecLvlScroll_valueChanged(int value)
{
    int val = ui->cloudSecLvlScroll->value();
    data->cloudsSecondLay = char(val);
    ui->cloudSecLayer_inp->setText(QString::number(val));
    qDebug()<<"data->cloudsSecondLay" <<data->cloudsSecondLay<<"\n";
}

void meteoWindow::on_cloudsType_cmbB_currentIndexChanged(int index)
{
    data->cloudsType = char(index);
    qDebug()<<"cloudsType"<<data->cloudsType;
}
/*----------------------------------------------------*/
/*----rains----*/
void meteoWindow::on_localVis_inp_editingFinished()
{
    float local_visibility =  ui->localVis_inp->text().toFloat();
    data->local_visibility = local_visibility;
    ui->localVisScroll->setValue(int(local_visibility));
    qDebug()<<"data->local_visibility" <<data->local_visibility<<"\n";
}

void meteoWindow::on_localVisScroll_valueChanged(int value)
{
    float loc_vis=ui->localVisScroll->value();
    ui->localVis_inp->setText(QString::number(loc_vis));
    data->local_visibility = loc_vis;
}

void meteoWindow::on_rain_inp_editingFinished()
{
    float rain = ui->rain_inp->text().toFloat();
    data->rain = rain;
    ui->rainScroll->setValue(int(rain));
    qDebug()<<"data->rain" <<data->rain<<"\n";
}

void meteoWindow::on_rainScroll_valueChanged(int value)
{
    float rain=ui->rainScroll->value();
    ui->rain_inp->setText(QString::number(rain));
    data->rain = rain;
}

void meteoWindow::on_snow_inp_editingFinished()
{
    float snow =ui->snow_inp->text().toFloat();
    data->snow = snow;
    ui->snowScroll->setValue(int(snow));
    qDebug()<<"data->snow" <<data->snow<<"\n";
}

void meteoWindow::on_snowScroll_valueChanged(int value)
{
    float snow=ui->snowScroll->value();
    ui->snow_inp->setText(QString::number(snow));
    data->snow = snow;
}

void meteoWindow::on_hmist_inp_editingFinished()
{
    float hmist = ui->hmist_inp->text().toFloat();
    data->hmist = hmist;
    ui->mistScroll->setValue(int(hmist));
    qDebug()<<"data->hmist" <<data->hmist<<"\n";
}

void meteoWindow::on_mistScroll_valueChanged(int value)
{
    float mist=ui->mistScroll->value();
    ui->hmist_inp->setText(QString::number(mist));
    data->hmist = mist;
}
/*----------------------------------------------------*/
/*----Winds----*/
void meteoWindow::on_windSpeed_inp_editingFinished()
{
    float windSpeed=ui->windSpeed_inp->text().toFloat();
    data->wind_speed = windSpeed;
    ui->windSpeedScroll->setValue(int(windSpeed));
    qDebug()<<"data->wind_speed" <<data->wind_speed<<"\n";
}
void meteoWindow::on_windSpeedScroll_valueChanged(int value)
{
    qDebug()<<"windSpeed val" <<ui->windSpeedScroll->value();
    float windSpeed=ui->windSpeedScroll->value();
    ui->windSpeed_inp->setText(QString::number(windSpeed));
    data->wind_speed = windSpeed;
}

void meteoWindow::on_windSpeedPsi_inp_editingFinished()
{
    float windPsi=ui->windSpeedPsi_inp->text().toFloat();
    data->wind_psi = windPsi;
    ui->windPsiScroll->setValue(int(windPsi));
    qDebug()<<"data->wind_psi" <<data->wind_psi<<"\n";
}
void meteoWindow::on_windPsiScroll_valueChanged(int value)
{
    float windPsi=ui->windPsiScroll->value();
    ui->windSpeedPsi_inp->setText(QString::number(int(windPsi)));
    data->wind_psi = windPsi;
}

/*----------------------------------------------------*/
/*----stars----*/
void meteoWindow::on_visibility_inp_editingFinished()
{
    float visibility = ui->visibility_inp->text().toFloat();
    data->Visibility = visibility;
    ui->visScroll->setValue(int(visibility));
    qDebug()<<"data->Visibility" <<data->Visibility<<"\n";
}

void meteoWindow::on_visScroll_valueChanged(int value)
{
    qDebug()<<"visibility" <<ui->visScroll->value();
    float visibility=ui->visScroll->value();
    ui->visibility_inp->setText(QString::number(visibility));
    data->Visibility = visibility;
}

void meteoWindow::on_starsBright_inp_editingFinished()
{
    qDebug()<<"sr";
    qDebug()<<"srtext"<<ui->starsBright_inp->text();
    data->StarBright = ui->starsBright_inp->text().toFloat();
    ui->starsBrightScroll->setValue(int(data->StarBright));
    qDebug()<<"data->StarBright" <<data->StarBright<<"\n";
}

void meteoWindow::on_starsBrightScroll_valueChanged(int value)
{
    float starsBr=ui->starsBrightScroll->value();
    ui->starsBright_inp->setText(QString::number(starsBr));
    data->StarBright = starsBr;
}
