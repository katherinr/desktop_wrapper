#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QValidator>
#include <qdebug.h>
#include <QDate>
#include <file_meteo_io.h>
meteoWindow::meteoWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::meteoWindow),
    data(new METEO_DATA)
{
    ui->setupUi(this);
    data->message = 11;
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
    ui->cloudThickScroll->setSingleStep(100);
    ui->cloudThickScroll->setPageStep(100);
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
    //time
   // ui->day_spnB->setf
    //ui->time_spnB_2->setMinimum(1);
    //ui->day_spnB->setMaximum(31);
    //ui->day_spnb->setSingleStep(1);
    //ui->day_spnb->setRange(1,31);
}

meteoWindow::~meteoWindow()
{
    delete ui;
    qDebug()<<"destructor";
}

/*----------------------------------------------------*/
/*----time----*/

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
    ui->month_cmbB->setValidator(new QIntValidator(0,2));
    ui->mAutumnPushB->setChecked(false);
    ui->mSpringPushB->setChecked(false);
    ui->mSummerPushB->setChecked(false);
    if (ui->month_cmbB->currentIndex() == 0)
    {
          data->Month = 12;
    }
    else
    {
        data->Month = short(ui->month_cmbB->currentIndex());
    }
     ui->month_cmbB->update();
    qDebug()<<"data->month_cmbB"<<data->Month;
}

void meteoWindow::on_mAutumnPushB_pressed()
{
     ui->month_cmbB->setValidator(new QIntValidator(9,11));
     ui->mWinterPushB->setChecked(false);
     ui->mSpringPushB->setChecked(false);
     ui->mSummerPushB->setChecked(false);
     data->Month = short(ui->month_cmbB->currentIndex());
     ui->month_cmbB->update();
     qDebug()<<"data->month_cmbB"<<data->Month;
}

void meteoWindow::on_month_cmbB_currentIndexChanged(int index)
{
   qDebug()<<"sIndex(5) " << index;
    if(ui->mSummerPushB->isChecked() )
        if (index<6 ||
                index>8)
        {
            ui->month_cmbB->setCurrentIndex(6);

        }
    if(ui->mSpringPushB->isChecked() )
    {
        if (ui->month_cmbB->currentIndex()<3 ||
                ui->month_cmbB->currentIndex()>5)
         {
            ui->month_cmbB->setCurrentIndex(3);
             qDebug()<<"setCurrentIndex(2) " << data->Month;
         }
    }
    if(ui->mWinterPushB->isChecked() )
    {
        if (index>2 )
           {
            qDebug()<<"sindex)11) " << index;
            ui->month_cmbB->setCurrentIndex(0);
            //qDebug()<<"setCurrentIndex((2)11) " << data->Month;
           }
    }
    if(ui->mAutumnPushB->isChecked() )
    {
        if (index<9 ||
                index>11)
        {
            ui->month_cmbB->setCurrentIndex(9);
            qDebug()<<"setCurrentIndex(9) " << data->Month;
        }
    }
    ui->month_cmbB->update();
    if (index==0)
        data->Month = 12;
    else
        data->Month = ui->month_cmbB->currentIndex();
    qDebug()<<"data->Month " <<  ui->month_cmbB->currentIndex();
}

void meteoWindow::on_mSummerPushB_pressed()
{
    ui->month_cmbB->setValidator(new QIntValidator(6,8));
    ui->mAutumnPushB->setChecked(false);
    ui->mSpringPushB->setChecked(false);
    ui->mWinterPushB->setChecked(false);
    data->Month = short(ui->month_cmbB->currentIndex());
    ui->month_cmbB->update();
    qDebug()<<"data->Month " << data->Month;
}

void meteoWindow::on_mSpringPushB_pressed()
{
    ui->month_cmbB->setValidator(new QIntValidator(3,5));
    ui->mAutumnPushB->setChecked(false);
    ui->mWinterPushB->setChecked(false);
    ui->mSummerPushB->setChecked(false);
    data->Month = short(ui->month_cmbB->currentIndex());
    ui->month_cmbB->update();
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

void meteoWindow::on_cloudThickScroll_valueChanged(int value)
{
    qDebug()<<"cloud thick" <<value;
   // qDebug()<<"cloud thick val" <<ui->cloudHeightScroll->value();
    //short thick=ui->cloudThickScroll->value();
    ui->cloudThick_inp->setText(QString::number(value));
    data->CloudUpper = value;
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
    data->cloudsSecondLay = ui->cloudSecLayer_inp->text().toFloat();
    ui->cloudSecLvlScroll->setValue(data->SecLayHeight);
    qDebug()<<"data->cloudsSecondLay inp line edit" <<data->SecLayHeight<<"\n";
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
    float val = ui->cloudSecLvlScroll->value();
    data->SecLayHeight = val;
    ui->cloudSecLayer_inp->setText(QString::number(value));
    qDebug()<<"data->cloudsSecondLay scroll" <<data->SecLayHeight<<"\n";
}

void meteoWindow::on_cloudsType_cmbB_currentIndexChanged(int index)
{
    data->cloudsType = char(index);
    qDebug()<<"cloudsType"<<data->cloudsType;
}

void meteoWindow::on_cloudSize_inp_editingFinished()
{
    data->CloudSize = ui->cloudSize_inp->text().toShort();
    qDebug()<<"data->CloudSize" <<data->CloudSize<<"\n";
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

void meteoWindow::on_action_4_triggered()
{
    QApplication::quit();
}

void meteoWindow::on_action_triggered()
{
    //read meteo from file
    auto meteo_data = file_io.loadFile();
    if(!meteo_data)
        return;
    writeToFields(meteo_data);

    qDebug() << meteo_data->message;
    qDebug() << meteo_data->Visibility;
    qDebug() << meteo_data->CloudBase;
    qDebug() << meteo_data->CloudUpper;
    qDebug() << meteo_data->CloudSize;
    qDebug() << meteo_data->cloudsType;
    qDebug() << meteo_data->cloudsSecondLay;
    qDebug() << meteo_data->SecLayHeight;
    qDebug() << meteo_data->Day;
    qDebug() << meteo_data->Month;
    qDebug() << meteo_data->Hours;
    qDebug() << meteo_data->Minutes;
    qDebug() << meteo_data->local_visibility;
    qDebug() << meteo_data->rain;
    qDebug() << meteo_data->snow;
    qDebug() << meteo_data->hmist;
    qDebug() << meteo_data->wind_speed;
    qDebug() << meteo_data->wind_psi;
    qDebug() << meteo_data->StarBright;
}


void meteoWindow::on_action_2_triggered()
{
    //save meteo to file
    file_io.saveFile(data);
}

void meteoWindow::writeToFields(std::shared_ptr<METEO_DATA> meteo_data )
{
    data->message = 11;//meteo_data->message;
    data->CloudBase = meteo_data->CloudBase;
    data->CloudSize = meteo_data->CloudSize;
    data->CloudUpper = meteo_data->CloudUpper;
    data->Day = meteo_data->Day;
    data->Hours = meteo_data->Hours;
    data->Minutes = meteo_data->Minutes;
    data->Month = meteo_data->Month;
    data->SecLayHeight = meteo_data->SecLayHeight;
    data->StarBright = meteo_data->StarBright;
    data->Visibility = meteo_data->Visibility;
    data->cloudsSecondLay = meteo_data->cloudsSecondLay;
    data->cloudsType = meteo_data->cloudsType;
    data->hmist = meteo_data->hmist;
    data->local_visibility = meteo_data->local_visibility;
    data->rain = meteo_data->rain;
    data->snow = meteo_data->snow;
    data->wind_psi = meteo_data->wind_psi;
    data->wind_speed = meteo_data->wind_speed;

    ui->visibility_inp->setText(QString::number(data->Visibility));
    ui->cloudBase_inp->setText(QString::number(data->CloudBase));
    ui->cloudThick_inp->setText(QString::number(data->CloudUpper));
    ui->cloudSize_inp->setText(QString::number(data->CloudSize));
    ui->cloudsType_cmbB->setCurrentIndex(data->cloudsType);
    ui->cloudsSecLay_cmbB->setCurrentIndex( data->cloudsSecondLay);
    ui->cloudSecLayer_inp->setText(QString::number(data->SecLayHeight));

    if (meteo_data->Month == 12)
        ui->month_cmbB->setCurrentIndex(0);
    else
        ui->month_cmbB->setCurrentIndex(meteo_data->Month);
    ui->day_spnB->setValue( data->Day);
    ui->time_spnB->setDateTime(QDateTime(QDate(2018, data->Month, data->Day),QTime(data->Hours,data->Minutes)));

    ui->localVis_inp->setText(QString::number(data->local_visibility));
    ui->rain_inp->setText(QString::number(data->rain));
    ui->snow_inp->setText(QString::number(data->snow));
    ui->hmist_inp->setText(QString::number(data->hmist));
    ui->windSpeed_inp->setText(QString::number(data->wind_speed));
    ui->windSpeedPsi_inp->setText(QString::number( data->wind_psi));
    ui->starsBright_inp->setText(QString::number(data->StarBright));

    lineDataToScrollValue();
}

void meteoWindow::on_day_spnB_valueChanged(int arg1)
{
    data->Day = ui->day_spnB->value();
    qDebug()<<"data->Day" <<data->Day<<"\n";
}

void meteoWindow::lineDataToScrollValue()
  {
    //another shitty code
    ui->cloudHeightScroll->setValue(data->CloudBase);
    ui->cloudSecLvlScroll->setValue(data->cloudsSecondLay);
    ui->cloudThickScroll->setValue(data->CloudUpper);
    ui->localVisScroll->setValue(data->local_visibility);
    ui->mistScroll->setValue(data->hmist);
    ui->windSpeedScroll->setValue(data->wind_speed);
    ui->windPsiScroll->setValue(data->wind_psi);
    ui->snowScroll->setValue(data->snow);
    ui->rainScroll->setValue(data->rain);
    ui->starsBrightScroll->setValue(data->StarBright);
}




