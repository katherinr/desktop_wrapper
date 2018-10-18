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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_11;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_12;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_6;
    QPushButton *mainVisPushButton;
    QPushButton *meteoPushButton;
    QPushButton *AerodromsLightsPB;
    QPushButton *CorrectPB;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_9;
    QCheckBox *visd_chb_rem;
    QCheckBox *man_vis_chb;
    QHBoxLayout *horizontalLayout_8;
    QCheckBox *meteo_remchb;
    QCheckBox *manmeteo_chb;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *rem_aerol_chb;
    QCheckBox *man_aerolights_chb;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *backw_rem_chb;
    QCheckBox *man_backw_chb;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *sendIPEdit;
    QLineEdit *sendPortEdit;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *mainVisCheckBox;
    QCheckBox *meteoCheckBox;
    QCheckBox *lightsCheckBox;
    QCheckBox *BackwardCheckBox;
    QVBoxLayout *verticalLayout;
    QLineEdit *mainVisIntervalEdit;
    QLineEdit *meteoIntervalEdit;
    QLineEdit *lightsIntervalEdit;
    QLineEdit *backwardIntervalEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *sendOnceButton;
    QPushButton *startStopSendButton;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *receivePortEdit;
    QVBoxLayout *verticalLayout_9;
    QLabel *receivedLabel;
    QPlainTextEdit *plainTextEdit;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *okPB;
    QPushButton *CancelPB;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::WindowModal);
        MainWindow->resize(1297, 465);
        MainWindow->setContextMenuPolicy(Qt::PreventContextMenu);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_5 = new QVBoxLayout(centralwidget);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        horizontalLayout_12 = new QHBoxLayout(groupBox_3);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        mainVisPushButton = new QPushButton(groupBox_3);
        mainVisPushButton->setObjectName(QStringLiteral("mainVisPushButton"));

        verticalLayout_6->addWidget(mainVisPushButton);

        meteoPushButton = new QPushButton(groupBox_3);
        meteoPushButton->setObjectName(QStringLiteral("meteoPushButton"));

        verticalLayout_6->addWidget(meteoPushButton);

        AerodromsLightsPB = new QPushButton(groupBox_3);
        AerodromsLightsPB->setObjectName(QStringLiteral("AerodromsLightsPB"));

        verticalLayout_6->addWidget(AerodromsLightsPB);

        CorrectPB = new QPushButton(groupBox_3);
        CorrectPB->setObjectName(QStringLiteral("CorrectPB"));

        verticalLayout_6->addWidget(CorrectPB);


        horizontalLayout_10->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        visd_chb_rem = new QCheckBox(groupBox_3);
        visd_chb_rem->setObjectName(QStringLiteral("visd_chb_rem"));

        horizontalLayout_9->addWidget(visd_chb_rem);

        man_vis_chb = new QCheckBox(groupBox_3);
        man_vis_chb->setObjectName(QStringLiteral("man_vis_chb"));

        horizontalLayout_9->addWidget(man_vis_chb);


        verticalLayout_7->addLayout(horizontalLayout_9);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        meteo_remchb = new QCheckBox(groupBox_3);
        meteo_remchb->setObjectName(QStringLiteral("meteo_remchb"));

        horizontalLayout_8->addWidget(meteo_remchb);

        manmeteo_chb = new QCheckBox(groupBox_3);
        manmeteo_chb->setObjectName(QStringLiteral("manmeteo_chb"));

        horizontalLayout_8->addWidget(manmeteo_chb);


        verticalLayout_7->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        rem_aerol_chb = new QCheckBox(groupBox_3);
        rem_aerol_chb->setObjectName(QStringLiteral("rem_aerol_chb"));

        horizontalLayout_7->addWidget(rem_aerol_chb);

        man_aerolights_chb = new QCheckBox(groupBox_3);
        man_aerolights_chb->setObjectName(QStringLiteral("man_aerolights_chb"));

        horizontalLayout_7->addWidget(man_aerolights_chb);


        verticalLayout_7->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        backw_rem_chb = new QCheckBox(groupBox_3);
        backw_rem_chb->setObjectName(QStringLiteral("backw_rem_chb"));

        horizontalLayout_6->addWidget(backw_rem_chb);

        man_backw_chb = new QCheckBox(groupBox_3);
        man_backw_chb->setObjectName(QStringLiteral("man_backw_chb"));

        horizontalLayout_6->addWidget(man_backw_chb);


        verticalLayout_7->addLayout(horizontalLayout_6);


        horizontalLayout_10->addLayout(verticalLayout_7);


        horizontalLayout_12->addLayout(horizontalLayout_10);


        horizontalLayout_11->addWidget(groupBox_3);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_10 = new QVBoxLayout(groupBox);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_4->addWidget(label_3);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_4->addWidget(label_2);


        horizontalLayout_4->addLayout(verticalLayout_4);

        horizontalSpacer = new QSpacerItem(278, 58, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        sendIPEdit = new QLineEdit(groupBox);
        sendIPEdit->setObjectName(QStringLiteral("sendIPEdit"));
        sendIPEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_3->addWidget(sendIPEdit);

        sendPortEdit = new QLineEdit(groupBox);
        sendPortEdit->setObjectName(QStringLiteral("sendPortEdit"));
        sendPortEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_3->addWidget(sendPortEdit);


        horizontalLayout_4->addLayout(verticalLayout_3);


        verticalLayout_10->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        mainVisCheckBox = new QCheckBox(groupBox);
        mainVisCheckBox->setObjectName(QStringLiteral("mainVisCheckBox"));

        verticalLayout_2->addWidget(mainVisCheckBox);

        meteoCheckBox = new QCheckBox(groupBox);
        meteoCheckBox->setObjectName(QStringLiteral("meteoCheckBox"));

        verticalLayout_2->addWidget(meteoCheckBox);

        lightsCheckBox = new QCheckBox(groupBox);
        lightsCheckBox->setObjectName(QStringLiteral("lightsCheckBox"));

        verticalLayout_2->addWidget(lightsCheckBox);

        BackwardCheckBox = new QCheckBox(groupBox);
        BackwardCheckBox->setObjectName(QStringLiteral("BackwardCheckBox"));

        verticalLayout_2->addWidget(BackwardCheckBox);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        mainVisIntervalEdit = new QLineEdit(groupBox);
        mainVisIntervalEdit->setObjectName(QStringLiteral("mainVisIntervalEdit"));
        mainVisIntervalEdit->setEnabled(false);
        mainVisIntervalEdit->setContextMenuPolicy(Qt::ActionsContextMenu);
        mainVisIntervalEdit->setAcceptDrops(true);
        mainVisIntervalEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        mainVisIntervalEdit->setClearButtonEnabled(false);

        verticalLayout->addWidget(mainVisIntervalEdit);

        meteoIntervalEdit = new QLineEdit(groupBox);
        meteoIntervalEdit->setObjectName(QStringLiteral("meteoIntervalEdit"));
        meteoIntervalEdit->setEnabled(false);
        meteoIntervalEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(meteoIntervalEdit);

        lightsIntervalEdit = new QLineEdit(groupBox);
        lightsIntervalEdit->setObjectName(QStringLiteral("lightsIntervalEdit"));
        lightsIntervalEdit->setEnabled(false);
        lightsIntervalEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(lightsIntervalEdit);

        backwardIntervalEdit = new QLineEdit(groupBox);
        backwardIntervalEdit->setObjectName(QStringLiteral("backwardIntervalEdit"));
        backwardIntervalEdit->setEnabled(false);
        backwardIntervalEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(backwardIntervalEdit);


        horizontalLayout_3->addLayout(verticalLayout);


        verticalLayout_10->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(243, 18, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        sendOnceButton = new QPushButton(groupBox);
        sendOnceButton->setObjectName(QStringLiteral("sendOnceButton"));
        sendOnceButton->setMaximumSize(QSize(133, 16777215));
        sendOnceButton->setCheckable(false);

        horizontalLayout->addWidget(sendOnceButton);

        startStopSendButton = new QPushButton(groupBox);
        startStopSendButton->setObjectName(QStringLiteral("startStopSendButton"));
        startStopSendButton->setMinimumSize(QSize(84, 0));
        startStopSendButton->setMaximumSize(QSize(133, 16777215));
        startStopSendButton->setCheckable(true);

        horizontalLayout->addWidget(startStopSendButton);


        verticalLayout_10->addLayout(horizontalLayout);


        horizontalLayout_11->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_8 = new QVBoxLayout(groupBox_2);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_2->addWidget(label_7);

        horizontalSpacer_4 = new QSpacerItem(88, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        receivePortEdit = new QLineEdit(groupBox_2);
        receivePortEdit->setObjectName(QStringLiteral("receivePortEdit"));
        receivePortEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(receivePortEdit);


        verticalLayout_8->addLayout(horizontalLayout_2);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        receivedLabel = new QLabel(groupBox_2);
        receivedLabel->setObjectName(QStringLiteral("receivedLabel"));

        verticalLayout_9->addWidget(receivedLabel);

        plainTextEdit = new QPlainTextEdit(groupBox_2);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        verticalLayout_9->addWidget(plainTextEdit);


        verticalLayout_8->addLayout(verticalLayout_9);


        horizontalLayout_11->addWidget(groupBox_2);


        verticalLayout_5->addLayout(horizontalLayout_11);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_3 = new QSpacerItem(852, 28, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        okPB = new QPushButton(centralwidget);
        okPB->setObjectName(QStringLiteral("okPB"));

        horizontalLayout_5->addWidget(okPB);

        CancelPB = new QPushButton(centralwidget);
        CancelPB->setObjectName(QStringLiteral("CancelPB"));

        horizontalLayout_5->addWidget(CancelPB);


        verticalLayout_5->addLayout(horizontalLayout_5);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1297, 31));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QString());
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Edit Data", nullptr));
        mainVisPushButton->setText(QApplication::translate("MainWindow", "VISUAL DATA", nullptr));
        meteoPushButton->setText(QApplication::translate("MainWindow", "METEO", nullptr));
        AerodromsLightsPB->setText(QApplication::translate("MainWindow", "AERODROME LIGHTS", nullptr));
        CorrectPB->setText(QApplication::translate("MainWindow", "BACKWARD", nullptr));
        visd_chb_rem->setText(QApplication::translate("MainWindow", "Remotely", nullptr));
        man_vis_chb->setText(QApplication::translate("MainWindow", "Manually", nullptr));
        meteo_remchb->setText(QApplication::translate("MainWindow", "Remotely", nullptr));
        manmeteo_chb->setText(QApplication::translate("MainWindow", "Manually", nullptr));
        rem_aerol_chb->setText(QApplication::translate("MainWindow", "Remotely", nullptr));
        man_aerolights_chb->setText(QApplication::translate("MainWindow", "Manually", nullptr));
        backw_rem_chb->setText(QApplication::translate("MainWindow", "Remotely", nullptr));
        man_backw_chb->setText(QApplication::translate("MainWindow", "Manually", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "Send UDP", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "IP Address", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Port", nullptr));
        mainVisCheckBox->setText(QApplication::translate("MainWindow", "MAIN Visual Data send interval [msec]", nullptr));
        meteoCheckBox->setText(QApplication::translate("MainWindow", "METEO data send interval [msec]", nullptr));
        lightsCheckBox->setText(QApplication::translate("MainWindow", "AERODROME LIGHTS data send intevral [msec]", nullptr));
        BackwardCheckBox->setText(QApplication::translate("MainWindow", "BACKWARD data send interval [msec]", nullptr));
        sendOnceButton->setText(QApplication::translate("MainWindow", "Send once", nullptr));
        startStopSendButton->setText(QApplication::translate("MainWindow", "Start send", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Receive UDP", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Port", nullptr));
        receivedLabel->setText(QApplication::translate("MainWindow", "Received Data", nullptr));
        okPB->setText(QApplication::translate("MainWindow", "Ok", nullptr));
        CancelPB->setText(QApplication::translate("MainWindow", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
