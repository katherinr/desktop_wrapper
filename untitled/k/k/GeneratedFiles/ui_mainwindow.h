/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_23;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *startPB;
    QPushButton *stopPB;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_19;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_12;
    QHBoxLayout *horizontalLayout;
    QLabel *label_7;
    QLineEdit *receivePortEdit;
    QCheckBox *send_from_this;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *mainVisPushButton;
    QComboBox *mainiComboBox;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *meteoPushButton;
    QComboBox *meteoComboBox;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *AerodromsLightsPB;
    QComboBox *aerodrCB;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_10;
    QCheckBox *backwardChkBox;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_9;
    QLabel *label_10;
    QVBoxLayout *verticalLayout_6;
    QLineEdit *backwIPedit;
    QLineEdit *backwPortEdit;
    QGroupBox *CHANgeVisgroupBox;
    QVBoxLayout *verticalLayout_28;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *sendIPEdit;
    QLineEdit *sendPortEdit;
    QLabel *label;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *mainVisCheckBox;
    QCheckBox *meteoCheckBox;
    QCheckBox *lightsCheckBox;
    QVBoxLayout *verticalLayout;
    QLineEdit *mainVisIntervalEdit;
    QLineEdit *meteoIntervalEdit;
    QLineEdit *aerodromsIntervalEdit;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer;
    QPushButton *sendOnceButton;
    QSpacerItem *verticalSpacer_4;
    QGroupBox *graphicsGroupBox;
    QVBoxLayout *verticalLayout_27;
    QHBoxLayout *horizontalLayout_22;
    QVBoxLayout *verticalLayout_24;
    QLabel *label_20;
    QLabel *label_21;
    QCheckBox *send2plotsCHb;
    QVBoxLayout *verticalLayout_26;
    QLineEdit *plotIPsend;
    QLineEdit *portPlotSend;
    QLineEdit *timePlots;
    QVBoxLayout *verticalLayout_8;
    QCheckBox *backwReceive;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_8;
    QLineEdit *receivePortEdit_2;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *CorrectPB;
    QVBoxLayout *verticalLayout_20;
    QGroupBox *MapGroupBox;
    QVBoxLayout *verticalLayout_22;
    QHBoxLayout *horizontalLayout_14;
    QVBoxLayout *verticalLayout_17;
    QLabel *label_16;
    QLabel *label_17;
    QCheckBox *send2mapCHb;
    QVBoxLayout *verticalLayout_18;
    QLineEdit *mapIPsend;
    QLineEdit *portMapSend;
    QLineEdit *timeMap;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_21;
    QVBoxLayout *verticalLayout_14;
    QCheckBox *showWindchB;
    QCheckBox *showTrajChB;
    QCheckBox *showRoutechB;
    QCheckBox *followMainPlainCHB;
    QCheckBox *isOrientCamchB;
    QVBoxLayout *verticalLayout_21;
    QHBoxLayout *horizontalLayout_15;
    QPushButton *routePushB;
    QVBoxLayout *verticalLayout_15;
    QLabel *label_14;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_12;
    QLineEdit *centerLat;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_13;
    QLineEdit *centerLon;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_15;
    QSpinBox *mapHeiihtspinBox;
    QGroupBox *SoundGrBox;
    QVBoxLayout *verticalLayout_25;
    QVBoxLayout *verticalLayout_16;
    QHBoxLayout *horizontalLayout_13;
    QVBoxLayout *verticalLayout_19;
    QLabel *label_18;
    QLabel *label_19;
    QCheckBox *send2SOUNDCHb;
    QVBoxLayout *verticalLayout_13;
    QLineEdit *soundIPsend;
    QLineEdit *soundPortSend;
    QLineEdit *soundTime;
    QHBoxLayout *horizontalLayout_20;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *soundPB;
    QSpacerItem *verticalSpacer_5;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::WindowModal);
        MainWindow->resize(1729, 787);
        MainWindow->setContextMenuPolicy(Qt::PreventContextMenu);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_23 = new QVBoxLayout(centralwidget);
        verticalLayout_23->setObjectName(QStringLiteral("verticalLayout_23"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        startPB = new QPushButton(centralwidget);
        startPB->setObjectName(QStringLiteral("startPB"));
        startPB->setEnabled(true);
        startPB->setMinimumSize(QSize(370, 0));
        startPB->setMaximumSize(QSize(270, 16777215));
        startPB->setCheckable(false);
        startPB->setChecked(false);
        startPB->setAutoExclusive(false);

        horizontalLayout_12->addWidget(startPB);

        stopPB = new QPushButton(centralwidget);
        stopPB->setObjectName(QStringLiteral("stopPB"));
        stopPB->setEnabled(true);
        stopPB->setCheckable(false);

        horizontalLayout_12->addWidget(stopPB);

        horizontalSpacer_4 = new QSpacerItem(858, 32, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_4);


        verticalLayout_23->addLayout(horizontalLayout_12);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_12 = new QVBoxLayout(groupBox_3);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout->addWidget(label_7);

        receivePortEdit = new QLineEdit(groupBox_3);
        receivePortEdit->setObjectName(QStringLiteral("receivePortEdit"));
        receivePortEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(receivePortEdit);


        verticalLayout_12->addLayout(horizontalLayout);

        send_from_this = new QCheckBox(groupBox_3);
        send_from_this->setObjectName(QStringLiteral("send_from_this"));
        send_from_this->setEnabled(false);
        send_from_this->setChecked(false);

        verticalLayout_12->addWidget(send_from_this);

        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_12->addWidget(label_4);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        mainVisPushButton = new QPushButton(groupBox_3);
        mainVisPushButton->setObjectName(QStringLiteral("mainVisPushButton"));
        mainVisPushButton->setEnabled(true);

        horizontalLayout_8->addWidget(mainVisPushButton);

        mainiComboBox = new QComboBox(groupBox_3);
        mainiComboBox->addItem(QString());
        mainiComboBox->addItem(QString());
        mainiComboBox->setObjectName(QStringLiteral("mainiComboBox"));

        horizontalLayout_8->addWidget(mainiComboBox);


        verticalLayout_7->addLayout(horizontalLayout_8);

        verticalSpacer_3 = new QSpacerItem(298, 68, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_3);


        verticalLayout_12->addLayout(verticalLayout_7);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_9->addWidget(label_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        meteoPushButton = new QPushButton(groupBox_3);
        meteoPushButton->setObjectName(QStringLiteral("meteoPushButton"));

        horizontalLayout_7->addWidget(meteoPushButton);

        meteoComboBox = new QComboBox(groupBox_3);
        meteoComboBox->addItem(QString());
        meteoComboBox->addItem(QString());
        meteoComboBox->setObjectName(QStringLiteral("meteoComboBox"));

        horizontalLayout_7->addWidget(meteoComboBox);


        verticalLayout_9->addLayout(horizontalLayout_7);

        verticalSpacer_2 = new QSpacerItem(295, 88, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_2);


        verticalLayout_12->addLayout(verticalLayout_9);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_11->addWidget(label_6);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        AerodromsLightsPB = new QPushButton(groupBox_3);
        AerodromsLightsPB->setObjectName(QStringLiteral("AerodromsLightsPB"));

        horizontalLayout_6->addWidget(AerodromsLightsPB);

        aerodrCB = new QComboBox(groupBox_3);
        aerodrCB->addItem(QString());
        aerodrCB->addItem(QString());
        aerodrCB->setObjectName(QStringLiteral("aerodrCB"));

        horizontalLayout_6->addWidget(aerodrCB);


        verticalLayout_11->addLayout(horizontalLayout_6);

        verticalSpacer = new QSpacerItem(295, 88, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_11->addItem(verticalSpacer);


        verticalLayout_12->addLayout(verticalLayout_11);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        backwardChkBox = new QCheckBox(groupBox_3);
        backwardChkBox->setObjectName(QStringLiteral("backwardChkBox"));
        backwardChkBox->setEnabled(false);
        backwardChkBox->setMaximumSize(QSize(16777215, 25));
        backwardChkBox->setChecked(false);

        verticalLayout_10->addWidget(backwardChkBox);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setEnabled(false);

        verticalLayout_5->addWidget(label_9);

        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setEnabled(false);

        verticalLayout_5->addWidget(label_10);


        horizontalLayout_5->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        backwIPedit = new QLineEdit(groupBox_3);
        backwIPedit->setObjectName(QStringLiteral("backwIPedit"));
        backwIPedit->setEnabled(false);
        backwIPedit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_6->addWidget(backwIPedit);

        backwPortEdit = new QLineEdit(groupBox_3);
        backwPortEdit->setObjectName(QStringLiteral("backwPortEdit"));
        backwPortEdit->setEnabled(false);
        backwPortEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_6->addWidget(backwPortEdit);


        horizontalLayout_5->addLayout(verticalLayout_6);


        verticalLayout_10->addLayout(horizontalLayout_5);


        verticalLayout_12->addLayout(verticalLayout_10);


        horizontalLayout_19->addWidget(groupBox_3);

        CHANgeVisgroupBox = new QGroupBox(centralwidget);
        CHANgeVisgroupBox->setObjectName(QStringLiteral("CHANgeVisgroupBox"));
        verticalLayout_28 = new QVBoxLayout(CHANgeVisgroupBox);
        verticalLayout_28->setObjectName(QStringLiteral("verticalLayout_28"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalSpacer_2 = new QSpacerItem(158, 58, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_3 = new QLabel(CHANgeVisgroupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setEnabled(false);

        verticalLayout_4->addWidget(label_3);

        label_2 = new QLabel(CHANgeVisgroupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setEnabled(false);

        verticalLayout_4->addWidget(label_2);


        horizontalLayout_4->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        sendIPEdit = new QLineEdit(CHANgeVisgroupBox);
        sendIPEdit->setObjectName(QStringLiteral("sendIPEdit"));
        sendIPEdit->setEnabled(false);
        sendIPEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_3->addWidget(sendIPEdit);

        sendPortEdit = new QLineEdit(CHANgeVisgroupBox);
        sendPortEdit->setObjectName(QStringLiteral("sendPortEdit"));
        sendPortEdit->setEnabled(false);
        sendPortEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_3->addWidget(sendPortEdit);


        horizontalLayout_4->addLayout(verticalLayout_3);


        horizontalLayout_9->addLayout(horizontalLayout_4);


        verticalLayout_28->addLayout(horizontalLayout_9);

        label = new QLabel(CHANgeVisgroupBox);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_28->addWidget(label);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        mainVisCheckBox = new QCheckBox(CHANgeVisgroupBox);
        mainVisCheckBox->setObjectName(QStringLiteral("mainVisCheckBox"));
        mainVisCheckBox->setChecked(true);

        verticalLayout_2->addWidget(mainVisCheckBox);

        meteoCheckBox = new QCheckBox(CHANgeVisgroupBox);
        meteoCheckBox->setObjectName(QStringLiteral("meteoCheckBox"));
        meteoCheckBox->setChecked(true);

        verticalLayout_2->addWidget(meteoCheckBox);

        lightsCheckBox = new QCheckBox(CHANgeVisgroupBox);
        lightsCheckBox->setObjectName(QStringLiteral("lightsCheckBox"));
        lightsCheckBox->setChecked(true);

        verticalLayout_2->addWidget(lightsCheckBox);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        mainVisIntervalEdit = new QLineEdit(CHANgeVisgroupBox);
        mainVisIntervalEdit->setObjectName(QStringLiteral("mainVisIntervalEdit"));
        mainVisIntervalEdit->setEnabled(true);
        mainVisIntervalEdit->setContextMenuPolicy(Qt::ActionsContextMenu);
        mainVisIntervalEdit->setAcceptDrops(true);
        mainVisIntervalEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        mainVisIntervalEdit->setClearButtonEnabled(false);

        verticalLayout->addWidget(mainVisIntervalEdit);

        meteoIntervalEdit = new QLineEdit(CHANgeVisgroupBox);
        meteoIntervalEdit->setObjectName(QStringLiteral("meteoIntervalEdit"));
        meteoIntervalEdit->setEnabled(true);
        meteoIntervalEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(meteoIntervalEdit);

        aerodromsIntervalEdit = new QLineEdit(CHANgeVisgroupBox);
        aerodromsIntervalEdit->setObjectName(QStringLiteral("aerodromsIntervalEdit"));
        aerodromsIntervalEdit->setEnabled(true);
        aerodromsIntervalEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(aerodromsIntervalEdit);


        horizontalLayout_3->addLayout(verticalLayout);


        verticalLayout_28->addLayout(horizontalLayout_3);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalSpacer = new QSpacerItem(348, 58, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer);

        sendOnceButton = new QPushButton(CHANgeVisgroupBox);
        sendOnceButton->setObjectName(QStringLiteral("sendOnceButton"));
        sendOnceButton->setEnabled(false);
        sendOnceButton->setMinimumSize(QSize(200, 50));
        sendOnceButton->setMaximumSize(QSize(133, 16777215));
        sendOnceButton->setCheckable(false);

        horizontalLayout_10->addWidget(sendOnceButton);


        verticalLayout_28->addLayout(horizontalLayout_10);

        verticalSpacer_4 = new QSpacerItem(428, 276, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_28->addItem(verticalSpacer_4);

        graphicsGroupBox = new QGroupBox(CHANgeVisgroupBox);
        graphicsGroupBox->setObjectName(QStringLiteral("graphicsGroupBox"));
        verticalLayout_27 = new QVBoxLayout(graphicsGroupBox);
        verticalLayout_27->setObjectName(QStringLiteral("verticalLayout_27"));
        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        verticalLayout_24 = new QVBoxLayout();
        verticalLayout_24->setObjectName(QStringLiteral("verticalLayout_24"));
        label_20 = new QLabel(graphicsGroupBox);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_24->addWidget(label_20);

        label_21 = new QLabel(graphicsGroupBox);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_24->addWidget(label_21);

        send2plotsCHb = new QCheckBox(graphicsGroupBox);
        send2plotsCHb->setObjectName(QStringLiteral("send2plotsCHb"));
        send2plotsCHb->setEnabled(false);
        send2plotsCHb->setChecked(true);

        verticalLayout_24->addWidget(send2plotsCHb);


        horizontalLayout_22->addLayout(verticalLayout_24);

        verticalLayout_26 = new QVBoxLayout();
        verticalLayout_26->setObjectName(QStringLiteral("verticalLayout_26"));
        plotIPsend = new QLineEdit(graphicsGroupBox);
        plotIPsend->setObjectName(QStringLiteral("plotIPsend"));
        plotIPsend->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_26->addWidget(plotIPsend);

        portPlotSend = new QLineEdit(graphicsGroupBox);
        portPlotSend->setObjectName(QStringLiteral("portPlotSend"));
        portPlotSend->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_26->addWidget(portPlotSend);

        timePlots = new QLineEdit(graphicsGroupBox);
        timePlots->setObjectName(QStringLiteral("timePlots"));
        timePlots->setEnabled(false);
        timePlots->setContextMenuPolicy(Qt::ActionsContextMenu);
        timePlots->setAcceptDrops(true);
        timePlots->setEchoMode(QLineEdit::NoEcho);
        timePlots->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        timePlots->setClearButtonEnabled(false);

        verticalLayout_26->addWidget(timePlots);


        horizontalLayout_22->addLayout(verticalLayout_26);


        verticalLayout_27->addLayout(horizontalLayout_22);


        verticalLayout_28->addWidget(graphicsGroupBox);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        backwReceive = new QCheckBox(CHANgeVisgroupBox);
        backwReceive->setObjectName(QStringLiteral("backwReceive"));
        backwReceive->setChecked(true);

        verticalLayout_8->addWidget(backwReceive);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_8 = new QLabel(CHANgeVisgroupBox);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_2->addWidget(label_8);

        receivePortEdit_2 = new QLineEdit(CHANgeVisgroupBox);
        receivePortEdit_2->setObjectName(QStringLiteral("receivePortEdit_2"));
        receivePortEdit_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(receivePortEdit_2);


        verticalLayout_8->addLayout(horizontalLayout_2);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalSpacer_3 = new QSpacerItem(448, 18, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_3);

        CorrectPB = new QPushButton(CHANgeVisgroupBox);
        CorrectPB->setObjectName(QStringLiteral("CorrectPB"));

        horizontalLayout_11->addWidget(CorrectPB);


        verticalLayout_8->addLayout(horizontalLayout_11);


        verticalLayout_28->addLayout(verticalLayout_8);


        horizontalLayout_19->addWidget(CHANgeVisgroupBox);

        verticalLayout_20 = new QVBoxLayout();
        verticalLayout_20->setObjectName(QStringLiteral("verticalLayout_20"));
        MapGroupBox = new QGroupBox(centralwidget);
        MapGroupBox->setObjectName(QStringLiteral("MapGroupBox"));
        verticalLayout_22 = new QVBoxLayout(MapGroupBox);
        verticalLayout_22->setObjectName(QStringLiteral("verticalLayout_22"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        label_16 = new QLabel(MapGroupBox);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_17->addWidget(label_16);

        label_17 = new QLabel(MapGroupBox);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_17->addWidget(label_17);

        send2mapCHb = new QCheckBox(MapGroupBox);
        send2mapCHb->setObjectName(QStringLiteral("send2mapCHb"));
        send2mapCHb->setEnabled(false);
        send2mapCHb->setChecked(true);

        verticalLayout_17->addWidget(send2mapCHb);


        horizontalLayout_14->addLayout(verticalLayout_17);

        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setObjectName(QStringLiteral("verticalLayout_18"));
        mapIPsend = new QLineEdit(MapGroupBox);
        mapIPsend->setObjectName(QStringLiteral("mapIPsend"));
        mapIPsend->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_18->addWidget(mapIPsend);

        portMapSend = new QLineEdit(MapGroupBox);
        portMapSend->setObjectName(QStringLiteral("portMapSend"));
        portMapSend->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_18->addWidget(portMapSend);

        timeMap = new QLineEdit(MapGroupBox);
        timeMap->setObjectName(QStringLiteral("timeMap"));
        timeMap->setEnabled(false);
        timeMap->setContextMenuPolicy(Qt::ActionsContextMenu);
        timeMap->setAcceptDrops(true);
        timeMap->setEchoMode(QLineEdit::NoEcho);
        timeMap->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        timeMap->setClearButtonEnabled(false);

        verticalLayout_18->addWidget(timeMap);


        horizontalLayout_14->addLayout(verticalLayout_18);


        verticalLayout_22->addLayout(horizontalLayout_14);

        horizontalSpacer_7 = new QSpacerItem(377, 18, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_22->addItem(horizontalSpacer_7);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        showWindchB = new QCheckBox(MapGroupBox);
        showWindchB->setObjectName(QStringLiteral("showWindchB"));
        showWindchB->setChecked(true);

        verticalLayout_14->addWidget(showWindchB);

        showTrajChB = new QCheckBox(MapGroupBox);
        showTrajChB->setObjectName(QStringLiteral("showTrajChB"));
        showTrajChB->setChecked(true);

        verticalLayout_14->addWidget(showTrajChB);

        showRoutechB = new QCheckBox(MapGroupBox);
        showRoutechB->setObjectName(QStringLiteral("showRoutechB"));
        showRoutechB->setChecked(true);

        verticalLayout_14->addWidget(showRoutechB);

        followMainPlainCHB = new QCheckBox(MapGroupBox);
        followMainPlainCHB->setObjectName(QStringLiteral("followMainPlainCHB"));
        followMainPlainCHB->setChecked(true);

        verticalLayout_14->addWidget(followMainPlainCHB);

        isOrientCamchB = new QCheckBox(MapGroupBox);
        isOrientCamchB->setObjectName(QStringLiteral("isOrientCamchB"));
        isOrientCamchB->setChecked(true);

        verticalLayout_14->addWidget(isOrientCamchB);


        horizontalLayout_21->addLayout(verticalLayout_14);

        verticalLayout_21 = new QVBoxLayout();
        verticalLayout_21->setObjectName(QStringLiteral("verticalLayout_21"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        routePushB = new QPushButton(MapGroupBox);
        routePushB->setObjectName(QStringLiteral("routePushB"));
        routePushB->setEnabled(false);
        routePushB->setMinimumSize(QSize(130, 0));
        routePushB->setMaximumSize(QSize(130, 16777215));

        horizontalLayout_15->addWidget(routePushB);


        verticalLayout_21->addLayout(horizontalLayout_15);


        horizontalLayout_21->addLayout(verticalLayout_21);


        verticalLayout_22->addLayout(horizontalLayout_21);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        label_14 = new QLabel(MapGroupBox);
        label_14->setObjectName(QStringLiteral("label_14"));

        verticalLayout_15->addWidget(label_14);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        label_12 = new QLabel(MapGroupBox);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_16->addWidget(label_12);

        centerLat = new QLineEdit(MapGroupBox);
        centerLat->setObjectName(QStringLiteral("centerLat"));
        centerLat->setMaximumSize(QSize(130, 16777215));

        horizontalLayout_16->addWidget(centerLat);


        verticalLayout_15->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        label_13 = new QLabel(MapGroupBox);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_17->addWidget(label_13);

        centerLon = new QLineEdit(MapGroupBox);
        centerLon->setObjectName(QStringLiteral("centerLon"));
        centerLon->setMaximumSize(QSize(130, 16777215));

        horizontalLayout_17->addWidget(centerLon);


        verticalLayout_15->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        label_15 = new QLabel(MapGroupBox);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_18->addWidget(label_15);

        mapHeiihtspinBox = new QSpinBox(MapGroupBox);
        mapHeiihtspinBox->setObjectName(QStringLiteral("mapHeiihtspinBox"));
        mapHeiihtspinBox->setMaximumSize(QSize(130, 16777215));
        mapHeiihtspinBox->setMouseTracking(true);
        mapHeiihtspinBox->setMaximum(10000000);
        mapHeiihtspinBox->setSingleStep(100);
        mapHeiihtspinBox->setValue(30000);
        mapHeiihtspinBox->setDisplayIntegerBase(10);

        horizontalLayout_18->addWidget(mapHeiihtspinBox);


        verticalLayout_15->addLayout(horizontalLayout_18);


        verticalLayout_22->addLayout(verticalLayout_15);


        verticalLayout_20->addWidget(MapGroupBox);

        SoundGrBox = new QGroupBox(centralwidget);
        SoundGrBox->setObjectName(QStringLiteral("SoundGrBox"));
        verticalLayout_25 = new QVBoxLayout(SoundGrBox);
        verticalLayout_25->setObjectName(QStringLiteral("verticalLayout_25"));
        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        verticalLayout_19 = new QVBoxLayout();
        verticalLayout_19->setObjectName(QStringLiteral("verticalLayout_19"));
        label_18 = new QLabel(SoundGrBox);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_19->addWidget(label_18);

        label_19 = new QLabel(SoundGrBox);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_19->addWidget(label_19);

        send2SOUNDCHb = new QCheckBox(SoundGrBox);
        send2SOUNDCHb->setObjectName(QStringLiteral("send2SOUNDCHb"));
        send2SOUNDCHb->setEnabled(false);
        send2SOUNDCHb->setChecked(true);

        verticalLayout_19->addWidget(send2SOUNDCHb);


        horizontalLayout_13->addLayout(verticalLayout_19);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        soundIPsend = new QLineEdit(SoundGrBox);
        soundIPsend->setObjectName(QStringLiteral("soundIPsend"));
        soundIPsend->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_13->addWidget(soundIPsend);

        soundPortSend = new QLineEdit(SoundGrBox);
        soundPortSend->setObjectName(QStringLiteral("soundPortSend"));
        soundPortSend->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_13->addWidget(soundPortSend);

        soundTime = new QLineEdit(SoundGrBox);
        soundTime->setObjectName(QStringLiteral("soundTime"));
        soundTime->setEnabled(false);
        soundTime->setContextMenuPolicy(Qt::ActionsContextMenu);
        soundTime->setAcceptDrops(true);
        soundTime->setEchoMode(QLineEdit::NoEcho);
        soundTime->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        soundTime->setClearButtonEnabled(false);

        verticalLayout_13->addWidget(soundTime);


        horizontalLayout_13->addLayout(verticalLayout_13);


        verticalLayout_16->addLayout(horizontalLayout_13);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        horizontalSpacer_5 = new QSpacerItem(188, 18, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_20->addItem(horizontalSpacer_5);

        soundPB = new QPushButton(SoundGrBox);
        soundPB->setObjectName(QStringLiteral("soundPB"));

        horizontalLayout_20->addWidget(soundPB);


        verticalLayout_16->addLayout(horizontalLayout_20);


        verticalLayout_25->addLayout(verticalLayout_16);

        verticalSpacer_5 = new QSpacerItem(428, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_25->addItem(verticalSpacer_5);


        verticalLayout_20->addWidget(SoundGrBox);


        horizontalLayout_19->addLayout(verticalLayout_20);


        verticalLayout_23->addLayout(horizontalLayout_19);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        mainiComboBox->setCurrentIndex(0);
        meteoComboBox->setCurrentIndex(0);
        aerodrCB->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "BIRD WRAPPER", nullptr));
        startPB->setText(QApplication::translate("MainWindow", "\320\222\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \320\276\320\261\320\274\320\265\320\275 \320\270\320\267 \320\264\320\260\320\275\320\275\320\276\320\271 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\213", nullptr));
        stopPB->setText(QApplication::translate("MainWindow", "\320\236\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\320\236\320\261\320\274\320\265\320\275 \321\201 \320\274\320\276\320\264\320\265\320\273\321\214\321\216", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "IP \320\277\320\276\321\200\321\202 \320\277\321\200\320\270\320\265\320\274\320\260 \320\276\321\202 \320\274\320\276\320\264\320\265\320\273\320\270:", nullptr));
        receivePortEdit->setText(QApplication::translate("MainWindow", "5103", nullptr));
        send_from_this->setText(QApplication::translate("MainWindow", "\320\230\320\267 \320\264\320\260\320\275\320\275\320\276\320\271 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\213", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\320\236\321\201\320\275\320\276\320\262\320\275\320\276\320\271 \320\277\320\260\320\272\320\265\321\202 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
        mainVisPushButton->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200 \320\277\320\260\320\272\320\265\321\202\320\260", nullptr));
        mainiComboBox->setItemText(0, QApplication::translate("MainWindow", "\320\230\320\267 \320\274\320\276\320\264\320\265\320\273\320\270", nullptr));
        mainiComboBox->setItemText(1, QApplication::translate("MainWindow", "\320\230\320\267 \320\264\320\260\320\275\320\275\320\276\320\271 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\213", nullptr));

        label_5->setText(QApplication::translate("MainWindow", "\320\224\320\260\320\275\320\275\321\213\320\265 \320\276 \320\262\321\200\320\265\320\274\320\265\320\275\320\270 \320\270 \320\277\320\276\320\263\320\276\320\264\320\265", nullptr));
        meteoPushButton->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200 \320\277\320\260\320\272\320\265\321\202\320\260", nullptr));
        meteoComboBox->setItemText(0, QApplication::translate("MainWindow", "\320\230\320\267 \320\274\320\276\320\264\320\265\320\273\320\270", nullptr));
        meteoComboBox->setItemText(1, QApplication::translate("MainWindow", "\320\230\320\267 \320\264\320\260\320\275\320\275\320\276\320\271 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\213", nullptr));

        label_6->setText(QApplication::translate("MainWindow", "\320\224\320\260\320\275\320\275\321\213\320\265 \320\276\320\261 \320\260\321\215\321\200\320\276\320\264\321\200\320\276\320\274\320\260\321\205", nullptr));
        AerodromsLightsPB->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200 \320\277\320\260\320\272\320\265\321\202\320\260", nullptr));
        aerodrCB->setItemText(0, QApplication::translate("MainWindow", "\320\230\320\267 \320\274\320\276\320\264\320\265\320\273\320\270", nullptr));
        aerodrCB->setItemText(1, QApplication::translate("MainWindow", "\320\230\320\267 \320\264\320\260\320\275\320\275\320\276\320\271 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\213", nullptr));

        backwardChkBox->setText(QApplication::translate("MainWindow", "\320\222\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \320\276\321\202\321\201\321\213\320\273\320\272\321\203 \320\276\320\261\321\200\320\260\321\202\320\275\320\276\320\263\320\276 \320\277\320\260\320\272\320\265\321\202\320\260", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "IP \320\260\320\264\321\200\320\265\321\201 \320\276\321\202\321\201\321\213\320\273\320\272\320\270", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "IP \320\277\320\276\321\200\321\202 \320\276\321\202\321\201\321\213\320\273\320\272\320\270", nullptr));
        backwIPedit->setText(QApplication::translate("MainWindow", "127.0.0.1", nullptr));
        backwIPedit->setPlaceholderText(QApplication::translate("MainWindow", "127.0.0.1", nullptr));
        backwPortEdit->setText(QApplication::translate("MainWindow", "5003", nullptr));
        CHANgeVisgroupBox->setTitle(QApplication::translate("MainWindow", "\320\236\320\261\320\274\320\265\320\275 \321\201 \320\262\320\270\320\267\321\203\320\260\320\273\320\270\320\267\320\260\321\206\320\270\320\265\320\271", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "IP \320\260\320\264\321\200\320\265\321\201 \320\276\321\202\321\201\321\213\320\273\320\272\320\270", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "IP \320\277\320\276\321\200\321\202 \320\276\321\202\321\201\321\213\320\273\320\272\320\270", nullptr));
        sendIPEdit->setText(QApplication::translate("MainWindow", "127.0.0.1", nullptr));
        sendIPEdit->setPlaceholderText(QApplication::translate("MainWindow", "127.0.0.1", nullptr));
        sendPortEdit->setText(QApplication::translate("MainWindow", "5001", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\270\320\276\320\264\321\213, \321\201", nullptr));
        mainVisCheckBox->setText(QApplication::translate("MainWindow", "\320\236\321\202\321\201\321\213\320\273\320\272\320\260 \320\276\321\201\320\275\320\276\320\262\320\275\321\213\321\205 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
        meteoCheckBox->setText(QApplication::translate("MainWindow", "\320\236\321\202\321\201\321\213\320\273\320\272\320\260 \320\264\320\273\321\217 \320\262\321\200\320\265\320\274\320\265\320\275\320\270/\320\277\320\276\320\263\320\276\320\264\321\213", nullptr));
        lightsCheckBox->setText(QApplication::translate("MainWindow", "\320\236\321\202\321\201\321\213\320\273\320\272\320\260 \320\264\320\260\320\275\320\275\321\213\321\205 \320\264\320\273\321\217 \320\260\321\215\321\200\320\276\320\264\321\200\320\276\320\274\320\276\320\262", nullptr));
        mainVisIntervalEdit->setText(QApplication::translate("MainWindow", "0.01", nullptr));
        meteoIntervalEdit->setText(QApplication::translate("MainWindow", "5", nullptr));
        aerodromsIntervalEdit->setText(QApplication::translate("MainWindow", "5", nullptr));
        sendOnceButton->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214 \321\200\320\260\320\267\320\276\320\262\321\213\320\271 \320\277\320\260\320\272\320\265\321\202", nullptr));
        graphicsGroupBox->setTitle(QApplication::translate("MainWindow", "\320\223\321\200\320\260\321\204\320\270\320\272\320\270", nullptr));
        label_20->setText(QApplication::translate("MainWindow", "IP \320\260\320\264\321\200\320\265\321\201 \320\276\321\202\321\201\321\213\320\273\320\272\320\270", nullptr));
        label_21->setText(QApplication::translate("MainWindow", "IP \320\277\320\276\321\200\321\202 \320\276\321\202\321\201\321\213\320\273\320\272\320\270", nullptr));
        send2plotsCHb->setText(QApplication::translate("MainWindow", "\320\236\321\202\321\201\321\213\320\273\320\272\320\260 \320\264\320\260\320\275\320\275\321\213\321\205 \320\275\320\260 \320\263\321\200\320\260\321\204\320\270\320\272\320\270", nullptr));
        plotIPsend->setText(QApplication::translate("MainWindow", "127.0.0.1", nullptr));
        plotIPsend->setPlaceholderText(QApplication::translate("MainWindow", "127.0.0.1", nullptr));
        portPlotSend->setText(QApplication::translate("MainWindow", "3456", nullptr));
        timePlots->setText(QApplication::translate("MainWindow", "0.01", nullptr));
        backwReceive->setText(QApplication::translate("MainWindow", "\320\222\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \320\277\321\200\320\270\320\265\320\274 \320\276\321\202 \320\262\320\270\320\267\321\203\320\260\320\273\320\270\320\267\320\260\321\206\320\270\320\270", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\200\321\202 \320\277\321\200\320\270\320\265\320\274\320\260 \320\264\320\260\320\275\320\275\321\213\321\205 \320\276\321\202 \320\262\320\270\320\267\321\203\320\260\320\273\320\270\320\267\320\260\321\206\320\270\320\270", nullptr));
        receivePortEdit_2->setText(QApplication::translate("MainWindow", "5002", nullptr));
        CorrectPB->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200 \320\277\320\260\320\272\320\265\321\202\320\260", nullptr));
        MapGroupBox->setTitle(QApplication::translate("MainWindow", "\320\232\320\260\321\200\321\202\320\260", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "IP \320\260\320\264\321\200\320\265\321\201 \320\276\321\202\321\201\321\213\320\273\320\272\320\270", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "IP \320\277\320\276\321\200\321\202 \320\276\321\202\321\201\321\213\320\273\320\272\320\270", nullptr));
        send2mapCHb->setText(QApplication::translate("MainWindow", "\320\236\321\202\321\201\321\213\320\273\320\272\320\260 \320\264\320\260\320\275\320\275\321\213\321\205 \320\275\320\260 \320\272\320\260\321\200\321\202\321\203", nullptr));
        mapIPsend->setText(QApplication::translate("MainWindow", "127.0.0.1", nullptr));
        mapIPsend->setPlaceholderText(QApplication::translate("MainWindow", "127.0.0.1", nullptr));
        portMapSend->setText(QApplication::translate("MainWindow", "3456", nullptr));
        timeMap->setText(QApplication::translate("MainWindow", "0.01", nullptr));
        showWindchB->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\276\320\272\320\275\320\276", nullptr));
        showTrajChB->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267 \321\202\321\200\320\260\320\265\320\272\321\202\320\276\321\200\320\270\320\270", nullptr));
        showRoutechB->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267 \320\237\320\237\320\234", nullptr));
        followMainPlainCHB->setText(QApplication::translate("MainWindow", "\320\236\321\201\320\275\320\276\320\262\320\275\320\276\320\271 \320\262\321\201\320\265\320\263\320\264\320\260 \320\262 \321\206\320\265\320\275\321\202\321\200\320\265", nullptr));
        isOrientCamchB->setText(QApplication::translate("MainWindow", "\320\236\321\201\320\275\320\276\320\262\320\275\320\276\320\271 \320\262\321\201\320\265\320\263\320\264\320\260 \320\262\320\262\320\265\321\200\321\205 (\320\272\320\276\320\263\320\264\320\260 \320\262 \321\206\320\265\320\275\321\202\321\200\320\265)", nullptr));
        routePushB->setText(QApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214 \320\274\320\260\321\200\321\210\321\200\321\203\321\202", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213 \321\203\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\270 \320\272\320\260\320\274\320\265\321\200\321\213", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\320\273\321\214\320\275\320\260\321\217 \321\210\320\270\321\200\320\276\321\202\320\260, [\320\263\321\200\320\260\320\264]", nullptr));
        centerLat->setText(QApplication::translate("MainWindow", "55.564917", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\320\273\321\214\320\275\320\260\321\217 \320\264\320\276\320\273\320\263\320\276\321\202\320\260, [\320\263\321\200\320\260\320\264]", nullptr));
        centerLon->setText(QApplication::translate("MainWindow", "38.137015", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\201\320\276\321\202\320\260, \320\274", nullptr));
        SoundGrBox->setTitle(QApplication::translate("MainWindow", "\320\227\320\262\321\203\320\272", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "IP \320\260\320\264\321\200\320\265\321\201 \320\276\321\202\321\201\321\213\320\273\320\272\320\270", nullptr));
        label_19->setText(QApplication::translate("MainWindow", "IP \320\277\320\276\321\200\321\202 \320\276\321\202\321\201\321\213\320\273\320\272\320\270", nullptr));
        send2SOUNDCHb->setText(QApplication::translate("MainWindow", "\320\236\321\202\321\201\321\213\320\273\320\272\320\260 \320\264\320\260\320\275\320\275\321\213\321\205 \320\276 \320\267\320\262\321\203\320\272\320\265", nullptr));
        soundIPsend->setText(QApplication::translate("MainWindow", "127.0.0.1", nullptr));
        soundIPsend->setPlaceholderText(QApplication::translate("MainWindow", "127.0.0.1", nullptr));
        soundPortSend->setText(QApplication::translate("MainWindow", "4455", nullptr));
        soundTime->setText(QApplication::translate("MainWindow", "0.01", nullptr));
        soundPB->setText(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
