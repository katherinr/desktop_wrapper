#include "udpserver.h"
#include <QtNetwork/qudpsocket.h>
#include <QTimer>
#include <QTime>
#include <QDataStream>
#include <QString>
#include <meteo_struct.h>
void printMeteo(const METEO_DATA *meteo_data)
{
    qDebug() << "PRINT METEO";
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
    m_enabledPackets["METEO_DATA"] = false;

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

void UdpServer::setSendData_METEO(const METEO_DATA* data)
{
    //print meteo
    qDebug()<<"meteo set send";
    qDebug() << "METEO_DATA size: " << sizeof(METEO_DATA) << " and data: " << sizeof(*data);
    printMeteo(data);
    m_meteoPacket = QByteArray::fromRawData(reinterpret_cast<const char*>(data), sizeof(METEO_DATA));
    m_enabledPackets["METEO_DATA"] = true;
}

void UdpServer::setDataFromReceived(const QByteArray &received)
{
    qDebug()<<"setting data from received function";
    QDataStream stream(received);

    unsigned int message_type = received.at(0);

    switch (message_type)
    {
    case 11: // meteo
    {
        if (received.size() != sizeof(METEO_DATA))
        {
            qWarning() << "paket with \"METEO_DATA\" identifier has wrong size.\n";
            break;
        }
        m_meteo_data = *(reinterpret_cast<const METEO_DATA*>(received.data()));
        emit dataUpdated(&m_meteo_data);
        break;
    }
    case 203: // aeroports
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
    case 205: //bckw
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
    }
}

void UdpServer::restartListening(quint16 _port)
{
    setReceivingPort(_port);
    qDebug()<<"listen port is"<<receiving_port;

    if (m_receiver_socket->state() != QAbstractSocket::UnconnectedState)
        {
            //m_socket.disconnectFromHost();
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
    if (m_receiver_socket->hasPendingDatagrams())
    {
        qDebug()<<"hasPendingDatagrams";
        while (m_receiver_socket->hasPendingDatagrams())
        {
            datagram.resize(m_receiver_socket->pendingDatagramSize());

            m_receiver_socket->readDatagram(datagram.data(), datagram.size(),
                                &sender, &senderPort);
              qDebug()<<"reading start"<<senderPort;
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

/*void  UdpServer::receiveMeteo(const QByteArray& received)
{
    const METEO_DATA *_data = (reinterpret_cast<const METEO_DATA*>(received.data()));
    if (_data->message == 11)
    {
        METEO_DATA to_dialog;

        qDebug() << _data->message;
        qDebug() << _data->Visibility;
        qDebug() << _data->CloudBase;
        qDebug() << _data->CloudUpper;
        qDebug() << _data->CloudSize;
        qDebug() << _data->cloudsType;
        qDebug() << _data->cloudsSecondLay;
        qDebug() << _data->SecLayHeight;
        qDebug() << _data->Day;
        qDebug() << _data->Month;
        qDebug() << _data->Hours;
        qDebug() << _data->Minutes;
        qDebug() << _data->local_visibility;
        qDebug() << _data->rain;
        qDebug() << _data->snow;
        qDebug() << _data->hmist;
        qDebug() << _data->wind_speed;
        qDebug() << _data->wind_psi;
       qDebug() << _data->StarBright;

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
        /*QByteArray packet;
        packet = QByteArray::fromRawData((char*)&toClient, sizeof(METEO_DATA));

        if (m_udp.writeDatagram(packet, sender, senderPort) == -1)
        {
            qWarning() << m_socket.errorString();
        }
    }
}*/
