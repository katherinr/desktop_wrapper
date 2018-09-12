#ifndef MAINWINDOW_H
#define METEO_WINDOW_H
#include <meteo_struct.h>
#include <QMainWindow>

namespace Ui {
class meteoWindow;
}

class meteoWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit meteoWindow(QWidget *parent = nullptr);
    ~meteoWindow();

private:
    Ui::meteoWindow *ui;
    METEO_DATA *data;

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
    void on_month_cmbB_editTextChanged(const QString &arg1);
    void on_cloudSecLayer_inp_editingFinished();
    void on_cloudThick_inp_editingFinished();
    void on_mWinterPushB_pressed();
    void on_mDayPushB_pressed();
    void on_mNightPushB_pressed();
    void on_time_spnB_timeChanged(const QTime &time);
};

#endif // METEO_WINDOW_H
