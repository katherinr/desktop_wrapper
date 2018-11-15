#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "utilities.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	time_from_start.start();
    m_server = new UdpServer();
    //*/////////////////////////////////////////////*/

    meteo_ui = new meteoWindow;
    deep_meteo_copy(meteo_ui->data, &meteo_data );
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
    connect(m_server, SIGNAL(dataUpdated(_AirportData*)), this, SLOT(receiveDatafromModel(_AirportData*)));
    connect(m_server, SIGNAL(dataUpdated(_DataToModel*)), this, SLOT(receiveDatafromModel(_DataToModel*)));
    connect(m_server, SIGNAL(dataUpdated(_MeteoData*)), this, SLOT(receiveDatafromModel(_MeteoData*)));
    connect(m_server, SIGNAL(dataUpdated(_MainVisualData*)), this, SLOT(receiveDatafromModel(_MainVisualData*)));

    connect(this, SIGNAL(sendUpdatedData(_MeteoData*)),meteo_ui,SLOT(writeToFields(_MeteoData*)));
    connect(this, SIGNAL(sendUpdatedData(_DataToModel*)),backward_ui,SLOT(writeToFields(_DataToModel*)));
    connect(this, SIGNAL(sendUpdatedData(_AirportData*)),aerodrom_ui,SLOT(writeToFields(_AirportData*)));
    connect(this, SIGNAL(sendUpdatedData(_MainVisualData*)),mainvis_ui,SLOT(setDataToShow(_MainVisualData*)));
	
	mainvis_ui->setDataFromDefaut(&visual_data);  
	meteo_ui->setDataFromDefaultMeteo();
	deep_meteo_copy(meteo_ui->data, &meteo_data);
	
	aerodrom_ui->readDefault(&airoports_lights_data);
	backward_ui->readDefault(&backward_data);
	
	//clear model data pointers
	flushMeteoData(&meteo_data_from_model);
	flushaEROData(&airoports_lights_data_from_model);
	flushVISUALData(visual_data_from_model);
//	flushBackwardData(back)
	//flushMeteoData(&meteo_data_from_model);
	QString timer_text = "T = " + QString::number(time_from_start.elapsed()/1000) + " c";
    QMainWindow::statusBar()->showMessage(timer_text);
}

void MainWindow::receiveData(_AirportData *_data)
{
	deepAeroportcopy(_data, &airoports_lights_data);
	emit sendUpdatedData(&airoports_lights_data);
   /* airoports_lights_data.packet_id =NPR_PACKET_TYPE_AIRPORT_DATA;
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
    //printAeroData(_data);
	//if(ui->aerodrCB->currentIndex()==1)
	 // emit sendUpdatedData(&airoports_lights_data);		   */
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

}

void MainWindow::receiveData(_MeteoData * _data)
{
    deep_meteo_copy(_data, &meteo_data);

   /* printMeteo(_data);

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
    }		*/
	meteo_ui->set_from_net = false;
	emit sendUpdatedData(&meteo_data);
}

void MainWindow::receiveData(_MainVisualData * _data)
{
	deepVisualCopy(_data, visual_data);
	emit sendUpdatedData(&visual_data);
}

//from model
void MainWindow::receiveDatafromModel(_AirportData *_data)
{
	deepAeroportcopy(_data, &airoports_lights_data_from_model);
	emit sendUpdatedData(&airoports_lights_data_from_model);
}

void MainWindow::receiveDatafromModel(_MeteoData * _data)
{
	deep_meteo_copy(_data, &meteo_data_from_model);
	meteo_ui->set_from_net = true;
	emit sendUpdatedData(&meteo_data_from_model);
}

void MainWindow::receiveDatafromModel(_MainVisualData * _data)
{
	deepVisualCopy(_data, visual_data_from_model);
	emit sendUpdatedData(&visual_data_from_model);
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
    qDebug()<<"setting new data from received"<<message_type;
    if (message_type ==  NPR_PACKET_TYPE_METEO_DATA || message_type ==  11)
        MainWindow::statusBar()->showMessage(tr("Meteo packet received"));
    else if(message_type == NPR_PACKET_TYPE_AIRPORT_DATA)
		MainWindow::statusBar()->showMessage(tr("Aerodrom lights packet received"));
    else if(message_type == NPR_PACKET_TYPE_BACK_DATA||message_type ==  10)
		MainWindow::statusBar()->showMessage(tr("Backward packet received"));
   
	m_server->setDataFromReceived(datagram);
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

    m_server->changeTimerInterval("visTimer",ui->mainVisIntervalEdit->text().toUInt()/1000 );

    m_server->setSendData_VISUAL(&visual_data, checked);
}


void MainWindow::on_lightsCheckBox_toggled(bool checked)
{
    ui->aerodromsIntervalEdit->setEnabled(checked);
    ui->aerodromsIntervalEdit->setText("5");
    m_server->changeTimerInterval("aerodromsTimer",ui->aerodromsIntervalEdit->text().toUInt()/1000 );

        m_server->setSendData_AERODROMS(&airoports_lights_data, checked);
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
        message += " backward ";
    }
    if( ui->meteoCheckBox->isChecked() )
    {
        //emit sendUpdatedData(&meteo_data);
        message += " meteo ";
    }
    if( ui->lightsCheckBox->isChecked())
    {
        // emit sendUpdatedData(&airoports_lights_data);
        message += " aerodrom lights ";
    }//qDebug() <<message;

    //ui->SendInfoText->appendPlainText(QString("Sending"+message+" packets"));
    qDebug() <<"sending once" <<message;
    m_server->sendOnce();
	 message = "sending once " + message + "packets at" + (time_from_start.currentTime()).toString();
	MainWindow::statusBar()->showMessage(message);
}

void MainWindow::on_stopPB_clicked()
{
    qDebug()<<"stop button toggled";
	
	//gui interpretation
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

	//stops receiving everything
    m_server->keep_recieve = false;

    qDebug()<<"rec port now is "<<m_server->getReceivingPort();

	//stops sending everything
    m_server->stopSending();
    blockSignals(m_server);

	QString message = "Stopped receiving and listening on " + ui->receivePortEdit->text() + " port";
	MainWindow::statusBar()->showMessage(message);
}

void MainWindow::readConfig()
{
   //interchange with ,odel
	m_server->setReceivingPort(ui->receivePortEdit->text().toUInt());
	//backward edit send

	//sending
	m_server->setAddress2Send(QHostAddress(ui->sendIPEdit->text().toUInt()));
	m_server->setSendingPort(ui->sendPortEdit->text().toUInt());

	if (ui->meteoCheckBox->isChecked())
	{
		m_server->changeTimerInterval("meteoTimer", ui->meteoIntervalEdit->text().toUInt());
		m_server->setSendData_METEO(&meteo_data, ui->meteoCheckBox->isChecked());
	}

	if (ui->mainVisCheckBox->isChecked())
	{
		m_server->changeTimerInterval("visTimer", ui->mainVisIntervalEdit->text().toUInt());
		m_server->setSendData_VISUAL(&visual_data, ui->mainVisCheckBox->isChecked());
	}

	if (ui->lightsCheckBox->isChecked())
	{
		m_server->changeTimerInterval("aerodromsTimer", ui->aerodromsIntervalEdit->text().toUInt());
		m_server->setSendData_AERODROMS(&airoports_lights_data, ui->lightsCheckBox->isChecked());
	}
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

   
        qDebug()<<"meteo set send";
        printMeteo(&meteo_data);
        m_server->setSendData_METEO(&meteo_data, checked);
   
}

void MainWindow::on_mainiComboBox_currentIndexChanged(int index)
{
    if (index==0)
    {
        qDebug()<<"sending to vis ui";
        emit sendUpdatedData(&visual_data_from_model);
		backward_ui->updateBackwardPacket(visual_data_from_model);
		mainvis_ui->setDisabled(true);
		//update backward packet
    }
	else if (index == 1)
	{
		//update backward packet
		emit sendUpdatedData(&visual_data);
		backward_ui->updateBackwardPacket(visual_data);
		mainvis_ui->setEnabled(true);
	}
	else
	{
		m_server->keep_recieve = false;
		blockSignals(m_server);
	}
}

void MainWindow::on_meteoComboBox_currentIndexChanged(int index)
{
    if (index==0)
    {
        qDebug()<<"sending to meteo ui";
        emit sendUpdatedData(&meteo_data_from_model);
		meteo_ui->setEnabled(false);
    }
	else if (index == 1)
	{
		qDebug() << "sending to meteo ui";
		emit sendUpdatedData(&meteo_data);
		meteo_ui->setEnabled(true);
	}
	else
	{
		m_server->keep_recieve = false;
		blockSignals(m_server);
	}
}
void MainWindow::on_aerodrCB_currentIndexChanged(int index)
{
	if (index == 0)
	{
		qDebug() << "sending to meteo ui";
		emit sendUpdatedData(&airoports_lights_data_from_model);
		aerodrom_ui->setEnabled(false);
	}
	else if (index == 1)
	{
		qDebug() << "sending to meteo ui";
		emit sendUpdatedData(&airoports_lights_data);
		aerodrom_ui->setEnabled(true);
	}
	else
	{
		m_server->keep_recieve = false;
		blockSignals(m_server);
	}
}

void MainWindow::on_startPB_clicked()
{
    qDebug()<<"start sending?receiving check";
  
	m_server->m_time.start();
    ui->sendOnceButton->setEnabled(false);
    ui->startPB->setEnabled(false);
    ui->receivePortEdit->setEnabled(false);
    ui->receivePortEdit_2->setEnabled(false);
    ui->backwIPedit->setEnabled(false);
    ui->backwPortEdit-> setEnabled(false);
    ui->CHANgeVisgroupBox->setEnabled(false);
    ui->startPB->setEnabled(false);

    if (m_server->keep_recieve == false)
	{
		connect(m_server, SIGNAL(readyRead()), m_server, SLOT(readDatagram()));
        QString message = "Listening on " + ui->receivePortEdit->text() +" port";
		if (m_server->setReceivingPort(ui->receivePortEdit->text().toUInt())   )
			m_server->restartListening(ui->receivePortEdit->text().toInt());
        m_server->keep_recieve = true;
    }

    if (m_server->setSendingPort(ui->receivePortEdit->text().toUInt()))
    {
        m_server->setSendToAddress(QHostAddress(ui->sendIPEdit->text()), ui->sendPortEdit->text().toInt());
        m_server->changeTimerInterval("visTimer", ui->mainVisIntervalEdit->text().toUInt()/1000);
        m_server->changeTimerInterval("meteoTimer", ui->meteoIntervalEdit->text().toUInt()/1000);
        m_server->changeTimerInterval("aerodromsTimer", ui->aerodromsIntervalEdit->text().toUInt()/1000);

        if (ui->backwardChkBox->isChecked())
        {
            //куда слать обратный пакет
            m_server->changeTimerInterval("backwTimer", ui->mainVisIntervalEdit->text().toUInt()/1000);
        }

        m_server->startSending();
    }
	MainWindow::statusBar()->showMessage(QString::fromLocal8Bit("Идет обмен"));
}

void MainWindow::on_send2mapchb_toggled(bool checked)
{
    if (checked)
        ui->send2mapIE->setEnabled(true);
    else
        ui->send2mapIE->setEnabled(false);
}


void MainWindow::on_backwReceive_toggled(bool checked)
{
	//данные от визуализации
	//set	ui->receivePortEdit_2->
	ui->backwReceive->setEnabled(checked);
	//ui->backwPortEdit->setEnabled(checked);
}

void MainWindow::on_backwardChkBox_toggled(bool checked)
{
    ui->backwIPedit->setEnabled(checked);
	ui->backwPortEdit->setEnabled(checked);
    //read backwport and fill backw address

 
        m_server->setSendData_BACKWARD(&backward_data,checked);
}
