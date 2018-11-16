#include "meteo_form.h"
#include "ui_meteoform.h"
#include <QValidator>
#include <qdebug.h>
#include <QDate>
#include "file_meteo_io.h"
#include <memory>
#include <QtScript/qscriptclass.h>
#include "meteo_struct.h"
#include "utilities.h"
meteoWindow::meteoWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::meteoWindow),
    data(new _MeteoData)
{

    //qDebug() << data;


   
    ui->setupUi(this);
    data->packet_id = NPR_PACKET_TYPE_METEO_DATA;
    //setDataFromDefaultMeteo();
    setWindowModality(Qt::ApplicationModal);
    setLimitsToScrolls();
    setLimitsToLines();
}

void meteoWindow::setLimitsToScrolls()
{
    //cloud height
    ui->cloudHeightScroll_->setMinimum(0);
    ui->cloudHeightScroll_->setMaximum(3000);
    ui->cloudHeightScroll_->setSingleStep(10);
    ui->cloudHeightScroll_->setPageStep(10);
    //cloud thickness
    ui->cloudThickScroll_->setMinimum(0);
    ui->cloudThickScroll_->setMaximum(2000);
    ui->cloudThickScroll_->setSingleStep(100);
    ui->cloudThickScroll_->setPageStep(100);
    //second layer height
    ui->cloudSecLvlScroll_->setMinimum(0);
    ui->cloudSecLvlScroll_->setMaximum(15000);
    ui->cloudSecLvlScroll_->setSingleStep(100);
    ui->cloudSecLvlScroll_->setPageStep(100);
    //precipation
    //local visibility in rain
    ui->localVisScroll_->setMinimum(0);
    ui->localVisScroll_->setMaximum(500);
    ui->localVisScroll_->setSingleStep(10);
    ui->localVisScroll_->setPageStep(10);
    //rain density
    ui->rainScroll_->setMinimum(0);
    ui->rainScroll_->setMaximum(100);
    ui->rainScroll_->setSingleStep(1);
    ui->rainScroll_->setPageStep(10);
    //snow density
    ui->snowScroll_->setMinimum(0);
    ui->snowScroll_->setMaximum(100);
    ui->snowScroll_->setSingleStep(1);
    ui->snowScroll_->setPageStep(10);
    //mist density
    ui->mistScroll_->setMinimum(0);
    ui->mistScroll_->setMaximum(1000);
    ui->mistScroll_->setSingleStep(50);
    ui->mistScroll_->setPageStep(50);
    //wind
    //speed
    ui->windSpeedScroll_->setMinimum(0);
    ui->windSpeedScroll_->setMaximum(50);
    ui->windSpeedScroll_->setSingleStep(1);
    ui->windSpeedScroll_->setPageStep(1);
    //psi
    ui->windPsiScroll_->setMinimum(0);
    ui->windPsiScroll_->setMaximum(360);
    ui->windPsiScroll_->setSingleStep(1);
    ui->windPsiScroll_->setPageStep(1);
    //stars
    //brightness
    ui->starsBrightScroll_->setMinimum(0);
    ui->starsBrightScroll_->setMaximum(100);
    ui->starsBrightScroll_->setSingleStep(1);
    ui->starsBrightScroll_->setPageStep(1);
    //global visibility
    ui->visScroll_->setMinimum(0);
    ui->visScroll_->setMaximum(200000);
    ui->visScroll_->setSingleStep(1000);
    ui->visScroll_->setPageStep(10);
}

void meteoWindow::setLimitsToLines()
{
    // interval validators from meteo_struct
    //clouds
    ui->cloudBase_inp_->setValidator(new QIntValidator(0, 3000));
    ui->cloudSecLayer_inp_->setValidator(new QIntValidator(0, 15000));
    ui->cloudSize_inp_->setValidator(new QIntValidator(0, 10));
    ui->cloudThick_inp_->setValidator(new QIntValidator(0, 2000));
    //wind
    ui->windSpeedPsi_inp_->setValidator(new QIntValidator(0, 360));
    ui->windSpeed_inp_->setValidator(new QIntValidator(0, 50));
    //precipation
    ui->snow_inp_->setValidator(new QIntValidator(0, 100));
    ui->rain_inp_->setValidator(new QIntValidator(0, 100));
    ui->localVis_inp_->setValidator(new QIntValidator(0, 500));
    ui->hmist_inp_->setValidator(new QIntValidator(0, 1000));
    //stars
    ui->starsBright_inp_->setValidator(new QIntValidator(0, 100));
    ui->visibility_inp_->setValidator(new QIntValidator(0, 200000));
    ui->day_spnB_->setMinimum(1);
    //tim
    ui->day_spnB_->setMaximum(31);

}

void meteoWindow::setDataFromDefaultMeteo()
{
    data->visibility= ui->visibility_inp_->text().toFloat();
    data->cloudBase=ui->cloudBase_inp_->text().toFloat();
    data->cloudUpper=ui->cloudThick_inp_->text().toFloat();
    data->cloudSize=ui->cloudSize_inp_->text().toFloat();
    data->cloudsType=ui->cloudsType_cmbB_->currentIndex();
    data->cloudsSecondLay=(int)ui->cloudsSecLay_cmbB_->currentIndex();
    data->SecLayHeight=ui->cloudSecLayer_inp_->text().toFloat();

   // data->Month=ui->month_cmbB_->currentIndex();
	if (ui->day_spnB_->value() == 0)
		ui->day_spnB_->setValue(1);

    data->Day=ui->day_spnB_->value();

    if (ui->month_cmbB_->currentIndex() == 0)
    {
        data->Month = 12;
    }
    else
    {
        data->Month = short(ui->month_cmbB_->currentIndex());
    }
    data->Hours = short(ui->time_spnB_->HourSection);
    data->Minutes = short(ui->time_spnB_->MinuteSection);
    data->local_visibility=ui->localVis_inp_->text().toFloat();
    data->rain=ui->rain_inp_->text().toFloat();
    data->snow=ui->snow_inp_->text().toFloat();
    data->hmist=ui->hmist_inp_->text().toFloat();
    data->wind_speed=ui->windSpeed_inp_->text().toFloat();
    data->wind_psi=ui->windSpeedPsi_inp_->text().toFloat();
    data->starBright=ui->starsBright_inp_->text().toFloat();
    data->packet_id = NPR_PACKET_TYPE_METEO_DATA;
    lineDataToScrollValue(data);
}

meteoWindow::~meteoWindow()
{
    delete ui;
    delete data;
    qDebug()<<"destructor";
}

/*----------------------------------------------------*/
/*----time----*/

void meteoWindow::on_mDayPushB__pressed()
{
    ui->mNightPushB_->setChecked(false);
    ui->time_spnB_->setTimeRange(QTime(7,0,0,0),QTime(23,59,0,0));
    ui->time_spnB_->setTime(QTime(12,00));
    ui->time_spnB_->update();
}


void meteoWindow::on_mNightPushB__pressed()
{
    ui->mDayPushB_->setChecked(false);
    ui->time_spnB_->setTimeRange(QTime(0,0,0,0),QTime(6,59,0,0));
    ui->time_spnB_->setTime(QTime(00,00));
    ui->time_spnB_->update();
}

void meteoWindow::on_time_spnB__timeChanged(const QTime &time)
{
    data->Hours = short(time.hour());
    data->Minutes = short(time.minute());
    // qDebug()<<"data->Hours " << data->Hours<<"ddata->Minutes " << data->Minutes<<"\n";
}

void meteoWindow::on_mWinterPushB__pressed()
{
    ui->month_cmbB_->setValidator(new QIntValidator(0,2));
    ui->mAutumnPushB_->setChecked(false);
    ui->mSpringPushB_->setChecked(false);
    ui->mSummerPushB_->setChecked(false);
    if (ui->month_cmbB_->currentIndex() == 0)
    {
        data->Month = 12;
    }
    else
    {
        data->Month = short(ui->month_cmbB_->currentIndex());
    }
    ui->month_cmbB_->update();
    //  qDebug()<<"data->month_cmbB_"<<data->Month;
}

void meteoWindow::on_mAutumnPushB__pressed()
{
    ui->month_cmbB_->setValidator(new QIntValidator(9,11));
    ui->mWinterPushB_->setChecked(false);
    ui->mSpringPushB_->setChecked(false);
    ui->mSummerPushB_->setChecked(false);
    data->Month = short(ui->month_cmbB_->currentIndex());
    ui->month_cmbB_->update();
    //  qDebug()<<"data->month_cmbB_"<<data->Month;
}

void meteoWindow::on_month_cmbB__currentIndexChanged(int index)
{
    qDebug()<<"sIndex(5) " << index;
    if(ui->mSummerPushB_->isChecked() )
        if (index<6 ||
                index>8)
        {
            ui->month_cmbB_->setCurrentIndex(6);

        }
    if(ui->mSpringPushB_->isChecked() )
    {
        if (ui->month_cmbB_->currentIndex()<3 ||
                ui->month_cmbB_->currentIndex()>5)
        {
            ui->month_cmbB_->setCurrentIndex(3);
            //  qDebug()<<"setCurrentIndex(2) " << data->Month;
        }
    }
    if(ui->mWinterPushB_->isChecked() )
    {
        if (index>2 )
        {
            qDebug()<<"sindex)11) " << index;
            ui->month_cmbB_->setCurrentIndex(0);
            //qDebug()<<"setCurrentIndex((2)11) " << data->Month;
        }
    }
    if(ui->mAutumnPushB_->isChecked() )
    {
        if (index<9 ||
                index>11)
        {
            ui->month_cmbB_->setCurrentIndex(9);
            //  qDebug()<<"setCurrentIndex(9) " << data->Month;
        }
    }
    ui->month_cmbB_->update();

    if (index==0)
        data->Month = 12;
    else
        data->Month = ui->month_cmbB_->currentIndex();

    if (ui->month_cmbB_->currentIndex()==2 )
    {
        ui->day_spnB_->setRange(1,28);
    }
    else
    {
        if (ui->month_cmbB_->currentIndex()==0 ||
                ui->month_cmbB_->currentIndex()== 1||
                ui->month_cmbB_->currentIndex()==3||
                ui->month_cmbB_->currentIndex()==5||
                ui->month_cmbB_->currentIndex()==8||
                ui->month_cmbB_->currentIndex()==10)
        {
            ui->day_spnB_->setRange(1,31);
        }
        else
            ui->day_spnB_->setRange(1,30);

    }
    ui->day_spnB_->update();
    //qDebug()<<"data->Month " <<  ui->month_cmbB_->currentIndex();
}

void meteoWindow::on_mSummerPushB__pressed()
{
    ui->month_cmbB_->setValidator(new QIntValidator(6,8));
    ui->mAutumnPushB_->setChecked(false);
    ui->mSpringPushB_->setChecked(false);
    ui->mWinterPushB_->setChecked(false);
    data->Month = short(ui->month_cmbB_->currentIndex());
    ui->month_cmbB_->update();
    // qDebug()<<"data->Month " << data->Month;
}

void meteoWindow::on_mSpringPushB__pressed()
{
    ui->month_cmbB_->setValidator(new QIntValidator(3,5));
    ui->mAutumnPushB_->setChecked(false);
    ui->mWinterPushB_->setChecked(false);
    ui->mSummerPushB_->setChecked(false);
    data->Month = short(ui->month_cmbB_->currentIndex());



    ui->day_spnB_->update();
}

/*----------------------------------------------------*/
/*----cloudness----*/


void meteoWindow::on_cloudThick_inp__editingFinished()
{
    short thick=ui->cloudThick_inp_->text().toShort();
    data->cloudUpper = thick;
    ui->cloudThickScroll_->setValue(thick);
    // qDebug()<<"data->CloudUpper" <<data->CloudUpper<<"\n";
}

void meteoWindow::on_cloudHeightScroll__valueChanged(int value)
{
    // qDebug()<<"cloud height" <<value;
    //  qDebug()<<"cloud height val" <<ui->cloudHeightScroll_->value();
    short height=ui->cloudHeightScroll_->value();
    ui->cloudBase_inp_->setText(QString::number(height));
    data->cloudBase = height;
}

void meteoWindow::on_cloudThickScroll__valueChanged(int value)
{
    // qDebug()<<"cloud thick" <<value;
    // qDebug()<<"cloud thick val" <<ui->cloudHeightScroll_->value();
    //short thick=ui->cloudThickScroll_->value();
    ui->cloudThick_inp_->setText(QString::number(value));
    data->cloudUpper = value;
}

void meteoWindow::on_cloudBase_inp__editingFinished()
{
    short val = ui->cloudBase_inp_->text().toShort();
    data->cloudBase = val;
    ui->cloudHeightScroll_->setValue(val);
    //qDebug()<<"data->CloudBase" <<data->CloudBase<<"\n";
    //qDebug()<<"----cloud height val" <<ui->cloudHeightScroll_->value();
}

//scrolls
void meteoWindow::on_cloudSecLayer_inp__editingFinished()
{
    data->cloudsSecondLay = ui->cloudSecLayer_inp_->text().toFloat();
    ui->cloudSecLvlScroll_->setValue(data->SecLayHeight);
    // qDebug()<<"data->cloudsSecondLay inp line edit" <<data->SecLayHeight<<"\n";
}

void meteoWindow::on_cloudsSecLay_cmbB__currentIndexChanged(int index)
{
    // qDebug()<<"isSecondLayerClouds"<<index;
    char isSecLay = char(index);
    data->cloudsSecondLay = isSecLay;
    ui->cloudSecLayer_inp_->setEnabled(bool(index));
    ui->cloudSecLvlScroll_->setEnabled(bool(index));
}

void meteoWindow::on_cloudSecLvlScroll__valueChanged(int value)
{
    float val = ui->cloudSecLvlScroll_->value();
    data->SecLayHeight = val;
    ui->cloudSecLayer_inp_->setText(QString::number(value));
    //  qDebug()<<"data->cloudsSecondLay scroll" <<data->SecLayHeight<<"\n";
}

void meteoWindow::on_cloudsType_cmbB__currentIndexChanged(int index)
{
    data->cloudsType = char(index);
    //  qDebug()<<"cloudsType"<<data->cloudsType;
}

void meteoWindow::on_cloudSize_inp__editingFinished()
{
    data->cloudSize = ui->cloudSize_inp_->text().toShort();
    //  qDebug()<<"data->CloudSize" <<data->CloudSize<<"\n";
}
/*----------------------------------------------------*/
/*----rains----*/
void meteoWindow::on_localVis_inp__editingFinished()
{
    float local_visibility =  ui->localVis_inp_->text().toFloat();
    data->local_visibility = local_visibility;
    ui->localVisScroll_->setValue(int(local_visibility));
    // qDebug()<<"data->local_visibility" <<data->local_visibility<<"\n";
}

void meteoWindow::on_localVisScroll__valueChanged(int value)
{
    float loc_vis=ui->localVisScroll_->value();
    ui->localVis_inp_->setText(QString::number(loc_vis));
    data->local_visibility = loc_vis;
}

void meteoWindow::on_rain_inp__editingFinished()
{
    float rain = ui->rain_inp_->text().toFloat();
    data->rain = rain;
    ui->rainScroll_->setValue(int(rain));
    // qDebug()<<"data->rain" <<data->rain<<"\n";
}

void meteoWindow::on_rainScroll__valueChanged(int value)
{
    float rain=ui->rainScroll_->value();
    ui->rain_inp_->setText(QString::number(rain));
    data->rain = rain;
}

void meteoWindow::on_snow_inp__editingFinished()
{
    float snow =ui->snow_inp_->text().toFloat();
    data->snow = snow;
    ui->snowScroll_->setValue(int(snow));
    // qDebug()<<"data->snow" <<data->snow<<"\n";
}

void meteoWindow::on_snowScroll__valueChanged(int value)
{
    float snow=ui->snowScroll_->value();
    ui->snow_inp_->setText(QString::number(snow));
    data->snow = snow;
}

void meteoWindow::on_hmist_inp__editingFinished()
{
    float hmist = ui->hmist_inp_->text().toFloat();
    data->hmist = hmist;
    ui->mistScroll_->setValue(int(hmist));
    //  qDebug()<<"data->hmist" <<data->hmist<<"\n";
}

void meteoWindow::on_mistScroll__valueChanged(int value)
{
    float mist=ui->mistScroll_->value();
    ui->hmist_inp_->setText(QString::number(mist));
    data->hmist = mist;
}
/*----------------------------------------------------*/
/*----Winds----*/
void meteoWindow::on_windSpeed_inp__editingFinished()
{
    float windSpeed=ui->windSpeed_inp_->text().toFloat();
    data->wind_speed = windSpeed;
    ui->windSpeedScroll_->setValue(int(windSpeed));
    // qDebug()<<"data->wind_speed" <<data->wind_speed<<"\n";
}

void meteoWindow::on_windSpeedScroll__valueChanged(int value)
{
    // qDebug()<<"windSpeed val" <<ui->windSpeedScroll_->value();
    float windSpeed=ui->windSpeedScroll_->value();
    ui->windSpeed_inp_->setText(QString::number(windSpeed));
    data->wind_speed = windSpeed;
}

void meteoWindow::on_windSpeedPsi_inp__editingFinished()
{
    float windPsi=ui->windSpeedPsi_inp_->text().toFloat();
    data->wind_psi = windPsi;
    ui->windPsiScroll_->setValue(int(windPsi));
    // qDebug()<<"data->wind_psi" <<data->wind_psi<<"\n";
}

void meteoWindow::on_windPsiScroll__valueChanged(int value)
{
    float windPsi=ui->windPsiScroll_->value();
    ui->windSpeedPsi_inp_->setText(QString::number(int(windPsi)));
    data->wind_psi = windPsi;
}

/*----------------------------------------------------*/
/*----stars----*/
void meteoWindow::on_visibility_inp__editingFinished()
{
    float visibility = ui->visibility_inp_->text().toFloat();
    data->visibility = visibility;
    ui->visScroll_->setValue(int(visibility));
    //  qDebug()<<"data->Visibility" <<data->Visibility<<"\n";
}

void meteoWindow::on_visScroll__valueChanged(int value)
{
    //  qDebug()<<"visibility" <<ui->visScroll_->value();
    float visibility=ui->visScroll_->value();
    ui->visibility_inp_->setText(QString::number(visibility));
    data->visibility = visibility;
}

void meteoWindow::on_starsBright_inp__editingFinished()
{
    //  qDebug()<<"sr";
    //  qDebug()<<"srtext"<<ui->starsBright_inp_->text();
    data->starBright = ui->starsBright_inp_->text().toFloat();
    ui->starsBrightScroll_->setValue(int(data->starBright));
    // qDebug()<<"data->StarBright" <<data->StarBright<<"\n";
}

void meteoWindow::on_starsBrightScroll__valueChanged(int value)
{
    float starsBr=ui->starsBrightScroll_->value();
    ui->starsBright_inp_->setText(QString::number(starsBr));
    data->starBright = starsBr;
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
    qDebug() << "reading file";
    /*qDebug() << meteo_data->message;
    qDebug() << meteo_data->Visibility;
    qDebug() << meteo_data->CloudBase;
    qDebug() << meteo_data->CloudUpper;
    qDebug() << meteo_data->CloudSize;
    qDebug() << meteo_data->cloudsType;*/
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
    //  qDebug() << meteo_data->StarBright;
}


void meteoWindow::on_action_2_triggered()
{
    //save meteo to file
    file_io.saveFile(data);
}

void meteoWindow::writeToFields(std::shared_ptr<_MeteoData> meteo_data )
{
    data->packet_id = 202;//NPR_PACKET_TYPE_METEO_DATA;//meteo_data->message;
    deep_meteo_copy(meteo_data.get() ,data );
    qDebug()<<"setting shared data from received";
    ui->visibility_inp_->setText(QString::number(data->visibility));
    ui->cloudBase_inp_->setText(QString::number(data->cloudBase));
    ui->cloudThick_inp_->setText(QString::number(data->cloudUpper));
    ui->cloudSize_inp_->setText(QString::number(data->cloudSize));
    ui->cloudsType_cmbB_->setCurrentIndex(data->cloudsType);
    ui->cloudsSecLay_cmbB_->setCurrentIndex( data->cloudsSecondLay);
    ui->cloudSecLayer_inp_->setText(QString::number(data->SecLayHeight));

    if (meteo_data->Month == 12)
        ui->month_cmbB_->setCurrentIndex(0);
    else
        ui->month_cmbB_->setCurrentIndex(meteo_data->Month);
    ui->day_spnB_->setValue( data->Day);
    ui->time_spnB_->setDateTime(QDateTime(QDate(2018, data->Month, data->Day),QTime(data->Hours,data->Minutes)));

    ui->localVis_inp_->setText(QString::number(data->local_visibility));
    ui->rain_inp_->setText(QString::number(data->rain));
    ui->snow_inp_->setText(QString::number(data->snow));
    ui->hmist_inp_->setText(QString::number(data->hmist));
    ui->windSpeed_inp_->setText(QString::number(data->wind_speed));
    ui->windSpeedPsi_inp_->setText(QString::number( data->wind_psi));
    ui->starsBright_inp_->setText(QString::number(data->starBright));

    lineDataToScrollValue(data);
    this->update();
}
void meteoWindow::writeToFields(_MeteoData * _data )
{
    _data->packet_id = NPR_PACKET_TYPE_METEO_DATA;//meteo_data->message;
	
	if( !set_from_net  )
		deep_meteo_copy(_data, data );
    
	qDebug()<<"setting data from received";
    ui->visibility_inp_->setText(QString::number(_data->visibility));
    ui->cloudBase_inp_->setText(QString::number(_data->cloudBase));
    ui->cloudThick_inp_->setText(QString::number(_data->cloudUpper));
    ui->cloudSize_inp_->setText(QString::number(_data->cloudSize));
    ui->cloudsType_cmbB_->setCurrentIndex(_data->cloudsType);
    ui->cloudsSecLay_cmbB_->setCurrentIndex(_data->cloudsSecondLay);
    ui->cloudSecLayer_inp_->setText(QString::number(_data->SecLayHeight));

    if (_data->Month == 12)
        ui->month_cmbB_->setCurrentIndex(0);
    else
        ui->month_cmbB_->setCurrentIndex(_data->Month);
    ui->day_spnB_->setValue(_data->Day);
    ui->time_spnB_->setDateTime(QDateTime(QDate(2018, _data->Month, _data->Day),QTime(_data->Hours, _data->Minutes)));

    ui->localVis_inp_->setText(QString::number(_data->local_visibility));
    ui->rain_inp_->setText(QString::number(_data->rain));
    ui->snow_inp_->setText(QString::number(_data->snow));
    ui->hmist_inp_->setText(QString::number(_data->hmist));
    ui->windSpeed_inp_->setText(QString::number(_data->wind_speed));
    ui->windSpeedPsi_inp_->setText(QString::number(_data->wind_psi));
    ui->starsBright_inp_->setText(QString::number(_data->starBright));

    lineDataToScrollValue(_data);
    this->update();
}
void meteoWindow::setReadOnly(bool _isReadOnly)
{
	ui->mSummerPushB_->setDisabled(_isReadOnly);
	ui->mAutumnPushB_->setDisabled(_isReadOnly);
	ui->mWinterPushB_->setDisabled(_isReadOnly);
	ui->mSpringPushB_->setDisabled(_isReadOnly);

	ui->mDayPushB_->setDisabled(_isReadOnly);
	ui->mNightPushB_->setDisabled(_isReadOnly);

	ui->visibility_inp_->setReadOnly(_isReadOnly);
	ui->cloudBase_inp_->setReadOnly(_isReadOnly);
	ui->cloudThick_inp_->setReadOnly(_isReadOnly);
	ui->cloudSize_inp_->setReadOnly(_isReadOnly);

	ui->cloudSecLayer_inp_->setReadOnly(_isReadOnly);	
	ui->day_spnB_->setReadOnly(_isReadOnly);
	ui->time_spnB_->setReadOnly(_isReadOnly);

	ui->localVis_inp_->setReadOnly(_isReadOnly);
	ui->rain_inp_->setReadOnly(_isReadOnly);
	ui->snow_inp_->setReadOnly(_isReadOnly);
	ui->hmist_inp_->setReadOnly(_isReadOnly);
	ui->windSpeed_inp_->setReadOnly(_isReadOnly);
	ui->windSpeedPsi_inp_->setReadOnly(_isReadOnly);
	ui->starsBright_inp_->setReadOnly(_isReadOnly);

	ui->cloudsType_cmbB_->setEnabled(!_isReadOnly);
	ui->cloudsSecLay_cmbB_->setEnabled(!_isReadOnly);	
	ui->month_cmbB_->setEnabled(!_isReadOnly);
	
	ui->cloudHeightScroll_->setEnabled(!_isReadOnly);
	ui->cloudSecLvlScroll_->setEnabled(false);//think of it!!
	ui->cloudThickScroll_->setEnabled(!_isReadOnly);
	ui->localVisScroll_->setEnabled(!_isReadOnly);
	ui->mistScroll_->setEnabled(!_isReadOnly);
	ui->windSpeedScroll_->setEnabled(!_isReadOnly);
	ui->windPsiScroll_->setEnabled(!_isReadOnly);
	ui->snowScroll_->setEnabled(!_isReadOnly);
	ui->rainScroll_->setEnabled(!_isReadOnly);
	ui->visScroll_->setEnabled(!_isReadOnly);
	ui->starsBrightScroll_->setEnabled(!_isReadOnly);

}
void meteoWindow::writeToFieldsNet(_MeteoData *meteo_data)
{
   /* data->packet_id = 202;//NPR_PACKET_TYPE_METEO_DATA;//meteo_data->message;
   // deep_meteo_copy(meteo_data, network_data );

    if (set_from_net==false)
        return;

    qDebug()<<"setting METEO data from received NET";
    ui->visibility_inp_->setText(QString::number(meteo_data->visibility));
    ui->cloudBase_inp_->setText(QString::number(meteo_data->cloudBase));
    ui->cloudThick_inp_->setText(QString::number(meteo_data->cloudUpper));
    ui->cloudSize_inp_->setText(QString::number(meteo_data->cloudSize));
    ui->cloudsType_cmbB_->setCurrentIndex((int)meteo_data->cloudsType);
    ui->cloudsSecLay_cmbB_->setCurrentIndex( (int)meteo_data->cloudsSecondLay);
    ui->cloudSecLayer_inp_->setText(QString::number(meteo_data->SecLayHeight));

    if (meteo_data->Month == 12)
        ui->month_cmbB_->setCurrentIndex(0);
    else
        ui->month_cmbB_->setCurrentIndex(meteo_data->Month);
    ui->day_spnB_->setValue( meteo_data->Day);
    ui->time_spnB_->setDateTime(QDateTime(QDate(2018, meteo_data->Month, meteo_data->Day),QTime(meteo_data->Hours,meteo_data->Minutes)));

    ui->localVis_inp_->setText(QString::number(meteo_data->local_visibility));
    ui->rain_inp_->setText(QString::number(meteo_data->rain));
    ui->snow_inp_->setText(QString::number(meteo_data->snow));
    ui->hmist_inp_->setText(QString::number(meteo_data->hmist));
    ui->windSpeed_inp_->setText(QString::number(meteo_data->wind_speed));
    ui->windSpeedPsi_inp_->setText(QString::number( meteo_data->wind_psi));
    ui->starsBright_inp_->setText(QString::number(meteo_data->starBright));

    /*set read only*
    ui->starsBright_inp_->setReadOnly(true);
    ui->localVis_inp_->setReadOnly(true);
    ui->rain_inp_->setReadOnly(true);
    ui->snow_inp_->setReadOnly(true);
    ui->hmist_inp_->setReadOnly(true);
    ui->windSpeed_inp_->setReadOnly(true);
    ui->windSpeedPsi_inp_->setReadOnly(true);
    ui->starsBright_inp_->setReadOnly(true);

    ui->month_cmbB_->setEnabled(false);
    ui->day_spnB_->setReadOnly(true);
    ui->time_spnB_->setReadOnly(true);
    ui->visibility_inp_->setReadOnly(true);
    ui->cloudBase_inp_->setReadOnly(true);
    ui->cloudThick_inp_->setReadOnly(true);
    ui->cloudSize_inp_->setReadOnly(true);
    ui->cloudsType_cmbB_->setEnabled(false);
    ui->cloudsSecLay_cmbB_->setEnabled(false);
    ui->cloudSecLayer_inp_->setReadOnly(true);

    lineDataToScrollValue();	 */
}

void meteoWindow::on_day_spnB__valueChanged(int arg1)
{

    data->Day = ui->day_spnB_->value();
    //  qDebug()<<"data->Day" <<data->Day<<"\n";
}

void meteoWindow::lineDataToScrollValue(_MeteoData *curr)
{
    //another shitty code
    ui->cloudHeightScroll_->setValue(curr->cloudBase);
    ui->cloudSecLvlScroll_->setValue(curr->cloudsSecondLay);
    ui->cloudThickScroll_->setValue(curr->cloudUpper);
    ui->localVisScroll_->setValue(curr->local_visibility);
    ui->mistScroll_->setValue(curr->hmist);
    ui->windSpeedScroll_->setValue(curr->wind_speed);
    ui->windPsiScroll_->setValue(curr->wind_psi);
    ui->snowScroll_->setValue(curr->snow);
    ui->rainScroll_->setValue(curr->rain);
	ui->visScroll_->setValue(curr->visibility);
    ui->starsBrightScroll_->setValue(curr->starBright);
}

void meteoWindow::on_ok_pushb__pressed()
{
    qDebug() << "data->Day" << this->data->hmist << "\n";
    emit sendData(this->data);
    this->close();
}

void meteoWindow::on_CancelPB__clicked()
{
    this->close();
}

void meteoWindow::on_ok_pushb__clicked()
{
 //   emit sendData(this->data);
   // this->close();
}

void meteoWindow::on_mAutumnPushB__clicked()
{
    //add change month
    ui->month_cmbB_->setCurrentIndex(9);
}

void meteoWindow::on_mSpringPushB__clicked()
{
    ui->month_cmbB_->setCurrentIndex(3);
}

void meteoWindow::on_mWinterPushB__clicked()
{
    ui->month_cmbB_->setCurrentIndex(0);
}

void meteoWindow::on_mSummerPushB__clicked()
{
    ui->month_cmbB_->setCurrentIndex(6);
}

