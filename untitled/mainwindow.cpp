#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*//////////////////////////////////////////////*/
    test_udp_socket = new QUdpSocket();
    m_server = new UdpServer();
    backward_data = new _DataToModel();
    airoports_lights_data = new _AirportData();

    //*/////////////////////////////////////////////*/

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

    //read and send data via UDP

    //connect(m_server->m_receiver_socket, SIGNAL(readyRead()), m_server, SLOT(readDatagram()));
    connect(m_server, &UdpServer::newDatagram, this, &MainWindow::onNewDatagramReceived);
    connect(m_server, SIGNAL(readyRead()), m_server, SLOT(readDatagram()));

    //connect(test_udp_socket, SIGNAL(readyRead()), test_udp_socket, SLOT(readDatagram()));


    {
        qDebug()<<"rec port construct"<<ui->receivePortEdit->text().toUInt()<<ui->receivePortEdit->text().toInt();
        m_server->restartListening(ui->receivePortEdit->text().toUInt());
    }
    /*/////////////////////////////////////////////*/

    //set data from UDP
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
qDebug()<<"received backward";
    qDebug()<<"packet_id" << _data->packet_id;
    qDebug()<< "p_coord.H"<<  _data->p_coord.H ;
    qDebug()<<"p_coord.X"  << _data->p_coord.X ;
    qDebug()<<"p_coord.Z" <<  _data->p_coord.Z;
    qDebug()<<"simulation_time" <<  _data->simulation_time;
}

void MainWindow::receiveData(METEO_DATA * _data)
{
    //auto data = m_dataProvider->getMeteoData();

    deep_meteo_copy(_data, &meteo_data );

    qDebug() << meteo_data.message;
    qDebug() << meteo_data.Visibility;
    qDebug() << meteo_data.CloudBase;
    qDebug() << meteo_data.CloudUpper;
    qDebug() << meteo_data.CloudSize;
    qDebug() << meteo_data.cloudsType;
    qDebug() << meteo_data.cloudsSecondLay;
    qDebug() << meteo_data.SecLayHeight;
    qDebug() << meteo_data.Day;
    qDebug() << meteo_data.Month;
    qDebug() << meteo_data.Hours;
    qDebug() << meteo_data.Minutes;
    qDebug() << meteo_data.local_visibility;
    qDebug() << meteo_data.rain;
    qDebug() << meteo_data.snow;
    qDebug() << meteo_data.hmist;
    qDebug() << meteo_data.wind_speed;
    qDebug() << meteo_data.wind_psi;
    qDebug() << meteo_data.StarBright;
}


MainWindow::~MainWindow()
{
    delete ui;
    delete meteo_ui;
    delete aerodrom_ui;
    delete backward_ui;
}

void MainWindow::onNewDatagramReceived(const QByteArray& datagram)
{
    m_server->setDataFromReceived(datagram);
}

void MainWindow::on_receivePortEdit_editingFinished()
{
    m_server->setReceivingPort(ui->receivePortEdit->text().toInt());

    qDebug() << "receivePortEdit"<<ui->receivePortEdit->text().toInt();
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
    qDebug()<<"meteo checked";
    ui->meteoIntervalEdit->setEnabled(checked);

    if (checked)
        m_server->setSendData_METEO(&meteo_data);
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

void MainWindow::on_recDatapB_clicked()
{

}

void MainWindow::on_recDatapB_2_pressed()
{
    qDebug()<<"receive pushed";
    m_server->restartListening(ui->receivePortEdit->text().toInt());

}


