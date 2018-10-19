#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

void deep_meteo_copy(METEO_DATA *_data,METEO_DATA *data )
{
    data->message = _data->message;
    data->Visibility = _data->Visibility;
    data->CloudBase = _data->CloudBase;
    data->CloudUpper = _data->CloudUpper;
    data->CloudSize = _data->CloudSize;
    data->cloudsType = _data->cloudsType;
    data->cloudsSecondLay = _data->cloudsSecondLay;
    data->SecLayHeight = _data->SecLayHeight;
    data->Day = _data->Day;
    data->Month = _data->Month;
    data->Hours = _data->Hours;
    data->Minutes = _data->Minutes;
    data->local_visibility = _data->local_visibility;
    data->rain = _data->rain;
    data->snow = _data->snow;
    data->hmist = _data->hmist;
    data->wind_speed = _data->wind_speed;
    data->wind_psi = _data->wind_psi;
    data->StarBright = _data->StarBright;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*//////////////////////////////////////////////*/

    m_server = new UdpServer(this);
    backward_data = new _DataToModel();
    meteo_data = new METEO_DATA();
    airoports_lights_data = new _AirportData();

    connect(ui->sendOnceButton, SIGNAL(clicked()), m_server, SLOT(m_server->sendOnce));
    connect(ui->startStopSendButton, SIGNAL(clicked()), m_server, SLOT(m_server->processDatagram()));
    /*/////////////////////////////////////////////*/

    meteo_ui = new meteoWindow;
    aerodrom_ui = new AirportsDialog;
    backward_ui = new backwardW;

    /*/////////////////////////////////////////////*/
    //show subwindows

    connect(ui->meteoPushButton, SIGNAL(clicked()), meteo_ui, SLOT(show()));
    connect(ui->AerodromsLightsPB, SIGNAL(clicked()), aerodrom_ui, SLOT(show()));
    connect(ui->CorrectPB, SIGNAL(clicked()), backward_ui, SLOT(show()));

    /*/////////////////////////////////////////////*/
    //receive data from subwindows
    connect(aerodrom_ui, SIGNAL(sendData(_AirportData*)), this, SLOT(receiveData(_AirportData*)));
    connect(backward_ui, SIGNAL(sendData(_DataToModel*)), this, SLOT(receiveData(_DataToModel*)));
    connect(meteo_ui, SIGNAL(sendData(METEO_DATA*)), this, SLOT(receiveData(METEO_DATA*)));

    /*/////////////////////////////////////////////*/
    //receive data from UDP
    connect(m_server, SIGNAL(dataUpdated(_AirportData*)), this, SLOT(receiveData(_AirportData*)));
    connect(m_server, SIGNAL(dataUpdated(_DataToModel*)), this, SLOT(receiveData(_DataToModel*)));
    connect(m_server, SIGNAL(dataUpdated(METEO_DATA*)), this, SLOT(receiveData(METEO_DATA*)));

}

void MainWindow::receiveData(_AirportData *_data)
{
    airoports_lights_data->packet_id = _data->packet_id;
    airoports_lights_data->ARRIVAL_AIRPORT_LIGHTS_ILLUMINATION =  _data->ARRIVAL_AIRPORT_LIGHTS_ILLUMINATION;
    airoports_lights_data->ARRIVAL_AIRPORT_LIGHTS_TAXIING =  _data->ARRIVAL_AIRPORT_LIGHTS_TAXIING;
    airoports_lights_data->ARRIVAL_AIRPORT_OTHER_LIGHTS =  _data->ARRIVAL_AIRPORT_OTHER_LIGHTS;
    airoports_lights_data->DEPARTURE_AIRPORT_LIGHTS_ILLUMINATION =  _data->DEPARTURE_AIRPORT_LIGHTS_ILLUMINATION;
    airoports_lights_data->DEPARTURE_AIRPORT_LIGHTS_TAXIING =  _data->DEPARTURE_AIRPORT_LIGHTS_TAXIING;
    airoports_lights_data->DEPARTURE_AIRPORT_OTHER_LIGHTS =  _data->DEPARTURE_AIRPORT_OTHER_LIGHTS;
    airoports_lights_data->TAKEOFF_RUNWAY_BORDER_LIGHTS =  _data->TAKEOFF_RUNWAY_BORDER_LIGHTS;
    airoports_lights_data->LANDING_RUNWAY_BORDER_LIGHTS =  _data->LANDING_RUNWAY_BORDER_LIGHTS;

    qstrcpy(airoports_lights_data->TAKEOFF_RUNWAY_CODE, _data->TAKEOFF_RUNWAY_CODE);
    qstrcpy(airoports_lights_data->LANDING_RUNWAY_CODE, _data->LANDING_RUNWAY_CODE);
    qstrcpy(airoports_lights_data->DEPARTURE_AIRPORT_CODE, _data->DEPARTURE_AIRPORT_CODE);
    qstrcpy(airoports_lights_data->ARRIVAL_AIRPORT_CODE, _data->ARRIVAL_AIRPORT_CODE);

    qDebug() << "airoports_lights_data->ARRIVAL_AIRPORT_LIGHTS_ILLUMINATION"<<airoports_lights_data->ARRIVAL_AIRPORT_LIGHTS_ILLUMINATION;
    qDebug() << airoports_lights_data->ARRIVAL_AIRPORT_LIGHTS_TAXIING;
    qDebug() <<airoports_lights_data->ARRIVAL_AIRPORT_OTHER_LIGHTS;
    qDebug() << airoports_lights_data->DEPARTURE_AIRPORT_LIGHTS_ILLUMINATION;
    qDebug() << airoports_lights_data->DEPARTURE_AIRPORT_LIGHTS_TAXIING;
    qDebug() << airoports_lights_data->DEPARTURE_AIRPORT_OTHER_LIGHTS;
    qDebug() << airoports_lights_data->TAKEOFF_RUNWAY_BORDER_LIGHTS;
    qDebug() << airoports_lights_data->LANDING_RUNWAY_BORDER_LIGHTS;
    qDebug() << airoports_lights_data->LANDING_RUNWAY_CODE;
    qDebug() << airoports_lights_data->TAKEOFF_RUNWAY_CODE;
    qDebug() << airoports_lights_data->DEPARTURE_AIRPORT_CODE;
    qDebug() << airoports_lights_data->ARRIVAL_AIRPORT_CODE;
    qDebug() << airoports_lights_data->packet_id;

    qDebug() <<"airoports_lights_data->packet_id"<< _data->packet_id;
    qDebug() <<"ARRIVAL_AIRPORT_LIGHTS_ILLUMINATION" <<  _data->ARRIVAL_AIRPORT_LIGHTS_ILLUMINATION;
    qDebug() <<"ARRIVAL_AIRPORT_LIGHTS_TAXIING"<<  _data->ARRIVAL_AIRPORT_LIGHTS_TAXIING;
    qDebug() <<"ARRIVAL_AIRPORT_OTHER_LIGHTS" << _data->ARRIVAL_AIRPORT_OTHER_LIGHTS;
    qDebug() <<"DEPARTURE_AIRPORT_LIGHTS_ILLUMINATION" <<  _data->DEPARTURE_AIRPORT_LIGHTS_ILLUMINATION;
    qDebug() <<"DEPARTURE_AIRPORT_LIGHTS_TAXIING"<< _data->DEPARTURE_AIRPORT_LIGHTS_TAXIING;
    qDebug() <<"DEPARTURE_AIRPORT_OTHER_LIGHTS"<<  _data->DEPARTURE_AIRPORT_OTHER_LIGHTS;
    qDebug() <<"TAKEOFF_RUNWAY_BORDER_LIGHTS" <<  _data->TAKEOFF_RUNWAY_BORDER_LIGHTS;
    qDebug() <<"LANDING_RUNWAY_BORDER_LIGHTS" <<  _data->LANDING_RUNWAY_BORDER_LIGHTS;
    qDebug() << "LANDING_RUNWAY_CODE"<<  _data->LANDING_RUNWAY_BORDER_LIGHTS;
    qDebug() << "TAKEOFF_RUNWAY_CODE"<<_data->TAKEOFF_RUNWAY_CODE;
    qDebug() << "DEPARTURE_AIRPORT_CODE"<<  _data->DEPARTURE_AIRPORT_CODE;;
    qDebug() << "ARRIVAL_AIRPORT_CODE"<<_data->TAKEOFF_RUNWAY_CODE;
    qDebug() <<"pid"<< _data->packet_id;

}

void MainWindow::receiveData(_DataToModel *_data)
{
    backward_data->packet_id = _data->packet_id;
    backward_data->p_coord.H = _data->p_coord.H ;
    backward_data->p_coord.X  = _data->p_coord.X ;
    backward_data->p_coord.Z  = _data->p_coord.Z;
    backward_data->simulation_time = _data->simulation_time;

    qDebug()<<"packet_id" << _data->packet_id;
    qDebug()<< "p_coord.H"<<  _data->p_coord.H ;
    qDebug()<<"p_coord.X"  << _data->p_coord.X ;
    qDebug()<<"p_coord.Z" <<  _data->p_coord.Z;
    qDebug()<<"simulation_time" <<  _data->simulation_time;
}

void MainWindow::receiveData(METEO_DATA * _data)
{
    //auto data = m_dataProvider->getMeteoData();

    meteo_data->message = _data->message;
    meteo_data->Visibility = _data->Visibility;
    meteo_data->CloudBase = _data->CloudBase;
    meteo_data->CloudUpper = _data->CloudUpper;
    meteo_data->CloudSize = _data->CloudSize;
    meteo_data->cloudsType = _data->cloudsType;
    meteo_data->cloudsSecondLay = _data->cloudsSecondLay;
    meteo_data->SecLayHeight = _data->SecLayHeight;
    meteo_data->Day = _data->Day;
    meteo_data->Month = _data->Month;
    meteo_data->Hours = _data->Hours;
    meteo_data->Minutes = _data->Minutes;
    meteo_data->local_visibility = _data->local_visibility;
    meteo_data->rain = _data->rain;
    meteo_data->snow = _data->snow;
    meteo_data->hmist = _data->hmist;
    meteo_data->wind_speed = _data->wind_speed;
    meteo_data->wind_psi = _data->wind_psi;
    meteo_data->StarBright = _data->StarBright;
    qDebug() << meteo_data->message;
    qDebug() << meteo_data->Visibility;
    qDebug() << meteo_data->CloudBase;
    qDebug() << meteo_data->CloudUpper;
    qDebug() << meteo_data->CloudSize;
    qDebug() << meteo_data->cloudsType;
    qDebug() << meteo_data->cloudsSecondLay;
    qDebug() << meteo_data->SecLayHeight;
    qDebug() << meteo_data->Day;
    qDebug() << meteo_data->Month;
    qDebug() << meteo_data->Hours;
    qDebug() << meteo_data->Minutes;
    qDebug() << meteo_data->local_visibility;
    qDebug() << meteo_data->rain;
    qDebug() << meteo_data->snow;
    qDebug() << meteo_data->hmist;
    qDebug() << meteo_data->wind_speed;
    qDebug() << meteo_data->wind_psi;
    qDebug() << meteo_data->StarBright;
}


MainWindow::~MainWindow()
{
    delete ui;
    delete meteo_ui;
    delete aerodrom_ui;
    delete backward_ui;
}

void MainWindow::on_receivePortEdit_editingFinished()
{
    m_server->setReceivingPort(ui->receivePortEdit->text().toInt());
    qDebug() << "osendPortEdit"<<ui->receivePortEdit->text().toInt();
}

void MainWindow::on_startStopSendButton_toggled(bool checked)
{
    if (checked)
    {
        ui->startStopSendButton->setText("Stop");
        m_server->setSendToAddress(QHostAddress(ui->sendIPEdit->text()), ui->sendPortEdit->text().toInt());
        // m_server->changeTimerInterval("meteoTimer", ui->meteoIntervalEdit->text().toUInt());
        m_server->startSending();
        ui->sendOnceButton->setEnabled(false);
    }
    else
    {
        ui->startStopSendButton->setText("Start send");
        m_server->stopSending();
        ui->sendOnceButton->setEnabled(true);
    }
}

void MainWindow::on_mainVisCheckBox_toggled(bool checked)
{
    ui->mainVisIntervalEdit->setEnabled(checked);
    //   m_server->setSendData_VIS(meteo_data);
}

void MainWindow::on_meteoCheckBox_clicked(bool checked)
{
    ui->meteoIntervalEdit->setEnabled(checked);

    if (checked)
        m_server->setSendData_METEO(meteo_data);
}

void MainWindow::on_lightsCheckBox_clicked(bool checked)
{
    ui->lightsIntervalEdit->setEnabled(checked);
    if (checked)
        m_server->setSendData_AERODROMS(airoports_lights_data);
}

void MainWindow::on_BackwardCheckBox_clicked(bool checked)
{
    ui->backwardIntervalEdit->setEnabled(checked);
    if (checked)
        m_server->setSendData_BACKWARD(backward_data);
}

void MainWindow::on_sendOnceButton_pressed()
{
    qDebug() << "on_sendOnceButton_pressed start";
    m_server->setSendToAddress(QHostAddress(ui->sendIPEdit->text()), ui->sendPortEdit->text().toInt());
    m_server->sendOnce();
    qDebug() << "on_sendOnceButton_pressed finish";
}

void MainWindow::on_sendIPEdit_editingFinished()
{
    m_server->setAddress2Send(QHostAddress(ui->sendIPEdit->text()));
    qDebug() << "setAddress2Send"<<QHostAddress(ui->sendIPEdit->text());
}

void MainWindow::on_sendPortEdit_editingFinished()
{
    m_server->setSendingPort(ui->sendPortEdit->text().toInt());
    qDebug() << "osendPortEdit"<<ui->sendPortEdit->text().toInt();
}

void MainWindow::on_okPB_pressed()
{
    //save to files? ask smth?
    this->close();
}

void MainWindow::on_CancelPB_clicked()
{
    //no saving
    this->close();
}
