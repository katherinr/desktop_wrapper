﻿#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QEvent>
#include "meteo_form.h"
#include "ui_meteoform.h"
#include "airportsdialog.h"
#include "ui_airportsdialog.h"
#include "mainvisual.h"
#include "udpserver.h"
#include "backward.h"
#include "sound_form.h"
#include "elbird_sound_data.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void sendUpdatedData(_MeteoData *data);
    void sendUpdatedData(_AirportData *data);
    void sendUpdatedData(_DataToModel *data);
    void sendUpdatedData(_MainVisualData *data);

	void mapControlDataUpdated(const MAP_CONTROL_UDP&);

private slots:
    //receiving
    void receiveData(_AirportData*);
    void receiveData(_DataToModel*);
    void receiveData(_MeteoData * _data);
	void receiveData(_MainVisualData * _data);

	void receiveDatafromModel(_AirportData*);
	void receiveDatafromModel(_MeteoData * _data);
	void receiveDatafromModel(_MainVisualData * _data);
    void on_receivePortEdit_editingFinished();

    //sending
    void on_mainVisCheckBox_toggled(bool checked);
    void on_lightsCheckBox_toggled(bool checked);
    void on_meteoCheckBox_toggled(bool checked);

    void on_sendIPEdit_editingFinished();
    void on_sendPortEdit_editingFinished();

    //show dialogs contents
    void on_mainiComboBox_currentIndexChanged(int index);
    void on_meteoComboBox_currentIndexChanged(int index);
	void on_aerodrCB_currentIndexChanged(int index);

    //global process
    void on_startPB_clicked();
    void on_sendOnceButton_clicked();
    void on_stopPB_clicked();
	void readConfig();

	//map indication
	//fixme - move to separate file!
    void on_routePushB_clicked();
    void on_backwReceive_toggled(bool checked);

    void on_backwardChkBox_toggled(bool checked);

    void on_showWindchB_toggled(bool checked);

    void on_showTrajChB_toggled(bool checked);

    void on_showRoutechB_toggled(bool checked);

    void on_followMainPlainCHB_toggled(bool checked);

    void on_isOrientCamchB_toggled(bool checked);

   

    void on_centerLat_editingFinished();

    void on_centerLon_editingFinished();

    void on_mapHeiihtspinBox_valueChanged(int arg1);

    void on_receivePortEdit_2_editingFinished();

    void on_send2mapCHb_toggled(bool checked);

    void on_portMapSend_editingFinished();

    void on_mapIPsend_editingFinished();

    void on_mapHeiihtspinBox_editingFinished();

    void on_send_from_this_toggled(bool checked);

	///sound indication


    void on_soundIPsend_editingFinished();

    void on_soundPortSend_editingFinished();

    void on_portPlotSend_textEdited(const QString &arg1);

    void on_plotIPsend_textChanged(const QString &arg1);

protected:
	void closeEvent(QCloseEvent *event) override;

private:
	void readSettings();
	void writeSettings();
public:
	void update_route_() { m_mapRoute.updateRoute++; };
private:
    Ui::MainWindow *ui;
    meteoWindow* meteo_ui;
    backwardW *backward_ui;
    AirportsDialog *aerodrom_ui;
    MainVisual *mainvis_ui;
    Sound_form *sound_ui;

    _MeteoData meteo_data;
    _AirportData airoports_lights_data;
    _DataToModel backward_data;
    _MainVisualData visual_data;
    SOUND_FUNC_SETTINGS sound_settings;

    _MeteoData meteo_data_from_model;
	_AirportData airoports_lights_data_from_model;
	_DataToModel backward_data_from_model;
	_MainVisualData visual_data_from_model;
	QTimer *modeling_timer;
	int shift_time = 0;		   //seconds

	QLabel * shift_time_indicator;
	QLabel * passed_time_indicator;
	int timer_id = 0;

//		int get_update_route() { return update_route; }

	MAP_CONTROL_UDP m_mapControlData;
	UDP_data_t m_mapRoute;
    UdpServer *m_server;
	QTime time_from_start;
};

#endif // MAINWINDOW_H
