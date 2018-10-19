#include "udpserver.h"
#include <QtNetwork/qudpsocket.h>
#include <QTimer>
#include <QTime>
#include <QDataStream>
#include <QString>
#include <meteo_struct.h>

UdpServer::UdpServer(QObject *parent):
    QObject (parent)
{
    m_receiver_socket = new QUdpSocket(this);
    connect(m_receiver_socket, SIGNAL(readyRead()), SLOT(readDatagram()));

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
    delete m_udp;
    delete m_receiver_socket;
    delete m_sender_socket;
}

void UdpServer::sendOnce()
{
    if (m_enabledPackets["BACKWARD_DATA"] == true)
    {
        sendUDPOnce(m_backwardPacket);
    }

    if (m_enabledPackets["VISUAL_DATA"] == true)
    {
        sendUDPOnce(m_visualPacket);
    }

    if (m_enabledPackets["METEO_DATA"] == true)
    {
        sendUDPOnce(m_meteoPacket);
    }

    if (m_enabledPackets["AERODROMS_DATA"] == true)
    {
        sendUDPOnce(m_aerodromePacket);
    }
}

void UdpServer::setSendData_METEO(const METEO_DATA* data)
{
    //print meteo
    m_meteoPacket = QByteArray::fromRawData(reinterpret_cast<const char*>(data), sizeof(METEO_DATA));
}

void UdpServer::setDataFromReceived(const QByteArray &received)
{
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

void UdpServer::setSendData_BACKWARD(const _DataToModel* data)
{
    //print meteo
    m_backwardPacket = QByteArray::fromRawData(reinterpret_cast<const char*>(data), sizeof(_DataToModel));
}

void UdpServer::setSendData_AERODROMS(const _AirportData* data)
{
    //print meteo
    m_aerodromePacket = QByteArray::fromRawData(reinterpret_cast<const char*>(data), sizeof(_AirportData));
}

void UdpServer::receiveData()
{
    m_receiver_socket->bind(QHostAddress::Any,receiving_port);
    //setDataFromReceived()
}

void UdpServer::startSending()
{
    foreach(QTimer* timer, m_timerList)
    {
        timer->start();
    }
    qInfo() << "UDP sending to " << address2send .toString() << " : "
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
    if (m_udp->writeDatagram(packet, address2send, sender_port) == -1)
    {
        qWarning() << m_udp->errorString();
    }

}

/*
void UdpServer::sendDatagram()
{
    m_udp->bind(QHostAddress::LocalHost,2424);

    QByteArray badatagram;
    QDataStream out(&badatagram, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_3);
    QDateTime dt = QDateTime::currentDateTime();

    out<<dt;

   // qDebug()<<"!!!!!!!!!Sent"<< dt.toString();
    m_udp->writeDatagram(badatagram,QHostAddress::LocalHost,2424);
}
*/
void UdpServer::processDatagrams()
{
    QByteArray badatagram;
    do
    {
        badatagram.resize(m_receiver_socket->pendingDatagramSize());
        m_udp->readDatagram(badatagram.data(),badatagram.size());
    }
    while( m_udp->hasPendingDatagrams());

    qDebug()<<"!!!!!!!!!!!!!!!Received";//<< dateTime.toString();

    //receiveMeteo(badatagram);

}

void UdpServer::readDatagram()
{
    QByteArray datagram;
    QHostAddress sender;
    quint16 senderPort;

    // read all availible datagrams
    if (m_receiver_socket->hasPendingDatagrams())
    {
        while (m_receiver_socket->hasPendingDatagrams())
        {
            datagram.resize(m_receiver_socket->pendingDatagramSize());

            m_udp->readDatagram(datagram.data(), datagram.size(),
                                &sender, &senderPort);
        }
    }

    if (datagram.size() == 0)
    {
        qWarning() << m_udp->errorString();
    }
    else
    {
        // and parse the last one
        emit newDatagram(datagram);
    }
}

void UdpServer::setSendToAddress(const QHostAddress& address, quint16 port)
{
    QString x = address.toString();
    address2send = address;
    sender_port = port;
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
