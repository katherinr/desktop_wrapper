#ifndef MAINWINDOW_H
#define METEO_WINDOW_H
#include <meteo_struct.h>
#include <QMainWindow>
#include "file_meteo_io.h"

namespace Ui {
class meteoWindow;
}

class meteoWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit meteoWindow(QWidget *parent = nullptr);
    void setLimitsToScrolls();
    void setLimitsToLines();
    ~meteoWindow();
    void writeToFields(std::shared_ptr<METEO_DATA> meteo_data );
private:
    Ui::meteoWindow *ui;
    METEO_DATA *data;
    FileMeteoIO file_io;
private slots:
    void on_cloudBase_inp_editingFinished();
    void on_cloudUpper_inp_editingFinished();
    void on_localVis_inp_editingFinished();
    void on_rain_inp_editingFinished();
    void on_snow_inp_editingFinished();
    void on_hmist_inp_editingFinished();
    void on_windSpeed_inp_editingFinished();
    void on_windSpeedPsi_inp_editingFinished();
    void on_visibility_inp_editingFinished();
    void on_starsBright_inp_editingFinished();
    void on_cloudSize_spnB_valueChanged(int arg1);
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

    void on_day_spnb_editingFinished();
};

#endif // METEO_WINDOW_H
