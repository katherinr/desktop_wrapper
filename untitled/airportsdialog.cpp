#include "airportsdialog.h"
#include "ui_airportsdialog.h"
#include <QRegExpValidator>
#include <QDebug>
AirportsDialog::AirportsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AirportsDialog),
    data(new _AirportData)
{
    ui->setupUi(this);
    data->packet_id = 203;
     setWindowFlags(Qt::WindowStaysOnTopHint);
    fill_aeroport_codes();
   // setLimitsToLines();
};

AirportsDialog::~AirportsDialog()
{
    delete ui;
    delete data;

    qDebug()<<"destructor airp";
}

void AirportsDialog::on_ok_pb_clicked()
{
    this->close();
}

void AirportsDialog::on_cancel_pb_clicked()
{
   //clean data
    data->ARRIVAL_AIRPORT_LIGHTS_ILLUMINATION = 0;
    data->ARRIVAL_AIRPORT_LIGHTS_TAXIING = 0;
    data->ARRIVAL_AIRPORT_OTHER_LIGHTS = 0;
    data->DEPARTURE_AIRPORT_LIGHTS_ILLUMINATION = 0;
    data->DEPARTURE_AIRPORT_LIGHTS_TAXIING = 0;
    data->DEPARTURE_AIRPORT_OTHER_LIGHTS = 0;
    data->TAKEOFF_RUNWAY_BORDER_LIGHTS = 0;
    data->LANDING_RUNWAY_BORDER_LIGHTS = 0;

    qstrcpy(data->TAKEOFF_RUNWAY_CODE, "0");
    qstrcpy(data->LANDING_RUNWAY_CODE, "0");
    qstrcpy(data->DEPARTURE_AIRPORT_CODE, "0");
    qstrcpy(data->ARRIVAL_AIRPORT_CODE, "0");
    this->close();
   // QApplication::quit();
}

void AirportsDialog::setLimitsToLines()
{
   // [a-z0-9]
    QRegExpValidator *rv = new QRegExpValidator(QRegExp("[a-zA-Z0-9]"));
    ui->arrival_airport_code->setValidator(rv);
    ui->arrival_airport_code->setMaxLength(4);

    ui->departure_airport_code->setValidator(rv);
    ui->departure_airport_code->setMaxLength(4);

    ui->landing_runway_code->setMaxLength(3);
    ui->landing_runway_border_lights->setMaxLength(3);

    ui->arrival_airport_lights_taxiing->setMaxLength(3);
    ui->arrival_airport_lights_illumination->setMaxLength(3);
    ui->arrival_airport_other_lights->setMaxLength(3);

    ui->takeoff_runway_code->setMaxLength(4);
    ui->takeoff_runway_border_lights->setMaxLength(4);

    ui->departure_airport_lights_taxiing->setMaxLength(4);
    ui->departure_airport_lights_illumination->setMaxLength(4);
    ui->departure_airport_other_lights->setMaxLength(4);

}

void AirportsDialog::on_takeoff_runway_border_lights_editingFinished()
{
    QString s = ui->takeoff_runway_border_lights->text();
    qstrcpy(&data->TAKEOFF_RUNWAY_BORDER_LIGHTS, s.toLatin1());
    qDebug()<<"data->TAKEOFF_RUNWAY_BORDER_LIGHTS" <<data->TAKEOFF_RUNWAY_BORDER_LIGHTS<<"\n";
}

void AirportsDialog::on_departure_airport_lights_taxiing_editingFinished()
{
    qstrcpy(&data->DEPARTURE_AIRPORT_LIGHTS_TAXIING, qPrintable(ui->departure_airport_lights_taxiing->text()));
    qDebug()<<"data->DEPARTURE_AIRPORT_LIGHTS_TAXIING" <<data->DEPARTURE_AIRPORT_LIGHTS_TAXIING<<"\n";
}

void AirportsDialog::on_departure_airport_code_editingFinished()
{
    QString s = ui->departure_airport_code->text();
    qstrcpy(data->DEPARTURE_AIRPORT_CODE, s.toLatin1());
    qDebug()<<"data->DEPARTURE_AIRPORT_CODE" <<data->DEPARTURE_AIRPORT_CODE<<"\n";
}

void AirportsDialog::on_takeoff_runway_code_editingFinished()
{
    QString s = ui->takeoff_runway_code->text();
    qstrcpy(data->TAKEOFF_RUNWAY_CODE, s.toLatin1());
    qDebug()<<"data->TAKEOFF_RUNWAY_CODE" <<data->TAKEOFF_RUNWAY_CODE<<"\n";
}

void AirportsDialog::on_departure_airport_lights_illumination_editingFinished()
{
    qstrcpy(&data->DEPARTURE_AIRPORT_LIGHTS_ILLUMINATION, qPrintable(ui->departure_airport_lights_illumination->text()));
    qDebug()<<"data->DEPARTURE_AIRPORT_LIGHTS_ILLUMINATION" <<data->DEPARTURE_AIRPORT_LIGHTS_ILLUMINATION<<"\n";

}

void AirportsDialog::on_departure_airport_other_lights_editingFinished()
{
    qstrcpy(&data->DEPARTURE_AIRPORT_OTHER_LIGHTS, qPrintable(ui->departure_airport_other_lights->text()));
    qDebug()<<"data->DEPARTURE_AIRPORT_OTHER_LIGHTS" <<data->DEPARTURE_AIRPORT_OTHER_LIGHTS<<"\n";

}

void AirportsDialog::on_arrival_airport_code_editingFinished()
{
    QString s = ui->arrival_airport_code->text();
    qstrcpy(data->ARRIVAL_AIRPORT_CODE, s.toLatin1());
    qDebug()<<"data->ARRIVAL_AIRPORT_CODE" <<data->ARRIVAL_AIRPORT_CODE<<"\n";
}

void AirportsDialog::on_landing_runway_code_editingFinished()
{
    QString s = ui->landing_runway_code->text();
    qstrcpy(data->LANDING_RUNWAY_CODE, s.toLatin1());
    qDebug()<<"data->LANDING_RUNWAY_CODE" <<data->LANDING_RUNWAY_CODE<<"\n";

}

void AirportsDialog::on_landing_runway_border_lights_editingFinished()
{
    qstrcpy(&data->LANDING_RUNWAY_BORDER_LIGHTS, qPrintable(ui->landing_runway_border_lights->text()));
    qDebug()<<"data->LANDING_RUNWAY_BORDER_LIGHTS" <<data->LANDING_RUNWAY_BORDER_LIGHTS<<"\n";
}

void AirportsDialog::on_arrival_airport_lights_taxiing_editingFinished()
{
    qstrcpy(&data->ARRIVAL_AIRPORT_LIGHTS_TAXIING, qPrintable(ui->arrival_airport_lights_taxiing->text()));
    qDebug()<<"data->ARRIVAL_AIRPORT_LIGHTS_TAXIING" <<data->ARRIVAL_AIRPORT_LIGHTS_TAXIING<<"\n";

}

void AirportsDialog::on_arrival_airport_lights_illumination_editingFinished()
{
    qstrcpy(&data->ARRIVAL_AIRPORT_LIGHTS_ILLUMINATION, qPrintable(ui->arrival_airport_lights_illumination->text()));
    qDebug()<<"data->ARRIVAL_AIRPORT_LIGHTS_ILLUMINATION" <<data->ARRIVAL_AIRPORT_LIGHTS_ILLUMINATION<<"\n";

}

void AirportsDialog::on_arrival_airport_other_lights_editingFinished()
{
    qstrcpy(&data->ARRIVAL_AIRPORT_OTHER_LIGHTS, qPrintable(ui->arrival_airport_other_lights->text()));
    qDebug()<<"data->ARRIVAL_AIRPORT_OTHER_LIGHTS" <<data->ARRIVAL_AIRPORT_OTHER_LIGHTS<<"\n";
}

void AirportsDialog::on_model_simulation_time_editingFinished()
{
    data->model_simulation_time = ui->model_simulation_time->text().toDouble();
    qDebug()<<"data->model_simulation_time" <<data->model_simulation_time<<"\n";

}

void AirportsDialog::fill_aeroport_codes()
{
    aeroports_codes["Moscow SVO"].code1 = "UUEE";
    aeroports_codes["Moscow DME"].code1= "UUDD";
    aeroports_codes["Moscow VKO"].code1 = "UUWW";
    aeroports_codes["Moscow ZIA"].code1= "UUBW";
    aeroports_codes["Moscow OST"].code1= "UUMO";

    aeroports_codes["London"].code1 = "LCY";
    aeroports_codes["London"].code2 = "EGLC";

    aeroports_codes["KarlovyVary"].code1= "KLV";
    aeroports_codes["KarlovyVary"].code2 = "LKKV";

    aeroports_codes["Tivat"].code1 = "TIV";
    aeroports_codes["Tivat"].code2 = "LYTV";

    aeroports_codes["Bruxelles"].code1= "BRU";
    aeroports_codes["Bruxelles"].code2 = "EBBR";

    aeroports_codes["Venice"].code1= "VCE";
    aeroports_codes["Venice"].code2 = "LIPZ";

    aeroports_codes["Dublin"].code1= "DUB";
    aeroports_codes["Dublin"].code2 = "EIDW";

    aeroports_codes["Insbruk"].code1= "INN";
    aeroports_codes["Insbruk"].code2 = "LOWI";

    aeroports_codes["Keflavic"].code1 = "KEF";
    aeroports_codes["Keflavic"].code2 = "BIKF";

    aeroports_codes["Komsomolsk"].code1= "KXK";
    aeroports_codes["Komsomolsk"].code2 = "UHKK";

    aeroports_codes["Pulkovo"].code1= "LED";
    aeroports_codes["Pulkovo"].code2 = "ULLI";

    aeroports_codes["Sochi"].code1= "AER";
    aeroports_codes["Sochi"].code2 = "URSS";

    aeroports_codes["Toluca"].code1= "TLC";
    aeroports_codes["Toluca"].code2 = "MMTO";

    aeroports_codes["Helsinki"].code1= "HEL";
    aeroports_codes["Helsinki"].code2 = "EFHK";

}

void AirportsDialog::on_arrivalCity_currentIndexChanged(const QString &arg1)
{
    std::string city = ui->arrivalCity->currentText().toStdString();
    ui->arrivalCode->clear();
    ui->arrival_airport_code->setText(QString::fromStdString(aeroports_codes[city].code1));
    ui->arrivalCode->addItem(QString::fromStdString(aeroports_codes[city].code1));
    ui->arrivalCode->addItem(QString::fromStdString(aeroports_codes[city].code2));
}

void AirportsDialog::on_departureCity_currentIndexChanged(int index)
{
    std::string city = ui->departureCity->currentText().toStdString();
    ui->departureCode->clear();
    ui->departureCode->addItem(QString::fromStdString(aeroports_codes[city].code1));
    ui->departureCode->addItem(QString::fromStdString(aeroports_codes[city].code2));
    ui->departure_airport_code->setText(QString::fromStdString(aeroports_codes[city].code1));
}

void AirportsDialog::on_departureCode_currentIndexChanged(const QString &arg1)
{
     std::string city = ui->departureCode->currentText().toStdString();
     ui->departure_airport_code->setText(QString::fromStdString(city));
}

void AirportsDialog::on_arrivalCode_currentIndexChanged(const QString &arg1)
{
    std::string city = ui->arrivalCode->currentText().toStdString();
    ui->arrival_airport_code->setText(QString::fromStdString(city));
}

void AirportsDialog::on_ok_pb_pressed()
{
    emit sendData(this->data);
    this->close();
}
