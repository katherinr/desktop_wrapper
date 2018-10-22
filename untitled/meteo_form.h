#ifndef METEO_WINDOW_H
#define METEO_WINDOW_H
//#include <data_from_kd_vis.h>
#include <QMainWindow>
#include "file_meteo_io.h"
#include <QSignalBlocker>


namespace Ui {
class meteoWindow;
}

class meteoWindow : public QMainWindow
{
    Q_OBJECT
	
public:
    explicit meteoWindow(QWidget *parent = nullptr);
    //meteoWindow(QWidget *parent );
    void setLimitsToScrolls();
    void setLimitsToLines();
    ~meteoWindow();
public slots:
    void writeToFields(std::shared_ptr<METEO_DATA> meteo_data );
    void writeToFields(METEO_DATA * meteo_data );
private:
    METEO_DATA* data;
    Ui::meteoWindow *ui;
    FileMeteoIO file_io;
 signals:
     void  sendData(METEO_DATA *data) ;
private slots:

    void on_cloudThickScroll_valueChanged(int value);
    void on_cloudBase_inp_editingFinished();
 
    void on_localVis_inp_editingFinished();
    void on_rain_inp_editingFinished();
    void on_snow_inp_editingFinished();
    void on_hmist_inp_editingFinished();
    void on_windSpeed_inp_editingFinished();
    void on_windSpeedPsi_inp_editingFinished();
    void on_visibility_inp_editingFinished();
    void on_starsBright_inp_editingFinished();

    void on_cloudSecLayer_inp_editingFinished();
    void on_cloudThick_inp_editingFinished();
    void on_mWinterPushB_pressed();
    void on_mSummerPushB_pressed();
    void on_mSpringPushB_pressed();
    void on_mAutumnPushB_pressed();
    void on_mDayPushB_pressed();
    void on_mNightPushB_pressed();
    void on_time_spnB_timeChanged(const QTime &time);
    void on_month_cmbB_currentIndexChanged(int index);
    void on_cloudHeightScroll_valueChanged(int value);
    void on_action_triggered();
    void on_action_2_triggered();
    void on_cloudSecLvlScroll_valueChanged(int value);
    void on_cloudsSecLay_cmbB_currentIndexChanged(int index);
    void on_cloudsType_cmbB_currentIndexChanged(int index);
    void on_localVisScroll_valueChanged(int value);
    void on_rainScroll_valueChanged(int value);
    void on_snowScroll_valueChanged(int value);
    void on_mistScroll_valueChanged(int value);
    void on_windSpeedScroll_valueChanged(int value);
    void on_windPsiScroll_valueChanged(int value);
    void on_visScroll_valueChanged(int value);
    void on_starsBrightScroll_valueChanged(int value);
    void on_action_4_triggered();
    void on_day_spnB_valueChanged(int arg1);
    void lineDataToScrollValue();
    void on_cloudSize_inp_editingFinished();
    void on_ok_pushb_pressed();
    void on_CancelPB_clicked();
    void on_ok_pushb_clicked();
};

#endif // METEO_WINDOW_H
