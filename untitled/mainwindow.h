#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "meteo_form.h"
#include "ui_meteoform.h"
#include "airportsdialog.h"
#include "ui_airportsdialog.h"
#include "mainvisual.h"
#include "udpserver.h"
#include "backward.h"
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

private slots:
    //receiving
    void onNewDatagramReceived(const QByteArray& datagram);
    void receiveData(_AirportData*);
    void receiveData(_DataToModel*);
    void receiveData(_MeteoData * _data);
	void receiveData(_MainVisualData * _data);

	void receiveDatafromModel(_AirportData*);
	//void receiveDatafromModel(_DataToModel*);
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
    void on_routePushB_clicked();
    void on_send2mapchb_toggled(bool checked);

    void on_backwReceive_toggled(bool checked);

    void on_backwardChkBox_toggled(bool checked);

    void on_showWindchB_toggled(bool checked);

    void on_showTrajChB_toggled(bool checked);

    void on_showRoutechB_toggled(bool checked);

    void on_followMainPlainCHB_toggled(bool checked);

    void on_isOrientCamchB_toggled(bool checked);

    void on_sendIPEdit_2_editingFinished();

    void on_sendPortEdit_2_editingFinished();

    void on_send2mapIE_editingFinished();

    void on_nppm_editingFinished();

    void on_updateRoute_editingFinished();

    void on_centerLat_editingFinished();

    void on_centerLon_editingFinished();

    void on_centerH_editingFinished();

private:
    Ui::MainWindow *ui;
    meteoWindow* meteo_ui;
    backwardW *backward_ui;
    AirportsDialog *aerodrom_ui;
    MainVisual *mainvis_ui;

    _MeteoData meteo_data;
    _AirportData airoports_lights_data;
    _DataToModel backward_data;
    _MainVisualData visual_data;

	_MeteoData meteo_data_from_model;
	_AirportData airoports_lights_data_from_model;
	_DataToModel backward_data_from_model;
	_MainVisualData visual_data_from_model;


    UDP_data_t map_data;
    UdpServer *m_server;
	QTime time_from_start;
};

#endif // MAINWINDOW_H
