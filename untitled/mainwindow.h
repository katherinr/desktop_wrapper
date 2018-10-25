#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <meteo_form.h>
#include "ui_meteoform.h"
#include <airportsdialog.h>
#include "ui_airportsdialog.h"
#include <udpserver.h>
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

private slots:
    void onNewDatagramReceived(const QByteArray& datagram);

    void on_receivePortEdit_editingFinished();
    void on_startStopSendButton_toggled(bool checked);

    void on_mainVisCheckBox_toggled(bool checked);

    void on_meteoCheckBox_clicked(bool checked);

    void on_lightsCheckBox_clicked(bool checked);

    void on_BackwardCheckBox_clicked(bool checked);

    void on_sendOnceButton_pressed();

    void on_sendIPEdit_editingFinished();

    void on_sendPortEdit_editingFinished();

    void on_okPB_pressed();

    void on_CancelPB_clicked();

    void receiveData(_AirportData*);
    void receiveData(_DataToModel*);
    void receiveData(_MeteoData * _data);

    void on_recDatapB_2_toggled(bool checked);
    void on_meteo_remchb_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    meteoWindow* meteo_ui;
    backwardW *backward_ui;
    AirportsDialog *aerodrom_ui;

    _MeteoData meteo_data;
    _AirportData airoports_lights_data;
    _DataToModel backward_data;

    UdpServer *m_server;
};

#endif // MAINWINDOW_H
