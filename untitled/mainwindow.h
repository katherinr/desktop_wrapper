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

private slots:

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
    void receiveData(METEO_DATA * _data);
private:
    Ui::MainWindow *ui;
    meteoWindow* meteo_ui;
    backwardW *backward_ui;
    AirportsDialog *aerodrom_ui;

    METEO_DATA* meteo_data;
    _AirportData* airoports_lights_data;
    _DataToModel *backward_data;

    UdpServer *m_server;
};

#endif // MAINWINDOW_H
