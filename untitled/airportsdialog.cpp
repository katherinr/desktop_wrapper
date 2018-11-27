#include "airportsdialog.h"
#include "ui_airportsdialog.h"
#include <QRegExpValidator>
#include <QDebug>
#include <QTextCodec>
#include "utilities.h"	 
#include "meteo_struct.h"
#include <stdlib.h>
#include <map>
AirportsDialog::AirportsDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::AirportsDialog),
	data(new _AirportData)
{
	ui->setupUi(this);
	data->packet_id = NPR_PACKET_TYPE_AIRPORT_DATA;
	// ui->arrPolosa->clear();
	// ui->depPolosa->clear();
	setWindowModality(Qt::ApplicationModal);
	//readDefault();
	fill_aeroport_codes();
	fill_flights_strips();
	fillRouteByICAO(route_points_by_icao);
	icaoByrus = fillICAObyRus();

	setLimitsToLines();
	setLimitsToScrolls();
};

void AirportsDialog::setLimitsToScrolls()
{
	//*departure*///
	ui->depBokLightscroll->setMinimum(0);
	ui->depBokLightscroll->setMaximum(100);
	ui->depBokLightscroll->setSingleStep(1);
	ui->depBokLightscroll->setValue(ui->depBokLightscroll->maximum());
	//ui->depBokLightscroll->setRange(0,100);

	ui->depOtherScroll->setMinimum(0);
	ui->depOtherScroll->setMaximum(100);
	ui->depOtherScroll->setSingleStep(1);
	ui->depOtherScroll->setValue(ui->depOtherScroll->maximum());
	// ui->depOtherScroll->setRange(0,100);

	ui->depRelLightsScroll->setMinimum(0);
	ui->depRelLightsScroll->setMaximum(100);
	ui->depRelLightsScroll->setSingleStep(1);
	ui->depRelLightsScroll->setValue(ui->depRelLightsScroll->maximum());
	// ui->depRelLightsScroll->setRange(0,100);

	ui->depStoyankScroll->setMinimum(0);
	ui->depStoyankScroll->setMaximum(100);
	ui->depStoyankScroll->setSingleStep(1);
	ui->depStoyankScroll->setValue(ui->depStoyankScroll->maximum());

	// ui->depStoyankScroll->setRange(0,100);

	//*arrival*///
	ui->arrOther->setMinimum(0);
	ui->arrOther->setMaximum(100);
	ui->arrOther->setSingleStep(1);
	ui->arrOther->setValue(ui->arrOther->maximum());
	ui->arrOther->resize(ui->arrOther->sizeHint());
	//  ui->arrOther->setRange(0,100);

	ui->arrPodsvet->setMinimum(0);
	ui->arrPodsvet->setMaximum(100);
	ui->arrPodsvet->setSingleStep(1);
	ui->arrPodsvet->setValue(ui->arrPodsvet->maximum());
	//  ui->arrPodsvet->setRange(0,100);

	ui->arrYarkBok->setMinimum(0);
	ui->arrYarkBok->setMaximum(100);
	ui->arrYarkBok->setSingleStep(1);
	ui->arrYarkBok->setValue(ui->arrYarkBok->maximum());
	// ui->arrYarkBok->setRange(0,100);

	ui->arrRulez->setMinimum(0);
	ui->arrRulez->setMaximum(100);
	ui->arrRulez->setSingleStep(1);
	ui->arrRulez->setValue(ui->arrRulez->maximum());

	//  ui->arrRulez->setRange(0,100);

}

QMap <QString, QString> AirportsDialog::fillICAObyRus()
{
	QMap<QString, QString> answer;

	foreach(QString key, aeroports_codes.keys())
	{
		QString value = aeroports_codes.value(key).icao;
		answer[value] = key;
	}

	return answer;
}

AirportsDialog::~AirportsDialog()
{
	delete ui;
	delete data;

	qDebug() << "destructor airp";
}

void AirportsDialog::writeToFields(_AirportData *_data)
{
	ui->arrival_airport_lights_illumination->setText(QString::number(_data->ARRIVAL_AIRPORT_LIGHTS_ILLUMINATION));
	ui->arrival_airport_lights_taxiing->setText(QString::number(_data->ARRIVAL_AIRPORT_LIGHTS_TAXIING));
	ui->arrival_airport_other_lights->setText(QString::number(_data->ARRIVAL_AIRPORT_OTHER_LIGHTS));

	ui->departure_airport_lights_illumination->setText(QString::number(_data->DEPARTURE_AIRPORT_LIGHTS_ILLUMINATION));
	ui->departure_airport_lights_taxiing->setText(QString::number(_data->DEPARTURE_AIRPORT_LIGHTS_TAXIING));
	ui->departure_airport_other_lights->setText(QString::number(_data->DEPARTURE_AIRPORT_OTHER_LIGHTS));

	ui->takeoff_runway_border_lights->setText(QString::number(_data->TAKEOFF_RUNWAY_BORDER_LIGHTS));
	ui->landing_runway_border_lights->setText(QString::number(_data->LANDING_RUNWAY_BORDER_LIGHTS));

	char tmp[5] = { '\0' };
	tmp[0] = _data->ARRIVAL_AIRPORT_CODE[0];
	tmp[1] = _data->ARRIVAL_AIRPORT_CODE[1];
	tmp[2] = _data->ARRIVAL_AIRPORT_CODE[2];
	tmp[3] = _data->ARRIVAL_AIRPORT_CODE[3];
	QString arrCity = QString::fromUtf8(tmp);


	tmp[0] = _data->DEPARTURE_AIRPORT_CODE[0];
	tmp[1] = _data->DEPARTURE_AIRPORT_CODE[1];
	tmp[2] = _data->DEPARTURE_AIRPORT_CODE[2];
	tmp[3] = _data->DEPARTURE_AIRPORT_CODE[3];

	QString depCity = QString::fromUtf8(tmp);

	//ui->arrivalCity->setCurrentText(arrCity);
	//ui->departureCity->setCurrentText(depCity);

	//ui->arrPolosa->setCurrentText(QString::fromUtf8(_data->LANDING_RUNWAY_CODE));
	//ui->depPolosa->setCurrentText(QString::fromUtf8(_data->TAKEOFF_RUNWAY_CODE));

	ui->arrival_airport_code->setText(arrCity);
	ui->departure_airport_code->setText(depCity);
	
	auto rusCityArr = icaoByrus.find(arrCity);
	if (rusCityArr != icaoByrus.end())
		ui->arrivalCity->setCurrentText(rusCityArr.value());

	auto rusCityDep = icaoByrus.find(depCity);
	if (rusCityDep != icaoByrus.end())
		ui->departureCity->setCurrentText(rusCityDep.value());	 
	///fill strips
	if (!from_model)
	{
		
		fillStripsComboBoxArr(arrCity);
		
		fillStripsComboBoxDep(depCity);

		auto jt = flight_strips.find(ui->departure_airport_code->text());

		if (jt != flight_strips.end())
			ui->depPolosa->setCurrentText(*jt.value().begin());

		auto kt = flight_strips.find(ui->arrival_airport_code->text());

		if (kt != flight_strips.end())
			ui->arrPolosa->setCurrentText(*kt.value().begin());
	}
	else
	{
		ui->arrPolosa->clear();
		ui->depPolosa->clear();
		char tmp1[4] = { '\0' };
		tmp[0] = _data->LANDING_RUNWAY_CODE[0];
		tmp[1] = _data->LANDING_RUNWAY_CODE[1];
		tmp[2] = _data->LANDING_RUNWAY_CODE[2];
		tmp[3] = _data->LANDING_RUNWAY_CODE[3];
		QString landCode = QString::fromUtf8(tmp);


		tmp[0] = _data->TAKEOFF_RUNWAY_CODE[0];
		tmp[1] = _data->TAKEOFF_RUNWAY_CODE[1];
		tmp[2] = _data->TAKEOFF_RUNWAY_CODE[2];
		tmp[3] = _data->TAKEOFF_RUNWAY_CODE[3];

		QString takeoffCode = QString::fromUtf8(tmp);
		ui->arrPolosa->setCurrentText(landCode);
		ui->depPolosa->setCurrentText(takeoffCode);
		
	/*	const auto& rusCityArr = icaoByrus.find(landCode);

		if (rusCityArr != icaoByrus.end())
			ui->arrivalCity->setCurrentText(rusCityArr.value());

		auto rusCityDep = icaoByrus.find(landCode);
		if (rusCityDep != icaoByrus.end())
			ui->departureCity->setCurrentText(rusCityDep.value());	*/
	}

	//scrolls
	ui->arrPodsvet->setSliderPosition(ui->arrival_airport_lights_illumination->text().toInt());
	ui->arrRulez->setSliderPosition(ui->arrival_airport_lights_taxiing->text().toInt());
	ui->arrOther->setSliderPosition(ui->arrival_airport_other_lights->text().toInt());
	ui->arrYarkBok->setSliderPosition(ui->landing_runway_border_lights->text().toInt());

	ui->depStoyankScroll->setSliderPosition(ui->departure_airport_lights_illumination->text().toInt());
	ui->depRelLightsScroll->setSliderPosition(ui->departure_airport_lights_taxiing->text().toInt());
	ui->depOtherScroll->setSliderPosition(ui->departure_airport_other_lights->text().toInt());
	ui->depBokLightscroll->setSliderPosition(ui->takeoff_runway_border_lights->text().toInt());
}

void AirportsDialog::readDefault(_AirportData *data_)
{
	data_->ARRIVAL_AIRPORT_LIGHTS_ILLUMINATION = ui->arrival_airport_lights_illumination->text().toInt();
	data_->ARRIVAL_AIRPORT_LIGHTS_TAXIING = ui->arrival_airport_lights_taxiing->text().toInt();
	data_->ARRIVAL_AIRPORT_OTHER_LIGHTS = ui->arrival_airport_other_lights->text().toInt();

	data_->DEPARTURE_AIRPORT_LIGHTS_ILLUMINATION = ui->departure_airport_lights_illumination->text().toInt();
	data_->DEPARTURE_AIRPORT_LIGHTS_TAXIING = ui->departure_airport_lights_taxiing->text().toInt();
	data_->DEPARTURE_AIRPORT_OTHER_LIGHTS = ui->departure_airport_other_lights->text().toInt();

	data_->TAKEOFF_RUNWAY_BORDER_LIGHTS = ui->takeoff_runway_border_lights->text().toInt();
	data_->LANDING_RUNWAY_BORDER_LIGHTS = ui->landing_runway_border_lights->text().toInt();

	QString s = ui->arrival_airport_code->text();
	qstrcpy(data_->ARRIVAL_AIRPORT_CODE, s.toLatin1());
	s.clear();
	s = ui->departure_airport_code->text();
	qstrcpy(data_->DEPARTURE_AIRPORT_CODE, s.toLatin1());

	s.clear();
	s = ui->depPolosa->currentText();
	qstrcpy(data_->TAKEOFF_RUNWAY_CODE, s.toLatin1());

	s.clear();
	s = ui->arrPolosa->currentText();
	qstrcpy(data_->LANDING_RUNWAY_CODE, s.toLatin1());

	///fill strips
	auto jt = flight_strips.find(ui->departure_airport_code->text());
	if (jt != flight_strips.end())
	{
		ui->depPolosa->clear();
		for (auto it : jt.value())
			ui->depPolosa->addItem(it);
	}

	auto kt = flight_strips.find(ui->arrival_airport_code->text());
	if (kt != flight_strips.end())
	{
		ui->arrPolosa->clear();
		for (auto it : kt.value())
			ui->arrPolosa->addItem(it);
	}

	ui->arrPodsvet->setSliderPosition(ui->arrival_airport_lights_illumination->text().toInt());
	ui->arrRulez->setSliderPosition(ui->arrival_airport_lights_taxiing->text().toInt());
	ui->arrOther->setSliderPosition(ui->arrival_airport_other_lights->text().toInt());
	ui->arrYarkBok->setSliderPosition(ui->landing_runway_border_lights->text().toInt());

	ui->depStoyankScroll->setSliderPosition(ui->departure_airport_lights_illumination->text().toInt());
	ui->depRelLightsScroll->setSliderPosition(ui->departure_airport_lights_taxiing->text().toInt());
	ui->depOtherScroll->setSliderPosition(ui->departure_airport_other_lights->text().toInt());
	ui->depBokLightscroll->setSliderPosition(ui->takeoff_runway_border_lights->text().toInt());
	//emit sendData(data_);
}

void AirportsDialog::on_ok_pb_clicked()
{
	printAeroData(data);
	emit sendData(data);
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

}

void AirportsDialog::setLimitsToLines()
{
	// [a-z0-9]
	QRegExpValidator *rv = new QRegExpValidator(QRegExp("[a-zA-Z0-9]"));
	ui->arrival_airport_code->setValidator(rv);
	// ui->arrival_airport_code->setMaxLength(70);
	ui->arrival_airport_code->isReadOnly();

	//ui->departure_airport_code->setMaxLength(70);
	ui->departure_airport_code->setValidator(rv);
	ui->departure_airport_code->isReadOnly();

	// ui->landing_runway_border_lights->setMaxLength(70);
	ui->landing_runway_border_lights->setValidator(new QIntValidator(0, 100));

	//  ui->arrival_airport_lights_taxiing->setMaxLength(70);
	ui->arrival_airport_lights_taxiing->setValidator(new QIntValidator(0, 100));

	//   ui->arrival_airport_lights_illumination->setMaxLength(70);
	ui->arrival_airport_lights_illumination->setValidator(new QIntValidator(0, 100));

	//  ui->arrival_airport_other_lights->setMaxLength(70);
	ui->arrival_airport_other_lights->setValidator(new QIntValidator(0, 100));

	//    ui->takeoff_runway_border_lights->setMaxLength(70);
	ui->takeoff_runway_border_lights->setValidator(new QIntValidator(0, 100));

	//  ui->departure_airport_lights_taxiing->setMaxLength(70);
	ui->departure_airport_lights_taxiing->setValidator(new QIntValidator(0, 100));

	// ui->departure_airport_lights_illumination->setMaxLength(70);
	ui->departure_airport_lights_illumination->setValidator(new QIntValidator(0, 100));

	//   ui->departure_airport_other_lights->setMaxLength(70);
	ui->departure_airport_other_lights->setValidator(new QIntValidator(0, 100));

}

void AirportsDialog::on_takeoff_runway_border_lights_editingFinished()
{
	QString s = ui->takeoff_runway_border_lights->text();
	int tmp = s.toInt();
	//data->TAKEOFF_RUNWAY_BORDER_LIGHTS = itoa(tmp,&data->TAKEOFF_RUNWAY_BORDER_LIGHTS,10);
	qstrcpy(&data->TAKEOFF_RUNWAY_BORDER_LIGHTS, s.toLatin1());
	qDebug() << "data->TAKEOFF_RUNWAY_BORDER_LIGHTS" << (int)data->TAKEOFF_RUNWAY_BORDER_LIGHTS << "\n";
	ui->depBokLightscroll->setSliderPosition(ui->takeoff_runway_border_lights->text().toInt());

}

void AirportsDialog::on_departure_airport_lights_taxiing_editingFinished()
{
	qstrcpy(&data->DEPARTURE_AIRPORT_LIGHTS_TAXIING, qPrintable(ui->departure_airport_lights_taxiing->text()));
	qDebug() << "data->DEPARTURE_AIRPORT_LIGHTS_TAXIING" << (int)data->DEPARTURE_AIRPORT_LIGHTS_TAXIING << "\n";
	ui->depRelLightsScroll->setSliderPosition(ui->departure_airport_lights_taxiing->text().toInt());


}

void AirportsDialog::on_departure_airport_lights_illumination_editingFinished()
{
	qstrcpy(&data->DEPARTURE_AIRPORT_LIGHTS_ILLUMINATION, qPrintable(ui->departure_airport_lights_illumination->text()));
	qDebug() << "data->DEPARTURE_AIRPORT_LIGHTS_ILLUMINATION" << (int)data->DEPARTURE_AIRPORT_LIGHTS_ILLUMINATION << "\n";
	ui->depStoyankScroll->setSliderPosition(ui->departure_airport_lights_illumination->text().toInt());

}

void AirportsDialog::on_departure_airport_other_lights_editingFinished()
{
	qstrcpy(&data->DEPARTURE_AIRPORT_OTHER_LIGHTS, qPrintable(ui->departure_airport_other_lights->text()));
	qDebug() << "data->DEPARTURE_AIRPORT_OTHER_LIGHTS" << (int)data->DEPARTURE_AIRPORT_OTHER_LIGHTS << "\n";
	ui->depOtherScroll->setSliderPosition(ui->departure_airport_other_lights->text().toInt());
}

void AirportsDialog::on_arrival_airport_code_editingFinished()
{
	QString s = ui->arrival_airport_code->text();
	qstrcpy(data->ARRIVAL_AIRPORT_CODE, s.toLatin1());
	qDebug() << "data->ARRIVAL_AIRPORT_CODE" << data->ARRIVAL_AIRPORT_CODE << "\n";
}

void AirportsDialog::on_landing_runway_code_editingFinished()
{
	QString s = ui->departure_airport_code->text();
	qstrcpy(data->LANDING_RUNWAY_CODE, s.toLatin1());
	qDebug() << "data->LANDING_RUNWAY_CODE" << data->LANDING_RUNWAY_CODE << "\n";

}

void AirportsDialog::on_landing_runway_border_lights_editingFinished()
{
	qstrcpy(&data->LANDING_RUNWAY_BORDER_LIGHTS, qPrintable(ui->landing_runway_border_lights->text()));
	qDebug() << "data->LANDING_RUNWAY_BORDER_LIGHTS" << (int)data->LANDING_RUNWAY_BORDER_LIGHTS << "\n";
	ui->arrYarkBok->setSliderPosition(ui->landing_runway_border_lights->text().toInt());

}

void AirportsDialog::on_arrival_airport_lights_taxiing_editingFinished()
{
	qstrcpy(&data->ARRIVAL_AIRPORT_LIGHTS_TAXIING, qPrintable(ui->arrival_airport_lights_taxiing->text()));
	qDebug() << "data->ARRIVAL_AIRPORT_LIGHTS_TAXIING" << (int)data->ARRIVAL_AIRPORT_LIGHTS_TAXIING << "\n";
	ui->arrRulez->setSliderPosition(ui->arrival_airport_lights_taxiing->text().toInt());
}

void AirportsDialog::on_arrival_airport_lights_illumination_editingFinished()
{
	qstrcpy(&data->ARRIVAL_AIRPORT_LIGHTS_ILLUMINATION, qPrintable(ui->arrival_airport_lights_illumination->text()));
	qDebug() << "data->ARRIVAL_AIRPORT_LIGHTS_ILLUMINATION" << (int)data->ARRIVAL_AIRPORT_LIGHTS_ILLUMINATION << "\n";
	ui->arrPodsvet->setSliderPosition(ui->arrival_airport_lights_illumination->text().toInt());
}

void AirportsDialog::on_arrival_airport_other_lights_editingFinished()
{
	qstrcpy(&data->ARRIVAL_AIRPORT_OTHER_LIGHTS, qPrintable(ui->arrival_airport_other_lights->text()));
	qDebug() << "data->ARRIVAL_AIRPORT_OTHER_LIGHTS" << (int)data->ARRIVAL_AIRPORT_OTHER_LIGHTS << "\n";
	ui->arrOther->setSliderPosition(ui->arrival_airport_other_lights->text().toInt());
}

void AirportsDialog::fill_aeroport_codes()
{
	QString s = QString::fromLocal8Bit("Шереметьево (SVO/UUEE)");
	//  QString s = s1+ "";
	aeroports_codes[s].icao = "UUEE";
	aeroports_codes[s].iata = "SVO";

	aeroports_codes[QString::fromLocal8Bit("Домодедово (DME/UUDD)")].icao = "UUDD";
	aeroports_codes[QString::fromLocal8Bit("Домодедово (DME/UUDD)")].iata = "DME";

	aeroports_codes[QString::fromLocal8Bit("Внуково (VKO/UUWW)")].icao = "UUWW";
	aeroports_codes[QString::fromLocal8Bit("Внуково (VKO/UUWW)")].iata = "SVO";

	aeroports_codes[QString::fromLocal8Bit("Жуковский (ZIA/UUBW)")].icao = "UUBW";
	aeroports_codes[QString::fromLocal8Bit("Жуковский (ZIA/UUBW)")].iata = "ZIA";

	aeroports_codes[QString::fromLocal8Bit("Остафьево (OSF/UUMO)")].icao = "UUMO";
	aeroports_codes[QString::fromLocal8Bit("Остафьево (OSF/UUMO)")].iata = "OSF";

	aeroports_codes[QString::fromLocal8Bit("Лондон (LCY/EGLC)")].iata = "LCY";
	aeroports_codes[QString::fromLocal8Bit("Лондон (LCY/EGLC)")].icao = "EGLC";

	aeroports_codes[QString::fromLocal8Bit("Карловы Вары (KLV/LKKV)")].iata = "KLV";
	aeroports_codes[QString::fromLocal8Bit("Карловы Вары (KLV/LKKV)")].icao = "LKKV";

	aeroports_codes[QString::fromLocal8Bit("Тиват (TIV/LYTV)")].iata = "TIV";
	aeroports_codes[QString::fromLocal8Bit("Тиват (TIV/LYTV)")].icao = "LYTV";

	aeroports_codes[QString::fromLocal8Bit("Брюссель (BRU/EBBR)")].iata = "BRU";
	aeroports_codes[QString::fromLocal8Bit("Брюссель (BRU/EBBR)")].icao = "EBBR";

	aeroports_codes[QString::fromLocal8Bit("Венеция (VCE/LIPZ)")].iata = "VCE";
	aeroports_codes[QString::fromLocal8Bit("Венеция (VCE/LIPZ)")].icao = "LIPZ";

	aeroports_codes[QString::fromLocal8Bit("Дублин (DUB/EIBW)")].iata = "DUB";
	aeroports_codes[QString::fromLocal8Bit("Дублин (DUB/EIBW)")].icao = "EIDW";

	aeroports_codes[QString::fromLocal8Bit("Инсбрук (INN/LOWI)")].iata = "INN";
	aeroports_codes[QString::fromLocal8Bit("Инсбрук (INN/LOWI)")].icao = "LOWI";

	aeroports_codes[QString::fromLocal8Bit("Кеблавик (KEF/BIKF)")].iata = "KEF";
	aeroports_codes[QString::fromLocal8Bit("Кеблавик (KEF/BIKF)")].icao = "BIKF";

	aeroports_codes[QString::fromLocal8Bit("Комсомольск (KXK/UHKK)")].iata = "KXK";
	aeroports_codes[QString::fromLocal8Bit("Комсомольск (KXK/UHKK)")].icao = "UHKK";

	aeroports_codes[QString::fromLocal8Bit("Пулково (LED/ULLI)")].iata = "LED";
	aeroports_codes[QString::fromLocal8Bit("Пулково (LED/ULLI)")].icao = "ULLI";

	aeroports_codes[QString::fromLocal8Bit("Сочи (AER/URSS)")].iata = "AER";
	aeroports_codes[QString::fromLocal8Bit("Сочи (AER/URSS)")].icao = "URSS";

	aeroports_codes[QString::fromLocal8Bit("Толука (TLC/MMTO)")].iata = "TLC";
	aeroports_codes[QString::fromLocal8Bit("Толука (TLC/MMTO)")].icao = "MMTO";

	aeroports_codes[QString::fromLocal8Bit("Хельсинки (HEL/EFHK)")].iata = "HEL";
	aeroports_codes[QString::fromLocal8Bit("Хельсинки (HEL/EFHK)")].icao = "EFHK";

	//   qDebug()<<aeroports_codes["Шереметьево (SVO/UUEE)"].iata;
	 //  qDebug()<<aeroports_codes["Шереметьево (SVO/UUEE)"].icao;
}

void AirportsDialog::fill_flights_strips()
{
	std::vector <QString> tmp{ "07L","25R","07R","25L" };

	flight_strips[QString::fromLocal8Bit("Шереметьево (SVO/UUEE)")].insert
	(flight_strips[QString::fromLocal8Bit("Шереметьево (SVO/UUEE)")].begin(),
		tmp.begin(), tmp.end());
	//qDebug()<<flight_strips[QString::fromLocal8Bit("Шереметьево (SVO/UUEE)")];
	tmp.clear();
	tmp = { "32L","14R","32R","14L" };
	flight_strips[QString::fromLocal8Bit("Домодедово (DME/UUDD)")].insert
	(flight_strips[QString::fromLocal8Bit("Домодедово (DME/UUDD)")].begin(),
		tmp.begin(), tmp.end());

	tmp.clear();
	tmp = { "06","24","01","19" };
	flight_strips[QString::fromLocal8Bit("Внуково (VKO/UUWW)")].insert
	(flight_strips[QString::fromLocal8Bit("Внуково (VKO/UUWW)")].begin(),
		tmp.begin(), tmp.end());

	tmp.clear();
	tmp = { "12","30" };
	flight_strips[QString::fromLocal8Bit("Жуковский (ZIA/UUBW)")].insert
	(flight_strips[QString::fromLocal8Bit("Жуковский (ZIA/UUBW)")].begin(),
		tmp.begin(), tmp.end());

	tmp.clear();
	tmp = { "26","08" };
	flight_strips[QString::fromLocal8Bit("Остафьево (OSF/UUMO)")].insert
	(flight_strips[QString::fromLocal8Bit("Остафьево (OSF/UUMO)")].begin(),
		tmp.begin(), tmp.end());

	tmp.clear();
	tmp = { "09","27" };
	flight_strips[QString::fromLocal8Bit("Лондон (LCY/EGLC)")].insert
	(flight_strips[QString::fromLocal8Bit("Лондон (LCY/EGLC)")].begin(),
		tmp.begin(), tmp.end());

	tmp.clear();
	tmp = { "11","29" };
	flight_strips[QString::fromLocal8Bit("Карловы Вары (KLV/LKKV)")].insert
	(flight_strips[QString::fromLocal8Bit("Карловы Вары (KLV/LKKV)")].begin(),
		tmp.begin(), tmp.end());

	tmp.clear();
	tmp = { "14","32" };
	flight_strips[QString::fromLocal8Bit("Тиват (TIV/LYTV)")].insert
	(flight_strips[QString::fromLocal8Bit("Тиват (TIV/LYTV)")].begin(),
		tmp.begin(), tmp.end());

	tmp.clear();
	tmp = { "07L","25R","07R","25L","02","20" };
	flight_strips[QString::fromLocal8Bit("Брюссель (BRU/EBBR)")].insert
	(flight_strips[QString::fromLocal8Bit("Брюссель (BRU/EBBR)")].begin(),
		tmp.begin(), tmp.end());
	tmp.clear();
	tmp = { "04L","22R","04R","22L" };
	flight_strips[QString::fromLocal8Bit("Венеция (VCE/LIPZ)")].insert
	(flight_strips[QString::fromLocal8Bit("Венеция (VCE/LIPZ)")].begin(),
		tmp.begin(), tmp.end());

	tmp.clear();
	tmp = { "10","28","16","34","11","29" };
	flight_strips[QString::fromLocal8Bit("Дублин (DUB/EIBW)")].insert
	(flight_strips[QString::fromLocal8Bit("Дублин (DUB/EIBW)")].begin(),
		tmp.begin(), tmp.end());

	tmp.clear();
	tmp = { "08","26" };
	flight_strips[QString::fromLocal8Bit("Инсбрук (INN/LOWI)")].insert
	(flight_strips[QString::fromLocal8Bit("Инсбрук (INN/LOWI)")].begin(),
		tmp.begin(), tmp.end());

	tmp.clear();
	tmp = { "11","29","02","20" };
	flight_strips[QString::fromLocal8Bit("Кеблавик (KEF/BIKF)")].insert
	(flight_strips[QString::fromLocal8Bit("Кеблавик (KEF/BIKF)")].begin(),
		tmp.begin(), tmp.end());

	tmp.clear();
	tmp = { "36","18" };
	flight_strips[QString::fromLocal8Bit("Комсомольск (KXK/UHKK)")].insert
	(flight_strips[QString::fromLocal8Bit("Комсомольск (KXK/UHKK)")].begin(),
		tmp.begin(), tmp.end());

	tmp.clear();
	tmp = { "10L","10R","28R","28L" };
	flight_strips[QString::fromLocal8Bit("Пулково (LED/ULLI)")].insert
	(flight_strips[QString::fromLocal8Bit("Пулково (LED/ULLI)")].begin(),
		tmp.begin(), tmp.end());

	tmp.clear();
	tmp = { "06","24","02","20" };
	flight_strips[QString::fromLocal8Bit("Сочи (AER/URSS)")].insert
	(flight_strips[QString::fromLocal8Bit("Сочи (AER/URSS)")].begin(),
		tmp.begin(), tmp.end());

	tmp.clear();
	tmp = { "15","33" };
	flight_strips[QString::fromLocal8Bit("Толука (TLC/MMTO)")].insert
	(flight_strips[QString::fromLocal8Bit("Толука (TLC/MMTO)")].begin(),
		tmp.begin(), tmp.end());

	tmp.clear();
	tmp = { "04L","22R","04R","22L","15","33" };
	flight_strips[QString::fromLocal8Bit("Хельсинки (HEL/EFHK)")].insert
	(flight_strips[QString::fromLocal8Bit("Хельсинки (HEL/EFHK)")].begin(),
		tmp.begin(), tmp.end());
}

void AirportsDialog::on_ok_pb_pressed()
{
	emit sendData(this->data);
	this->close();
}

void AirportsDialog::updateScrolls()
{
	//qDebug()<<ui->takeoff_runway_border_lights->text().toInt();
	ui->depBokLightscroll->setValue(ui->takeoff_runway_border_lights->text().toInt());
	ui->depOtherScroll->setValue(ui->departure_airport_other_lights->text().toInt());
	ui->depRelLightsScroll->setValue(ui->departure_airport_lights_taxiing->text().toInt());;
	ui->depStoyankScroll->setValue(ui->departure_airport_lights_illumination->text().toInt());

	//*arrival*///
	ui->arrOther->setValue(ui->arrival_airport_other_lights->text().toInt());
	ui->arrRulez->setValue(ui->arrival_airport_lights_taxiing->text().toInt());
	ui->arrPodsvet->setValue(ui->arrival_airport_lights_illumination->text().toInt());;
	ui->arrYarkBok->setValue(ui->landing_runway_border_lights->text().toInt());

}

void AirportsDialog::on_arrivalCity_currentIndexChanged(const QString &arg1)
{
	qDebug() << "arg = " << arg1;
	//for(const auto& aer : aeroports_codes.keys())
	//  qDebug() << "aeroports_codes[" << aer <<"] = " << aeroports_codes[aer].iata <<  aeroports_codes[aer].icao;
	auto it = aeroports_codes.find(arg1);
	if (it != aeroports_codes.end())
	{
		qDebug() << "arrcityworks" << arg1 << it->icao;
		//ui->arrival_airport_code->settclear();
		ui->arrival_airport_code->setText(it->icao);
		fillStripsComboBoxArr(arg1);
		auto jt = flight_strips.find(arg1);

		/*if (jt != flight_strips.end())
		{
			ui->arrPolosa->clear();
			for (auto it : jt.value())
				ui->arrPolosa->addItem(it);

			ui->arrPolosa->setCurrentText(*jt.value().begin());
		}  */

		if (jt != flight_strips.end())
			ui->arrPolosa->setCurrentText(*jt.value().begin());
	}

	QString s = ui->arrival_airport_code->text();
	qstrcpy(data->ARRIVAL_AIRPORT_CODE, s.toLatin1());

	s.clear();
	s = ui->arrPolosa->currentText();
	qstrcpy(data->LANDING_RUNWAY_CODE, s.toLatin1());
}

void AirportsDialog::fillStripsComboBoxArr(const QString &iata)
{
	auto jt = flight_strips.find(iata);

	if (jt != flight_strips.end())
	{
		ui->arrPolosa->clear();
		for (auto it : jt.value())
			ui->arrPolosa->addItem(it);

		//	ui->arrPolosa->setCurrentText(*jt.value().begin());
	}

}

void AirportsDialog::fillStripsComboBoxDep(const QString &iata)
{
	auto jt = flight_strips.find(iata);

	if (jt != flight_strips.end())
	{
		ui->depPolosa->clear();
		for (auto it : jt.value())
			ui->depPolosa->addItem(it);

		//ui->depPolosa->setCurrentText(*jt.value().begin());
	}

}
void AirportsDialog::on_departureCity_currentIndexChanged(const QString &arg1)
{
	qDebug() << "arg = " << arg1;
	// for(const auto& aer : aeroports_codes.keys())
	//    qDebug() << "aeroports_codes[" << aer <<"] = " << aeroports_codes[aer].iata <<  aeroports_codes[aer].icao;
	auto it = aeroports_codes.find(arg1);

	if (it != aeroports_codes.end())
	{
		qDebug() << "arrcityworks" << arg1 << it->icao;
		ui->departure_airport_code->clear();
		ui->departure_airport_code->setText(it->icao);

		auto jt = flight_strips.find(arg1);
		/*ui->depPolosa->clear();
		if (jt != flight_strips.end())
		{
			for (auto it : jt.value())
				ui->depPolosa->addItem(it);

			ui->depPolosa->setCurrentText(*jt.value().begin());
		} */
		fillStripsComboBoxDep(arg1);
		if (jt != flight_strips.end())
		{
			ui->depPolosa->setCurrentText(*jt.value().begin());
		}
	}

	QString s = ui->departure_airport_code->text();
	qstrcpy(data->DEPARTURE_AIRPORT_CODE, s.toLatin1());

	s.clear();
	s = ui->depPolosa->currentText();
	qstrcpy(data->TAKEOFF_RUNWAY_CODE, s.toLatin1());
}


//arrival sliders
void AirportsDialog::on_arrYarkBok_valueChanged(int position)
{
	char dep_border = ui->arrYarkBok->value();
	ui->landing_runway_border_lights->setText(QString::number(dep_border));
	data->LANDING_RUNWAY_BORDER_LIGHTS = dep_border;
}

void AirportsDialog::on_arrRulez_valueChanged(int position)
{
	char dep_border = ui->arrRulez->value();
	ui->arrival_airport_lights_taxiing->setText(QString::number(dep_border));
	data->ARRIVAL_AIRPORT_LIGHTS_TAXIING = dep_border;
}

void AirportsDialog::on_arrPodsvet_valueChanged(int position)
{
	char dep_border = ui->arrPodsvet->value();
	ui->arrival_airport_lights_illumination->setText(QString::number(dep_border));
	data->ARRIVAL_AIRPORT_LIGHTS_ILLUMINATION = dep_border;
}

void AirportsDialog::on_arrOther_valueChanged(int position)
{
	char dep_border = ui->arrOther->value();
	ui->arrival_airport_other_lights->setText(QString::number(dep_border));
	data->ARRIVAL_AIRPORT_OTHER_LIGHTS = dep_border;
}

//departure sliders
void AirportsDialog::on_depBokLightscroll_valueChanged(int position)
{
	char dep_border = ui->depBokLightscroll->value();
	ui->takeoff_runway_border_lights->setText(QString::number(dep_border));
	data->TAKEOFF_RUNWAY_BORDER_LIGHTS = dep_border;
	//qDebug()<<dep_border<< ui->takeoff_runway_border_lights->text();
}

void AirportsDialog::on_depOtherScroll_valueChanged(int position)
{
	char dep_border = ui->depOtherScroll->value();
	ui->departure_airport_other_lights->setText(QString::number(dep_border));
	data->DEPARTURE_AIRPORT_OTHER_LIGHTS = dep_border;
	//qDebug()<<dep_border<< data->DEPARTURE_AIRPORT_OTHER_LIGHTS;
}

void AirportsDialog::on_depRelLightsScroll_valueChanged(int position)
{
	char dep_border = ui->depRelLightsScroll->value();
	ui->departure_airport_lights_taxiing->setText(QString::number(dep_border));
	data->DEPARTURE_AIRPORT_LIGHTS_TAXIING = dep_border;
	qDebug() << dep_border << data->DEPARTURE_AIRPORT_LIGHTS_TAXIING;
}

void AirportsDialog::on_depStoyankScroll_valueChanged(int value)
{
	char dep_border = ui->depStoyankScroll->value();
	ui->departure_airport_lights_illumination->setText(QString::number(dep_border));
	data->DEPARTURE_AIRPORT_LIGHTS_ILLUMINATION = dep_border;
	//qDebug()<<dep_border<< data->DEPARTURE_AIRPORT_LIGHTS_ILLUMINATION;
}


void AirportsDialog::fillRouteByICAO(QMap <QString, route_point> &answer)
{
	//QMap <QString, route_point> answer;

	answer["UUDD"].routeLat = 55.973607;
	answer["UUDD"].routeLon = 37.412512;

	answer["UUEE"].routeLat = 55.410222;
	answer["UUEE"].routeLon = 37.902443;

	answer["UUWW"].routeLat = 55.599611;
	answer["UUWW"].routeLon = 37.271236;

	answer["UUBW"].routeLat = 55.973607;
	answer["UUBW"].routeLon = 37.412512;

	answer["UUMO"].routeLat = 55.513190;
	answer["UUMO"].routeLon = 37.507440;

	answer["EGLC"].routeLat = 51.505523;
	answer["EGLC"].routeLon = 0.045733;

	answer["LKKV"].routeLat = 50.202978000000;
	answer["LKKV"].routeLon = 12.914983000000;

	answer["LYTV"].routeLat = 42.404778;
	answer["LYTV"].routeLon = 18.723146;

	answer["EBBR"].routeLat = 50.901389000000;
	answer["EBBR"].routeLon = 4.484444000000;

	answer["LIPZ"].routeLat = 45.505278;
	answer["LIPZ"].routeLon = 12.351944;

	answer["EIDW"].routeLat = 53.421389000000;
	answer["EIDW"].routeLon = -6.270000000000;

	answer["LOWI"].routeLat = 47.2602005004883;
	answer["LOWI"].routeLon = 11.3439998626709;

	answer["BIKF"].routeLat = 63.985000000000;
	answer["BIKF"].routeLon = -22.605556000000;

	answer["UHKK"].routeLat = 50.409444000000;
	answer["UHKK"].routeLon = 136.934167000000;

	answer["ULLI"].routeLat = 59.800292000000;
	answer["ULLI"].routeLon = 30.262503000000;

	answer["URSS"].routeLat = 43.449928000000;
	answer["URSS"].routeLon = 39.956589000000;

	answer["MMTO"].routeLat = 19.337072000000;
	answer["MMTO"].routeLon = -99.566008000000;

	answer["EFHK"].routeLat = 60.317222000000;
	answer["EFHK"].routeLon = 24.963333000000;

	//return answer;
}

void AirportsDialog::on_departure_airport_code_editingFinished()
{
	/*fillStripsComboBoxArr(ui->departure_airport_code->text());

	auto jt = flight_strips.find(ui->departure_airport_code->text());

	if (jt != flight_strips.end())
	{
		ui->depPolosa->clear();
		for (auto it : jt.value())
			ui->depPolosa->addItem(it);
	}  */
}
