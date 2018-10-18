#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

void deep_meteo_copy(METEO_DATA *_data,METEO_DATA *data )
{
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
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*//////////////////////////////////////////////*/

    m_server = new UdpServer(this);
    //connect(ui->sendOnceButton, SIGNAL(clicked()), m_server, SLOT(m_udp->processDatagrams()));
//    connect(ui->startStopSendButton, SIGNAL(clicked()), m_server, SLOT(m_udp->processDatagram()));
    /*/////////////////////////////////////////////*/

    meteo_ui = new meteoWindow;
    aerodrom_ui = new AirportsDialog;
    backward_ui = new backwardW;
    /*/////////////////////////////////////////////*/
    //show subwindows

    connect(ui->meteoPushButton, SIGNAL(clicked()), meteo_ui, SLOT(show()));
   // connect(meteo_ui, SIGNAL(sendData(METEO_DATA*)), this, SLOT(receiveData(METEO_DATA*)));
    connect(ui->AerodromsLightsPB, SIGNAL(clicked()), aerodrom_ui, SLOT(show()));
    connect(ui->CorrectPB, SIGNAL(clicked()), backward_ui, SLOT(show()));
    connect(ui->meteoCheckBox, &QPushButton::toggled, this, &MainWindow::onCheckBoxChecked);
    //connect(aerodrom_ui, SIGNAL(sendData(_AirportData*)), this, SLOT(receiveData(_AirportData*)));
}

void MainWindow::onCheckBoxChecked(bool state)
{
    QCheckBox* sender = qobject_cast<QCheckBox*>(this->sender());
    Q_ASSERT(sender != nullptr);

    QString structName = sender->property("struct").toString();

    m_server->setSendData_METEO(meteo_data);
}


void MainWindow::receiveData(METEO_DATA * _data)
{
    //auto data = m_dataProvider->getMeteoData();

    meteo_data->message = _data->message;
    meteo_data->Visibility = _data->Visibility;
    meteo_data->CloudBase = _data->CloudBase;
    meteo_data->CloudUpper = _data->CloudUpper;
    meteo_data->CloudSize = _data->CloudSize;
    meteo_data->cloudsType = _data->cloudsType;
    meteo_data->cloudsSecondLay = _data->cloudsSecondLay;
    meteo_data->SecLayHeight = _data->SecLayHeight;
    meteo_data->Day = _data->Day;
    meteo_data->Month = _data->Month;
    meteo_data->Hours = _data->Hours;
    meteo_data->Minutes = _data->Minutes;
    meteo_data->local_visibility = _data->local_visibility;
    meteo_data->rain = _data->rain;
    meteo_data->snow = _data->snow;
    meteo_data->hmist = _data->hmist;
    meteo_data->wind_speed = _data->wind_speed;
    meteo_data->wind_psi = _data->wind_psi;
    meteo_data->StarBright = _data->StarBright;
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


MainWindow::~MainWindow()
{
    delete ui;
    delete meteo_ui;
    delete aerodrom_ui;
    delete backward_ui;
}

void MainWindow::on_receivePortEdit_editingFinished()
{
    m_server->setReceivingPort(ui->receivePortEdit->text().toInt());
    qDebug() << "osendPortEdit"<<ui->receivePortEdit->text().toInt();
}

void MainWindow::on_startStopSendButton_toggled(bool checked)
{
    if (checked)
    {
        ui->startStopSendButton->setText("Stop");
       // m_server->setSendToAddress(QHostAddress(ui->sendIPEdit->text()), ui->sendPortEdit->text().toInt());
      //  m_udpManager->changeTimerInterval("meteoTimer", ui->meteoIntervalEdit->text().toUInt());
       // m_udpManager->startSending();

        ui->sendOnceButton->setEnabled(false);
    }
    else
    {
        ui->startStopSendButton->setText("Start send");
       // m_udpManager->stopSending();
        ui->sendOnceButton->setEnabled(true);
    }
}


void MainWindow::on_mainVisCheckBox_toggled(bool checked)
{
    ui->mainVisIntervalEdit->setEnabled(checked);
}

void MainWindow::on_meteoCheckBox_clicked(bool checked)
{
    ui->meteoIntervalEdit->setEnabled(checked);
}

void MainWindow::on_lightsCheckBox_clicked(bool checked)
{
    ui->lightsIntervalEdit->setEnabled(checked);
}

void MainWindow::on_BackwardCheckBox_clicked(bool checked)
{
    ui->backwardIntervalEdit->setEnabled(checked);
}

void MainWindow::on_sendOnceButton_pressed()
{
    qDebug() << "on_sendOnceButton_pressed start";
     m_server->setSendData_METEO(meteo_data);
    //if (m_server->data->message==11)
      //  deep_meteo_copy(m_server->data,meteo_ui->data);
    qDebug() << "on_sendOnceButton_pressed finish";
}

void MainWindow::on_sendIPEdit_editingFinished()
{
    m_server->setAddress2Send(QHostAddress(ui->sendIPEdit->text()));
    qDebug() << "setAddress2Send"<<QHostAddress(ui->sendIPEdit->text());
}

void MainWindow::on_sendPortEdit_editingFinished()
{
    m_server->setSendingPort(ui->sendPortEdit->text().toInt());
    qDebug() << "osendPortEdit"<<ui->sendPortEdit->text().toInt();
}

void MainWindow::on_okPB_pressed()
{
    //save to files? ask smth?
    this->close();
}

void MainWindow::on_CancelPB_clicked()
{
    //no saving
    this->close();
}

void MainWindow::on_sendOnceButton_clicked()
{
    //QString x = address.toString();
    //m_clientAddress = address;
    //m_clientPort = port;
}
