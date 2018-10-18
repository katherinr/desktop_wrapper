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
    m_udp = new QUdpSocket(this);
    m_udp->bind(QHostAddress::LocalHost, 5001);
    //data = new METEO_DATA;
    connect(m_udp, SIGNAL(readyRead()), SLOT(processDatagrams()));

/*    QTimer* ptimer = new QTimer(this);
    ptimer->setInterval(10);
    ptimer->start();
*/

    // enabled/disable sending for each udp packet
    m_enabledPackets["VISUAL_DATA"] = false;
    m_enabledPackets["TRAFFIC_DATA"] = false;
    m_enabledPackets["CORRECT_DATA"] = false;
    m_enabledPackets["LIMITERS_DATA"] = false;
    m_enabledPackets["LANDING_ZONE_DATA"] = false;
    m_enabledPackets["LIGHTS_DATA"] = false;
    m_enabledPackets["METEO_DATA"] = false;

    QTimer* meteoTimer = new QTimer(this);
    meteoTimer->setObjectName("meteoTimer");
    meteoTimer->setInterval(1000);
    connect(meteoTimer, &QTimer::timeout, this, &UdpServer::meteoTimerTimeout);
    //m_time.start(); // O. asked to send current time in VISUAL_DATA.Other[0];
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
    m_meteoPacket = QByteArray::fromRawData(reinterpret_cast<const char*>(data), sizeof(METEO_DATA));
}

void UdpServer::receiveData()
{

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
        badatagram.resize(m_udp->pendingDatagramSize());
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
    if (m_udp->hasPendingDatagrams())
    {
        while (m_udp->hasPendingDatagrams())
        {
            datagram.resize(m_udp->pendingDatagramSize());

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
