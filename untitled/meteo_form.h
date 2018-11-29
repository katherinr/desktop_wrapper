#ifndef METEO_WINDOW_H
#define METEO_WINDOW_H
#include <QMainWindow>
#include "file_meteo_io.h"
#include <QSignalBlocker>
#include <QDialog>

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
    void setDataFromDefaultMeteo();
    ~meteoWindow();
    bool set_from_net = false;
    _MeteoData* data;
	void writeToFields(_MeteoData * meteo_data);
	void setReadOnly(bool isReadOnly);
	void writeToFieldsNet(_MeteoData * meteo_data);
	void writeToFields(std::shared_ptr<_MeteoData> meteo_data);
/*public slots:
	void writeToFields(std::shared_ptr<_MeteoData> meteo_data);
	void writeToFieldsNet(_MeteoData * meteo_data);		*/
private:

   // _MeteoData* network_data;
    Ui::meteoWindow *ui;
    FileMeteoIO file_io;
 signals:
    void  sendData(_MeteoData *data) ;

private slots:
    void on_localVis_inp__editingFinished();
    void on_cloudThickScroll__valueChanged(int value);
    void on_cloudBase_inp__editingFinished();
    void on_cloudSize_inp__editingFinished();

    void on_rain_inp__editingFinished();
    void on_snow_inp__editingFinished();
    void on_hmist_inp__editingFinished();
    void on_windSpeed_inp__editingFinished();
    void on_windSpeedPsi_inp__editingFinished();
    void on_visibility_inp__editingFinished();
    void on_starsBright_inp__editingFinished();

    void on_cloudSecLayer_inp__editingFinished();
    void on_cloudThick_inp__editingFinished();
    void on_mWinterPushB__pressed();
    void on_mSummerPushB__pressed();
    void on_mSpringPushB__pressed();
    void on_mAutumnPushB__pressed();
    void on_mDayPushB__pressed();
    void on_mNightPushB__pressed();
    void on_time_spnB__timeChanged(const QTime &time);
    void on_month_cmbB__currentIndexChanged(int index);
    void on_cloudHeightScroll__valueChanged(int value);
    void on_action_triggered();
    void on_action_2_triggered();
    void on_cloudSecLvlScroll__valueChanged(int value);
    void on_cloudsSecLay_cmbB__currentIndexChanged(int index);
    void on_cloudsType_cmbB__currentIndexChanged(int index);
    void on_localVisScroll__valueChanged(int value);
    void on_rainScroll__valueChanged(int value);
    void on_snowScroll__valueChanged(int value);
    void on_mistScroll__valueChanged(int value);
    void on_windSpeedScroll__valueChanged(int value);
    void on_windPsiScroll__valueChanged(int value);
    void on_visScroll__valueChanged(int value);
    void on_starsBrightScroll__valueChanged(int value);
    void on_action_4_triggered();
    void on_day_spnB__valueChanged(int arg1);
    void lineDataToScrollValue(_MeteoData *curr);

    void on_ok_pushb__pressed();
    void on_CancelPB__clicked();
    void on_ok_pushb__clicked();
    void on_mAutumnPushB__clicked();
    void on_mSpringPushB__clicked();
    void on_mWinterPushB__clicked();
    void on_mSummerPushB__clicked();

};

#endif // METEO_WINDOW_H
