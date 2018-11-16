#ifndef AIRPORTSDIALOG_H
#define AIRPORTSDIALOG_H
#include <string>
#include <QMap>
#include <QDialog>
#include "meteo_struct.h"
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
	void readDefault(_AirportData *);
    void writeToFields(_AirportData*);

private slots:

    void on_ok_pb_clicked();
    void on_cancel_pb_clicked();
    void setLimitsToLines();
    void on_takeoff_runway_border_lights_editingFinished();

    void on_departure_airport_lights_taxiing_editingFinished();

    void on_departure_airport_lights_illumination_editingFinished();

    void on_departure_airport_other_lights_editingFinished();

    void on_arrival_airport_code_editingFinished();

    void on_landing_runway_code_editingFinished();

    void on_landing_runway_border_lights_editingFinished();

    void on_arrival_airport_lights_taxiing_editingFinished();

    void on_arrival_airport_lights_illumination_editingFinished();

    void on_arrival_airport_other_lights_editingFinished();

    void fill_aeroport_codes();
    void fill_flights_strips();

    void on_ok_pb_pressed();

    void updateScrolls();
    void on_arrivalCity_currentIndexChanged(const QString &arg1);
    void on_departureCity_currentIndexChanged(const QString &arg1);

    void on_arrYarkBok_valueChanged(int position);

    void on_arrRulez_valueChanged(int position);

    void on_arrPodsvet_valueChanged(int position);

    void on_arrOther_valueChanged(int position);

    void on_depOtherScroll_valueChanged(int position);
    void on_depRelLightsScroll_valueChanged(int position);
    void on_depBokLightscroll_valueChanged(int position);
    void on_depStoyankScroll_valueChanged(int value);

    void on_departure_airport_code_editingFinished();

private:
    Ui::AirportsDialog *ui;
    _AirportData *data;

    struct codes
    {
        QString iata;
        QString icao;
    };

    QMap<QString,codes> aeroports_codes;
    QMap<QString,std::vector <QString>> flight_strips;
    void setLimitsToScrolls();
signals:
    void sendData(_AirportData *data);
};

#endif // AIRPORTSDIALOG_H
