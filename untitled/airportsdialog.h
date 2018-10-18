#ifndef AIRPORTSDIALOG_H
#define AIRPORTSDIALOG_H
#include <string>
#include <QDialog>
#include <meteo_struct.h>
//#include <Protocol_templates(25.09.2018).h>
namespace Ui {
class AirportsDialog;
}

class AirportsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AirportsDialog(QWidget *parent = nullptr);
    ~AirportsDialog();

private slots:

    void on_ok_pb_clicked();

    void on_cancel_pb_clicked();
    void setLimitsToLines();
    void on_takeoff_runway_border_lights_editingFinished();

    void on_departure_airport_lights_taxiing_editingFinished();

    void on_departure_airport_code_editingFinished();

    void on_takeoff_runway_code_editingFinished();

    void on_departure_airport_lights_illumination_editingFinished();

    void on_departure_airport_other_lights_editingFinished();

    void on_arrival_airport_code_editingFinished();

    void on_landing_runway_code_editingFinished();

    void on_landing_runway_border_lights_editingFinished();

    void on_arrival_airport_lights_taxiing_editingFinished();

    void on_arrival_airport_lights_illumination_editingFinished();

    void on_arrival_airport_other_lights_editingFinished();

    void on_model_simulation_time_editingFinished();
    void fill_aeroport_codes();
    void on_arrivalCity_currentIndexChanged(const QString &arg1);

    void on_departureCity_currentIndexChanged(int index);

    void on_departureCode_currentIndexChanged(const QString &arg1);

    void on_arrivalCode_currentIndexChanged(const QString &arg1);

    void on_ok_pb_pressed();

private:
    Ui::AirportsDialog *ui;
    _AirportData *data;
    struct codes
    {
        std::string code1;
        std::string code2;
    };

    std::map<std::string,codes> aeroports_codes;
signals:
    void sendData(_AirportData *data);
};

#endif // AIRPORTSDIALOG_H
