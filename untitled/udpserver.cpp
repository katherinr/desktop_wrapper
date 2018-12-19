#include "udpserver.h"
#include <QtNetwork/qudpsocket.h>
#include <QTimer>
#include <QTime>
#include <QDataStream>
#include <QString>
#include "meteo_struct.h"
#include "utilities.h"

UdpServer::UdpServer(QObject *parent) :
	QObject(parent)
{
	//del?
	m_receiver_socket = new QUdpSocket(this);
	connect(m_receiver_socket, SIGNAL(readyRead()), this, SLOT(readDatagram()));

	m_sender_socket = new QUdpSocket(this);
	connect(m_sender_socket, SIGNAL(readyRead()), this, SLOT(readDatagram()));

	m_map_sender_socket = new QUdpSocket(this);
	connect(m_map_sender_socket, SIGNAL(readyRead()), this, SLOT(readDatagram()));

	//del?
	m_backward_sender_socket = new QUdpSocket(this);
	connect(m_backward_sender_socket, SIGNAL(readyRead()), this, SLOT(backwardReadDatagram()));

	m_sound_sender_socket = new QUdpSocket(this);
	//connect(m_sound_sender_socket, SIGNAL(readyRead()), this, SLOT(readDatagram()));
	m_plots_socket = new QUdpSocket(this);
	
	// enabled/disable sending for each udp packet
	m_enabledPackets["VISUAL_DATA"] = false;
	m_enabledPackets["AERODROMS_DATA"] = false;
	m_enabledPackets["BACKWARD_DATA"] = false;
	m_enabledPackets["METEO_DATA"] = false;
	m_enabledPackets["MAP_DATA"] = false;
	/*/////////////////timers////////////////*/

	QTimer* visTimer = new QTimer(this);
	visTimer->setObjectName("visTimer");
	visTimer->setInterval(10);
	connect(visTimer, &QTimer::timeout, this, &UdpServer::visTimerTimeout);

	QTimer* aerodromsTimer = new QTimer(this);
	aerodromsTimer->setObjectName("aerodromsTimer");
	aerodromsTimer->setInterval(1000);
	connect(aerodromsTimer, &QTimer::timeout, this, &UdpServer::aerodromsTimerTimeout);

	QTimer* meteoTimer = new QTimer(this);
	meteoTimer->setObjectName("meteoTimer");
	meteoTimer->setInterval(1000);
	connect(meteoTimer, &QTimer::timeout, this, &UdpServer::meteoTimerTimeout);

	  QTimer* backwardTimer = new QTimer(this);
	  backwardTimer->setObjectName("backwardTimer");
	  backwardTimer->setInterval(10);
	  connect(backwardTimer, &QTimer::timeout, this, &UdpServer::backwTimerTimeout);		

	QTimer* mapTimer = new QTimer(this);
	mapTimer->setObjectName("mapTimer");
	mapTimer->setInterval(10);
	connect(mapTimer, &QTimer::timeout, this, &UdpServer::mapTimerTimeout);

	m_timerList << visTimer << aerodromsTimer << meteoTimer << backwardTimer <<mapTimer;

	m_olegSoundPacker.Initialize(0.01); // шаг моедлирования модели откуда взять
}

UdpServer::~UdpServer()
{
	delete m_receiver_socket;
	delete m_sender_socket;
	delete m_map_sender_socket;
	delete m_backward_sender_socket;
	delete m_sound_sender_socket;
	delete m_plots_socket;
}

void UdpServer::changeTimerInterval(const QString& timerObjName, int interval)
{
	QTimer* timer = this->findChild<QTimer*>(timerObjName);

	if (timer)
	{
		timer->setInterval(interval);
	}
	else {
		qDebug() << "Timer not found: " << timerObjName << "\n";
	}
}

void UdpServer::meteoTimerTimeout()
{
	if (m_enabledPackets["METEO_DATA"] == true)
	{
		QByteArray meteoData_ = QByteArray::fromRawData(reinterpret_cast<const char*>(m_meteoData), sizeof(_MeteoData));
		_MeteoData* meteo_ptr = reinterpret_cast<_MeteoData*>(meteoData_.data());

		meteo_ptr->model_simulation_time = m_time.elapsed();
		//sendUDPOnce(meteoData_);
	}
}

void UdpServer::visTimerTimeout()
{
	if (m_enabledPackets["VISUAL_DATA"] == true)
	{
		QByteArray visualData = QByteArray::fromRawData(reinterpret_cast<const char*>(m_visualData), sizeof(_MainVisualData));
		_MainVisualData* visual_ptr = reinterpret_cast<_MainVisualData*>(visualData.data());

		visual_ptr->model_simulation_time = m_time.elapsed();
		//sendUDPOnce(visualData);
	}
}

void UdpServer::aerodromsTimerTimeout()
{
	if (m_enabledPackets["AERODROMS_DATA"] == true)
	{
		//qDebug() << "m_aerodromePacket staff";
		QByteArray aerodrome_data = QByteArray::fromRawData(reinterpret_cast<const char*>(m_airoportsData), sizeof(_AirportData));
		_AirportData* aerodrome_ptr = reinterpret_cast<_AirportData*>(aerodrome_data.data());

		aerodrome_ptr->model_simulation_time =  m_time.elapsed();
		//sendUDPOnce(aerodrome_data);
	}
}

void UdpServer::backwTimerTimeout()
{
	if (m_enabledPackets["BACKWARD_DATA"] == true)
	{
		QByteArray d2m = QByteArray::fromRawData(reinterpret_cast<const char*>(m_backwardData), sizeof(_DataToModel));
		_DataToModel* backw_ptr = reinterpret_cast<_DataToModel*>(d2m.data());

		QByteArray visualData = QByteArray::fromRawData(reinterpret_cast<const char*>(m_visualData), sizeof(_MainVisualData));
		_MainVisualData* visual_ptr = reinterpret_cast<_MainVisualData*>(visualData.data());

		backw_ptr->p_coord.H = visual_ptr->p_coord.H;
		backw_ptr->p_coord.X = visual_ptr->p_coord.X;
		backw_ptr->p_coord.Z = visual_ptr->p_coord.Z;

		backw_ptr->simulation_time = visual_ptr->model_simulation_time;

		//sendBACKWARDUDPOnce(d2m);
	}
}

void UdpServer::mapTimerTimeout()
{
	if (m_enabledPackets["MAP_DATA"] == true)
	{
		QByteArray visualData = QByteArray::fromRawData(reinterpret_cast<const char*>(m_visualData), sizeof(_MainVisualData));
		_MainVisualData* visual_ptr = reinterpret_cast<_MainVisualData*>(visualData.data());

		QByteArray aerodrome_data = QByteArray::fromRawData(reinterpret_cast<const char*>(m_airoportsData), sizeof(_AirportData));
		_AirportData* aerodrome_ptr = reinterpret_cast<_AirportData*>(aerodrome_data.data());

		m_mapData.seconds = m_time.elapsed();//visual_ptr->model_simulation_time; 
		MAP_fill_route(&m_mapData, visual_ptr, aerodrome_ptr);
		m_mapPacket = QByteArray::fromRawData(reinterpret_cast<const char*>(&m_mapData), sizeof(UDP_data_t));

		//sendMAPUDPOnce(m_mapPacket);
	}
}

void UdpServer::stopSending()
{
	foreach(QTimer* timer, m_timerList)
	{
		timer->stop();
	}
	qInfo() << "UDP sending stopped.\n";
}

void UdpServer::sendOnce()
{
	//qDebug()<<"sending staff";
	if (m_enabledPackets["BACKWARD_DATA"] == true)
	{
		//  qDebug()<<"m_backwardPacket staff";
		_DataToModel* backw_ptr = reinterpret_cast<_DataToModel*>(m_backwardPacket.data());
		_MainVisualData* visual_ptr = reinterpret_cast<_MainVisualData*>(m_visualPacket.data());

		backw_ptr->p_coord.H = visual_ptr->p_coord.H;
		backw_ptr->p_coord.X = visual_ptr->p_coord.X;
		backw_ptr->p_coord.Z = visual_ptr->p_coord.Z;

		backw_ptr->simulation_time = visual_ptr->model_simulation_time;
		sendUDPOnce(m_backwardPacket);
	}

	if (m_enabledPackets["METEO_DATA"] == true)
	{
		//  qDebug()<<"m_meteoPacket staff"<<*m_meteoPacket.begin();
		 // printMeteo(&m_meteo_data);
		_MeteoData* meteo_ptr = reinterpret_cast<_MeteoData*>(m_meteoPacket.data());
	//	meteo_ptr->model_simulation_time = m_time.elapsed();
		sendUDPOnce(m_meteoPacket);
	}

	if (m_enabledPackets["AERODROMS_DATA"] == true)
	{
		//  qDebug()<<"m_aerodromePacket staff";
		_AirportData* aerodrome_ptr = reinterpret_cast<_AirportData*>(m_aerodromePacket.data());
		//aerodrome_ptr->model_simulation_time = m_time.elapsed();
		sendUDPOnce(m_aerodromePacket);
	}

	if (m_enabledPackets["VISUAL_DATA"] == true)
	{
		// qDebug()<<"m_visualPacket staff";
	 //    printVisualData(&m_vis_data);
		_MainVisualData* visual_ptr = reinterpret_cast<_MainVisualData*>(m_visualPacket.data());
		sendUDPOnce(m_visualPacket);
	}

	if (m_enabledPackets["MAP_DATA"] == true)
	{
		//	qDebug() << "map staff";
		UDP_data_t* map_ptr = reinterpret_cast<UDP_data_t*>(m_mapPacket.data());
		//	map_ptr->simulation_time = m_time.elapsed();

		sendMAPUDPOnce(m_mapPacket);
	}
}

void UdpServer::setSendData_METEO(const _MeteoData* data, bool check)
{
	m_meteoPacket = QByteArray::fromRawData(reinterpret_cast<const char*>(data), sizeof(_MeteoData));
	m_enabledPackets["METEO_DATA"] = check;
	m_meteoData = data;
}

void UdpServer::setSendData_BACKWARD(const _DataToModel* data, bool check)
{
	//print meteo
	m_enabledPackets["BACKWARD_DATA"] = check;
	m_backwardPacket = QByteArray::fromRawData(reinterpret_cast<const char*>(data), sizeof(_DataToModel));
	m_backwardData = data;
}

void UdpServer::setSendData_AERODROMS(const _AirportData* data, bool check)
{
	//print meteo
//	printAeroData(data);
	m_enabledPackets["AERODROMS_DATA"] = check;
	m_aerodromePacket = QByteArray::fromRawData(reinterpret_cast<const char*>(data), sizeof(_AirportData));
	m_airoportsData = data;
}

void UdpServer::setSendData_VISUAL(const _MainVisualData *data, bool check)
{
	m_visualPacket = QByteArray::fromRawData(reinterpret_cast<const char*>(data), sizeof(_MainVisualData));
	m_enabledPackets["VISUAL_DATA"] = check;
	m_visualData = data;
}

//void UdpServer::setSendData_MAP(MAP_CONTROL_UDP* data, bool check)
//{
//	qDebug() << "map set send";
//	qDebug() << "_Mainvis size: " << sizeof(UDP_data_t) << " and data: " << sizeof(*data);
//	//printMeteo(data);
//
//	m_mapPacket = QByteArray::fromRawData(reinterpret_cast<const char*>(data), sizeof(UDP_data_t));
//
//	m_enabledPackets["MAP_DATA"] = check;
//
//	m_mapControlData = data;
//}
bool aeroports_compare( char d1[4],  char d2[4])
{
	if (d1[0] == d2[0] &&
		d1[1] == d2[1] &&
		d1[2] == d2[2] &&
		d1[3] ==  d2[3])
		return true;
	return false;
}
void UdpServer::setDataFromReceived(const QByteArray &received)
{
	//  qDebug()<<"setting data from received function";
	QDataStream stream(received);

	unsigned char message_type = received.at(0);

	switch (message_type)
	{
	case  NPR_PACKET_TYPE_METEO_DATA: // meteo
	{
		if (received.size() != sizeof(_MeteoData))
		{
			//   qDebug()<<received.size()<<"size rec;";
			qDebug() << "_MeteoData size: " << sizeof(_MeteoData) << " and data: " << received.size();

			qWarning() << "paket with \"METEO_DATA\" identifier has wrong size.\n";
			break;
		}
		m_meteo_data = *(reinterpret_cast<const _MeteoData*>(received.data()));
		emit dataUpdated(&m_meteo_data);
		break;
	}
	case NPR_PACKET_TYPE_AIRPORT_DATA: // aeroports
	{
		if (received.size() != sizeof(_AirportData))
		{
			qWarning() << "paket with \"_AirportData\" identifier has wrong size.\n";
			break;
		}

		m_airoports_lights_data = *(reinterpret_cast<const _AirportData*>(received.data()));
		if (!aeroports_compare(DEPARTURE_AIRPORT_CODE, m_airoports_lights_data.DEPARTURE_AIRPORT_CODE) &&
			!aeroports_compare(ARRIVAL_AIRPORT_CODE, m_airoports_lights_data.ARRIVAL_AIRPORT_CODE))
		{
			m_mapData.updateRoute++;

			DEPARTURE_AIRPORT_CODE[0] = m_airoports_lights_data.DEPARTURE_AIRPORT_CODE[0];
			DEPARTURE_AIRPORT_CODE[1] = m_airoports_lights_data.DEPARTURE_AIRPORT_CODE[1];
			DEPARTURE_AIRPORT_CODE[2] = m_airoports_lights_data.DEPARTURE_AIRPORT_CODE[2];
			DEPARTURE_AIRPORT_CODE[3] = m_airoports_lights_data.DEPARTURE_AIRPORT_CODE[3];

			ARRIVAL_AIRPORT_CODE[0] = m_airoports_lights_data.ARRIVAL_AIRPORT_CODE[0];
			ARRIVAL_AIRPORT_CODE[1] = m_airoports_lights_data.ARRIVAL_AIRPORT_CODE[1];
			ARRIVAL_AIRPORT_CODE[2] = m_airoports_lights_data.ARRIVAL_AIRPORT_CODE[2];
			ARRIVAL_AIRPORT_CODE[3] = m_airoports_lights_data.ARRIVAL_AIRPORT_CODE[3];
		}


		emit dataUpdated(&m_airoports_lights_data);
		break;
	}
	case NPR_PACKET_TYPE_BACK_DATA: //bckw
	{
		if (received.size() != sizeof(_DataToModel))
		{
			qWarning() << "paket with \"_DataToModel\" identifier has wrong size.\n";
			break;
		}
		m_backward_data = *(reinterpret_cast<const _DataToModel*>(received.data()));
		emit dataUpdated(&m_backward_data);
		break;
	}
	case  NPR_PACKET_TYPE_VISUAL_DATA: // visual
	{
		if (received.size() != sizeof(_MainVisualData))
		{
			//  qDebug()<<received.size()<<"size rec;";
			qDebug() << "_MainVisualData size: " << sizeof(_MainVisualData) << " and data: " << received.size();

			qWarning() << "paket with \"_MainVisualData\" identifier has wrong size.\n";
			break;
		}
		m_vis_data = *(reinterpret_cast<const _MainVisualData*>(received.data()));
		emit dataUpdated(&m_vis_data);
		break;
	}
	}
}

void UdpServer::restartListening(quint16 _port)
{
	if(!setReceivingPort(_port)) {
		return;
	}
	// qDebug()<<"listen port is"<<receiving_port;

	if (m_receiver_socket->state() != QAbstractSocket::UnconnectedState)
	{
		//   m_receiver_socket->disconnectFromHost();
		m_receiver_socket->abort();
	}
	// qDebug() <<"try to bind";
	if (!m_receiver_socket->bind(QHostAddress::Any, receiving_port))
	{
		auto error = m_receiver_socket->errorString();
		qWarning() << "Could not create socket: " << QHostAddress(QHostAddress::Any)
			<< ":" << receiving_port << " " << error << "!\n";
		return;
	}

	qInfo() << "Listening on" << QHostAddress(QHostAddress::Any) << ":" << receiving_port << "\n";

}

void UdpServer::restartBACKWARDListening(quint16 _port)
{
	if (!setBackwardReceivingPort(_port)) {
		return;
	}
	//qDebug() << "listen port is" << backward_receive_port;

	if (m_backward_sender_socket->state() != QAbstractSocket::UnconnectedState)
	{
		//   m_receiver_socket->disconnectFromHost();
		m_backward_sender_socket->abort();
	}
	//qDebug() << "try to bind";
	if (!m_backward_sender_socket->bind(QHostAddress::Any, backward_receive_port))
	{
		auto error = m_backward_sender_socket->errorString();
		qWarning() << "Could not create socket: " << QHostAddress(QHostAddress::Any)
			<< ":" << backward_receive_port << " " << error << "!\n";
		return;
	}

	qInfo() << "Listening on" << QHostAddress(QHostAddress::Any) << ":" << backward_receive_port << "\n";

}

void UdpServer::startSending()
{
	foreach(QTimer* timer, m_timerList)
	{
		timer->start();
	}

	qInfo() << "UDP sending to " << address2send.toString() << " : "
		<< QString::number(sender_port) << " started.";
}

void UdpServer::sendUDPOnce(const QByteArray& packet)
{
	if (m_sender_socket->writeDatagram(packet, address2send, sender_port) == -1)
	{
		qWarning() << m_sender_socket->errorString();
	}

}

void UdpServer::sendBACKWARDUDPOnce(const QByteArray& packet)
{
	if (m_backward_sender_socket->writeDatagram(packet, backward_address2send, backward_sender_port) == -1)
	{
		qWarning() << m_backward_sender_socket->errorString();
	}

}
void UdpServer::sendMAPUDPOnce(const QByteArray& packet)
{
	auto address = map_address2send.toString();

	if (m_map_sender_socket->writeDatagram(packet, map_address2send, map_sender_port) == -1)
	{
		qWarning() << m_map_sender_socket->errorString();
	}

}

void UdpServer::sendSOUNDUDPOnce(const QByteArray & packet)
{
	if (m_sound_sender_socket->writeDatagram(packet, SOUND_address2send, SOUND_sender_port) == -1)
	{
		qWarning() << m_sound_sender_socket->errorString();
	}
}


void UdpServer::readDatagram()
{
	QByteArray datagram;
	QHostAddress sender;
	quint16 senderPort;
	//  qDebug()<<"reading datagrams";
	  // read all availible datagrams
	if (m_receiver_socket->hasPendingDatagrams())
	{
		//  qDebug()<<"hasPendingDatagrams";

		while (m_receiver_socket->hasPendingDatagrams())
		{
			datagram.resize(m_receiver_socket->pendingDatagramSize());

			m_receiver_socket->readDatagram(datagram.data(), datagram.size(),
				&sender, &senderPort);

			if (datagram.size() == 0)
			{
				qWarning() << m_receiver_socket->errorString();
			}
			else
			{
				//отсылка дальше
				if (!m_send_from_this)
				{
				//	sendUDPOnce(datagram);
					  
					 //send map indication
					MAP_fill_route(&m_mapData, &m_vis_data, &m_airoports_lights_data);


					m_mapData.seconds = m_vis_data.model_simulation_time;
					//костыль!!! 	   fixme
				//	if (m_airoports_lights_data)
				//	m_mapData.updateRoute++;

					m_mapPacket = QByteArray::fromRawData(reinterpret_cast<const char*>(&m_mapData), sizeof(UDP_data_t));
					sendMAPUDPOnce(m_mapPacket);
					
					send_to_sound(m_vis_data, m_guiSoundSettings);
					send_to_plot(m_vis_data);
				}

				setDataFromReceived(datagram);
			}
		}
	}

}

void UdpServer::onNewGuiMapSetting(const MAP_CONTROL_UDP& mapControl)
{
	auto x = sizeof(MAP_CONTROL_UDP);

	if (
		x = m_map_sender_socket->writeDatagram(reinterpret_cast<const char*>(&mapControl),
			sizeof(MAP_CONTROL_UDP), map_control_address2send, map_control_sender_port) == -1
		)
	{
		qWarning() << Q_FUNC_INFO << map_control_address2send.toString() << ":" << map_control_sender_port << " " << m_map_sender_socket->errorString();
	}
}

void UdpServer::backwardReadDatagram()
{
	QByteArray datagram;
	QHostAddress sender;
	quint16 senderPort;

	if (m_backward_sender_socket->hasPendingDatagrams())
	{
		while (m_backward_sender_socket->hasPendingDatagrams())
		{
			datagram.resize(m_backward_sender_socket->pendingDatagramSize());

			m_backward_sender_socket->readDatagram(datagram.data(), datagram.size(),
				&sender, &senderPort);

			if (datagram.size() == 0)
			{
				qWarning() << m_backward_sender_socket->errorString();
			}
			else
			{
					setDataFromReceived(datagram);
					//sendBACKWARDUDPOnce(datagram);
			}
		}
	}

}

void UdpServer::send_to_sound(const _MainVisualData & visualData, const SOUND_FUNC_SETTINGS& guiSoundSettings)
{
	SOUND_FUNC_INPUT soundInput{ 0 };

	soundInput.simulation_status = visualData.SimulationRunning;
	soundInput.model_time = visualData.model_simulation_time;
	soundInput.N_left_curr = visualData.N2_L;
	soundInput.N_rght_curr = visualData.N2_R;
	soundInput.Flaps_curr = visualData.Flaps;
	soundInput.Abrks_curr = 6;
	soundInput.LG_curr = 7;
	soundInput.LG_touchdown_nose = 8;
	soundInput.LG_touchdown_left = 9;
	soundInput.LG_touchdown_rght = 10;
	soundInput.beep = 11;

	m_olegSoundPacker.Update(soundInput, guiSoundSettings);

	if (
		m_sound_sender_socket->writeDatagram(reinterpret_cast<const char*>(m_olegSoundPacker.getSendPacketPtr()),
			sizeof(SOUND_FUNC_INPUT), SOUND_address2send, SOUND_sender_port) == -1
		)
	{
		qWarning() << Q_FUNC_INFO << SOUND_address2send.toString() <<":" << SOUND_sender_port << " " << m_sound_sender_socket->errorString();
	}
}

void UdpServer::send_to_plot(const _MainVisualData & visualData)
{

	if (visualData.SimulationReset) {
		// send clear msg 
		auto clearMsg = m_plotPacker.packClearRequest();
		if (
			m_plots_socket->writeDatagram(clearMsg.data(), clearMsg.size(), plot_address2send, plot_sender_port) == -1
			)
		{
			qWarning() << Q_FUNC_INFO << plot_address2send.toString() << ":" << plot_sender_port << " " << m_plots_socket->errorString();
		}

		// send channel names msg 
		auto namesMsg = m_plotPacker.packChannelNamesFromFile("plot_channel_names.json");
		if (namesMsg.size()) {
			if (
				m_plots_socket->writeDatagram(namesMsg.data(), namesMsg.size(), plot_address2send, plot_sender_port) == -1
				)
			{
				qWarning() << Q_FUNC_INFO << plot_address2send.toString() << ":" << plot_sender_port << " " << m_plots_socket->errorString();
			}
		}
	}

	// set data msg
	auto dataMsg = m_plotPacker.packVisualMessage(visualData);
	if (
		m_plots_socket->writeDatagram(dataMsg.data(), dataMsg.size(), plot_address2send, plot_sender_port) == -1
		)
	{
		qWarning() << Q_FUNC_INFO << plot_address2send.toString() << ":" << plot_sender_port << " " << m_plots_socket->errorString();
	}
}

void UdpServer::onNewGuiSoundSettings(const SOUND_FUNC_SETTINGS& newSettings)
{
	m_guiSoundSettings = newSettings;
}

void UdpServer::setSendToAddress(const QHostAddress& address, quint16 port)
{
	address2send = address;
	sender_port = port;
}