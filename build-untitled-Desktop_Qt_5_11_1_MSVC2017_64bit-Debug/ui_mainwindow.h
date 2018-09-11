/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_meteoWindow
{
public:
    QAction *action;
    QAction *action_2;
    QAction *action_4;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_15;
    QSplitter *splitter;
    QGroupBox *mTimeGrB;
    QVBoxLayout *verticalLayout_5;
    QSplitter *splitter_7;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *mWinterPushB;
    QPushButton *mSpringPushB;
    QPushButton *mSummerPushB;
    QPushButton *mAutumnPushB;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *mDayPushB;
    QPushButton *mNightPushB;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_11;
    QSpinBox *day_spnb;
    QLabel *label_12;
    QComboBox *month_cmbB;
    QLabel *label_13;
    QTimeEdit *time_spnB;
    QGroupBox *mCloudGrB;
    QVBoxLayout *verticalLayout_16;
    QSplitter *splitter_3;
    QWidget *layoutWidget3;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_9;
    QLabel *label_6;
    QLabel *label_8;
    QVBoxLayout *verticalLayout_10;
    QScrollBar *cloudHeightScroll;
    QScrollBar *cloudThickScroll;
    QSpacerItem *verticalSpacer;
    QScrollBar *cloudSecLvlScroll;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_11;
    QVBoxLayout *verticalLayout_19;
    QLineEdit *cloudBase_inp;
    QLineEdit *cloudUpper_inp;
    QVBoxLayout *verticalLayout_9;
    QSpinBox *cloudSize_spnB;
    QComboBox *cloudsSecLay_cmbB;
    QComboBox *cloudsType_cmbB;
    QSpinBox *secLayHeight_spnB;
    QGroupBox *mPrecipationGrB;
    QVBoxLayout *verticalLayout_17;
    QSplitter *splitter_2;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_10;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_7;
    QVBoxLayout *verticalLayout_4;
    QScrollBar *localVisScroll;
    QScrollBar *rainScroll;
    QScrollBar *snowScroll;
    QScrollBar *mistScroll;
    QWidget *layoutWidget6;
    QVBoxLayout *verticalLayout_7;
    QLineEdit *localVis_inp;
    QLineEdit *rain_inp;
    QLineEdit *snow_inp;
    QLineEdit *hmist_inp;
    QGroupBox *mWindGrB;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_14;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_21;
    QSpacerItem *horizontalSpacer;
    QLabel *label_22;
    QSplitter *splitter_4;
    QWidget *layoutWidget7;
    QVBoxLayout *verticalLayout_6;
    QScrollBar *windSpeedScroll;
    QScrollBar *windPsiScroll;
    QWidget *layoutWidget8;
    QVBoxLayout *verticalLayout_13;
    QLineEdit *windSpeed_inp;
    QLineEdit *windSpeedPsi_inp;
    QGroupBox *mSightGrB;
    QHBoxLayout *horizontalLayout_9;
    QSplitter *splitter_6;
    QWidget *layoutWidget9;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_25;
    QLabel *label_26;
    QVBoxLayout *verticalLayout_3;
    QScrollBar *visScroll;
    QScrollBar *starsBrightScroll;
    QWidget *layoutWidget10;
    QVBoxLayout *verticalLayout_12;
    QLineEdit *visibility_inp;
    QLineEdit *starsBright_inp;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menu;

    void setupUi(QMainWindow *meteoWindow)
    {
        if (meteoWindow->objectName().isEmpty())
            meteoWindow->setObjectName(QStringLiteral("meteoWindow"));
        meteoWindow->setWindowModality(Qt::ApplicationModal);
        meteoWindow->resize(764, 984);
        action = new QAction(meteoWindow);
        action->setObjectName(QStringLiteral("action"));
        action_2 = new QAction(meteoWindow);
        action_2->setObjectName(QStringLiteral("action_2"));
        action_4 = new QAction(meteoWindow);
        action_4->setObjectName(QStringLiteral("action_4"));
        centralWidget = new QWidget(meteoWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_15 = new QVBoxLayout(centralWidget);
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setContentsMargins(11, 11, 11, 11);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        mTimeGrB = new QGroupBox(splitter);
        mTimeGrB->setObjectName(QStringLiteral("mTimeGrB"));
        mTimeGrB->setMinimumSize(QSize(0, 0));
        mTimeGrB->setBaseSize(QSize(0, 0));
        mTimeGrB->setTabletTracking(false);
        mTimeGrB->setContextMenuPolicy(Qt::NoContextMenu);
        mTimeGrB->setAcceptDrops(false);
        verticalLayout_5 = new QVBoxLayout(mTimeGrB);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        splitter_7 = new QSplitter(mTimeGrB);
        splitter_7->setObjectName(QStringLiteral("splitter_7"));
        splitter_7->setOrientation(Qt::Vertical);
        layoutWidget = new QWidget(splitter_7);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        mWinterPushB = new QPushButton(layoutWidget);
        mWinterPushB->setObjectName(QStringLiteral("mWinterPushB"));

        horizontalLayout_5->addWidget(mWinterPushB);

        mSpringPushB = new QPushButton(layoutWidget);
        mSpringPushB->setObjectName(QStringLiteral("mSpringPushB"));

        horizontalLayout_5->addWidget(mSpringPushB);

        mSummerPushB = new QPushButton(layoutWidget);
        mSummerPushB->setObjectName(QStringLiteral("mSummerPushB"));

        horizontalLayout_5->addWidget(mSummerPushB);

        mAutumnPushB = new QPushButton(layoutWidget);
        mAutumnPushB->setObjectName(QStringLiteral("mAutumnPushB"));

        horizontalLayout_5->addWidget(mAutumnPushB);

        splitter_7->addWidget(layoutWidget);
        layoutWidget1 = new QWidget(splitter_7);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        mDayPushB = new QPushButton(layoutWidget1);
        mDayPushB->setObjectName(QStringLiteral("mDayPushB"));

        horizontalLayout_7->addWidget(mDayPushB);

        mNightPushB = new QPushButton(layoutWidget1);
        mNightPushB->setObjectName(QStringLiteral("mNightPushB"));

        horizontalLayout_7->addWidget(mNightPushB);

        splitter_7->addWidget(layoutWidget1);
        layoutWidget2 = new QWidget(splitter_7);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(layoutWidget2);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout->addWidget(label_11);

        day_spnb = new QSpinBox(layoutWidget2);
        day_spnb->setObjectName(QStringLiteral("day_spnb"));
        day_spnb->setMinimum(1);
        day_spnb->setMaximum(31);
        day_spnb->setDisplayIntegerBase(31);

        horizontalLayout->addWidget(day_spnb);

        label_12 = new QLabel(layoutWidget2);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout->addWidget(label_12);

        month_cmbB = new QComboBox(layoutWidget2);
        month_cmbB->addItem(QString());
        month_cmbB->addItem(QString());
        month_cmbB->addItem(QString());
        month_cmbB->addItem(QString());
        month_cmbB->addItem(QString());
        month_cmbB->addItem(QString());
        month_cmbB->addItem(QString());
        month_cmbB->addItem(QString());
        month_cmbB->addItem(QString());
        month_cmbB->addItem(QString());
        month_cmbB->addItem(QString());
        month_cmbB->addItem(QString());
        month_cmbB->setObjectName(QStringLiteral("month_cmbB"));
        month_cmbB->setInsertPolicy(QComboBox::InsertBeforeCurrent);

        horizontalLayout->addWidget(month_cmbB);

        label_13 = new QLabel(layoutWidget2);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout->addWidget(label_13);

        time_spnB = new QTimeEdit(layoutWidget2);
        time_spnB->setObjectName(QStringLiteral("time_spnB"));

        horizontalLayout->addWidget(time_spnB);

        splitter_7->addWidget(layoutWidget2);

        verticalLayout_5->addWidget(splitter_7);

        splitter->addWidget(mTimeGrB);
        mCloudGrB = new QGroupBox(splitter);
        mCloudGrB->setObjectName(QStringLiteral("mCloudGrB"));
        verticalLayout_16 = new QVBoxLayout(mCloudGrB);
        verticalLayout_16->setSpacing(6);
        verticalLayout_16->setContentsMargins(11, 11, 11, 11);
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        splitter_3 = new QSplitter(mCloudGrB);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        layoutWidget3 = new QWidget(splitter_3);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        gridLayout = new QGridLayout(layoutWidget3);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        label_3 = new QLabel(layoutWidget3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(271, 0));

        verticalLayout_8->addWidget(label_3);

        label_4 = new QLabel(layoutWidget3);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_8->addWidget(label_4);

        label_5 = new QLabel(layoutWidget3);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_8->addWidget(label_5);

        label_9 = new QLabel(layoutWidget3);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_8->addWidget(label_9);

        label_6 = new QLabel(layoutWidget3);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_8->addWidget(label_6);

        label_8 = new QLabel(layoutWidget3);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_8->addWidget(label_8);


        gridLayout->addLayout(verticalLayout_8, 0, 0, 1, 1);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        cloudHeightScroll = new QScrollBar(layoutWidget3);
        cloudHeightScroll->setObjectName(QStringLiteral("cloudHeightScroll"));
        cloudHeightScroll->setOrientation(Qt::Horizontal);

        verticalLayout_10->addWidget(cloudHeightScroll);

        cloudThickScroll = new QScrollBar(layoutWidget3);
        cloudThickScroll->setObjectName(QStringLiteral("cloudThickScroll"));
        cloudThickScroll->setMinimumSize(QSize(0, 3));
        cloudThickScroll->setCursor(QCursor(Qt::UpArrowCursor));
        cloudThickScroll->setSingleStep(5);
        cloudThickScroll->setOrientation(Qt::Horizontal);

        verticalLayout_10->addWidget(cloudThickScroll);

        verticalSpacer = new QSpacerItem(17, 88, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer);

        cloudSecLvlScroll = new QScrollBar(layoutWidget3);
        cloudSecLvlScroll->setObjectName(QStringLiteral("cloudSecLvlScroll"));
        cloudSecLvlScroll->setOrientation(Qt::Horizontal);

        verticalLayout_10->addWidget(cloudSecLvlScroll);


        gridLayout->addLayout(verticalLayout_10, 0, 1, 1, 1);

        splitter_3->addWidget(layoutWidget3);
        layoutWidget4 = new QWidget(splitter_3);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        verticalLayout_11 = new QVBoxLayout(layoutWidget4);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        verticalLayout_19 = new QVBoxLayout();
        verticalLayout_19->setSpacing(6);
        verticalLayout_19->setObjectName(QStringLiteral("verticalLayout_19"));
        cloudBase_inp = new QLineEdit(layoutWidget4);
        cloudBase_inp->setObjectName(QStringLiteral("cloudBase_inp"));

        verticalLayout_19->addWidget(cloudBase_inp);

        cloudUpper_inp = new QLineEdit(layoutWidget4);
        cloudUpper_inp->setObjectName(QStringLiteral("cloudUpper_inp"));

        verticalLayout_19->addWidget(cloudUpper_inp);


        verticalLayout_11->addLayout(verticalLayout_19);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        cloudSize_spnB = new QSpinBox(layoutWidget4);
        cloudSize_spnB->setObjectName(QStringLiteral("cloudSize_spnB"));
        cloudSize_spnB->setTabletTracking(false);
        cloudSize_spnB->setToolTipDuration(0);
        cloudSize_spnB->setMinimum(1);
        cloudSize_spnB->setMaximum(10);
        cloudSize_spnB->setSingleStep(0);
        cloudSize_spnB->setValue(1);

        verticalLayout_9->addWidget(cloudSize_spnB);

        cloudsSecLay_cmbB = new QComboBox(layoutWidget4);
        cloudsSecLay_cmbB->addItem(QString());
        cloudsSecLay_cmbB->addItem(QString());
        cloudsSecLay_cmbB->setObjectName(QStringLiteral("cloudsSecLay_cmbB"));

        verticalLayout_9->addWidget(cloudsSecLay_cmbB);

        cloudsType_cmbB = new QComboBox(layoutWidget4);
        cloudsType_cmbB->addItem(QString());
        cloudsType_cmbB->addItem(QString());
        cloudsType_cmbB->setObjectName(QStringLiteral("cloudsType_cmbB"));

        verticalLayout_9->addWidget(cloudsType_cmbB);

        secLayHeight_spnB = new QSpinBox(layoutWidget4);
        secLayHeight_spnB->setObjectName(QStringLiteral("secLayHeight_spnB"));

        verticalLayout_9->addWidget(secLayHeight_spnB);


        verticalLayout_11->addLayout(verticalLayout_9);

        splitter_3->addWidget(layoutWidget4);

        verticalLayout_16->addWidget(splitter_3);

        splitter->addWidget(mCloudGrB);
        mPrecipationGrB = new QGroupBox(splitter);
        mPrecipationGrB->setObjectName(QStringLiteral("mPrecipationGrB"));
        verticalLayout_17 = new QVBoxLayout(mPrecipationGrB);
        verticalLayout_17->setSpacing(6);
        verticalLayout_17->setContentsMargins(11, 11, 11, 11);
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        splitter_2 = new QSplitter(mPrecipationGrB);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        layoutWidget5 = new QWidget(splitter_2);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_10 = new QLabel(layoutWidget5);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout_2->addWidget(label_10);

        label_2 = new QLabel(layoutWidget5);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        label = new QLabel(layoutWidget5);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        label_7 = new QLabel(layoutWidget5);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_2->addWidget(label_7);


        horizontalLayout_6->addLayout(verticalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        localVisScroll = new QScrollBar(layoutWidget5);
        localVisScroll->setObjectName(QStringLiteral("localVisScroll"));
        localVisScroll->setSingleStep(1);
        localVisScroll->setOrientation(Qt::Horizontal);

        verticalLayout_4->addWidget(localVisScroll);

        rainScroll = new QScrollBar(layoutWidget5);
        rainScroll->setObjectName(QStringLiteral("rainScroll"));
        rainScroll->setOrientation(Qt::Horizontal);

        verticalLayout_4->addWidget(rainScroll);

        snowScroll = new QScrollBar(layoutWidget5);
        snowScroll->setObjectName(QStringLiteral("snowScroll"));
        snowScroll->setOrientation(Qt::Horizontal);

        verticalLayout_4->addWidget(snowScroll);

        mistScroll = new QScrollBar(layoutWidget5);
        mistScroll->setObjectName(QStringLiteral("mistScroll"));
        mistScroll->setOrientation(Qt::Horizontal);

        verticalLayout_4->addWidget(mistScroll);


        horizontalLayout_6->addLayout(verticalLayout_4);

        splitter_2->addWidget(layoutWidget5);
        layoutWidget6 = new QWidget(splitter_2);
        layoutWidget6->setObjectName(QStringLiteral("layoutWidget6"));
        verticalLayout_7 = new QVBoxLayout(layoutWidget6);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        localVis_inp = new QLineEdit(layoutWidget6);
        localVis_inp->setObjectName(QStringLiteral("localVis_inp"));

        verticalLayout_7->addWidget(localVis_inp);

        rain_inp = new QLineEdit(layoutWidget6);
        rain_inp->setObjectName(QStringLiteral("rain_inp"));

        verticalLayout_7->addWidget(rain_inp);

        snow_inp = new QLineEdit(layoutWidget6);
        snow_inp->setObjectName(QStringLiteral("snow_inp"));

        verticalLayout_7->addWidget(snow_inp);

        hmist_inp = new QLineEdit(layoutWidget6);
        hmist_inp->setObjectName(QStringLiteral("hmist_inp"));

        verticalLayout_7->addWidget(hmist_inp);

        splitter_2->addWidget(layoutWidget6);

        verticalLayout_17->addWidget(splitter_2);

        splitter->addWidget(mPrecipationGrB);
        mWindGrB = new QGroupBox(splitter);
        mWindGrB->setObjectName(QStringLiteral("mWindGrB"));
        horizontalLayout_4 = new QHBoxLayout(mWindGrB);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_21 = new QLabel(mWindGrB);
        label_21->setObjectName(QStringLiteral("label_21"));

        horizontalLayout_2->addWidget(label_21);

        horizontalSpacer = new QSpacerItem(108, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_14->addLayout(horizontalLayout_2);

        label_22 = new QLabel(mWindGrB);
        label_22->setObjectName(QStringLiteral("label_22"));

        verticalLayout_14->addWidget(label_22);


        horizontalLayout_4->addLayout(verticalLayout_14);

        splitter_4 = new QSplitter(mWindGrB);
        splitter_4->setObjectName(QStringLiteral("splitter_4"));
        splitter_4->setOrientation(Qt::Horizontal);
        layoutWidget7 = new QWidget(splitter_4);
        layoutWidget7->setObjectName(QStringLiteral("layoutWidget7"));
        verticalLayout_6 = new QVBoxLayout(layoutWidget7);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        windSpeedScroll = new QScrollBar(layoutWidget7);
        windSpeedScroll->setObjectName(QStringLiteral("windSpeedScroll"));
        windSpeedScroll->setOrientation(Qt::Horizontal);

        verticalLayout_6->addWidget(windSpeedScroll);

        windPsiScroll = new QScrollBar(layoutWidget7);
        windPsiScroll->setObjectName(QStringLiteral("windPsiScroll"));
        windPsiScroll->setOrientation(Qt::Horizontal);

        verticalLayout_6->addWidget(windPsiScroll);

        splitter_4->addWidget(layoutWidget7);
        layoutWidget8 = new QWidget(splitter_4);
        layoutWidget8->setObjectName(QStringLiteral("layoutWidget8"));
        verticalLayout_13 = new QVBoxLayout(layoutWidget8);
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        verticalLayout_13->setContentsMargins(0, 0, 0, 0);
        windSpeed_inp = new QLineEdit(layoutWidget8);
        windSpeed_inp->setObjectName(QStringLiteral("windSpeed_inp"));

        verticalLayout_13->addWidget(windSpeed_inp);

        windSpeedPsi_inp = new QLineEdit(layoutWidget8);
        windSpeedPsi_inp->setObjectName(QStringLiteral("windSpeedPsi_inp"));

        verticalLayout_13->addWidget(windSpeedPsi_inp);

        splitter_4->addWidget(layoutWidget8);

        horizontalLayout_4->addWidget(splitter_4);

        splitter->addWidget(mWindGrB);
        mSightGrB = new QGroupBox(splitter);
        mSightGrB->setObjectName(QStringLiteral("mSightGrB"));
        horizontalLayout_9 = new QHBoxLayout(mSightGrB);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        splitter_6 = new QSplitter(mSightGrB);
        splitter_6->setObjectName(QStringLiteral("splitter_6"));
        splitter_6->setOrientation(Qt::Horizontal);
        layoutWidget9 = new QWidget(splitter_6);
        layoutWidget9->setObjectName(QStringLiteral("layoutWidget9"));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget9);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_25 = new QLabel(layoutWidget9);
        label_25->setObjectName(QStringLiteral("label_25"));

        verticalLayout->addWidget(label_25);

        label_26 = new QLabel(layoutWidget9);
        label_26->setObjectName(QStringLiteral("label_26"));

        verticalLayout->addWidget(label_26);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        visScroll = new QScrollBar(layoutWidget9);
        visScroll->setObjectName(QStringLiteral("visScroll"));
        visScroll->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(visScroll);

        starsBrightScroll = new QScrollBar(layoutWidget9);
        starsBrightScroll->setObjectName(QStringLiteral("starsBrightScroll"));
        starsBrightScroll->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(starsBrightScroll);


        horizontalLayout_3->addLayout(verticalLayout_3);

        splitter_6->addWidget(layoutWidget9);
        layoutWidget10 = new QWidget(splitter_6);
        layoutWidget10->setObjectName(QStringLiteral("layoutWidget10"));
        verticalLayout_12 = new QVBoxLayout(layoutWidget10);
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(0, 0, 0, 0);
        visibility_inp = new QLineEdit(layoutWidget10);
        visibility_inp->setObjectName(QStringLiteral("visibility_inp"));
        visibility_inp->setBaseSize(QSize(0, 3));

        verticalLayout_12->addWidget(visibility_inp);

        starsBright_inp = new QLineEdit(layoutWidget10);
        starsBright_inp->setObjectName(QStringLiteral("starsBright_inp"));

        verticalLayout_12->addWidget(starsBright_inp);

        splitter_6->addWidget(layoutWidget10);

        horizontalLayout_9->addWidget(splitter_6);

        splitter->addWidget(mSightGrB);

        verticalLayout_15->addWidget(splitter);

        meteoWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(meteoWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        meteoWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(meteoWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 764, 31));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        meteoWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(action);
        menu->addAction(action_2);
        menu->addSeparator();
        menu->addAction(action_4);

        retranslateUi(meteoWindow);

        QMetaObject::connectSlotsByName(meteoWindow);
    } // setupUi

    void retranslateUi(QMainWindow *meteoWindow)
    {
        meteoWindow->setWindowTitle(QApplication::translate("meteoWindow", "MainWindow", nullptr));
        action->setText(QApplication::translate("meteoWindow", "\320\241\321\207\320\270\321\202\320\260\321\202\321\214 \320\270\320\267 \321\202\320\265\320\272\321\201\321\202\320\276\320\262\320\276\320\263\320\276 \321\204\320\260\320\271\320\273\320\260", nullptr));
#ifndef QT_NO_SHORTCUT
        action->setShortcut(QApplication::translate("meteoWindow", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        action_2->setText(QApplication::translate("meteoWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\262 \321\202\320\265\320\272\321\201\321\202\320\276\320\262\320\276\320\274 \321\204\320\260\320\271\320\273\320\265", nullptr));
#ifndef QT_NO_SHORTCUT
        action_2->setShortcut(QApplication::translate("meteoWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        action_4->setText(QApplication::translate("meteoWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
#ifndef QT_NO_SHORTCUT
        action_4->setShortcut(QApplication::translate("meteoWindow", "Ctrl+E", nullptr));
#endif // QT_NO_SHORTCUT
        mTimeGrB->setTitle(QApplication::translate("meteoWindow", "\320\222\321\200\320\265\320\274\321\217", nullptr));
        mWinterPushB->setText(QApplication::translate("meteoWindow", "\320\227\320\270\320\274\320\260", nullptr));
        mSpringPushB->setText(QApplication::translate("meteoWindow", "\320\222\320\265\321\201\320\275\320\260", nullptr));
        mSummerPushB->setText(QApplication::translate("meteoWindow", "\320\233\320\265\321\202\320\276", nullptr));
        mAutumnPushB->setText(QApplication::translate("meteoWindow", "\320\236\321\201\320\265\320\275\321\214", nullptr));
        mDayPushB->setText(QApplication::translate("meteoWindow", "\320\224\320\265\320\275\321\214", nullptr));
        mNightPushB->setText(QApplication::translate("meteoWindow", "\320\235\320\276\321\207\321\214", nullptr));
        label_11->setText(QApplication::translate("meteoWindow", "\320\247\320\270\321\201\320\273\320\276", nullptr));
        label_12->setText(QApplication::translate("meteoWindow", "\320\234\320\265\321\201\321\217\321\206", nullptr));
        month_cmbB->setItemText(0, QApplication::translate("meteoWindow", "\321\217\320\275\320\262\320\260\321\200\321\214", nullptr));
        month_cmbB->setItemText(1, QApplication::translate("meteoWindow", "\321\204\320\265\320\262\321\200\320\260\320\273\321\214", nullptr));
        month_cmbB->setItemText(2, QApplication::translate("meteoWindow", "\320\274\320\260\321\200\321\202", nullptr));
        month_cmbB->setItemText(3, QApplication::translate("meteoWindow", "\320\260\320\277\321\200\320\265\320\273\321\214", nullptr));
        month_cmbB->setItemText(4, QApplication::translate("meteoWindow", "\320\274\320\260\320\271", nullptr));
        month_cmbB->setItemText(5, QApplication::translate("meteoWindow", "\320\270\321\216\320\275\321\214", nullptr));
        month_cmbB->setItemText(6, QApplication::translate("meteoWindow", "\320\270\321\216\320\273\321\214", nullptr));
        month_cmbB->setItemText(7, QApplication::translate("meteoWindow", "\320\260\320\262\320\263\321\203\321\201\321\202", nullptr));
        month_cmbB->setItemText(8, QApplication::translate("meteoWindow", "\321\201\320\265\320\275\321\202\321\217\320\261\321\200\321\214", nullptr));
        month_cmbB->setItemText(9, QApplication::translate("meteoWindow", "\320\276\320\272\321\202\321\217\320\261\321\200\321\214", nullptr));
        month_cmbB->setItemText(10, QApplication::translate("meteoWindow", "\320\275\320\276\321\217\320\261\321\200\321\214", nullptr));
        month_cmbB->setItemText(11, QApplication::translate("meteoWindow", "\320\264\320\265\320\272\320\260\320\261\321\200\321\214", nullptr));

        label_13->setText(QApplication::translate("meteoWindow", "\320\222\321\200\320\265\320\274\321\217", nullptr));
        mCloudGrB->setTitle(QApplication::translate("meteoWindow", "\320\236\320\261\320\273\320\260\321\207\320\275\320\276\321\201\321\202\321\214", nullptr));
        label_3->setText(QApplication::translate("meteoWindow", "\320\222\321\213\321\201\320\276\321\202\320\260 \320\275\320\270\320\266\320\275\320\265\320\271 \320\272\321\200\320\276\320\274\320\272\320\270 \320\276\320\261\320\273\320\260\320\272\320\276\320\262, [\320\274]", nullptr));
        label_4->setText(QApplication::translate("meteoWindow", "\320\242\320\276\320\273\321\211\320\270\320\275\320\260 \321\201\320\273\320\276\321\217 \320\276\320\261\320\273\320\260\320\272\320\276\320\262, [\320\274]", nullptr));
        label_5->setText(QApplication::translate("meteoWindow", "\320\221\320\260\320\273\321\214\320\275\320\276\321\201\321\202\321\214 \320\276\320\261\320\273\320\260\320\272\320\276\320\262,1...10 \320\265\320\264", nullptr));
        label_9->setText(QApplication::translate("meteoWindow", "\320\235\320\260\320\273\320\270\321\207\320\270\320\265 \320\262\321\202\320\276\321\200\320\276\320\263\320\276 \321\201\320\273\320\276\321\217 \320\276\320\261\320\273\320\260\320\272\320\276\320\262", nullptr));
        label_6->setText(QApplication::translate("meteoWindow", "\320\242\320\270\320\277 \320\276\320\261\320\273\320\260\320\272\320\276\320\262 (\320\276\320\261\321\213\321\207\320\275\321\213\320\265, \320\263\321\200\320\276\320\267\320\276\320\262\321\213\320\265)", nullptr));
        label_8->setText(QApplication::translate("meteoWindow", "\320\222\321\213\321\201\320\276\321\202\320\260 \320\262\321\202\320\276\321\200\320\276\320\263\320\276 \321\201\320\273\320\276\321\217 \320\276\320\261\320\273\320\260\320\272\320\276\320\262, [\320\274]", nullptr));
        cloudsSecLay_cmbB->setItemText(0, QApplication::translate("meteoWindow", "\320\264\320\260", nullptr));
        cloudsSecLay_cmbB->setItemText(1, QApplication::translate("meteoWindow", "\320\275\320\265\321\202", nullptr));

        cloudsType_cmbB->setItemText(0, QApplication::translate("meteoWindow", "\320\276\320\261\321\213\321\207\320\275\321\213\320\265", nullptr));
        cloudsType_cmbB->setItemText(1, QApplication::translate("meteoWindow", "\320\263\321\200\320\276\320\267\320\276\320\262\321\213\320\265", nullptr));

        mPrecipationGrB->setTitle(QApplication::translate("meteoWindow", "\320\236\321\201\320\260\320\264\320\272\320\270", nullptr));
        label_10->setText(QApplication::translate("meteoWindow", "\320\233\320\276\320\272\320\260\320\273\321\214\320\275\320\260\321\217 \320\264\320\260\320\273\321\214\320\275\320\276\321\201\321\202\321\214 \320\262\320\270\320\264\320\270\320\274\320\276\321\201\321\202\320\270, [\320\274]", nullptr));
        label_2->setText(QApplication::translate("meteoWindow", "\320\230\320\275\321\202\320\265\320\275\321\201\320\270\320\262\320\275\320\276\321\201\321\202\321\214 \320\264\320\276\320\266\320\264\321\217, %", nullptr));
        label->setText(QApplication::translate("meteoWindow", "\320\230\320\275\321\202\320\265\320\275\321\201\320\270\320\262\320\275\320\276\321\201\321\202\321\214 \321\201\320\275\320\265\320\263\320\260, %", nullptr));
        label_7->setText(QApplication::translate("meteoWindow", "\320\222\321\213\321\201\320\276\321\202\320\260 \320\264\321\213\320\274\320\272\320\270 \321\202\321\203\320\274\320\260\320\275\320\260, [\320\274]", nullptr));
        mWindGrB->setTitle(QApplication::translate("meteoWindow", "\320\222\320\265\321\202\320\265\321\200", nullptr));
        label_21->setText(QApplication::translate("meteoWindow", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214 \320\262\320\265\321\202\321\200\320\260, \320\274/\321\201", nullptr));
        label_22->setText(QApplication::translate("meteoWindow", "\320\235\320\260\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\262\320\265\321\202\321\200\320\260, 0...360 \320\263\321\200\320\260\320\264", nullptr));
        mSightGrB->setTitle(QApplication::translate("meteoWindow", "\320\222\320\270\320\264\320\270\320\274\320\276\321\201\321\202\321\214", nullptr));
        label_25->setText(QApplication::translate("meteoWindow", "\320\223\320\273\320\276\320\261\320\260\320\273\321\214\320\275\320\260\321\217 \320\264\320\260\320\273\321\214\320\275\320\276\321\201\321\202\321\214 \320\262\320\270\320\264\320\270\320\274\320\276\321\201\321\202\320\270, [\320\274]", nullptr));
        label_26->setText(QApplication::translate("meteoWindow", "\320\257\321\200\320\272\320\276\321\201\321\202\321\214 \320\267\320\262\320\265\320\267\320\264, %", nullptr));
        visibility_inp->setText(QString());
        menu->setTitle(QApplication::translate("meteoWindow", "\320\244\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class meteoWindow: public Ui_meteoWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
