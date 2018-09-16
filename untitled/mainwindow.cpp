#include "mainwindow.h"
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
    qDebug()<<"constructor";

  }

meteoWindow::~meteoWindow()
{
    delete ui;
    qDebug()<<"destructor";
}

void meteoWindow::on_cloudBase_inp_editingFinished()
{
    data->CloudBase = ui->cloudBase_inp->text().toShort();
    qDebug()<<"data->CloudBase" <<data->CloudBase<<"\n";
}

void meteoWindow::on_cloudUpper_inp_editingFinished()
{
     data->CloudUpper = ui->cloudThick_inp->text().toShort();
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
    qDebug()<<"sr";
    qDebug()<<"srtext"<<ui->starsBright_inp->text();
    data->StarBright = ui->starsBright_inp->text().toFloat();
    qDebug()<<"data->StarBright" <<data->StarBright<<"\n";
}

void meteoWindow::on_cloudSize_spnB_valueChanged(int arg1)
{
    data->CloudSize = ui->cloudSize_inp->text().toShort();
    qDebug()<<"data->CloudSize" <<data->CloudSize<<"\n";
}

void meteoWindow::on_month_cmbB_editTextChanged(const QString &arg1)
{
    data->Month = ui->month_cmbB->currentText().toShort();
    qDebug()<<"data->Month" <<data->Month<<"\n";
}

void meteoWindow::on_cloudSecLayer_inp_editingFinished()
{
    data->cloudsSecondLay = ui->cloudSecLayer_inp->text().toInt();
    qDebug()<<"data->cloudsSecondLay" <<data->cloudsSecondLay<<"\n";
}

void meteoWindow::on_cloudThick_inp_editingFinished()
{
    data->CloudUpper = ui->cloudThick_inp->text().toShort();
    qDebug()<<"data->CloudUpper" <<data->CloudUpper<<"\n";
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
    data->Hours = time.hour();
    data->Minutes = time.minute();
    qDebug()<<"data->Hours " << data->Hours<<"ddata->Minutes " << data->Minutes<<"\n";
}

void meteoWindow::on_mWinterPushB_pressed()
{
    ui->month_cmbB->setAutoCompletion(11);
    ui->mAutumnPushB->setChecked(false);
    ui->mSpringPushB->setChecked(false);
    ui->mSummerPushB->setChecked(false);
    data->Month = 1+ui->month_cmbB->currentIndex();
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

void meteoWindow::on_cloudHeightScroll_valueChanged(int value)
{
    ui->cloudHeightScroll->setRange(0,2000);
    auto new_val = value*ui->cloudHeightScroll->singleStep();
    ui->cloudBase_inp->setText(QString(new_val));
    data->CloudBase = new_val;
}
