#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_server = new UdpServer();
    // backward_data = new _DataToModel();
    // airoports_lights_data = new _AirportData();

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
    connect(meteo_ui, SIGNAL(sendData(_MeteoData*)), this, SLOT(receiveData(_MeteoData*)));
    /*/////////////////////////////////////////////*/

    //read and send data via UDP
     connect(m_server, &UdpServer::newDatagram, this, &MainWindow::onNewDatagramReceived);
     connect(m_server, SIGNAL(readyRead()), m_server, SLOT(readDatagram()));
    if (ui->receivePortEdit->text().toUInt())
    {
        qDebug()<<"rec port construct"<<ui->receivePortEdit->text().toUInt()<<ui->receivePortEdit->text().toInt();
        m_server->restartListening(ui->receivePortEdit->text().toUInt());
    }
    /*/////////////////////////////////////////////*/

    //set data from UDP
    connect(m_server, SIGNAL(dataUpdated(_AirportData*)), this, SLOT(receiveData(_AirportData*)));
    connect(m_server, SIGNAL(dataUpdated(_DataToModel*)), this, SLOT(receiveData(_DataToModel*)));
    connect(m_server, SIGNAL(dataUpdated(_MeteoData*)), this, SLOT(receiveData(_MeteoData*)));
    connect(this, SIGNAL(sendUpdatedData(_MeteoData*)),meteo_ui,SLOT(writeToFields(_MeteoData*)));
    connect(this, SIGNAL(sendUpdatedData(_DataToModel*)),backward_ui,SLOT(writeToFields(_DataToModel*)));
    connect(this, SIGNAL(sendUpdatedData(_AirportData*)),aerodrom_ui,SLOT(writeToFields(_AirportData*)));

}

void MainWindow::receiveData(_AirportData *_data)
{
    airoports_lights_data.packet_id = _data->packet_id;
    airoports_lights_data.ARRIVAL_AIRPORT_LIGHTS_ILLUMINATION =  _data->ARRIVAL_AIRPORT_LIGHTS_ILLUMINATION;
    airoports_lights_data.ARRIVAL_AIRPORT_LIGHTS_TAXIING =  _data->ARRIVAL_AIRPORT_LIGHTS_TAXIING;
    airoports_lights_data.ARRIVAL_AIRPORT_OTHER_LIGHTS =  _data->ARRIVAL_AIRPORT_OTHER_LIGHTS;
    airoports_lights_data.DEPARTURE_AIRPORT_LIGHTS_ILLUMINATION =  _data->DEPARTURE_AIRPORT_LIGHTS_ILLUMINATION;
    airoports_lights_data.DEPARTURE_AIRPORT_LIGHTS_TAXIING =  _data->DEPARTURE_AIRPORT_LIGHTS_TAXIING;
    airoports_lights_data.DEPARTURE_AIRPORT_OTHER_LIGHTS =  _data->DEPARTURE_AIRPORT_OTHER_LIGHTS;
    airoports_lights_data.TAKEOFF_RUNWAY_BORDER_LIGHTS =  _data->TAKEOFF_RUNWAY_BORDER_LIGHTS;
    airoports_lights_data.LANDING_RUNWAY_BORDER_LIGHTS =  _data->LANDING_RUNWAY_BORDER_LIGHTS;

    qstrcpy(airoports_lights_data.TAKEOFF_RUNWAY_CODE, _data->TAKEOFF_RUNWAY_CODE);
    qstrcpy(airoports_lights_data.LANDING_RUNWAY_CODE, _data->LANDING_RUNWAY_CODE);
    qstrcpy(airoports_lights_data.DEPARTURE_AIRPORT_CODE, _data->DEPARTURE_AIRPORT_CODE);
    qstrcpy(airoports_lights_data.ARRIVAL_AIRPORT_CODE, _data->ARRIVAL_AIRPORT_CODE);

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
    emit sendUpdatedData(&airoports_lights_data);
}

void MainWindow::receiveData(_DataToModel *_data)
{
    backward_data.packet_id = _data->packet_id;
    backward_data.p_coord.H = _data->p_coord.H ;
    backward_data.p_coord.X  = _data->p_coord.X ;
    backward_data.p_coord.Z  = _data->p_coord.Z;
    backward_data.simulation_time = _data->simulation_time;
    qDebug()<<"received backward";
    qDebug()<<"packet_id" << _data->packet_id;
    qDebug()<< "p_coord.H"<<  _data->p_coord.H ;
    qDebug()<<"p_coord.X"  << _data->p_coord.X ;
    qDebug()<<"p_coord.Z" <<  _data->p_coord.Z;
    qDebug()<<"simulation_time" <<  _data->simulation_time;
    emit sendUpdatedData(&backward_data);

    //ui->ReceiveInfoText->appendPlainText(QString("Backward packet received"));
}

void MainWindow::receiveData(_MeteoData * _data)
{
   qDebug()<<"received meteo";
    deep_meteo_copy(_data, &meteo_data );

    qDebug() << meteo_data.packet_id;
    qDebug() << meteo_data.visibility;
    qDebug() << meteo_data.cloudBase;
    qDebug() << meteo_data.cloudUpper;
    qDebug() << meteo_data.cloudSize;
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
    qDebug() << meteo_data.starBright;

    if (ui->meteo_remchb->isChecked())
    {
        qDebug()<<"meteo upd";

        emit sendUpdatedData(&meteo_data);
    }
}


MainWindow::~MainWindow()
{
    delete ui;
    delete meteo_ui;
    delete aerodrom_ui;
    delete backward_ui;
    delete m_server;
}

void MainWindow::onNewDatagramReceived(const QByteArray& datagram)
{
    unsigned int message_type = datagram.at(0);
     qDebug()<<"setting new data from received"<<message_type;
    if (message_type ==  NPR_PACKET_TYPE_METEO_DATA || message_type ==  11)
        ui->ReceiveInfoText->appendPlainText(QString("Meteo packet received"));
    else if(message_type == NPR_PACKET_TYPE_AIRPORT_DATA)
        ui->ReceiveInfoText->appendPlainText(QString("Aerodrom lights packet received"));
    else if(message_type == NPR_PACKET_TYPE_BACK_DATA||message_type ==  10)
        ui->ReceiveInfoText->appendPlainText(QString("Backward packet received"));
    m_server->setDataFromReceived(datagram);
}

void MainWindow::on_receivePortEdit_editingFinished()
{
    m_server->setReceivingPort(ui->receivePortEdit->text().toInt());

    qDebug() << "receivePortEdit set to"<<ui->receivePortEdit->text().toInt();
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
        m_server->setSendData_AERODROMS(&airoports_lights_data);
}

void MainWindow::on_BackwardCheckBox_clicked(bool checked)
{
    ui->backwardIntervalEdit->setEnabled(checked);
    if (checked)
        m_server->setSendData_BACKWARD(&backward_data);
}

void MainWindow::on_sendOnceButton_pressed()
{
    qDebug() << "on_sendOnceButton_pressed start";
    QString message = "";
    m_server->setSendToAddress(QHostAddress(ui->sendIPEdit->text()), ui->sendPortEdit->text().toInt());

    if( ui->BackwardCheckBox->isChecked() )
         message += " backward";
    if( ui->meteoCheckBox->isChecked() )
        message += " meteo";
    if( ui->lightsCheckBox->isChecked())
        message += " aerodrom lights";
    qDebug() <<message;
    ui->SendInfoText->appendPlainText(QString("Sending"+message+" packets"));
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
    qDebug() << "sendPortEdit"<<ui->sendPortEdit->text().toInt();
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



void MainWindow::on_recDatapB_2_toggled(bool checked)
{
    qDebug()<<"rec button toggled"<<checked;
    if (checked)
    {
        qDebug()<<"topp";
        ui->recDatapB_2->setText("Stop");
        connect(m_server, SIGNAL(readyRead()), m_server, SLOT(readDatagram()));

        //if (m_server->setReceivingPort(ui->receivePortEdit->text().toUInt()))
        {
            QString message = "Listening on " + ui->receivePortEdit->text() +" port";
            ui->ReceiveInfoText->appendPlainText(message);
            m_server->restartListening(ui->receivePortEdit->text().toInt());
m_server->keep_recieve = true;
            qDebug()<<"connect checkstate"<<ui->meteo_remchb->checkState();
            meteo_ui->set_from_net = true;
        }
    }
    else
    {
        ui->recDatapB_2->setText("Start receive");
       // m_server->setReceivingPort(0);
      m_server->keep_recieve = false;
        qDebug()<<"rec port now is "<<m_server->getReceivingPort();
        QString message = "Stopped listening on " + ui->receivePortEdit->text() +" port";
        ui->ReceiveInfoText->appendPlainText(message);
    }
}

void MainWindow::on_meteo_remchb_toggled(bool checked)
{
    if (ui->meteo_remchb->isChecked())
    {
        qDebug()<<"sending to meteo ui";
        emit sendUpdatedData(&meteo_data);
    }
    else
    {
        qDebug()<<"blocking signals";
        blockSignals(m_server);
}
}
