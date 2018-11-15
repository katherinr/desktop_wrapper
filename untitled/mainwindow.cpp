#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "utilities.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_server = new UdpServer();
    //*/////////////////////////////////////////////*/

    meteo_ui = new meteoWindow;
    deep_meteo_copy(meteo_ui->data, &meteo_data );
  //  meteo_data.packet_id = 202;
    aerodrom_ui = new AirportsDialog;
    backward_ui = new backwardW;
    mainvis_ui = new MainVisual;

    /*/////////////////////////////////////////////*/
    //show subwindows

    connect(ui->meteoPushButton, SIGNAL(clicked()), meteo_ui, SLOT(show()));
    connect(ui->AerodromsLightsPB, SIGNAL(clicked()), aerodrom_ui, SLOT(show()));
    connect(ui->CorrectPB, SIGNAL(clicked()), backward_ui, SLOT(show()));
    connect(ui->mainVisPushButton, SIGNAL(clicked()), mainvis_ui, SLOT(show()));
    /*/////////////////////////////////////////////*/
    //receive data from subwindows
    connect(aerodrom_ui, SIGNAL(sendData(_AirportData*)), this, SLOT(receiveData(_AirportData*)));
    connect(backward_ui, SIGNAL(sendData(_DataToModel*)), this, SLOT(receiveData(_DataToModel*)));
    connect(meteo_ui, SIGNAL(sendData(_MeteoData*)), this, SLOT(receiveData(_MeteoData*)));
    connect(mainvis_ui, SIGNAL(sendData(_MainVisualData*)), this, SLOT(receiveData(_MainVisualData*)));
    /*/////////////////////////////////////////////*/
    //read and send data via UDP
    connect(m_server, &UdpServer::newDatagram, this, &MainWindow::onNewDatagramReceived);
    connect(m_server, SIGNAL(readyRead()), m_server, SLOT(readDatagram()));

    //  if (ui->receivePortEdit->text().toUInt())
    {
        //   qDebug()<<"rec port construct"<<ui->receivePortEdit->text().toUInt()<<ui->receivePortEdit->text().toInt();
        // m_server->restartListening(ui->receivePortEdit->text().toUInt());
    }
    /*/////////////////////////////////////////////*/

    //set data from UDP
    connect(m_server, SIGNAL(dataUpdated(_AirportData*)), this, SLOT(receiveData(_AirportData*)));
    connect(m_server, SIGNAL(dataUpdated(_DataToModel*)), this, SLOT(receiveData(_DataToModel*)));
    connect(m_server, SIGNAL(dataUpdated(_MeteoData*)), this, SLOT(receiveData(_MeteoData*)));
    connect(m_server, SIGNAL(dataUpdated(_MainVisualData*)), this, SLOT(receiveData(_MainVisualData*)));

    connect(this, SIGNAL(sendUpdatedData(_MeteoData*)),meteo_ui,SLOT(writeToFields(_MeteoData*)));
    connect(this, SIGNAL(sendUpdatedData(_DataToModel*)),backward_ui,SLOT(writeToFields(_DataToModel*)));
    connect(this, SIGNAL(sendUpdatedData(_AirportData*)),aerodrom_ui,SLOT(writeToFields(_AirportData*)));
    connect(this, SIGNAL(sendUpdatedData(_MainVisualData*)),mainvis_ui,SLOT(setDataToShow(_MainVisualData*)));
	
	mainvis_ui->setDataFromDefaut(&visual_data);  
	meteo_ui->setDataFromDefaultMeteo();
	deep_meteo_copy(meteo_ui->data, &meteo_data);
	
	aerodrom_ui->readDefault(&airoports_lights_data);
	backward_ui->readDefault(&backward_data);


}

void MainWindow::receiveData(_AirportData *_data)
{
    airoports_lights_data.packet_id =NPR_PACKET_TYPE_AIRPORT_DATA;
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

    qDebug() <<"RECEIVED AERO DATA";
    printAeroData(_data);
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
    _data->packet_id = NPR_PACKET_TYPE_METEO_DATA;
    deep_meteo_copy(_data, &meteo_data_from_model);
    printMeteo(_data);

    if (ui->meteoComboBox->currentIndex()==1)
    {
        qDebug()<<"meteo sending";
        meteo_ui->set_from_net = true;
        meteo_data.packet_id = NPR_PACKET_TYPE_METEO_DATA;
        emit sendUpdatedData(&meteo_data_from_model);
    }
    else
    {
        //block signals
    }
}

void MainWindow::receiveData(_MainVisualData * data)
{
	visual_data.packet_id = NPR_PACKET_TYPE_VISUAL_DATA;

	qDebug() << "setting visual data from received";
	visual_data.num_correct = data->num_correct;
	visual_data.p_coord.X = data->p_coord.X;
	visual_data.p_coord.Z = data->p_coord.Z;
	visual_data.p_coord.H = data->p_coord.H;

	visual_data.p_angle.C = data->p_angle.C;
	visual_data.p_angle.P = data->p_angle.P;
	visual_data.p_angle.R = data->p_angle.R;

	//обороты
	visual_data.N2_L =data->N2_L;
	visual_data.N2_R = data->N2_R;

	//stabs, mechs
	visual_data.Flaps = data->Flaps;
	visual_data.Stabilizer = data->Stabilizer;
	visual_data.Slats = data->Slats;

	visual_data.Elevator_L = data->Elevator_L;
	visual_data.Elevator_R = data->Elevator_R;
	visual_data.Aileron_L = data->Aileron_L;
	visual_data.Aileron_R = data->Aileron_R;
	visual_data.Rudder = data->Rudder;

	visual_data.Spoiler_L_CE = data->Spoiler_L_CE;
	visual_data.Spoiler_L_IN = data->Spoiler_L_IN;
	visual_data.Spoiler_L_OB = data->Spoiler_L_OB;
	visual_data.Spoiler_R_CE = data->Spoiler_R_CE;
	visual_data.Spoiler_R_IN = data->Spoiler_R_IN;
	visual_data.Spoiler_R_OB = data->Spoiler_R_OB;

	visual_data.GroudSpoiler_L_IB = data->GroudSpoiler_L_IB;
	visual_data.GroudSpoiler_L_OB = data->GroudSpoiler_L_OB;
	visual_data.GroudSpoiler_R_IB = data->GroudSpoiler_R_IB;
	visual_data.GroudSpoiler_R_OB = data->GroudSpoiler_R_OB;
	visual_data.Spoiler_R_IN = data->Spoiler_R_IN;
	visual_data.Gear_N = data->Gear_N;
	visual_data.Gear_L = data->Gear_L;
	visual_data.Gear_R = data->Gear_R;
	visual_data.Gear_SteeringAngle = data->Gear_SteeringAngle;

	//бортовые огни
	visual_data.LandingLights = data->LandingLights;
	visual_data.TaxiLight = data->TaxiLight;
	visual_data.RunwayTurnoffLights = data->RunwayTurnoffLights;
	visual_data.NavigationLightGreen = data->NavigationLightGreen;
	visual_data.NavigationLightRed = data->NavigationLightRed;
	visual_data.NavigationLightWhite = data->NavigationLightWhite;
	visual_data.AntiCollisionBeaconWhite = data->AntiCollisionBeaconWhite;
	visual_data.AntiCollisionBeaconRed = data->AntiCollisionBeaconRed;
	visual_data.InternalLights = data->InternalLights;
}


MainWindow::~MainWindow()
{
    delete ui;
    delete meteo_ui;
    delete aerodrom_ui;
    delete backward_ui;
    delete mainvis_ui;
    delete m_server;
}

void MainWindow::onNewDatagramReceived(const QByteArray& datagram)
{
    unsigned int message_type = datagram.at(0);
    qDebug()<<"setting new data from received"<<message_type;
    /*if (message_type ==  NPR_PACKET_TYPE_METEO_DATA || message_type ==  11)
        ui->SendInfoText->appendPlainText(QString("Meteo packet received"));
    else if(message_type == NPR_PACKET_TYPE_AIRPORT_DATA)
        ui->SendInfoText->appendPlainText(QString("Aerodrom lights packet received"));
    else if(message_type == NPR_PACKET_TYPE_BACK_DATA||message_type ==  10)
        ui->SendInfoText->appendPlainText(QString("Backward packet received"));
   */ m_server->setDataFromReceived(datagram);
}

void MainWindow::on_receivePortEdit_editingFinished()
{
    m_server->setReceivingPort(ui->receivePortEdit->text().toInt());

    qDebug() << "receivePortEdit set to"<<ui->receivePortEdit->text().toInt();
}

void MainWindow::on_mainVisCheckBox_toggled(bool checked)
{
    ui->mainVisIntervalEdit->setEnabled(checked);
    ui->mainVisIntervalEdit->setText("0.01");

    m_server->changeTimerInterval("visTimer",ui->mainVisIntervalEdit->text().toUInt() );
    if (checked)
        m_server->setSendData_VISUAL(&visual_data);
}


void MainWindow::on_lightsCheckBox_toggled(bool checked)
{
    ui->aerodromsIntervalEdit->setEnabled(checked);
    ui->aerodromsIntervalEdit->setText("5");
    m_server->changeTimerInterval("aerodromsTimer",ui->aerodromsIntervalEdit->text().toUInt() );

    if (checked)
        m_server->setSendData_AERODROMS(&airoports_lights_data);
}

/*void MainWindow::on_BackwardCheckBox_clicked(bool checked)
{
 //   ui->back->setEnabled(checked);
    if (checked)
        m_server->setSendData_BACKWARD(&backward_data);
}*/


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

void MainWindow::on_sendOnceButton_clicked()
{
    qDebug() << "on_sendOnceButton_pressed start";
    QString message = "";
    m_server->setSendToAddress(QHostAddress(ui->sendIPEdit->text()), ui->sendPortEdit->text().toInt());

    if( ui->backwReceive->isChecked() )
    {
        // emit sendUpdatedData(&backward_data);
        message += " backward";
    }
    if( ui->meteoCheckBox->isChecked() )
    {
        //emit sendUpdatedData(&meteo_data);
        message += " meteo";
    }
    if( ui->lightsCheckBox->isChecked())
    {
        // emit sendUpdatedData(&airoports_lights_data);
        message += " aerodrom lights";
    }//qDebug() <<message;

    //ui->SendInfoText->appendPlainText(QString("Sending"+message+" packets"));
    qDebug() <<"sending once" <<message;
    m_server->sendOnce();
}

void MainWindow::on_stopPB_clicked()
{
    qDebug()<<"stop button toggled";
	//m_server->m_time.();

    ui->startPB->setEnabled(true);
    ui->sendOnceButton->setEnabled(true);
    ui->sendOnceButton->setEnabled(true);
    ui->startPB->setEnabled(true);
    ui->receivePortEdit->setEnabled(true);
    ui->receivePortEdit_2->setEnabled(true);
    ui->backwIPedit->setEnabled(true);
    ui->backwPortEdit-> setEnabled(true);
    ui->CHANgeVisgroupBox->setEnabled(true);
    ui->startPB->setEnabled(true);

    m_server->keep_recieve = false;

    qDebug()<<"rec port now is "<<m_server->getReceivingPort();
    // qDebug()<<"send port now is "<<m_server->;

    QString message = "Stopped listening on " + ui->receivePortEdit->text() +" port";
    //ui->SendInfoText->appendPlainText(message);

    m_server->stopSending();
    qDebug()<<"blocking signals";
    blockSignals(m_server);
}

void MainWindow::on_routePushB_clicked()
{
    //open route window
}

void MainWindow::on_meteoCheckBox_toggled(bool checked)
{
    qDebug()<<"meteo checked";
    ui->meteoIntervalEdit->setEnabled(checked);
    ui->meteoIntervalEdit->setText("5");

    m_server->changeTimerInterval("meteoTimer", ui->meteoIntervalEdit->text().toUInt() );

    if (checked)
    {
        qDebug()<<"meteo set send";
        printMeteo(&meteo_data);
        m_server->setSendData_METEO(&meteo_data);
    }
    /*
    if (checked)
    {
        qDebug()<<"sending to meteo ui";
        emit sendUpdatedData(&meteo_data);
    }
    else
    {
        qDebug()<<"blocking signals";
        blockSignals(m_server);
    }*/
}

void MainWindow::on_mainiComboBox_currentIndexChanged(int index)
{
    if (index==0)
    {
        qDebug()<<"sending to vis ui";
        emit sendUpdatedData(&visual_data);
    }
}

void MainWindow::on_meteoComboBox_currentIndexChanged(int index)
{
    if (index==0)
    {
        qDebug()<<"sending to meteo ui";
        emit sendUpdatedData(&meteo_data);
    }
}

void MainWindow::on_startPB_clicked()
{
    qDebug()<<"start sending?receiving check";
    connect(m_server, SIGNAL(readyRead()), m_server, SLOT(readDatagram()));
	m_server->m_time.start();
    ui->sendOnceButton->setEnabled(false);
    ui->startPB->setEnabled(false);
    ui->receivePortEdit->setEnabled(false);
    ui->receivePortEdit_2->setEnabled(false);
    ui->backwIPedit->setEnabled(false);
    ui->backwPortEdit-> setEnabled(false);
    ui->CHANgeVisgroupBox->setEnabled(false);
    ui->startPB->setEnabled(false);

    if (m_server->setReceivingPort(ui->receivePortEdit->text().toUInt()))
    {
        QString message = "Listening on " + ui->receivePortEdit->text() +" port";
        //ui->SendInfoText->appendPlainText(message);
        m_server->restartListening(ui->receivePortEdit->text().toInt());
        m_server->keep_recieve = true;
        // qDebug()<<"connect checkstate"<<ui->->checkState();
        // meteo_ui->set_from_net = true;
    }

    if (m_server->setSendingPort(ui->receivePortEdit->text().toUInt()))
    {
        m_server->setSendToAddress(QHostAddress(ui->sendIPEdit->text()), ui->sendPortEdit->text().toInt());
        m_server->changeTimerInterval("visTimer", ui->mainVisIntervalEdit->text().toUInt());
        m_server->changeTimerInterval("meteoTimer", ui->meteoIntervalEdit->text().toUInt());
        m_server->changeTimerInterval("aerodromsTimer", ui->aerodromsIntervalEdit->text().toUInt());

        if (ui->backwardChkBox->isChecked())
        {
            //куда слать обратный пакет
            m_server->changeTimerInterval("backwardTimer", ui->mainVisIntervalEdit->text().toUInt());
        }

        m_server->startSending();
    }
}

void MainWindow::on_send2mapchb_toggled(bool checked)
{
    if (checked)
        ui->send2mapIE->setEnabled(true);
    else
        ui->send2mapIE->setEnabled(false);
}
