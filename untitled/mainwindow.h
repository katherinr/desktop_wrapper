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

    //global process
    void on_startPB_clicked();
    void on_sendOnceButton_clicked();
    void on_stopPB_clicked();

    //map indication
    void on_routePushB_clicked();
    void on_send2mapchb_toggled(bool checked);

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

    UdpServer *m_server;
};

#endif // MAINWINDOW_H
