#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "utilities.h"

#define DATA_FROM_MODEL 0
#define USER_DATA_CHOICE 1

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    time_from_start.start();
    m_server = new UdpServer();
    //*/////////////////////////////////////////////*/

    meteo_ui = new meteoWindow;
    deep_meteo_copy(meteo_ui->data, &meteo_data);
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
    //connect(m_server, &UdpServer::newDatagram, this, &MainWindow::onNewDatagramReceived);
    connect(m_server, SIGNAL(readyRead()), m_server, SLOT(readDatagram()));

    /*/////////////////////////////////////////////*/

    //set data from UDP
    connect(m_server, SIGNAL(dataUpdated(_AirportData*)), this, SLOT(receiveDatafromModel(_AirportData*)));
    connect(m_server, SIGNAL(dataUpdated(_DataToModel*)), this, SLOT(receiveDatafromModel(_DataToModel*)));
    connect(m_server, SIGNAL(dataUpdated(_MeteoData*)), this, SLOT(receiveDatafromModel(_MeteoData*)));
    connect(m_server, SIGNAL(dataUpdated(_MainVisualData*)), this, SLOT(receiveDatafromModel(_MainVisualData*)));

    connect(this, SIGNAL(sendUpdatedData(_MeteoData*)), meteo_ui, SLOT(writeToFields(_MeteoData*)));
    connect(this, SIGNAL(sendUpdatedData(_DataToModel*)), backward_ui, SLOT(writeToFields(_DataToModel*)));
    connect(this, SIGNAL(sendUpdatedData(_AirportData*)), aerodrom_ui, SLOT(writeToFields(_AirportData*)));
    connect(this, SIGNAL(sendUpdatedData(_MainVisualData*)), mainvis_ui, SLOT(setDataToShow(_MainVisualData*)));

    mainvis_ui->setDataFromDefaut(&visual_data);
    meteo_ui->setDataFromDefaultMeteo();
    deep_meteo_copy(meteo_ui->data, &meteo_data);

    aerodrom_ui->readDefault(&airoports_lights_data);
    backward_ui->readDefault(&backward_data);

    //clear model data pointers
    flushMeteoData(&meteo_data_from_model);
    flushaEROData(&airoports_lights_data_from_model);
    flushVISUALData(visual_data_from_model);

    readConfig();

    QString timer_text = "T = " + QString::number(time_from_start.elapsed() / 1000) + " c";
    QMainWindow::statusBar()->showMessage(timer_text);
}

void MainWindow::receiveData(_AirportData *_data)
{
    deepAeroportcopy(_data, &airoports_lights_data);
    if (ui->aerodrCB->currentIndex() == USER_DATA_CHOICE)
        aerodrom_ui->writeToFields(_data);

}

void MainWindow::receiveData(_DataToModel *_data)
{
    backward_data.packet_id = _data->packet_id;
    backward_data.p_coord.H = _data->p_coord.H;
    backward_data.p_coord.X = _data->p_coord.X;
    backward_data.p_coord.Z = _data->p_coord.Z;
    backward_data.simulation_time = _data->simulation_time;

    qDebug() << "received backward";
    qDebug() << "packet_id" << _data->packet_id;
    qDebug() << "p_coord.H" << _data->p_coord.H;
    qDebug() << "p_coord.X" << _data->p_coord.X;
    qDebug() << "p_coord.Z" << _data->p_coord.Z;
    qDebug() << "simulation_time" << _data->simulation_time;

    emit sendUpdatedData(&backward_data);

}

void MainWindow::receiveData(_MeteoData * _data)
{
    deep_meteo_copy(_data, &meteo_data);
    meteo_ui->set_from_net = false;
    if (ui->meteoComboBox->currentIndex() == USER_DATA_CHOICE)
        meteo_ui->writeToFields(_data);
}

void MainWindow::receiveData(_MainVisualData * _data)
{
    deepVisualCopy(_data, &visual_data);
    if (ui->mainiComboBox->currentIndex() == USER_DATA_CHOICE)
        mainvis_ui->setDataToShow(_data);
}

//from model
void MainWindow::receiveDatafromModel(_AirportData *_data)
{
    deepAeroportcopy(_data, &airoports_lights_data_from_model);
    if (ui->aerodrCB->currentIndex() == DATA_FROM_MODEL)
        aerodrom_ui->writeToFields(_data);
}

void MainWindow::receiveDatafromModel(_MeteoData * _data)
{
    deep_meteo_copy(_data, &meteo_data_from_model);
    meteo_ui->set_from_net = true;
    if (ui->meteoComboBox->currentIndex() == DATA_FROM_MODEL)
        meteo_ui->writeToFields(_data);
}

void MainWindow::receiveDatafromModel(_MainVisualData * _data)
{
    deepVisualCopy(_data, &visual_data_from_model);
    if (ui->mainiComboBox->currentIndex() == DATA_FROM_MODEL)
        mainvis_ui->setDataToShow(_data);
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
    unsigned char message_type = datagram.at(0);
    qDebug() << "setting new data from received" << message_type;
    if (message_type == NPR_PACKET_TYPE_METEO_DATA)
        MainWindow::statusBar()->showMessage(tr("Meteo packet received"));
    if (message_type == NPR_PACKET_TYPE_AIRPORT_DATA)
        MainWindow::statusBar()->showMessage(tr("Aerodrom lights packet received"));
    if (message_type == NPR_PACKET_TYPE_VISUAL_DATA)
        MainWindow::statusBar()->showMessage(tr("Visual packet received"));


    m_server->setDataFromReceived(datagram);
}

void MainWindow::on_receivePortEdit_editingFinished()
{
    m_server->setReceivingPort(ui->receivePortEdit->text().toInt());

    qDebug() << "receivePortEdit set to" << ui->receivePortEdit->text().toInt();
}

void MainWindow::on_mainVisCheckBox_toggled(bool checked)
{
    ui->mainVisIntervalEdit->setEnabled(checked);
    ui->mainVisIntervalEdit->setText("0.01");
    m_server->changeTimerInterval("visTimer", ui->mainVisIntervalEdit->text().toUInt() / 1000);

    if (ui->mainiComboBox->currentIndex() == USER_DATA_CHOICE)
        m_server->setSendData_VISUAL(&visual_data, checked);
     if ((ui->mainiComboBox->currentIndex() == DATA_FROM_MODEL))
        m_server->setSendData_VISUAL(&visual_data_from_model, checked);

   // m_server->setSendData_VISUAL(&visual_data, checked);
}


void MainWindow::on_lightsCheckBox_toggled(bool checked)
{
    ui->aerodromsIntervalEdit->setEnabled(checked);
    ui->aerodromsIntervalEdit->setText("5");
    m_server->changeTimerInterval("aerodromsTimer", ui->aerodromsIntervalEdit->text().toUInt() / 1000);

    if (ui->aerodrCB->currentIndex() == USER_DATA_CHOICE)
        m_server->setSendData_AERODROMS(&airoports_lights_data, checked);

    if ((ui->aerodrCB->currentIndex() == DATA_FROM_MODEL))
        m_server->setSendData_AERODROMS(&airoports_lights_data_from_model, checked);

  //  m_server->setSendData_AERODROMS(&airoports_lights_data, checked);
}

/*void MainWindow::on_BackwardCheckBox_clicked(bool checked)
{
 //   ui->back->setEnabled(checked);
    if (checked)
        m_server->setSendData_BACKWARD(&backward_data);
}	   */


void MainWindow::on_sendIPEdit_editingFinished()
{
    m_server->setAddress2Send(QHostAddress(ui->sendIPEdit->text()));
    qDebug() << "setAddress2Send" << QHostAddress(ui->sendIPEdit->text());
}

void MainWindow::on_sendPortEdit_editingFinished()
{
    m_server->setSendingPort(ui->sendPortEdit->text().toInt());
    qDebug() << "sendPortEdit" << ui->sendPortEdit->text().toInt();
}

void MainWindow::on_sendOnceButton_clicked()
{
    qDebug() << "on_sendOnceButton_pressed start";
    QString message = "";
    m_server->setSendToAddress(QHostAddress(ui->sendIPEdit->text()), ui->sendPortEdit->text().toInt());

    if (ui->backwReceive->isChecked())
    {
        // emit sendUpdatedData(&backward_data);
        message += " backward ";
    }
    if (ui->meteoCheckBox->isChecked())
    {
        //emit sendUpdatedData(&meteo_data);
        message += " meteo ";
    }
    if (ui->lightsCheckBox->isChecked())
    {
        // emit sendUpdatedData(&airoports_lights_data);
        message += " aerodrom lights ";
    }//qDebug() <<message;

    //ui->SendInfoText->appendPlainText(QString("Sending"+message+" packets"));
    qDebug() << "sending once" << message;
    m_server->sendOnce();
    message = "sending once " + message + "packets at" + (time_from_start.currentTime()).toString();
    MainWindow::statusBar()->showMessage(message);
}

void MainWindow::on_stopPB_clicked()
{
    qDebug() << "stop button toggled";

    //gui interpretation
    ui->startPB->setEnabled(true);
    ui->sendOnceButton->setEnabled(true);
    ui->sendOnceButton->setEnabled(true);
    ui->startPB->setEnabled(true);
    ui->receivePortEdit->setEnabled(true);
    ui->receivePortEdit_2->setEnabled(true);
    ui->backwIPedit->setEnabled(true);
    ui->backwPortEdit->setEnabled(true);
    ui->CHANgeVisgroupBox->setEnabled(true);
	ui->sendIPEdit->setEnabled(true);
    ui->startPB->setEnabled(true);

    //stops receiving everything
    m_server->keep_recieve = false;

    qDebug() << "rec port now is " << m_server->getReceivingPort();

    //stops sending everything
    m_server->stopSending();
  //  blockSignals(m_server);

    QString message = "Stopped receiving and listening on " + ui->receivePortEdit->text() + " port";
    MainWindow::statusBar()->showMessage(message);
}

void MainWindow::readConfig()
{
    //interchange with model
 /*   m_server->setReceivingPort(ui->receivePortEdit->text().toUInt());
  
	if (ui->stopReceivingMain->isChecked() || 
		ui->stopReceivingMeteo->isChecked() ||
		ui->stopReceivingAerodroms->isChecked()
		)
		m_server->keep_recieve = false;

	if (ui->meteoComboBox->currentIndex() == USER_DATA_CHOICE)
		m_server->setSendData_METEO(&meteo_data, ui->meteoCheckBox->isChecked());
	else
		m_server->setSendData_METEO(&meteo_data_from_model, ui->meteoCheckBox->isChecked());
	
	if (ui->mainiComboBox->currentIndex() == USER_DATA_CHOICE)
		m_server->setSendData_VISUAL(&visual_data, ui->mainVisCheckBox->isChecked());
	else
		m_server->setSendData_VISUAL(&visual_data_from_model, ui->mainVisCheckBox->isChecked());

	if (ui->aerodrCB->currentIndex() == USER_DATA_CHOICE)
		m_server->setSendData_AERODROMS(&airoports_lights_data, ui->lightsCheckBox->isChecked());
	else
		m_server->setSendData_AERODROMS(&airoports_lights_data_from_model, ui->lightsCheckBox->isChecked());
    
	//backward edit send
    m_server->setBackwardAddress2Send(QHostAddress(ui->backwIPedit->text().toUInt()));
    m_server->setBackwardSendingPort(ui->backwPortEdit->text().toUInt());
	m_server->setSendData_BACKWARD(&backward_data,ui->backwardChkBox->isChecked());
	//backward receive
	m_server->setBackwardReceivingPort(ui->receivePortEdit_2->text().toUInt());
	//&???restartBACKWARDListeinig
	//m_server->restartBACKWARDListeinig
	//sending
    m_server->setAddress2Send(QHostAddress(ui->sendIPEdit->text().toUInt()));
    m_server->setSendingPort(ui->sendPortEdit->text().toUInt());

    //time intervals
    m_server->changeTimerInterval("visTimer", ui->mainVisIntervalEdit->text().toUInt()*1000);
    m_server->changeTimerInterval("aerodromsTimer", ui->aerodromsIntervalEdit->text().toUInt() * 1000);
    m_server->changeTimerInterval("meteoTimer", ui->meteoIntervalEdit->text().toUInt() * 1000);
	m_server->changeTimerInterval("backwardTimer", ui->mainVisIntervalEdit->text().toUInt() * 1000);

	//map indication on load
    m_server->setMAPAddress2Send(QHostAddress(ui->mapIPsend->text().toUInt()));
    m_server->setMAPSendingPort(ui->portMapSend->text().toUInt());

	m_server->changeTimerInterval("mapTimer", ui->timeMap->text().toUInt() * 1000);
    m_server->setSendData_MAP(&map_data, ui->send2mapCHb->isChecked());
	
	// map data
	map_data.isOrientingCamera = ui->isOrientCamchB->isChecked();
	map_data.isShowingWindow = ui->showWindchB->isChecked();
	map_data.showCurTraj = ui->showTrajChB->isChecked();
	map_data.showRoute = ui->showRoutechB->isChecked();
	map_data.followMainPlane = ui->followMainPlainCHB->isChecked();

	map_data.currWPT = ui->nppm->text().toInt();
	map_data.curLat = visual_data_from_model.p_coord.X;
	map_data.curLon = visual_data_from_model.p_coord.Z;
	map_data.curH = visual_data_from_model.p_coord.H;

	map_data.curGamma = visual_data_from_model.p_angle.R;
	map_data.curPsi = visual_data_from_model.p_angle.C;
	map_data.curTheta = visual_data_from_model.p_angle.P;
	map_data.updateRoute = ui->updateRoute->text().toInt();
	//route
	map_data.routeLat[0] = visual_data_from_model.p_coord.X;
	map_data.routeLon[0] = visual_data_from_model.p_coord.Z;
	map_data.routeAlt[0] = visual_data_from_model.p_coord.H;
	
	//map_data.routeLat[0] = airoports_lights_data.p_coord.X;
	//map_data.routeLon[0] = visual_data_from_model.p_coord.Z;
	//map_data.routeAlt[0] = visual_data_from_model.p_coord.H;
	for (size_t i = 0; i < 53; ++i)
	{
		map_data.routeLat[i] = map_data.routeLat[1];
		map_data.routeLon[i] = map_data.routeLon[1];
		map_data.routeAlt[i] = map_data.routeAlt[1];
	 }
	//bots
	for (auto & bot : map_data.bots)
	{
		bot.H = 0;
		bot.lat = 0;
		bot.psi = 0;
		bot.visibility = 0;
	}	  */
}

void MainWindow::on_routePushB_clicked()
{
    //open route window
}

void MainWindow::on_meteoCheckBox_toggled(bool checked)
{
    qDebug() << "meteo checked";
    ui->meteoIntervalEdit->setEnabled(checked);
    ui->meteoIntervalEdit->setText("5");
    m_server->changeTimerInterval("meteoTimer", ui->meteoIntervalEdit->text().toUInt());

    qDebug() << "meteo set send";
    printMeteo(&meteo_data);

    if (ui->meteoComboBox->currentIndex() == USER_DATA_CHOICE)
        m_server->setSendData_METEO(&meteo_data, checked);
    else if ((ui->meteoComboBox->currentIndex() == DATA_FROM_MODEL))
        m_server->setSendData_METEO(&meteo_data_from_model, checked);

}

void MainWindow::on_mainiComboBox_currentIndexChanged(int index)
{
    if (index == DATA_FROM_MODEL)
    {
        qDebug() << "sending to vis ui";
        //emit sendUpdatedData(&visual_data_from_model);
        mainvis_ui->setDataToShow(&visual_data_from_model);
        backward_ui->updateBackwardPacket(visual_data_from_model);
        mainvis_ui->setDisabled(true);
        //update backward packet
    }
    else if (index == USER_DATA_CHOICE)
    {
        //update backward packet
        //emit sendUpdatedData(&visual_data);
        mainvis_ui->setDataToShow(&visual_data);
        backward_ui->updateBackwardPacket(visual_data);
        mainvis_ui->setEnabled(true);
    }
    else
    {
        m_server->keep_recieve = false;
      //  blockSignals(m_server);
    }
}

void MainWindow::on_meteoComboBox_currentIndexChanged(int index)
{

    if (index == DATA_FROM_MODEL)
    {
        qDebug() << "sending to meteo ui";
        meteo_ui->writeToFields(&meteo_data_from_model);
        //	emit sendUpdatedData(&meteo_data_from_model);
        meteo_ui->setReadOnly(true);
    }
    else if (index == USER_DATA_CHOICE)
    {
        qDebug() << "sending to meteo ui";
        //emit sendUpdatedData(&meteo_data);
        meteo_ui->writeToFields(&meteo_data);
        meteo_ui->setReadOnly(false);
    }
    else
    {
        m_server->keep_recieve = false;
      //  blockSignals(m_server);
    }

}

void MainWindow::on_aerodrCB_currentIndexChanged(int index)
{
    if (index == DATA_FROM_MODEL)
    {
        qDebug() << "sending to meteo ui";
        aerodrom_ui->writeToFields(&airoports_lights_data_from_model);
        aerodrom_ui->setEnabled(false);
        aerodrom_ui->from_model = true;
    }
    else if (index == USER_DATA_CHOICE)
    {
        qDebug() << "sending to meteo ui";
        aerodrom_ui->writeToFields(&airoports_lights_data);
        aerodrom_ui->setEnabled(true);
        aerodrom_ui->from_model = false;
    }
    else
    {
        m_server->keep_recieve = false;
     //   blockSignals(m_server);
    }
}

void MainWindow::on_startPB_clicked()
{
    qDebug() << "start sending?receiving check";

    m_server->m_time.start();
    ui->sendOnceButton->setEnabled(false);
    ui->startPB->setEnabled(false);
    ui->receivePortEdit->setEnabled(false);
    ui->receivePortEdit_2->setEnabled(false);
    ui->backwIPedit->setEnabled(false);
    ui->backwPortEdit->setEnabled(false);

  //  ui->CHANgeVisgroupBox->setEnabled(false);
	ui->backwReceive->setEnabled(true);

    ui->startPB->setEnabled(false);

    if (m_server->keep_recieve == false)
    {
        QString message = "Listening on " + ui->receivePortEdit->text() + " port";
  
        m_server->restartListening(ui->receivePortEdit->text().toInt());
	
	//	m_server->restartBACKWARDListening(ui->backwReceive->text().toInt());
        
		m_server->keep_recieve = true;
    }

    if (m_server->setSendingPort(ui->receivePortEdit->text().toUInt()))
    {
        m_server->setSendToAddress(QHostAddress(ui->sendIPEdit->text()), ui->sendPortEdit->text().toInt());
        m_server->changeTimerInterval("visTimer", ui->mainVisIntervalEdit->text().toUInt() / 1000);
        m_server->changeTimerInterval("meteoTimer", ui->meteoIntervalEdit->text().toUInt() / 1000);
        m_server->changeTimerInterval("aerodromsTimer", ui->aerodromsIntervalEdit->text().toUInt() / 1000);
        m_server->changeTimerInterval("mapTimer", ui->timeMap->text().toUInt() * 1000);

        if (ui->backwardChkBox->isChecked())
        {
            //куда слать обратный пакет
            m_server->changeTimerInterval("backwTimer", ui->mainVisIntervalEdit->text().toUInt() / 1000);
        }

        m_server->startSending();
    }
    MainWindow::statusBar()->showMessage(QString::fromLocal8Bit("Идет обмен"));
}

void MainWindow::on_send2mapchb_toggled(bool checked)
{
    ui->mapIPsend->setEnabled(checked);
    // if (checked)
    m_server->setSendData_MAP(&map_data, checked);
}

//backward set
void MainWindow::on_backwReceive_toggled(bool checked)
{
    //данные от визуализации
    //set	ui->receivePortEdit_2->
    ui->backwReceive->setEnabled(checked);
    ui->backwPortEdit->setEnabled(checked);
}

void MainWindow::on_backwardChkBox_toggled(bool checked)
{
    ui->backwIPedit->setEnabled(checked);
    ui->backwPortEdit->setEnabled(checked);

    //read backwport and fill backw address
    m_server->setSendData_BACKWARD(&backward_data, checked);
}

void MainWindow::on_showWindchB_toggled(bool checked)
{
    map_data.isShowingWindow = checked;
}

void MainWindow::on_showTrajChB_toggled(bool checked)
{
    map_data.showCurTraj = checked;
}

void MainWindow::on_showRoutechB_toggled(bool checked)
{
    map_data.showRoute = checked;
}

void MainWindow::on_followMainPlainCHB_toggled(bool checked)
{
    map_data.followMainPlane = checked;
}

void MainWindow::on_isOrientCamchB_toggled(bool checked)
{
    map_data.isOrientingCamera = checked;
}

void MainWindow::on_sendIPEdit_2_editingFinished()
{
    //ui->sendPortEdit_2->text().toUInt()


}

void MainWindow::on_sendPortEdit_2_editingFinished()
{
    m_server->setMAPSendingPort(ui->portMapSend->text().toInt());
}

void MainWindow::on_send2mapIE_editingFinished()
{

}

void MainWindow::on_nppm_editingFinished()
{
    //&???
    map_data.currWPT = ui->nppm->text().toUInt();

}

void MainWindow::on_updateRoute_editingFinished()
{
    map_data.updateRoute = ui->updateRoute->text().toInt();
}

void MainWindow::on_centerLat_editingFinished()
{
    map_data.centerLat = ui->centerLat->text().toDouble();
}

void MainWindow::on_centerLon_editingFinished()
{
    map_data.centerLon = ui->centerLon->text().toDouble();
}

void MainWindow::on_centerH_editingFinished()
{
    map_data.centerLon = ui->centerLon->text().toFloat();
}
void MainWindow::on_stopReceivingMain_toggled(bool checked)
{
    m_server->keep_recieve=!checked;
    //blockSignals();
}

void MainWindow::on_mapHeiihtspinBox_valueChanged(int arg1)
{
    map_data.centerH = ui->mapHeiihtspinBox->text().toInt();
}

void MainWindow::on_receivePortEdit_2_editingFinished()
{
   m_server->setBackwardReceivingPort(ui->backwReceive->text().toUInt());
}

void MainWindow::on_send2mapCHb_toggled(bool checked)
{
    ui->timeMap->setEnabled(checked);
//	ui->mapIPsend->setEnabled(checked);
	// if (checked)
	m_server->setSendData_MAP(&map_data, checked);
   // m_server->changeTimerInterval("mapTimer", ui->timeMap->text().toUInt());

}

void MainWindow::on_portMapSend_editingFinished()
{
     m_server->setMAPSendingPort(ui->portMapSend->text().toUInt());
}

void MainWindow::on_mapIPsend_editingFinished()
{
     m_server->setMAPAddress2Send(QHostAddress(ui->mapIPsend->text()));
}

void MainWindow::on_stopReceivingMeteo_toggled(bool checked)
{
    m_server->keep_recieve= checked;
}
