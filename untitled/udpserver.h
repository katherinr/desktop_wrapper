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
	bool setMAPSendingPort(quint16 _port)
	{
		if (map_sender_port != _port)
		{
			map_sender_port = _port;
			return  true;
		}
		return false;
	}

	bool setBackwardSendingPort(quint16 _port)
	{
		if (backward_sender_port != _port)
		{
			backward_sender_port = _port;
			return  true;
		}
		return false;
	}

	bool setBackwardReceivingPort(quint16 _port)
	{
		if (backward_receive_port != _port)
		{
			backward_receive_port = _port;
			return  true;
		}
		return false;
	}

	void setBackwardAddress2Send(QHostAddress addr){backward_address2send = addr; }
    void setAddress2Send(QHostAddress addr){address2send = addr;}
	void setMAPAddress2Send(QHostAddress addr) { map_address2send = addr; }
	void setBackwReceive(bool check) { keep_backw_receive = check; }
	void restartBACKWARDListening(quint16 _port);
	quint16 getReceivingPort(){return receiving_port;}
    void sendUDPOnce(const QByteArray &array);
    void setPacketSendEnabled(const QString& paketName, bool enabled);
    void meteoTimerTimeout();
    void visTimerTimeout();
    void aerodromsTimerTimeout();
    void backwTimerTimeout();
	void mapTimerTimeout();
    void changeTimerInterval(const QString& timerObjName, int interval);
    void setSendData_AERODROMS(const _AirportData *data, bool check);
    void setSendData_BACKWARD(const _DataToModel *data, bool check);
    void setSendToAddress(const QHostAddress& address, quint16 port);
    void setSendData_METEO(const _MeteoData* data, bool check);
    void setSendData_VISUAL(const _MainVisualData* data, bool check);
	void setSendData_MAP(const UDP_data_t* data, bool check);
    void setDataFromReceived(const QByteArray&);
    void restartListening(quint16 _port);
	void sendMAPUDPOnce(const QByteArray& packet);
	void startSending();
	void stopSending();
	void sendBACKWARDUDPOnce(const QByteArray& packet);


    //private slots:
public slots:

    void sendOnce();
    void readDatagram();
	void backwardReadDatagram();
signals:
    void newDatagram(const QByteArray&);
    void dataUpdated( _MeteoData*);
    void dataUpdated( _AirportData*);
    void dataUpdated( _DataToModel*);
    void dataUpdated( _MainVisualData*);
public:
    bool keep_recieve = false;
	bool keep_backw_receive = false;
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
	QByteArray m_mapPacket;
    QMap<QString, bool> m_enabledPackets;

    _MeteoData m_meteo_data;
    _AirportData m_airoports_lights_data;
    _DataToModel m_backward_data;
    _MainVisualData m_vis_data;

	const _MainVisualData* m_visualData;
	const _MeteoData* m_meteoData;
	const _AirportData* m_airoportsData;
	const _DataToModel* m_backwardData;
	const UDP_data_t   *m_mapData;
	//backward
	QUdpSocket *m_backward_sender_socket;
	QUdpSocket *m_backward_receive_socket;
	QHostAddress backward_address2send = QHostAddress("127.0.0.1");
	quint16 backward_sender_port = 5003;
	quint16 backward_receive_port = 5001;
	//map
	QUdpSocket *m_map_sender_socket;
	QHostAddress map_address2send = QHostAddress("127.0.0.1");
	quint16 map_sender_port = 3456;
};

#endif // UDPSERVER_H
