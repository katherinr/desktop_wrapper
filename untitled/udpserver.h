#ifndef UDPSERVER_H
#define UDPSERVER_H
#include <QtNetwork/qudpsocket.h>
#include <QMainWindow>
#include "meteo_struct.h"
#include <QTime>
class UdpServer: public QObject
{
    Q_OBJECT

public:

    explicit UdpServer(QObject *parent = nullptr);
    virtual    ~UdpServer();

    bool setReceivingPort(quint16 _port)
    {
        if (receiving_port != _port)
        {
            receiving_port = _port;
            return true;
        }

        return false;
    }

    bool setSendingPort(quint16 _port)
    {
        if (sender_port != _port)
        {
            sender_port = _port;
            return  true;
        }
        return false;
    }

    void setAddress2Send(QHostAddress addr){address2send = addr;}
    quint16 getReceivingPort(){return receiving_port;}
    void sendUDPOnce(const QByteArray &array);
    void setPacketSendEnabled(const QString& paketName, bool enabled);
    void meteoTimerTimeout();
    void visTimerTimeout();
    void aerodromsTimerTimeout();
    void backwTimerTimeout();
    void changeTimerInterval(const QString& timerObjName, int interval);
    void setSendData_AERODROMS(const _AirportData *data);
    void setSendData_BACKWARD(const _DataToModel *data);
    void setSendToAddress(const QHostAddress& address, quint16 port);
    void setSendData_METEO(const _MeteoData* data);
    void setSendData_VISUAL(const _MainVisualData* data);
    void setDataFromReceived(const QByteArray&);
    void restartListening(quint16 _port);

    //private slots:
public slots:
    void startSending();
    void stopSending();
    void sendOnce();
    void readDatagram();

signals:
    void newDatagram(const QByteArray&);
    void dataUpdated( _MeteoData*);
    void dataUpdated( _AirportData*);
    void dataUpdated( _DataToModel*);
    void dataUpdated( _MainVisualData*);
public:
    bool keep_recieve = false;
	QTime m_time;
private:
    QUdpSocket *m_receiver_socket;
    QList<QTimer*> m_timerList;
    // QUdpSocket *m_udp;
    QUdpSocket *m_sender_socket;

    QHostAddress address2send;
    quint16 sender_port=0;
    quint16 receiving_port=0;

    //пакеты
    QByteArray m_meteoPacket;
    QByteArray m_aerodromePacket;
    QByteArray m_visualPacket;
    QByteArray m_backwardPacket;
    QMap<QString, bool> m_enabledPackets;

    

    _MeteoData m_meteo_data;
    _AirportData m_airoports_lights_data;
    _DataToModel m_backward_data;
    _MainVisualData m_vis_data;
};

#endif // UDPSERVER_H
