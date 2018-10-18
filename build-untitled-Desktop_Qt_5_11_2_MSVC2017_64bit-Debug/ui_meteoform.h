/********************************************************************************
** Form generated from reading UI file 'meteoform.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_METEOFORM_H
#define UI_METEOFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
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
    QVBoxLayout *verticalLayout_14;
    QGroupBox *mTimeGrB;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *mWinterPushB;
    QPushButton *mSpringPushB;
    QPushButton *mSummerPushB;
    QPushButton *mAutumnPushB;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *mDayPushB;
    QPushButton *mNightPushB;
    QHBoxLayout *horizontalLayout;
    QLabel *label_11;
    QSpinBox *day_spnB;
    QLabel *label_12;
    QComboBox *month_cmbB;
    QLabel *label_13;
    QTimeEdit *time_spnB;
    QGroupBox *mCloudGrB;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_9;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_8;
    QVBoxLayout *verticalLayout_9;
    QScrollBar *cloudHeightScroll;
    QScrollBar *cloudThickScroll;
    QSpacerItem *verticalSpacer;
    QScrollBar *cloudSecLvlScroll;
    QVBoxLayout *verticalLayout_10;
    QLineEdit *cloudBase_inp;
    QLineEdit *cloudThick_inp;
    QLineEdit *cloudSize_inp;
    QComboBox *cloudsSecLay_cmbB;
    QComboBox *cloudsType_cmbB;
    QSpacerItem *horizontalSpacer_9;
    QLineEdit *cloudSecLayer_inp;
    QGroupBox *mPrecipationGrB;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_10;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_12;
    QVBoxLayout *verticalLayout_7;
    QScrollBar *localVisScroll;
    QScrollBar *rainScroll;
    QScrollBar *snowScroll;
    QScrollBar *mistScroll;
    QSpacerItem *horizontalSpacer_8;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *localVis_inp;
    QLineEdit *rain_inp;
    QLineEdit *snow_inp;
    QLineEdit *hmist_inp;
    QSpacerItem *horizontalSpacer_13;
    QGroupBox *mWindGrB;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_21;
    QLabel *label_22;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout_11;
    QScrollBar *windSpeedScroll;
    QScrollBar *windPsiScroll;
    QSpacerItem *horizontalSpacer_7;
    QVBoxLayout *verticalLayout_13;
    QLineEdit *windSpeed_inp;
    QLineEdit *windSpeedPsi_inp;
    QSpacerItem *horizontalSpacer_11;
    QGroupBox *mSightGrB;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_25;
    QLabel *label_26;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_3;
    QScrollBar *visScroll;
    QScrollBar *starsBrightScroll;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_12;
    QLineEdit *visibility_inp;
    QLineEdit *starsBright_inp;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *ok_pushb;
    QPushButton *CancelPB;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menu;

    void setupUi(QMainWindow *meteoWindow)
    {
        if (meteoWindow->objectName().isEmpty())
            meteoWindow->setObjectName(QStringLiteral("meteoWindow"));
        meteoWindow->setWindowModality(Qt::ApplicationModal);
        meteoWindow->resize(678, 1080);
        meteoWindow->setContextMenuPolicy(Qt::NoContextMenu);
        meteoWindow->setLayoutDirection(Qt::LeftToRight);
        action = new QAction(meteoWindow);
        action->setObjectName(QStringLiteral("action"));
        action_2 = new QAction(meteoWindow);
        action_2->setObjectName(QStringLiteral("action_2"));
        action_4 = new QAction(meteoWindow);
        action_4->setObjectName(QStringLiteral("action_4"));
        centralWidget = new QWidget(meteoWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_14 = new QVBoxLayout(centralWidget);
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setContentsMargins(11, 11, 11, 11);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        mTimeGrB = new QGroupBox(centralWidget);
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
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        mWinterPushB = new QPushButton(mTimeGrB);
        mWinterPushB->setObjectName(QStringLiteral("mWinterPushB"));
        mWinterPushB->setCheckable(true);
        mWinterPushB->setChecked(false);

        horizontalLayout_5->addWidget(mWinterPushB);

        mSpringPushB = new QPushButton(mTimeGrB);
        mSpringPushB->setObjectName(QStringLiteral("mSpringPushB"));
        mSpringPushB->setCheckable(true);

        horizontalLayout_5->addWidget(mSpringPushB);

        mSummerPushB = new QPushButton(mTimeGrB);
        mSummerPushB->setObjectName(QStringLiteral("mSummerPushB"));
        mSummerPushB->setCheckable(true);

        horizontalLayout_5->addWidget(mSummerPushB);

        mAutumnPushB = new QPushButton(mTimeGrB);
        mAutumnPushB->setObjectName(QStringLiteral("mAutumnPushB"));
        mAutumnPushB->setCheckable(true);

        horizontalLayout_5->addWidget(mAutumnPushB);


        verticalLayout_5->addLayout(horizontalLayout_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        mDayPushB = new QPushButton(mTimeGrB);
        mDayPushB->setObjectName(QStringLiteral("mDayPushB"));
        mDayPushB->setCheckable(true);

        horizontalLayout_7->addWidget(mDayPushB);

        mNightPushB = new QPushButton(mTimeGrB);
        mNightPushB->setObjectName(QStringLiteral("mNightPushB"));
        mNightPushB->setEnabled(true);
        mNightPushB->setCheckable(true);
        mNightPushB->setChecked(false);

        horizontalLayout_7->addWidget(mNightPushB);


        verticalLayout_5->addLayout(horizontalLayout_7);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_11 = new QLabel(mTimeGrB);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout->addWidget(label_11);

        day_spnB = new QSpinBox(mTimeGrB);
        day_spnB->setObjectName(QStringLiteral("day_spnB"));
        day_spnB->setBaseSize(QSize(0, 1));
        day_spnB->setCursor(QCursor(Qt::UpArrowCursor));
        day_spnB->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        day_spnB->setMinimum(1);
        day_spnB->setMaximum(31);

        horizontalLayout->addWidget(day_spnB);

        label_12 = new QLabel(mTimeGrB);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout->addWidget(label_12);

        month_cmbB = new QComboBox(mTimeGrB);
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
        month_cmbB->setCurrentText(QString::fromUtf8("\321\217\320\275\320\262\320\260\321\200\321\214"));
        month_cmbB->setMaxCount(12);
        month_cmbB->setInsertPolicy(QComboBox::InsertBeforeCurrent);

        horizontalLayout->addWidget(month_cmbB);

        label_13 = new QLabel(mTimeGrB);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout->addWidget(label_13);

        time_spnB = new QTimeEdit(mTimeGrB);
        time_spnB->setObjectName(QStringLiteral("time_spnB"));
        time_spnB->setFocusPolicy(Qt::ClickFocus);
        time_spnB->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        time_spnB->setCurrentSection(QDateTimeEdit::HourSection);
        time_spnB->setCalendarPopup(true);
        time_spnB->setCurrentSectionIndex(0);

        horizontalLayout->addWidget(time_spnB);


        verticalLayout_5->addLayout(horizontalLayout);


        verticalLayout_14->addWidget(mTimeGrB);

        mCloudGrB = new QGroupBox(centralWidget);
        mCloudGrB->setObjectName(QStringLiteral("mCloudGrB"));
        horizontalLayout_6 = new QHBoxLayout(mCloudGrB);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        label_3 = new QLabel(mCloudGrB);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(271, 0));

        verticalLayout_8->addWidget(label_3);

        label_4 = new QLabel(mCloudGrB);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_8->addWidget(label_4);

        label_5 = new QLabel(mCloudGrB);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_8->addWidget(label_5);

        label_9 = new QLabel(mCloudGrB);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_8->addWidget(label_9);

        label_6 = new QLabel(mCloudGrB);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_8->addWidget(label_6);

        horizontalSpacer_5 = new QSpacerItem(268, 13, QSizePolicy::Fixed, QSizePolicy::Minimum);

        verticalLayout_8->addItem(horizontalSpacer_5);

        label_8 = new QLabel(mCloudGrB);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_8->addWidget(label_8);


        horizontalLayout_6->addLayout(verticalLayout_8);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        cloudHeightScroll = new QScrollBar(mCloudGrB);
        cloudHeightScroll->setObjectName(QStringLiteral("cloudHeightScroll"));
        cloudHeightScroll->setBaseSize(QSize(10, 0));
        cloudHeightScroll->setCursor(QCursor(Qt::UpArrowCursor));
        cloudHeightScroll->setAutoFillBackground(false);
        cloudHeightScroll->setMaximum(2000);
        cloudHeightScroll->setSingleStep(10);
        cloudHeightScroll->setPageStep(10);
        cloudHeightScroll->setOrientation(Qt::Horizontal);
        cloudHeightScroll->setInvertedControls(false);

        verticalLayout_9->addWidget(cloudHeightScroll);

        cloudThickScroll = new QScrollBar(mCloudGrB);
        cloudThickScroll->setObjectName(QStringLiteral("cloudThickScroll"));
        cloudThickScroll->setMinimumSize(QSize(0, 3));
        cloudThickScroll->setCursor(QCursor(Qt::UpArrowCursor));
        cloudThickScroll->setSingleStep(5);
        cloudThickScroll->setOrientation(Qt::Horizontal);

        verticalLayout_9->addWidget(cloudThickScroll);

        verticalSpacer = new QSpacerItem(188, 98, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_9->addItem(verticalSpacer);

        cloudSecLvlScroll = new QScrollBar(mCloudGrB);
        cloudSecLvlScroll->setObjectName(QStringLiteral("cloudSecLvlScroll"));
        cloudSecLvlScroll->setEnabled(false);
        cloudSecLvlScroll->setCursor(QCursor(Qt::UpArrowCursor));
        cloudSecLvlScroll->setMaximum(100);
        cloudSecLvlScroll->setOrientation(Qt::Horizontal);

        verticalLayout_9->addWidget(cloudSecLvlScroll);


        horizontalLayout_6->addLayout(verticalLayout_9);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        cloudBase_inp = new QLineEdit(mCloudGrB);
        cloudBase_inp->setObjectName(QStringLiteral("cloudBase_inp"));

        verticalLayout_10->addWidget(cloudBase_inp);

        cloudThick_inp = new QLineEdit(mCloudGrB);
        cloudThick_inp->setObjectName(QStringLiteral("cloudThick_inp"));

        verticalLayout_10->addWidget(cloudThick_inp);

        cloudSize_inp = new QLineEdit(mCloudGrB);
        cloudSize_inp->setObjectName(QStringLiteral("cloudSize_inp"));

        verticalLayout_10->addWidget(cloudSize_inp);

        cloudsSecLay_cmbB = new QComboBox(mCloudGrB);
        cloudsSecLay_cmbB->addItem(QString());
        cloudsSecLay_cmbB->addItem(QString());
        cloudsSecLay_cmbB->setObjectName(QStringLiteral("cloudsSecLay_cmbB"));

        verticalLayout_10->addWidget(cloudsSecLay_cmbB);

        cloudsType_cmbB = new QComboBox(mCloudGrB);
        cloudsType_cmbB->addItem(QString());
        cloudsType_cmbB->addItem(QString());
        cloudsType_cmbB->setObjectName(QStringLiteral("cloudsType_cmbB"));

        verticalLayout_10->addWidget(cloudsType_cmbB);

        horizontalSpacer_9 = new QSpacerItem(100, 13, QSizePolicy::Fixed, QSizePolicy::Minimum);

        verticalLayout_10->addItem(horizontalSpacer_9);

        cloudSecLayer_inp = new QLineEdit(mCloudGrB);
        cloudSecLayer_inp->setObjectName(QStringLiteral("cloudSecLayer_inp"));
        cloudSecLayer_inp->setEnabled(false);
        cloudSecLayer_inp->setCursor(QCursor(Qt::UpArrowCursor));

        verticalLayout_10->addWidget(cloudSecLayer_inp);


        horizontalLayout_6->addLayout(verticalLayout_10);


        verticalLayout_14->addWidget(mCloudGrB);

        mPrecipationGrB = new QGroupBox(centralWidget);
        mPrecipationGrB->setObjectName(QStringLiteral("mPrecipationGrB"));
        horizontalLayout_3 = new QHBoxLayout(mPrecipationGrB);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_10 = new QLabel(mPrecipationGrB);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMinimumSize(QSize(271, 0));

        verticalLayout_2->addWidget(label_10);

        label_2 = new QLabel(mPrecipationGrB);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(271, 0));

        verticalLayout_2->addWidget(label_2);

        label = new QLabel(mPrecipationGrB);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        label_7 = new QLabel(mPrecipationGrB);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_2->addWidget(label_7);

        horizontalSpacer_12 = new QSpacerItem(278, 17, QSizePolicy::Fixed, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer_12);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        localVisScroll = new QScrollBar(mPrecipationGrB);
        localVisScroll->setObjectName(QStringLiteral("localVisScroll"));
        localVisScroll->setBaseSize(QSize(271, 0));
        localVisScroll->setCursor(QCursor(Qt::UpArrowCursor));
        localVisScroll->setSingleStep(1);
        localVisScroll->setOrientation(Qt::Horizontal);

        verticalLayout_7->addWidget(localVisScroll);

        rainScroll = new QScrollBar(mPrecipationGrB);
        rainScroll->setObjectName(QStringLiteral("rainScroll"));
        rainScroll->setCursor(QCursor(Qt::UpArrowCursor));
        rainScroll->setOrientation(Qt::Horizontal);

        verticalLayout_7->addWidget(rainScroll);

        snowScroll = new QScrollBar(mPrecipationGrB);
        snowScroll->setObjectName(QStringLiteral("snowScroll"));
        snowScroll->setCursor(QCursor(Qt::UpArrowCursor));
        snowScroll->setOrientation(Qt::Horizontal);

        verticalLayout_7->addWidget(snowScroll);

        mistScroll = new QScrollBar(mPrecipationGrB);
        mistScroll->setObjectName(QStringLiteral("mistScroll"));
        mistScroll->setCursor(QCursor(Qt::UpArrowCursor));
        mistScroll->setOrientation(Qt::Horizontal);

        verticalLayout_7->addWidget(mistScroll);

        horizontalSpacer_8 = new QSpacerItem(188, 17, QSizePolicy::Fixed, QSizePolicy::Minimum);

        verticalLayout_7->addItem(horizontalSpacer_8);


        horizontalLayout_3->addLayout(verticalLayout_7);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        localVis_inp = new QLineEdit(mPrecipationGrB);
        localVis_inp->setObjectName(QStringLiteral("localVis_inp"));
        localVis_inp->setMinimumSize(QSize(0, 0));

        verticalLayout_4->addWidget(localVis_inp);

        rain_inp = new QLineEdit(mPrecipationGrB);
        rain_inp->setObjectName(QStringLiteral("rain_inp"));

        verticalLayout_4->addWidget(rain_inp);

        snow_inp = new QLineEdit(mPrecipationGrB);
        snow_inp->setObjectName(QStringLiteral("snow_inp"));

        verticalLayout_4->addWidget(snow_inp);

        hmist_inp = new QLineEdit(mPrecipationGrB);
        hmist_inp->setObjectName(QStringLiteral("hmist_inp"));

        verticalLayout_4->addWidget(hmist_inp);

        horizontalSpacer_13 = new QSpacerItem(118, 17, QSizePolicy::Fixed, QSizePolicy::Minimum);

        verticalLayout_4->addItem(horizontalSpacer_13);


        horizontalLayout_3->addLayout(verticalLayout_4);


        verticalLayout_14->addWidget(mPrecipationGrB);

        mWindGrB = new QGroupBox(centralWidget);
        mWindGrB->setObjectName(QStringLiteral("mWindGrB"));
        horizontalLayout_4 = new QHBoxLayout(mWindGrB);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_21 = new QLabel(mWindGrB);
        label_21->setObjectName(QStringLiteral("label_21"));

        verticalLayout_6->addWidget(label_21);

        label_22 = new QLabel(mWindGrB);
        label_22->setObjectName(QStringLiteral("label_22"));

        verticalLayout_6->addWidget(label_22);

        horizontalSpacer_6 = new QSpacerItem(278, 17, QSizePolicy::Fixed, QSizePolicy::Minimum);

        verticalLayout_6->addItem(horizontalSpacer_6);


        horizontalLayout_4->addLayout(verticalLayout_6);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        windSpeedScroll = new QScrollBar(mWindGrB);
        windSpeedScroll->setObjectName(QStringLiteral("windSpeedScroll"));
        windSpeedScroll->setCursor(QCursor(Qt::UpArrowCursor));
        windSpeedScroll->setOrientation(Qt::Horizontal);

        verticalLayout_11->addWidget(windSpeedScroll);

        windPsiScroll = new QScrollBar(mWindGrB);
        windPsiScroll->setObjectName(QStringLiteral("windPsiScroll"));
        windPsiScroll->setCursor(QCursor(Qt::UpArrowCursor));
        windPsiScroll->setOrientation(Qt::Horizontal);

        verticalLayout_11->addWidget(windPsiScroll);

        horizontalSpacer_7 = new QSpacerItem(188, 17, QSizePolicy::Fixed, QSizePolicy::Minimum);

        verticalLayout_11->addItem(horizontalSpacer_7);


        horizontalLayout_4->addLayout(verticalLayout_11);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        windSpeed_inp = new QLineEdit(mWindGrB);
        windSpeed_inp->setObjectName(QStringLiteral("windSpeed_inp"));

        verticalLayout_13->addWidget(windSpeed_inp);

        windSpeedPsi_inp = new QLineEdit(mWindGrB);
        windSpeedPsi_inp->setObjectName(QStringLiteral("windSpeedPsi_inp"));

        verticalLayout_13->addWidget(windSpeedPsi_inp);

        horizontalSpacer_11 = new QSpacerItem(100, 17, QSizePolicy::Fixed, QSizePolicy::Minimum);

        verticalLayout_13->addItem(horizontalSpacer_11);


        horizontalLayout_4->addLayout(verticalLayout_13);


        verticalLayout_14->addWidget(mWindGrB);

        mSightGrB = new QGroupBox(centralWidget);
        mSightGrB->setObjectName(QStringLiteral("mSightGrB"));
        horizontalLayout_2 = new QHBoxLayout(mSightGrB);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_25 = new QLabel(mSightGrB);
        label_25->setObjectName(QStringLiteral("label_25"));

        verticalLayout->addWidget(label_25);

        label_26 = new QLabel(mSightGrB);
        label_26->setObjectName(QStringLiteral("label_26"));

        verticalLayout->addWidget(label_26);

        horizontalSpacer_2 = new QSpacerItem(280, 17, QSizePolicy::Fixed, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        visScroll = new QScrollBar(mSightGrB);
        visScroll->setObjectName(QStringLiteral("visScroll"));
        visScroll->setCursor(QCursor(Qt::UpArrowCursor));
        visScroll->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(visScroll);

        starsBrightScroll = new QScrollBar(mSightGrB);
        starsBrightScroll->setObjectName(QStringLiteral("starsBrightScroll"));
        starsBrightScroll->setCursor(QCursor(Qt::UpArrowCursor));
        starsBrightScroll->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(starsBrightScroll);

        horizontalSpacer_3 = new QSpacerItem(188, 17, QSizePolicy::Fixed, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_3);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        visibility_inp = new QLineEdit(mSightGrB);
        visibility_inp->setObjectName(QStringLiteral("visibility_inp"));
        visibility_inp->setBaseSize(QSize(0, 3));

        verticalLayout_12->addWidget(visibility_inp);

        starsBright_inp = new QLineEdit(mSightGrB);
        starsBright_inp->setObjectName(QStringLiteral("starsBright_inp"));

        verticalLayout_12->addWidget(starsBright_inp);

        horizontalSpacer_10 = new QSpacerItem(128, 17, QSizePolicy::Fixed, QSizePolicy::Minimum);

        verticalLayout_12->addItem(horizontalSpacer_10);


        horizontalLayout_2->addLayout(verticalLayout_12);


        verticalLayout_14->addWidget(mSightGrB);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer_4 = new QSpacerItem(408, 38, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);

        ok_pushb = new QPushButton(centralWidget);
        ok_pushb->setObjectName(QStringLiteral("ok_pushb"));

        horizontalLayout_8->addWidget(ok_pushb);

        CancelPB = new QPushButton(centralWidget);
        CancelPB->setObjectName(QStringLiteral("CancelPB"));

        horizontalLayout_8->addWidget(CancelPB);


        verticalLayout_14->addLayout(horizontalLayout_8);

        meteoWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(meteoWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        meteoWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(meteoWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 678, 31));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        meteoWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(action);
        menu->addAction(action_2);
        menu->addSeparator();
        menu->addAction(action_4);

        retranslateUi(meteoWindow);

        mNightPushB->setDefault(false);
        month_cmbB->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(meteoWindow);
    } // setupUi

    void retranslateUi(QMainWindow *meteoWindow)
    {
        meteoWindow->setWindowTitle(QApplication::translate("meteoWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 \321\203\321\201\320\273\320\276\320\262\320\270\320\271 \320\276\320\272\321\200\321\203\320\266\320\260\321\216\321\211\320\265\320\271 \320\276\320\261\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\270", nullptr));
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
        month_cmbB->setItemText(0, QApplication::translate("meteoWindow", "\320\264\320\265\320\272\320\260\320\261\321\200\321\214", nullptr));
        month_cmbB->setItemText(1, QApplication::translate("meteoWindow", "\321\217\320\275\320\262\320\260\321\200\321\214", nullptr));
        month_cmbB->setItemText(2, QApplication::translate("meteoWindow", "\321\204\320\265\320\262\321\200\320\260\320\273\321\214", nullptr));
        month_cmbB->setItemText(3, QApplication::translate("meteoWindow", "\320\274\320\260\321\200\321\202", nullptr));
        month_cmbB->setItemText(4, QApplication::translate("meteoWindow", "\320\260\320\277\321\200\320\265\320\273\321\214", nullptr));
        month_cmbB->setItemText(5, QApplication::translate("meteoWindow", "\320\274\320\260\320\271", nullptr));
        month_cmbB->setItemText(6, QApplication::translate("meteoWindow", "\320\270\321\216\320\275\321\214", nullptr));
        month_cmbB->setItemText(7, QApplication::translate("meteoWindow", "\320\270\321\216\320\273\321\214", nullptr));
        month_cmbB->setItemText(8, QApplication::translate("meteoWindow", "\320\260\320\262\320\263\321\203\321\201\321\202", nullptr));
        month_cmbB->setItemText(9, QApplication::translate("meteoWindow", "\321\201\320\265\320\275\321\202\321\217\320\261\321\200\321\214", nullptr));
        month_cmbB->setItemText(10, QApplication::translate("meteoWindow", "\320\276\320\272\321\202\321\217\320\261\321\200\321\214", nullptr));
        month_cmbB->setItemText(11, QApplication::translate("meteoWindow", "\320\275\320\276\321\217\320\261\321\200\321\214", nullptr));

        label_13->setText(QApplication::translate("meteoWindow", "\320\222\321\200\320\265\320\274\321\217", nullptr));
        mCloudGrB->setTitle(QApplication::translate("meteoWindow", "\320\236\320\261\320\273\320\260\321\207\320\275\320\276\321\201\321\202\321\214", nullptr));
        label_3->setText(QApplication::translate("meteoWindow", "\320\222\321\213\321\201\320\276\321\202\320\260 \320\275\320\270\320\266\320\275\320\265\320\271 \320\272\321\200\320\276\320\274\320\272\320\270 \320\276\320\261\320\273\320\260\320\272\320\276\320\262, [\320\274]", nullptr));
        label_4->setText(QApplication::translate("meteoWindow", "\320\242\320\276\320\273\321\211\320\270\320\275\320\260 \321\201\320\273\320\276\321\217 \320\276\320\261\320\273\320\260\320\272\320\276\320\262, [\320\274]", nullptr));
        label_5->setText(QApplication::translate("meteoWindow", "\320\221\320\260\320\273\321\214\320\275\320\276\321\201\321\202\321\214 \320\276\320\261\320\273\320\260\320\272\320\276\320\262,1...10 [\320\265\320\264]", nullptr));
        label_9->setText(QApplication::translate("meteoWindow", "\320\235\320\260\320\273\320\270\321\207\320\270\320\265 \320\262\321\202\320\276\321\200\320\276\320\263\320\276 \321\201\320\273\320\276\321\217 \320\276\320\261\320\273\320\260\320\272\320\276\320\262", nullptr));
        label_6->setText(QApplication::translate("meteoWindow", "\320\242\320\270\320\277 \320\276\320\261\320\273\320\260\320\272\320\276\320\262 (\320\276\320\261\321\213\321\207\320\275\321\213\320\265, \320\263\321\200\320\276\320\267\320\276\320\262\321\213\320\265)", nullptr));
        label_8->setText(QApplication::translate("meteoWindow", "\320\222\321\213\321\201\320\276\321\202\320\260 \320\262\321\202\320\276\321\200\320\276\320\263\320\276 \321\201\320\273\320\276\321\217 \320\276\320\261\320\273\320\260\320\272\320\276\320\262, [\320\274]", nullptr));
        cloudBase_inp->setText(QApplication::translate("meteoWindow", "0", nullptr));
        cloudThick_inp->setText(QApplication::translate("meteoWindow", "0", nullptr));
        cloudSize_inp->setText(QApplication::translate("meteoWindow", "0", nullptr));
        cloudsSecLay_cmbB->setItemText(0, QApplication::translate("meteoWindow", "\320\275\320\265\321\202", nullptr));
        cloudsSecLay_cmbB->setItemText(1, QApplication::translate("meteoWindow", "\320\264\320\260", nullptr));

        cloudsType_cmbB->setItemText(0, QApplication::translate("meteoWindow", "\320\276\320\261\321\213\321\207\320\275\321\213\320\265", nullptr));
        cloudsType_cmbB->setItemText(1, QApplication::translate("meteoWindow", "\320\263\321\200\320\276\320\267\320\276\320\262\321\213\320\265", nullptr));

        cloudSecLayer_inp->setText(QApplication::translate("meteoWindow", "0", nullptr));
        mPrecipationGrB->setTitle(QApplication::translate("meteoWindow", "\320\236\321\201\320\260\320\264\320\272\320\270", nullptr));
        label_10->setText(QApplication::translate("meteoWindow", "\320\233\320\276\320\272\320\260\320\273\321\214\320\275\320\260\321\217 \320\264\320\260\320\273\321\214\320\275\320\276\321\201\321\202\321\214 \320\262\320\270\320\264\320\270\320\274\320\276\321\201\321\202\320\270, [\320\274]", nullptr));
        label_2->setText(QApplication::translate("meteoWindow", "\320\230\320\275\321\202\320\265\320\275\321\201\320\270\320\262\320\275\320\276\321\201\321\202\321\214 \320\264\320\276\320\266\320\264\321\217, %", nullptr));
        label->setText(QApplication::translate("meteoWindow", "\320\230\320\275\321\202\320\265\320\275\321\201\320\270\320\262\320\275\320\276\321\201\321\202\321\214 \321\201\320\275\320\265\320\263\320\260, %", nullptr));
        label_7->setText(QApplication::translate("meteoWindow", "\320\222\321\213\321\201\320\276\321\202\320\260 \320\264\321\213\320\274\320\272\320\270 \321\202\321\203\320\274\320\260\320\275\320\260, [\320\274]", nullptr));
        localVis_inp->setText(QApplication::translate("meteoWindow", "0", nullptr));
        rain_inp->setText(QApplication::translate("meteoWindow", "0", nullptr));
        snow_inp->setText(QApplication::translate("meteoWindow", "0", nullptr));
        hmist_inp->setText(QApplication::translate("meteoWindow", "0", nullptr));
        mWindGrB->setTitle(QApplication::translate("meteoWindow", "\320\222\320\265\321\202\320\265\321\200", nullptr));
        label_21->setText(QApplication::translate("meteoWindow", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214 \320\262\320\265\321\202\321\200\320\260, [\320\274/\321\201]", nullptr));
        label_22->setText(QApplication::translate("meteoWindow", "\320\235\320\260\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\262\320\265\321\202\321\200\320\260, 0...360 [\320\263\321\200\320\260\320\264]", nullptr));
        windSpeed_inp->setText(QApplication::translate("meteoWindow", "0", nullptr));
        windSpeedPsi_inp->setText(QApplication::translate("meteoWindow", "0", nullptr));
        mSightGrB->setTitle(QApplication::translate("meteoWindow", "\320\222\320\270\320\264\320\270\320\274\320\276\321\201\321\202\321\214", nullptr));
        label_25->setText(QApplication::translate("meteoWindow", "\320\223\320\273\320\276\320\261\320\260\320\273\321\214\320\275\320\260\321\217 \320\264\320\260\320\273\321\214\320\275\320\276\321\201\321\202\321\214 \320\262\320\270\320\264\320\270\320\274\320\276\321\201\321\202\320\270, [\320\274]", nullptr));
        label_26->setText(QApplication::translate("meteoWindow", "\320\257\321\200\320\272\320\276\321\201\321\202\321\214 \320\267\320\262\320\265\320\267\320\264, %", nullptr));
        visibility_inp->setText(QApplication::translate("meteoWindow", "0", nullptr));
        starsBright_inp->setText(QApplication::translate("meteoWindow", "0", nullptr));
        ok_pushb->setText(QApplication::translate("meteoWindow", "OK", nullptr));
        CancelPB->setText(QApplication::translate("meteoWindow", "Cancel", nullptr));
        menu->setTitle(QApplication::translate("meteoWindow", "\320\244\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class meteoWindow: public Ui_meteoWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_METEOFORM_H
