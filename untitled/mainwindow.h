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
};

#endif // METEO_WINDOW_H
