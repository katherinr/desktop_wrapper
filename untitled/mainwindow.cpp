#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "utilities.h"
#include "qtimer.h"
#include <qsettings.h>
#include <qhostaddress.h>

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
    sound_ui = new Sound_form;
    /*/////////////////////////////////////////////*/
	//time
	passed_time_indicator = new QLabel(this);
	modeling_timer = new QTimer(this);
	shift_time_indicator = new QLabel(this);
   
	//show subwindows
    connect(ui->meteoPushButton, SIGNAL(clicked()), meteo_ui, SLOT(show()));
    connect(ui->AerodromsLightsPB, SIGNAL(clicked()), aerodrom_ui, SLOT(show()));
    connect(ui->CorrectPB, SIGNAL(clicked()), backward_ui, SLOT(show()));
    connect(ui->mainVisPushButton, SIGNAL(clicked()), mainvis_ui, SLOT(show()));
    connect(ui->soundPB, SIGNAL(clicked()), sound_ui, SLOT(show()));
	/*/////////////////////////////////////////////*/
    //receive data from subwindows
    connect(aerodrom_ui, SIGNAL(sendData(_AirportData*)), this, SLOT(receiveData(_AirportData*)));
    connect(backward_ui, SIGNAL(sendData(_DataToModel*)), this, SLOT(receiveData(_DataToModel*)));
    connect(meteo_ui, SIGNAL(sendData(_MeteoData*)), this, SLOT(receiveData(_MeteoData*)));
    connect(mainvis_ui, SIGNAL(sendData(_MainVisualData*)), this, SLOT(receiveData(_MainVisualData*)));
	connect(sound_ui, &Sound_form::sendData, m_server, &UdpServer::onNewGuiSoundSettings);

    /*/////////////////////////////////////////////*/

    //set data from UDP
    connect(m_server, SIGNAL(dataUpdated(_AirportData*)), this, SLOT(receiveDatafromModel(_AirportData*)));
    connect(m_server, SIGNAL(dataUpdated(_DataToModel*)), this, SLOT(receiveData(_DataToModel*)));
    connect(m_server, SIGNAL(dataUpdated(_MeteoData*)), this, SLOT(receiveDatafromModel(_MeteoData*)));
    connect(m_server, SIGNAL(dataUpdated(_MainVisualData*)), this, SLOT(receiveDatafromModel(_MainVisualData*)));

	connect(this, &MainWindow::mapControlDataUpdated, m_server, &UdpServer::onNewGuiMapSetting);

	//small config
	ui->startPB->setEnabled(false);
	ui->stopPB->setEnabled(false);

	// криво
	m_mapControlData.centerH = 30000;
	m_mapControlData.centerLat = 53.564917000000001;
	m_mapControlData.centerLon = 37.96;
	m_mapControlData.followMainPlane = true;
	m_mapControlData.isOrientingCamera = true;
	m_mapControlData.isShowingWindow = true;
	m_mapControlData.showCurTraj = true;
	m_mapControlData.showRoute = true;
	m_mapRoute.updateRoute = 0;

	readSettings();

	m_server->restartListening(ui->receivePortEdit->text().toInt());
	m_server->setMAPAddress2Send(QHostAddress(ui->mapIPsend->text()));
	m_server->setMAPSendingPort(ui->portMapSend->text().toUInt());
	m_server->setSOUNDAddress2Send(QHostAddress(ui->soundIPsend->text()));
	m_server->setSOUNDSendingPort((ui->soundPortSend->text().toUInt()));
	m_server->restartBACKWARDListening(ui->receivePortEdit_2->text().toInt());

    mainvis_ui->setDataFromDefaut(&visual_data);
    meteo_ui->setDataFromDefaultMeteo();
    deep_meteo_copy(meteo_ui->data, &meteo_data);
	aerodrom_ui->readDefault(&airoports_lights_data);

   // backward_ui->readDefault(&backward_data);

	backward_data.packet_id = NPR_PACKET_TYPE_BACK_DATA;
	backward_data.p_coord.X = visual_data.p_coord.X;
	backward_data.p_coord.H = visual_data.p_coord.H;
	backward_data.p_coord.Z = visual_data.p_coord.Z;
	backward_ui->writeDataToFields(&backward_data);
    //clear model data pointers
    flushMeteoData(&meteo_data_from_model);
    flushaEROData(&airoports_lights_data_from_model);
    flushVISUALData(visual_data_from_model);
	
	airoports_lights_data.packet_id = NPR_PACKET_TYPE_AIRPORT_DATA;
	meteo_data.packet_id = NPR_PACKET_TYPE_METEO_DATA;
	visual_data.packet_id = NPR_PACKET_TYPE_VISUAL_DATA;
	/////////////////////////////////////////////////

	/*/////////////////////////////////////////////*/
	QString timer_text = "T = " + QString::number(visual_data_from_model.model_simulation_time / 1000) + " c";

	//timer connect	
	QTimer *timer = new QTimer(this);

//	connect(timer, SIGNAL(timeout()), this, SLOT(onTimerTimeout()));
	connect(timer, SIGNAL(timeout()), passed_time_indicator, SLOT(update()));

	QString pass_text = "T = " + QString::number(0) + " c";
	passed_time_indicator->setText(pass_text);

	QMainWindow::statusBar()->showMessage(timer_text);
	QMainWindow::statusBar()->addPermanentWidget(passed_time_indicator, 2);

	QString shift_time = "T late = " + QString::number((visual_data_from_model.model_simulation_time / 1000 - backward_data.simulation_time / 1000)*.5) + " c";
	shift_time_indicator->setText(pass_text);
	QMainWindow::statusBar()->addPermanentWidget(shift_time_indicator, 1);

	timer->start(1000);

	ui->mainVisCheckBox->setEnabled(false);
	//ui->send2mapCHb->setEnabled(false);
	ui->meteoCheckBox->setEnabled(false);
	ui->lightsCheckBox->setEnabled(false);

	ui->mainVisIntervalEdit->setEnabled(false);
	ui->aerodromsIntervalEdit->setEnabled(false);
	ui->meteoIntervalEdit->setEnabled(false);
	ui->timeMap->setEnabled(false);

	//map config
	m_mapControlData.isOrientingCamera = ui->isOrientCamchB->isChecked();
	m_mapControlData.isShowingWindow = ui->showWindchB->isChecked();
	m_mapControlData.showCurTraj = ui->showTrajChB->isChecked();
	m_mapControlData.showRoute = ui->showRoutechB->isChecked();
	m_mapControlData.followMainPlane = ui->followMainPlainCHB->isChecked();
	
	m_mapControlData.centerH = ui->mapHeiihtspinBox->text().toInt();
	m_mapControlData.centerLat = ui->centerLat->text().toDouble();
	m_mapControlData.centerLon = ui->centerLat->text().toDouble();

	//m_server->setSendData_MAP(&m_mapControlData, ui->send2mapCHb->isChecked());
	mapControlDataUpdated(m_mapControlData);
}

//from this program
void MainWindow::receiveData(_AirportData *_data)
{
    deepAeroportcopy(_data, &airoports_lights_data);
    if (ui->aerodrCB->currentIndex() == USER_DATA_CHOICE)
        aerodrom_ui->writeToFields(_data);
}

void MainWindow::receiveData(_DataToModel *_data)
{
	backwardDeepCopy(_data, &backward_data);
	backward_ui->writeDataToFields(&backward_data);
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
	
	QString shift_time = "T late = " + QString::number((visual_data_from_model.model_simulation_time  - backward_data.simulation_time )*.005) + " c";
	shift_time_indicator->setText(shift_time);
}

//from model
void MainWindow::receiveDatafromModel(_AirportData *_data)
{
    deepAeroportcopy(_data, &airoports_lights_data_from_model);
    if (ui->aerodrCB->currentIndex() == DATA_FROM_MODEL)
        aerodrom_ui->writeToFields(_data);
	update_route_();
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

	QString pass_text = "T = " + QString::number(_data->model_simulation_time / 1000) + " c";
	passed_time_indicator->setText(pass_text);
	QString shift_time = "T late = " + QString::number((_data->model_simulation_time / 1000 - backward_data.simulation_time / 1000)*.5) + " c";
	shift_time_indicator->setText(shift_time);
}


MainWindow::~MainWindow()
{
    delete ui;
    delete meteo_ui;
    delete aerodrom_ui;
    delete backward_ui;
    delete mainvis_ui;
    delete sound_ui;
    delete m_server;
	delete passed_time_indicator;
	killTimer(timer_id);
}

void MainWindow::on_receivePortEdit_editingFinished()
{
    //m_server->setReceivingPort(ui->receivePortEdit->text().toInt());
    m_server->restartListening(ui->receivePortEdit->text().toInt());
    qDebug() << "receivePortEdit set to" << ui->receivePortEdit->text().toInt();
}

void MainWindow::on_mainVisCheckBox_toggled(bool checked)
{
    ui->mainVisIntervalEdit->setEnabled(checked);
   // ui->mainVisIntervalEdit->setText("0.01");
    m_server->changeTimerInterval("visTimer", ui->mainVisIntervalEdit->text().toUInt() * 1000);
    m_server->setSendData_VISUAL(&visual_data, checked);
}

void MainWindow::on_lightsCheckBox_toggled(bool checked)
{
    ui->aerodromsIntervalEdit->setEnabled(checked);
 //   ui->aerodromsIntervalEdit->setText("5");
    m_server->changeTimerInterval("aerodromsTimer", ui->aerodromsIntervalEdit->text().toUInt()* 1000);
    m_server->setSendData_AERODROMS(&airoports_lights_data, checked);
}

void MainWindow::on_meteoCheckBox_toggled(bool checked)
{
	qDebug() << "meteo checked";
	ui->meteoIntervalEdit->setEnabled(checked);
	ui->meteoIntervalEdit->setText("5");
	m_server->changeTimerInterval("meteoTimer", ui->meteoIntervalEdit->text().toUInt());
	m_server->setSendData_METEO(&meteo_data, checked);

}

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
    }

    qDebug() << "sending once" << message;
    m_server->sendOnce();
    message = "sending once " + message + "packets at" + (time_from_start.currentTime()).toString();
    MainWindow::statusBar()->showMessage(message);
}

void MainWindow::on_stopPB_clicked()
{
    qDebug() << "stop button toggled";

    //gui interpretation
	ui->backwardChkBox->setEnabled(true);
	ui->sendPortEdit->setEnabled(true);
	ui->stopPB->setEnabled(false);
//	ui->send2mapCHb->setEnabled(true);
	ui->send_from_this->setEnabled(true);
	ui->mainVisCheckBox->setEnabled(true);
	ui->lightsCheckBox->setEnabled(true);
	ui->meteoCheckBox->setEnabled(true);

	ui->mainVisIntervalEdit->setEnabled(true);
	ui->meteoIntervalEdit->setEnabled(true);
	ui->aerodromsIntervalEdit->setEnabled(true);

	ui->backwReceive->setEnabled(true);

    ui->startPB->setEnabled(true);
    ui->sendOnceButton->setEnabled(true);
    ui->sendOnceButton->setEnabled(true);

    ui->receivePortEdit->setEnabled(true);
    ui->receivePortEdit_2->setEnabled(true);
    ui->backwIPedit->setEnabled(true);
    ui->backwPortEdit->setEnabled(true);
    ui->CHANgeVisgroupBox->setEnabled(true);
	ui->sendIPEdit->setEnabled(true);
 
    //stops receiving everything

	m_server->setBackwReceive(false);
    qDebug() << "rec port now is " << m_server->getReceivingPort();

    //stops sending everything
    m_server->stopSending();

    QString message = "Stopped receiving and listening on " + ui->receivePortEdit->text() + " port";
    MainWindow::statusBar()->showMessage(message);
}

void MainWindow::readConfig()
{
    //interchange with model
    //m_server->setReceivingPort(ui->receivePortEdit->text().toUInt());
	//backward edit send
    m_server->setBackwardAddress2Send(QHostAddress(ui->backwIPedit->text().toUInt()));
    m_server->setBackwardSendingPort(ui->backwPortEdit->text().toUInt());
	m_server->setSendData_BACKWARD(&backward_data,ui->backwardChkBox->isChecked());
	//backward receive
	m_server->setBackwardReceivingPort(ui->receivePortEdit_2->text().toUInt());
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
    //m_server->setSendData_MAP(&map_data, ui->send2mapCHb->isChecked());
	
	// map data
	m_mapControlData.isOrientingCamera = ui->isOrientCamchB->isChecked();
	m_mapControlData.isShowingWindow = ui->showWindchB->isChecked();
	m_mapControlData.showCurTraj = ui->showTrajChB->isChecked();
	m_mapControlData.showRoute = ui->showRoutechB->isChecked();
	m_mapControlData.followMainPlane = ui->followMainPlainCHB->isChecked();

	//m_server->setReceivingPort(ui->receivePortEdit->text().toUInt());

	m_server->setSendData_METEO(&meteo_data, ui->meteoCheckBox->isChecked());

	std::shared_ptr <_MainVisualData> ptr_vis(new _MainVisualData);

	auto ptr_vis_model = std::make_shared <_MainVisualData>(visual_data_from_model);

	m_server->setSendData_VISUAL(&visual_data, ui->mainVisCheckBox->isChecked());
	
	m_server->setSendData_AERODROMS(&airoports_lights_data, ui->lightsCheckBox->isChecked());

	//backward edit send
	m_server->setBackwardAddress2Send(QHostAddress(ui->backwIPedit->text()));
	m_server->setBackwardSendingPort(ui->backwPortEdit->text().toUInt());
	m_server->setSendData_BACKWARD(&backward_data, ui->backwardChkBox->isChecked());

	//backward receive
	if (ui->backwReceive->isChecked())
	{
		m_server->restartBACKWARDListening(ui->receivePortEdit_2->text().toUInt());
	}
	m_server->setBackwReceive(ui->backwReceive->isChecked());

	D3_POINT arrival;
	D3_POINT departure;

//	get_coords_by_aeroport_code(ptr_aero->ARRIVAL_AIRPORT_CODE, aerodrom_ui->getRouteByIcao(), arrival);
//	get_coords_by_aeroport_code(ptr_aero->DEPARTURE_AIRPORT_CODE, aerodrom_ui->getRouteByIcao(), departure);
	//map_data.updateRoute = get_update_route();

	//route

	m_server->changeTimerInterval("mapTimer", ui->timeMap->text().toUInt() * 1000);
}

void MainWindow::on_routePushB_clicked()
{
    //open route window
    //map_data.updateRoute++;
}



void MainWindow::on_mainiComboBox_currentIndexChanged(int index)
{
    if (index == DATA_FROM_MODEL)
    {
        qDebug() << "sending to vis ui";
        mainvis_ui->setDataToShow(&visual_data_from_model);
        backward_ui->updateBackwardPacket(visual_data_from_model);
        mainvis_ui->setDisabled(true);
    
    }

    if (index == USER_DATA_CHOICE)
    {
        mainvis_ui->setDataToShow(&visual_data);
        backward_ui->updateBackwardPacket(visual_data);
        mainvis_ui->setEnabled(true);
    }
 
}

void MainWindow::on_meteoComboBox_currentIndexChanged(int index)
{

    if (index == DATA_FROM_MODEL)
    {
        qDebug() << "sending to meteo ui";
        meteo_ui->writeToFields(&meteo_data_from_model);
        meteo_ui->setReadOnly(true);
    }
   
	if (index == USER_DATA_CHOICE)
    {
        qDebug() << "sending to meteo ui";
        meteo_ui->writeToFields(&meteo_data);
        meteo_ui->setReadOnly(false);
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
    
	if (index == USER_DATA_CHOICE)
    {
        qDebug() << "sending to meteo ui";
        aerodrom_ui->writeToFields(&airoports_lights_data);
		 aerodrom_ui->setEnabled(true);
        aerodrom_ui->from_model = false;
    }
  
}

void MainWindow::on_startPB_clicked()
{
    qDebug() << "start sending?receiving check";
	readConfig();
    m_server->m_time.start();

    ui->sendOnceButton->setEnabled(false);
    ui->startPB->setEnabled(false);
    ui->receivePortEdit->setEnabled(false);
    ui->receivePortEdit_2->setEnabled(false);
    ui->backwIPedit->setEnabled(false);
    ui->backwPortEdit->setEnabled(false);
	ui->backwReceive->setEnabled(true);
	ui->sendOnceButton->setEnabled(false);
	//////////////////////////////////////////////////////
	//m_server->setSendFromThis(false);
	ui->stopPB->setEnabled(true);
	ui->send_from_this->setEnabled(false);
	ui->mainVisCheckBox->setEnabled(false);
	ui->send2mapCHb->setEnabled(false);
	ui->meteoCheckBox->setEnabled(false);
	ui->lightsCheckBox->setEnabled(false);

	ui->mainVisIntervalEdit->setEnabled(false);
	ui->aerodromsIntervalEdit->setEnabled(false);
	ui->meteoIntervalEdit->setEnabled(false);
	ui->timeMap->setEnabled(false);

	//////////////////////////////////////////////////////
   // if (m_server->keep_recieve == false)
    {
        QString message = "Listening on " + ui->receivePortEdit->text() + " port";
  
        m_server->restartListening(ui->receivePortEdit->text().toInt());
	
		//m_server->restartBACKWARDListening(ui->receivePortEdit_2->text().toInt());
      
		m_server->setBackwReceive(true);
    }

    if (m_server->setSendingPort(ui->receivePortEdit->text().toUInt()))
    {
        m_server->setSendToAddress(QHostAddress(ui->sendIPEdit->text()), ui->sendPortEdit->text().toInt());
        m_server->changeTimerInterval("visTimer", ui->mainVisIntervalEdit->text().toUInt() * 1000);
        m_server->changeTimerInterval("meteoTimer", ui->meteoIntervalEdit->text().toUInt() * 1000);
        m_server->changeTimerInterval("aerodromsTimer", ui->aerodromsIntervalEdit->text().toUInt() * 1000);
        m_server->changeTimerInterval("mapTimer", ui->timeMap->text().toUInt() * 1000);

        if (ui->backwardChkBox->isChecked())
        {
            //куда слать обратный пакет
            m_server->changeTimerInterval("backwardTimer", ui->mainVisIntervalEdit->text().toUInt() * 1000);
        }
        m_server->startSending();
    }
    MainWindow::statusBar()->showMessage(QString::fromLocal8Bit("Идет обмен"));
}

//backward set
void MainWindow::on_backwReceive_toggled(bool checked)
{
	m_server->setBackwReceive(checked);
	//m_server->setBackwardReceivingPort(ui->receivePortEdit_2->text().toUInt());
	m_server->restartBACKWARDListening(ui->receivePortEdit_2->text().toInt());
}

void MainWindow::on_backwardChkBox_toggled(bool checked)
{
	m_server->setBackwardAddress2Send(QHostAddress(ui->backwIPedit->text()));
	m_server->setBackwardSendingPort(ui->backwPortEdit->text().toInt());
    //read backwport and fill backw address
    m_server->setSendData_BACKWARD(&backward_data, checked);
}

////map
void MainWindow::on_showWindchB_toggled(bool checked)
{
	m_mapControlData.isShowingWindow = checked;
	mapControlDataUpdated(m_mapControlData);
}

void MainWindow::on_showTrajChB_toggled(bool checked)
{
	m_mapControlData.showCurTraj = checked;
	mapControlDataUpdated(m_mapControlData);
}

void MainWindow::on_showRoutechB_toggled(bool checked)
{
	m_mapControlData.showRoute = checked;
	mapControlDataUpdated(m_mapControlData);
}

void MainWindow::on_followMainPlainCHB_toggled(bool checked)
{
	m_mapControlData.followMainPlane = checked;
	mapControlDataUpdated(m_mapControlData);
}

void MainWindow::on_isOrientCamchB_toggled(bool checked)
{
	m_mapControlData.isOrientingCamera = checked;
	mapControlDataUpdated(m_mapControlData);
}

void MainWindow::on_centerLat_editingFinished()
{
	m_mapControlData.centerLat = ui->centerLat->text().toDouble();
	mapControlDataUpdated(m_mapControlData);
}

void MainWindow::on_centerLon_editingFinished()
{
	m_mapControlData.centerLon = ui->centerLon->text().toDouble();
	mapControlDataUpdated(m_mapControlData);
}

void MainWindow::on_mapHeiihtspinBox_valueChanged(int arg1)
{
	m_mapControlData.centerH = ui->mapHeiihtspinBox->text().toInt();
	mapControlDataUpdated(m_mapControlData);
}

void MainWindow::on_receivePortEdit_2_editingFinished()
{
   m_server->restartBACKWARDListening(ui->receivePortEdit_2->text().toUInt());
}

void MainWindow::on_send2mapCHb_toggled(bool checked)
{
    ui->timeMap->setEnabled(checked);
	m_server->setMAPSendingPort(ui->portMapSend->text().toUInt());
	m_server->setMAPAddress2Send(QHostAddress(ui->mapIPsend->text()));
	//m_server->setSendData_MAP(&map_data, checked);
    m_server->changeTimerInterval("mapTimer", ui->timeMap->text().toUInt()*1000);
}	   

void MainWindow::on_portMapSend_editingFinished()
{
     m_server->setMAPSendingPort(ui->portMapSend->text().toUInt());
}

void MainWindow::on_mapIPsend_editingFinished()
{
     m_server->setMAPAddress2Send(QHostAddress(ui->mapIPsend->text()));
}

void MainWindow::on_mapHeiihtspinBox_editingFinished()
{
	m_mapControlData.centerH = ui->mapHeiihtspinBox->text().toInt();
	mapControlDataUpdated(m_mapControlData);
}

void MainWindow::on_send_from_this_toggled(bool checked)
{
	m_server->setSendFromThis(checked);
    ui->startPB->setEnabled(checked);
    ui->stopPB->setEnabled(checked);

	ui->mainVisCheckBox->setEnabled(checked);
	ui->send2mapCHb->setEnabled(checked);
	ui->meteoCheckBox->setEnabled(checked);
	ui->lightsCheckBox->setEnabled(checked);

	ui->mainVisIntervalEdit->setEnabled(checked);
	ui->aerodromsIntervalEdit->setEnabled(checked);
	ui->meteoIntervalEdit->setEnabled(checked);
	ui->timeMap->setEnabled(checked);

}

void MainWindow::on_soundIPsend_editingFinished()
{
   // sound_settings.
    m_server->setSOUNDAddress2Send(QHostAddress(ui->soundIPsend->text()));
}

void MainWindow::on_soundPortSend_editingFinished()
{
    m_server->setSOUNDSendingPort((ui->soundPortSend->text().toUInt()));

}

void MainWindow::on_portPlotSend_textEdited(const QString &arg1)
{
	m_server->setPLOTSendingPort(ui->portPlotSend->text().toUInt());
}

void MainWindow::on_plotIPsend_textChanged(const QString &arg1)
{

	m_server->setPLOTAddress2Send(QHostAddress(ui->plotIPsend->text()));
}

void MainWindow::closeEvent(QCloseEvent * event)
{
	writeSettings();
}

void MainWindow::readSettings()
{
	QSettings settings("bird_wrapper.ini", QSettings::IniFormat);

	settings.beginGroup("Mainwindow");
	this->setGeometry(settings.value("geometry", QRect(0, 0, this->sizeHint().width(), this->sizeHint().height())).toRect());
	settings.endGroup();

	settings.beginGroup("Network");
	ui->receivePortEdit->setText(settings.value("receivePortEdit", 5103).toString());
	ui->send_from_this->setChecked(settings.value("send_from_this", false).toBool());
	
	QHostAddress mapIpAddr;
	if (mapIpAddr.setAddress(settings.value("mapIpAddr", "127.0.0.1").toString())) {
		ui->mapIPsend->setText(mapIpAddr.toString());
	}
	else {
		ui->mapIPsend->setText("127.0.0.1");
	}

	ui->portMapSend->setText(settings.value("mapIpPort", 3456).toString());

	QHostAddress soundIpAddr;
	if (soundIpAddr.setAddress(settings.value("soundIpAddr", "127.0.0.1").toString())) {
		ui->soundIPsend->setText(soundIpAddr.toString());
	}
	else {
		ui->soundIPsend->setText("127.0.0.1");
	}

	ui->soundPortSend->setText(settings.value("soundIpPort", 4455).toString());

	ui->receivePortEdit_2->setText(settings.value("backwardReceiveIpPort", 5002).toString());

	QHostAddress plotIpAddr;
	if (plotIpAddr.setAddress(settings.value("plotIpAddr", "127.0.0.1").toString())) {
		ui->plotIPsend->setText(plotIpAddr.toString());
	}
	else {
		ui->plotIPsend->setText("127.0.0.1");
	}

	ui->portPlotSend->setText(settings.value("plotIpPort", 432).toString());

	settings.endGroup();

	settings.beginGroup("Map");
	ui->showWindchB->setChecked(settings.value("showWindchB", false).toBool());
	ui->showTrajChB->setChecked(settings.value("showTrajChB", false).toBool());
	ui->showRoutechB->setChecked(settings.value("showRoutechB", false).toBool());
	ui->followMainPlainCHB->setChecked(settings.value("followMainPlainCHB", false).toBool());
	ui->isOrientCamchB->setChecked(settings.value("isOrientCamchB", false).toBool());

	ui->centerLat->setText(settings.value("centerLat", 55.564917).toString());
	ui->centerLon->setText(settings.value("centerLon", 38.137015).toString());
	ui->mapHeiihtspinBox->setValue(settings.value("centerH", 30000).toInt());

	settings.endGroup();
}

void MainWindow::writeSettings()
{
	QSettings settings("bird_wrapper.ini", QSettings::IniFormat);

	settings.beginGroup("Mainwindow");
	settings.setValue("geometry", this->geometry());
	settings.endGroup();

	settings.beginGroup("Network");
	settings.setValue("receivePortEdit", ui->receivePortEdit->text());
	settings.setValue("send_from_this", ui->send_from_this->isChecked());
	settings.setValue("mapIpAddr", ui->mapIPsend->text());
	settings.setValue("mapIpPort", ui->portMapSend->text());
	settings.setValue("soundIpAddr", ui->soundIPsend->text());
	settings.setValue("soundIpPort", ui->soundPortSend->text());
	settings.setValue("plotIpPort", ui->plotIPsend->text());
	settings.setValue("plotIpAddr", ui->portPlotSend->text());


	settings.setValue("backwardReceiveIpPort", ui->receivePortEdit_2->text());
	settings.endGroup();

	settings.beginGroup("Map");
	settings.setValue("showWindchB", ui->showWindchB->isChecked());
	settings.setValue("showTrajChB", ui->showTrajChB->isChecked());
	settings.setValue("showRoutechB", ui->showRoutechB->isChecked());
	settings.setValue("followMainPlainCHB", ui->followMainPlainCHB->isChecked());
	settings.setValue("isOrientCamchB", ui->isOrientCamchB->isChecked());

	settings.setValue("centerLat", ui->centerLat->text());
	settings.setValue("centerLon", ui->centerLon->text());
	settings.setValue("centerH", ui->mapHeiihtspinBox->value());
	settings.endGroup();
}


