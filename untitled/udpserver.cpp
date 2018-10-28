#include "udpserver.h"
#include <QtNetwork/qudpsocket.h>
#include <QTimer>
#include <QTime>
#include <QDataStream>
#include <QString>
#include <meteo_struct.h>
void printMeteo(const _MeteoData *meteo_data)
{
    qDebug() << "PRINT METEO";
    qDebug() << meteo_data->packet_id;
    qDebug() << meteo_data->visibility;
    qDebug() << meteo_data->cloudBase;
    qDebug() << meteo_data->cloudUpper;
    qDebug() << meteo_data->cloudSize;
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
    qDebug() << meteo_data->starBright;
}

void printAeroData(const _AirportData *_data)
{
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

UdpServer::UdpServer(QObject *parent):
    QObject (parent)
{
   // m_udp = new QUdpSocket(this);
    m_receiver_socket = new QUdpSocket(this);

    connect(m_receiver_socket, SIGNAL(readyRead()),this, SLOT(readDatagram()));
    m_sender_socket =  new QUdpSocket(this);
    connect(m_sender_socket, SIGNAL(readyRead()),this, SLOT(readDatagram()));
    // enabled/disable sending for each udp packet
    m_enabledPackets["VISUAL_DATA"] = false;
    m_enabledPackets["AERODROMS_DATA"] = false;
    m_enabledPackets["BACKWARD_DATA"] = false;
    m_enabledPackets["_MeteoData"] = false;

    QTimer* meteoTimer = new QTimer(this);
    meteoTimer->setObjectName("meteoTimer");
    meteoTimer->setInterval(1000);
    connect(meteoTimer, &QTimer::timeout, this, &UdpServer::meteoTimerTimeout);

    m_time.start(); // O. asked to send current time in VISUAL_DATA.Other[0];
}

void UdpServer::meteoTimerTimeout()
{
    if (m_enabledPackets["METEO_DATA"] == true)
    {
        sendUDPOnce(m_meteoPacket);
    }
}

UdpServer::~UdpServer()
{
    //delete m_udp;
    delete m_receiver_socket;
    delete m_sender_socket;
}

void UdpServer::sendOnce()
{
    qDebug()<<"sending staff";
    if (m_enabledPackets["BACKWARD_DATA"] == true)
    {
        qDebug()<<"m_backwardPacket staff";
        sendUDPOnce(m_backwardPacket);
    }

    if (m_enabledPackets["VISUAL_DATA"] == true)
    {
        qDebug()<<"m_visualPacket staff";
        sendUDPOnce(m_visualPacket);
    }

    if (m_enabledPackets["METEO_DATA"] == true)
    {
        qDebug()<<"m_meteoPacket staff";
        sendUDPOnce(m_meteoPacket);
    }

    if (m_enabledPackets["AERODROMS_DATA"] == true)
    {
         qDebug()<<"m_aerodromePacket staff";
        sendUDPOnce(m_aerodromePacket);
    }
}

void UdpServer::setSendData_METEO(const _MeteoData* data)
{
    //print meteo
    qDebug()<<"meteo set send";
    qDebug() << "_MeteoData size: " << sizeof(_MeteoData) << " and data: " << sizeof(*data);
    printMeteo(data);
    m_meteoPacket = QByteArray::fromRawData(reinterpret_cast<const char*>(data), sizeof(_MeteoData));
    m_enabledPackets["METEO_DATA"] = true;
}

void UdpServer::setSendData_VISUAL(const _MainVisualData *data)
{
    //print meteo
    qDebug()<<"visual set send";
    qDebug() << "_Mainvis size: " << sizeof(_MainVisualData) << " and data: " << sizeof(*data);
    //printMeteo(data);
    m_visualPacket = QByteArray::fromRawData(reinterpret_cast<const char*>(data), sizeof(_MainVisualData));
    m_enabledPackets["VISUAL_DATA"] = true;
}

void UdpServer::setDataFromReceived(const QByteArray &received)
{
    qDebug()<<"setting data from received function";
    QDataStream stream(received);

    unsigned int message_type = received.at(0);

    switch (message_type)
    {
    case  NPR_PACKET_TYPE_METEO_DATA: // meteo
    {
        if (received.size() != sizeof(_MeteoData))
        {
            qDebug()<<received.size()<<"size rec;";
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
            qDebug()<<received.size()<<"size rec;";
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
    setReceivingPort(_port);
    qDebug()<<"listen port is"<<receiving_port;

    if (m_receiver_socket->state() != QAbstractSocket::UnconnectedState)
        {
            m_receiver_socket->disconnectFromHost();
            m_receiver_socket->abort();
        }
        qDebug() <<"try to bind";
        if(!m_receiver_socket->bind(QHostAddress::Any, receiving_port))
        {
            auto error = m_receiver_socket->errorString();
            qWarning() << "Could not create socket: " << QHostAddress(QHostAddress::Any)
                       << ":" << receiving_port << " " << error << "!\n";
            return;
        }

        qInfo() << "Listening on" << QHostAddress(QHostAddress::Any) << ":" << receiving_port << "\n";

}

void UdpServer::setSendData_BACKWARD(const _DataToModel* data)
{
    //print meteo
    m_enabledPackets["BACKWARD_DATA"] = true;
    m_backwardPacket = QByteArray::fromRawData(reinterpret_cast<const char*>(data), sizeof(_DataToModel));
}

void UdpServer::setSendData_AERODROMS(const _AirportData* data)
{
    //print meteo
    printAeroData(data);
    m_enabledPackets["AERODROMS_DATA"] = true;
    m_aerodromePacket = QByteArray::fromRawData(reinterpret_cast<const char*>(data), sizeof(_AirportData));

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

void UdpServer::stopSending()
{
    foreach(QTimer* timer, m_timerList)
    {
        timer->stop();
    }
    qInfo() << "UDP sending stopped.\n";
}

void UdpServer::sendUDPOnce(const QByteArray& packet)
{
    qDebug()<<QHostAddress::LocalHost<<sender_port;
    qDebug()<<"send Once port"<<sender_port;

    if (m_sender_socket->writeDatagram(packet, address2send, sender_port) == -1)
    {
        qWarning() << m_sender_socket->errorString();
    }

}


void UdpServer::readDatagram()
{
    QByteArray datagram;
    QHostAddress sender;
    quint16 senderPort;
    qDebug()<<"reading datagrams";
    // read all availible datagrams
    if (keep_recieve && m_receiver_socket->hasPendingDatagrams())
    {
        qDebug()<<"hasPendingDatagrams";

        while (m_receiver_socket->hasPendingDatagrams())
        {
            datagram.resize(m_receiver_socket->pendingDatagramSize());

            m_receiver_socket->readDatagram(datagram.data(), datagram.size(),
                                &sender, &senderPort);
            qDebug()<<"reading start"<<senderPort;

           // setDataFromReceived(datagram);
        }
    }

    if (datagram.size() == 0)
    {
        qWarning() << m_receiver_socket->errorString();
    }
    else
    {
        // and parse the last one
        emit newDatagram(datagram);
    }
}

void UdpServer::setSendToAddress(const QHostAddress& address, quint16 port)
{
    address2send = address;
    sender_port = port;
    qDebug()<<"address"<<address2send;
    qDebug()<<"sender_port"<<port;
}
