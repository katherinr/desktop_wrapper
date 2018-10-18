#ifndef UDPSERVER_H
#define UDPSERVER_H
#include <QtNetwork/qudpsocket.h>
#include <QMainWindow>
#include <meteo_struct.h>

class UdpServer: public QObject
{
    Q_OBJECT

public:

    explicit UdpServer(QObject *parent = nullptr);
    virtual    ~UdpServer();
    // void receiveMeteo(const QByteArray& received);
    void setReceivingPort(quint16 _port){receiving_port = _port;}
    void setSendingPort(quint16 _port){sender_port = _port;}
    void setAddress2Send(QHostAddress addr){address2send = addr;}
    void sendUDPOnce(const QByteArray &array);
    void receiveData();
    void setSendData_METEO(const METEO_DATA* data);
    void meteoTimerTimeout();
private slots:
    // void sendDatagram();
    void processDatagrams();
    void readDatagram();
    void startSending();
    void stopSending();
    void sendOnce();

signals:
    void newDatagram(const QByteArray&);
private:
    QList<QTimer*> m_timerList;
    QUdpSocket *m_udp;
    QUdpSocket *m_sender_socket;
    QUdpSocket *m_receiver_socket;
    QHostAddress address2send;
    quint16 sender_port=0;
    quint16 receiving_port=0;

    //пакеты
    QByteArray m_meteoPacket;
    QByteArray m_aerodromePacket;
    QByteArray m_visualPacket;
    QByteArray m_backwardPacket;
    QMap<QString, bool> m_enabledPackets;
};

#endif // UDPSERVER_H
