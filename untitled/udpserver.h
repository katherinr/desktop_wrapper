#ifndef UDPSERVER_H
#define UDPSERVER_H
#include <QtNetwork/qudpsocket.h>
#include <QMainWindow>
#include <meteo_struct.h>
#include <QTime>
class UdpServer: public QObject
{
    Q_OBJECT

public:

    explicit UdpServer(QObject *parent = nullptr);
    virtual    ~UdpServer();

    void setReceivingPort(quint16 _port){receiving_port = _port;}
    void setSendingPort(quint16 _port){sender_port = _port;}
    void setAddress2Send(QHostAddress addr){address2send = addr;}

    void sendUDPOnce(const QByteArray &array);
    void receiveData();

    void meteoTimerTimeout();
    void setSendData_AERODROMS(const _AirportData *data);
    void setSendData_BACKWARD(const _DataToModel *data);
    void setSendToAddress(const QHostAddress& address, quint16 port);
    void setSendData_METEO(const METEO_DATA* data);
    void setDataFromReceived(const QByteArray&);

private slots:
    // void sendDatagram();
    void processDatagrams();
    void readDatagram();

public slots:
    void startSending();
    void stopSending();
    void sendOnce();

signals:
    void newDatagram(const QByteArray&);
    void dataUpdated( METEO_DATA*);
    void dataUpdated( _AirportData*);
    void dataUpdated( _DataToModel*);

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

    QTime m_time;

    METEO_DATA m_meteo_data;
    _AirportData m_airoports_lights_data;
    _DataToModel m_backward_data;
};

#endif // UDPSERVER_H
