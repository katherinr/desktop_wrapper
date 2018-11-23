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
    QAction *action_3;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_34;
    QGroupBox *mTimeGrB;
    QVBoxLayout *verticalLayout_29;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *mWinterPushB_;
    QPushButton *mSpringPushB_;
    QPushButton *mSummerPushB_;
    QPushButton *mAutumnPushB_;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *mDayPushB_;
    QPushButton *mNightPushB_;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_36;
    QSpinBox *day_spnB_;
    QLabel *label_37;
    QComboBox *month_cmbB_;
    QLabel *label_38;
    QTimeEdit *time_spnB_;
    QGroupBox *mCloudGrB;
    QVBoxLayout *verticalLayout_33;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_41;
    QScrollBar *cloudHeightScroll_;
    QLineEdit *cloudBase_inp_;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_42;
    QScrollBar *cloudThickScroll_;
    QLineEdit *cloudThick_inp_;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_43;
    QSpacerItem *verticalSpacer_9;
    QLineEdit *cloudSize_inp_;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_44;
    QSpacerItem *verticalSpacer_10;
    QComboBox *cloudsSecLay_cmbB_;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_45;
    QSpacerItem *verticalSpacer_11;
    QComboBox *cloudsType_cmbB_;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_46;
    QScrollBar *cloudSecLvlScroll_;
    QLineEdit *cloudSecLayer_inp_;
    QGroupBox *mPrecipationGrB;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_26;
    QLabel *label_32;
    QLabel *label_33;
    QLabel *label_34;
    QLabel *label_35;
    QVBoxLayout *verticalLayout_27;
    QScrollBar *localVisScroll_;
    QScrollBar *rainScroll_;
    QScrollBar *snowScroll_;
    QScrollBar *mistScroll_;
    QVBoxLayout *verticalLayout_28;
    QLineEdit *localVis_inp_;
    QLineEdit *rain_inp_;
    QLineEdit *snow_inp_;
    QLineEdit *hmist_inp_;
    QGroupBox *mWindGrB;
    QHBoxLayout *horizontalLayout_12;
    QVBoxLayout *verticalLayout_30;
    QLabel *label_39;
    QLabel *label_40;
    QVBoxLayout *verticalLayout_31;
    QScrollBar *windSpeedScroll_;
    QScrollBar *windPsiScroll_;
    QVBoxLayout *verticalLayout_32;
    QLineEdit *windSpeed_inp_;
    QLineEdit *windSpeedPsi_inp_;
    QGroupBox *mSightGrB;
    QHBoxLayout *horizontalLayout_14;
    QVBoxLayout *verticalLayout_36;
    QLabel *label_47;
    QLabel *label_48;
    QVBoxLayout *verticalLayout_37;
    QScrollBar *visScroll_;
    QScrollBar *starsBrightScroll_;
    QVBoxLayout *verticalLayout_38;
    QLineEdit *visibility_inp_;
    QLineEdit *starsBright_inp_;
    QHBoxLayout *horizontalLayout_13;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *ok_pushb_;
    QPushButton *CancelPB_;
    QMenuBar *menuBar;
    QMenu *menu;

    void setupUi(QMainWindow *meteoWindow)
    {
        if (meteoWindow->objectName().isEmpty())
            meteoWindow->setObjectName(QStringLiteral("meteoWindow"));
        meteoWindow->setWindowModality(Qt::ApplicationModal);
        meteoWindow->resize(646, 883);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(meteoWindow->sizePolicy().hasHeightForWidth());
        meteoWindow->setSizePolicy(sizePolicy);
        meteoWindow->setMinimumSize(QSize(646, 883));
        meteoWindow->setMaximumSize(QSize(646, 883));
        meteoWindow->setBaseSize(QSize(646, 946));
        meteoWindow->setContextMenuPolicy(Qt::NoContextMenu);
#ifndef QT_NO_WHATSTHIS
        meteoWindow->setWhatsThis(QStringLiteral(""));
#endif // QT_NO_WHATSTHIS
        meteoWindow->setLayoutDirection(Qt::LeftToRight);
        meteoWindow->setAutoFillBackground(true);
        meteoWindow->setAnimated(false);
        action = new QAction(meteoWindow);
        action->setObjectName(QStringLiteral("action"));
        action_2 = new QAction(meteoWindow);
        action_2->setObjectName(QStringLiteral("action_2"));
        action_4 = new QAction(meteoWindow);
        action_4->setObjectName(QStringLiteral("action_4"));
        action_3 = new QAction(meteoWindow);
        action_3->setObjectName(QStringLiteral("action_3"));
        centralWidget = new QWidget(meteoWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        centralWidget->setMinimumSize(QSize(620, 852));
        centralWidget->setMaximumSize(QSize(646, 920));
        centralWidget->setBaseSize(QSize(646, 946));
        centralWidget->setContextMenuPolicy(Qt::NoContextMenu);
        verticalLayout_34 = new QVBoxLayout(centralWidget);
        verticalLayout_34->setSpacing(6);
        verticalLayout_34->setContentsMargins(11, 11, 11, 11);
        verticalLayout_34->setObjectName(QStringLiteral("verticalLayout_34"));
        mTimeGrB = new QGroupBox(centralWidget);
        mTimeGrB->setObjectName(QStringLiteral("mTimeGrB"));
        sizePolicy1.setHeightForWidth(mTimeGrB->sizePolicy().hasHeightForWidth());
        mTimeGrB->setSizePolicy(sizePolicy1);
        mTimeGrB->setMinimumSize(QSize(411, 131));
        mTimeGrB->setMaximumSize(QSize(620, 131));
        mTimeGrB->setBaseSize(QSize(0, 0));
        mTimeGrB->setTabletTracking(false);
        mTimeGrB->setContextMenuPolicy(Qt::NoContextMenu);
        mTimeGrB->setAcceptDrops(false);
        verticalLayout_29 = new QVBoxLayout(mTimeGrB);
        verticalLayout_29->setSpacing(5);
        verticalLayout_29->setContentsMargins(11, 11, 11, 11);
        verticalLayout_29->setObjectName(QStringLiteral("verticalLayout_29"));
        verticalLayout_29->setContentsMargins(5, 5, 5, 5);
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        mWinterPushB_ = new QPushButton(mTimeGrB);
        mWinterPushB_->setObjectName(QStringLiteral("mWinterPushB_"));
        mWinterPushB_->setCheckable(false);
        mWinterPushB_->setChecked(false);

        horizontalLayout_9->addWidget(mWinterPushB_);

        mSpringPushB_ = new QPushButton(mTimeGrB);
        mSpringPushB_->setObjectName(QStringLiteral("mSpringPushB_"));
        mSpringPushB_->setCheckable(false);

        horizontalLayout_9->addWidget(mSpringPushB_);

        mSummerPushB_ = new QPushButton(mTimeGrB);
        mSummerPushB_->setObjectName(QStringLiteral("mSummerPushB_"));
        mSummerPushB_->setCheckable(false);

        horizontalLayout_9->addWidget(mSummerPushB_);

        mAutumnPushB_ = new QPushButton(mTimeGrB);
        mAutumnPushB_->setObjectName(QStringLiteral("mAutumnPushB_"));
        mAutumnPushB_->setCheckable(false);

        horizontalLayout_9->addWidget(mAutumnPushB_);


        verticalLayout_29->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        mDayPushB_ = new QPushButton(mTimeGrB);
        mDayPushB_->setObjectName(QStringLiteral("mDayPushB_"));
        mDayPushB_->setCheckable(false);

        horizontalLayout_10->addWidget(mDayPushB_);

        mNightPushB_ = new QPushButton(mTimeGrB);
        mNightPushB_->setObjectName(QStringLiteral("mNightPushB_"));
        mNightPushB_->setEnabled(true);
        mNightPushB_->setToolTipDuration(0);
        mNightPushB_->setCheckable(false);
        mNightPushB_->setChecked(false);

        horizontalLayout_10->addWidget(mNightPushB_);


        verticalLayout_29->addLayout(horizontalLayout_10);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_36 = new QLabel(mTimeGrB);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_36);

        day_spnB_ = new QSpinBox(mTimeGrB);
        day_spnB_->setObjectName(QStringLiteral("day_spnB_"));
        day_spnB_->setBaseSize(QSize(0, 1));
        day_spnB_->setCursor(QCursor(Qt::UpArrowCursor));
        day_spnB_->setToolTipDuration(-2);
#ifndef QT_NO_WHATSTHIS
        day_spnB_->setWhatsThis(QStringLiteral(""));
#endif // QT_NO_WHATSTHIS
        day_spnB_->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        day_spnB_->setMinimum(1);
        day_spnB_->setMaximum(31);
        day_spnB_->setValue(15);

        horizontalLayout_2->addWidget(day_spnB_);

        label_37 = new QLabel(mTimeGrB);
        label_37->setObjectName(QStringLiteral("label_37"));
        label_37->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_37);

        month_cmbB_ = new QComboBox(mTimeGrB);
        month_cmbB_->addItem(QString());
        month_cmbB_->addItem(QString());
        month_cmbB_->addItem(QString());
        month_cmbB_->addItem(QString());
        month_cmbB_->addItem(QString());
        month_cmbB_->addItem(QString());
        month_cmbB_->addItem(QString());
        month_cmbB_->addItem(QString());
        month_cmbB_->addItem(QString());
        month_cmbB_->addItem(QString());
        month_cmbB_->addItem(QString());
        month_cmbB_->addItem(QString());
        month_cmbB_->setObjectName(QStringLiteral("month_cmbB_"));
        month_cmbB_->setCurrentText(QString::fromUtf8("\320\274\320\260\320\271"));
        month_cmbB_->setMaxCount(12);
        month_cmbB_->setInsertPolicy(QComboBox::InsertBeforeCurrent);

        horizontalLayout_2->addWidget(month_cmbB_);

        label_38 = new QLabel(mTimeGrB);
        label_38->setObjectName(QStringLiteral("label_38"));
        label_38->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_38);

        time_spnB_ = new QTimeEdit(mTimeGrB);
        time_spnB_->setObjectName(QStringLiteral("time_spnB_"));
        time_spnB_->setFocusPolicy(Qt::ClickFocus);
        time_spnB_->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        time_spnB_->setCurrentSection(QDateTimeEdit::HourSection);
        time_spnB_->setCalendarPopup(true);
        time_spnB_->setCurrentSectionIndex(0);
        time_spnB_->setTime(QTime(2, 0, 0));

        horizontalLayout_2->addWidget(time_spnB_);


        verticalLayout_29->addLayout(horizontalLayout_2);


        verticalLayout_34->addWidget(mTimeGrB);

        mCloudGrB = new QGroupBox(centralWidget);
        mCloudGrB->setObjectName(QStringLiteral("mCloudGrB"));
        sizePolicy1.setHeightForWidth(mCloudGrB->sizePolicy().hasHeightForWidth());
        mCloudGrB->setSizePolicy(sizePolicy1);
        mCloudGrB->setMinimumSize(QSize(620, 251));
        mCloudGrB->setMaximumSize(QSize(620, 251));
        mCloudGrB->setBaseSize(QSize(620, 0));
        mCloudGrB->setFocusPolicy(Qt::TabFocus);
        mCloudGrB->setAcceptDrops(false);
        verticalLayout_33 = new QVBoxLayout(mCloudGrB);
        verticalLayout_33->setSpacing(5);
        verticalLayout_33->setContentsMargins(11, 11, 11, 11);
        verticalLayout_33->setObjectName(QStringLiteral("verticalLayout_33"));
        verticalLayout_33->setContentsMargins(5, 5, 5, 5);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_41 = new QLabel(mCloudGrB);
        label_41->setObjectName(QStringLiteral("label_41"));
        sizePolicy.setHeightForWidth(label_41->sizePolicy().hasHeightForWidth());
        label_41->setSizePolicy(sizePolicy);
        label_41->setMinimumSize(QSize(280, 25));
        label_41->setMaximumSize(QSize(280, 25));
        label_41->setBaseSize(QSize(300, 25));

        horizontalLayout_8->addWidget(label_41);

        cloudHeightScroll_ = new QScrollBar(mCloudGrB);
        cloudHeightScroll_->setObjectName(QStringLiteral("cloudHeightScroll_"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(cloudHeightScroll_->sizePolicy().hasHeightForWidth());
        cloudHeightScroll_->setSizePolicy(sizePolicy2);
        cloudHeightScroll_->setMinimumSize(QSize(188, 25));
        cloudHeightScroll_->setMaximumSize(QSize(16777215, 25));
        cloudHeightScroll_->setBaseSize(QSize(10, 0));
        cloudHeightScroll_->setCursor(QCursor(Qt::UpArrowCursor));
        cloudHeightScroll_->setAutoFillBackground(false);
        cloudHeightScroll_->setMaximum(2000);
        cloudHeightScroll_->setSingleStep(10);
        cloudHeightScroll_->setPageStep(10);
        cloudHeightScroll_->setOrientation(Qt::Horizontal);
        cloudHeightScroll_->setInvertedControls(false);

        horizontalLayout_8->addWidget(cloudHeightScroll_);

        cloudBase_inp_ = new QLineEdit(mCloudGrB);
        cloudBase_inp_->setObjectName(QStringLiteral("cloudBase_inp_"));
        sizePolicy.setHeightForWidth(cloudBase_inp_->sizePolicy().hasHeightForWidth());
        cloudBase_inp_->setSizePolicy(sizePolicy);
        cloudBase_inp_->setMinimumSize(QSize(70, 25));
        cloudBase_inp_->setMaximumSize(QSize(100, 25));

        horizontalLayout_8->addWidget(cloudBase_inp_);


        verticalLayout_33->addLayout(horizontalLayout_8);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label_42 = new QLabel(mCloudGrB);
        label_42->setObjectName(QStringLiteral("label_42"));
        sizePolicy.setHeightForWidth(label_42->sizePolicy().hasHeightForWidth());
        label_42->setSizePolicy(sizePolicy);
        label_42->setMinimumSize(QSize(280, 25));
        label_42->setMaximumSize(QSize(300, 25));

        horizontalLayout_15->addWidget(label_42);

        cloudThickScroll_ = new QScrollBar(mCloudGrB);
        cloudThickScroll_->setObjectName(QStringLiteral("cloudThickScroll_"));
        sizePolicy2.setHeightForWidth(cloudThickScroll_->sizePolicy().hasHeightForWidth());
        cloudThickScroll_->setSizePolicy(sizePolicy2);
        cloudThickScroll_->setMinimumSize(QSize(188, 25));
        cloudThickScroll_->setMaximumSize(QSize(16777215, 25));
        cloudThickScroll_->setCursor(QCursor(Qt::UpArrowCursor));
        cloudThickScroll_->setSingleStep(5);
        cloudThickScroll_->setOrientation(Qt::Horizontal);

        horizontalLayout_15->addWidget(cloudThickScroll_);

        cloudThick_inp_ = new QLineEdit(mCloudGrB);
        cloudThick_inp_->setObjectName(QStringLiteral("cloudThick_inp_"));
        sizePolicy.setHeightForWidth(cloudThick_inp_->sizePolicy().hasHeightForWidth());
        cloudThick_inp_->setSizePolicy(sizePolicy);
        cloudThick_inp_->setMinimumSize(QSize(70, 25));
        cloudThick_inp_->setMaximumSize(QSize(100, 25));

        horizontalLayout_15->addWidget(cloudThick_inp_);


        verticalLayout_33->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(0);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        label_43 = new QLabel(mCloudGrB);
        label_43->setObjectName(QStringLiteral("label_43"));
        sizePolicy.setHeightForWidth(label_43->sizePolicy().hasHeightForWidth());
        label_43->setSizePolicy(sizePolicy);
        label_43->setMinimumSize(QSize(280, 25));
        label_43->setMaximumSize(QSize(300, 25));

        horizontalLayout_16->addWidget(label_43);

        verticalSpacer_9 = new QSpacerItem(208, 25, QSizePolicy::Minimum, QSizePolicy::Fixed);

        horizontalLayout_16->addItem(verticalSpacer_9);

        cloudSize_inp_ = new QLineEdit(mCloudGrB);
        cloudSize_inp_->setObjectName(QStringLiteral("cloudSize_inp_"));
        sizePolicy.setHeightForWidth(cloudSize_inp_->sizePolicy().hasHeightForWidth());
        cloudSize_inp_->setSizePolicy(sizePolicy);
        cloudSize_inp_->setMinimumSize(QSize(70, 25));
        cloudSize_inp_->setMaximumSize(QSize(100, 25));

        horizontalLayout_16->addWidget(cloudSize_inp_);


        verticalLayout_33->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        label_44 = new QLabel(mCloudGrB);
        label_44->setObjectName(QStringLiteral("label_44"));
        sizePolicy.setHeightForWidth(label_44->sizePolicy().hasHeightForWidth());
        label_44->setSizePolicy(sizePolicy);
        label_44->setMinimumSize(QSize(280, 25));
        label_44->setMaximumSize(QSize(300, 25));

        horizontalLayout_17->addWidget(label_44);

        verticalSpacer_10 = new QSpacerItem(208, 25, QSizePolicy::Minimum, QSizePolicy::Fixed);

        horizontalLayout_17->addItem(verticalSpacer_10);

        cloudsSecLay_cmbB_ = new QComboBox(mCloudGrB);
        cloudsSecLay_cmbB_->addItem(QString());
        cloudsSecLay_cmbB_->addItem(QString());
        cloudsSecLay_cmbB_->setObjectName(QStringLiteral("cloudsSecLay_cmbB_"));
        sizePolicy.setHeightForWidth(cloudsSecLay_cmbB_->sizePolicy().hasHeightForWidth());
        cloudsSecLay_cmbB_->setSizePolicy(sizePolicy);
        cloudsSecLay_cmbB_->setMinimumSize(QSize(70, 25));
        cloudsSecLay_cmbB_->setMaximumSize(QSize(100, 25));

        horizontalLayout_17->addWidget(cloudsSecLay_cmbB_);


        verticalLayout_33->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        label_45 = new QLabel(mCloudGrB);
        label_45->setObjectName(QStringLiteral("label_45"));
        sizePolicy.setHeightForWidth(label_45->sizePolicy().hasHeightForWidth());
        label_45->setSizePolicy(sizePolicy);
        label_45->setMinimumSize(QSize(280, 25));
        label_45->setMaximumSize(QSize(300, 25));

        horizontalLayout_18->addWidget(label_45);

        verticalSpacer_11 = new QSpacerItem(208, 25, QSizePolicy::Minimum, QSizePolicy::Fixed);

        horizontalLayout_18->addItem(verticalSpacer_11);

        cloudsType_cmbB_ = new QComboBox(mCloudGrB);
        cloudsType_cmbB_->addItem(QString());
        cloudsType_cmbB_->addItem(QString());
        cloudsType_cmbB_->setObjectName(QStringLiteral("cloudsType_cmbB_"));
        sizePolicy.setHeightForWidth(cloudsType_cmbB_->sizePolicy().hasHeightForWidth());
        cloudsType_cmbB_->setSizePolicy(sizePolicy);
        cloudsType_cmbB_->setMinimumSize(QSize(100, 25));
        cloudsType_cmbB_->setMaximumSize(QSize(100, 25));

        horizontalLayout_18->addWidget(cloudsType_cmbB_);


        verticalLayout_33->addLayout(horizontalLayout_18);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        label_46 = new QLabel(mCloudGrB);
        label_46->setObjectName(QStringLiteral("label_46"));
        sizePolicy.setHeightForWidth(label_46->sizePolicy().hasHeightForWidth());
        label_46->setSizePolicy(sizePolicy);
        label_46->setMinimumSize(QSize(280, 25));
        label_46->setMaximumSize(QSize(300, 25));

        horizontalLayout_19->addWidget(label_46);

        cloudSecLvlScroll_ = new QScrollBar(mCloudGrB);
        cloudSecLvlScroll_->setObjectName(QStringLiteral("cloudSecLvlScroll_"));
        cloudSecLvlScroll_->setEnabled(false);
        sizePolicy2.setHeightForWidth(cloudSecLvlScroll_->sizePolicy().hasHeightForWidth());
        cloudSecLvlScroll_->setSizePolicy(sizePolicy2);
        cloudSecLvlScroll_->setMinimumSize(QSize(188, 25));
        cloudSecLvlScroll_->setMaximumSize(QSize(16777215, 25));
        cloudSecLvlScroll_->setBaseSize(QSize(188, 25));
        cloudSecLvlScroll_->setCursor(QCursor(Qt::UpArrowCursor));
        cloudSecLvlScroll_->setMinimum(188);
        cloudSecLvlScroll_->setMaximum(188);
        cloudSecLvlScroll_->setValue(188);
        cloudSecLvlScroll_->setSliderPosition(188);
        cloudSecLvlScroll_->setOrientation(Qt::Horizontal);

        horizontalLayout_19->addWidget(cloudSecLvlScroll_);

        cloudSecLayer_inp_ = new QLineEdit(mCloudGrB);
        cloudSecLayer_inp_->setObjectName(QStringLiteral("cloudSecLayer_inp_"));
        cloudSecLayer_inp_->setEnabled(false);
        sizePolicy.setHeightForWidth(cloudSecLayer_inp_->sizePolicy().hasHeightForWidth());
        cloudSecLayer_inp_->setSizePolicy(sizePolicy);
        cloudSecLayer_inp_->setMinimumSize(QSize(100, 25));
        cloudSecLayer_inp_->setMaximumSize(QSize(100, 25));
        cloudSecLayer_inp_->setCursor(QCursor(Qt::UpArrowCursor));

        horizontalLayout_19->addWidget(cloudSecLayer_inp_);


        verticalLayout_33->addLayout(horizontalLayout_19);


        verticalLayout_34->addWidget(mCloudGrB);

        mPrecipationGrB = new QGroupBox(centralWidget);
        mPrecipationGrB->setObjectName(QStringLiteral("mPrecipationGrB"));
        sizePolicy1.setHeightForWidth(mPrecipationGrB->sizePolicy().hasHeightForWidth());
        mPrecipationGrB->setSizePolicy(sizePolicy1);
        mPrecipationGrB->setMinimumSize(QSize(620, 161));
        mPrecipationGrB->setMaximumSize(QSize(10000, 1000));
        mPrecipationGrB->setBaseSize(QSize(620, 161));
        mPrecipationGrB->setContextMenuPolicy(Qt::NoContextMenu);
        horizontalLayout_11 = new QHBoxLayout(mPrecipationGrB);
        horizontalLayout_11->setSpacing(5);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(5, 5, 5, 5);
        verticalLayout_26 = new QVBoxLayout();
        verticalLayout_26->setSpacing(6);
        verticalLayout_26->setObjectName(QStringLiteral("verticalLayout_26"));
        label_32 = new QLabel(mPrecipationGrB);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setMinimumSize(QSize(280, 25));
        label_32->setMaximumSize(QSize(280, 25));
        label_32->setBaseSize(QSize(275, 25));

        verticalLayout_26->addWidget(label_32);

        label_33 = new QLabel(mPrecipationGrB);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setMinimumSize(QSize(280, 25));
        label_33->setMaximumSize(QSize(280, 25));

        verticalLayout_26->addWidget(label_33);

        label_34 = new QLabel(mPrecipationGrB);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setMinimumSize(QSize(280, 25));
        label_34->setMaximumSize(QSize(280, 25));

        verticalLayout_26->addWidget(label_34);

        label_35 = new QLabel(mPrecipationGrB);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setMinimumSize(QSize(280, 25));
        label_35->setMaximumSize(QSize(280, 25));

        verticalLayout_26->addWidget(label_35);


        horizontalLayout_11->addLayout(verticalLayout_26);

        verticalLayout_27 = new QVBoxLayout();
        verticalLayout_27->setSpacing(6);
        verticalLayout_27->setObjectName(QStringLiteral("verticalLayout_27"));
        localVisScroll_ = new QScrollBar(mPrecipationGrB);
        localVisScroll_->setObjectName(QStringLiteral("localVisScroll_"));
        sizePolicy2.setHeightForWidth(localVisScroll_->sizePolicy().hasHeightForWidth());
        localVisScroll_->setSizePolicy(sizePolicy2);
        localVisScroll_->setMinimumSize(QSize(188, 25));
        localVisScroll_->setBaseSize(QSize(271, 0));
        localVisScroll_->setCursor(QCursor(Qt::UpArrowCursor));
        localVisScroll_->setMinimum(0);
        localVisScroll_->setSingleStep(1);
        localVisScroll_->setOrientation(Qt::Horizontal);

        verticalLayout_27->addWidget(localVisScroll_);

        rainScroll_ = new QScrollBar(mPrecipationGrB);
        rainScroll_->setObjectName(QStringLiteral("rainScroll_"));
        sizePolicy2.setHeightForWidth(rainScroll_->sizePolicy().hasHeightForWidth());
        rainScroll_->setSizePolicy(sizePolicy2);
        rainScroll_->setMinimumSize(QSize(188, 25));
        rainScroll_->setCursor(QCursor(Qt::UpArrowCursor));
        rainScroll_->setOrientation(Qt::Horizontal);

        verticalLayout_27->addWidget(rainScroll_);

        snowScroll_ = new QScrollBar(mPrecipationGrB);
        snowScroll_->setObjectName(QStringLiteral("snowScroll_"));
        sizePolicy2.setHeightForWidth(snowScroll_->sizePolicy().hasHeightForWidth());
        snowScroll_->setSizePolicy(sizePolicy2);
        snowScroll_->setMinimumSize(QSize(188, 25));
        snowScroll_->setMaximumSize(QSize(16777215, 25));
        snowScroll_->setCursor(QCursor(Qt::UpArrowCursor));
        snowScroll_->setOrientation(Qt::Horizontal);

        verticalLayout_27->addWidget(snowScroll_);

        mistScroll_ = new QScrollBar(mPrecipationGrB);
        mistScroll_->setObjectName(QStringLiteral("mistScroll_"));
        sizePolicy2.setHeightForWidth(mistScroll_->sizePolicy().hasHeightForWidth());
        mistScroll_->setSizePolicy(sizePolicy2);
        mistScroll_->setMinimumSize(QSize(188, 25));
        mistScroll_->setCursor(QCursor(Qt::UpArrowCursor));
        mistScroll_->setOrientation(Qt::Horizontal);

        verticalLayout_27->addWidget(mistScroll_);


        horizontalLayout_11->addLayout(verticalLayout_27);

        verticalLayout_28 = new QVBoxLayout();
        verticalLayout_28->setSpacing(6);
        verticalLayout_28->setObjectName(QStringLiteral("verticalLayout_28"));
        verticalLayout_28->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_28->setContentsMargins(-1, 0, -1, 0);
        localVis_inp_ = new QLineEdit(mPrecipationGrB);
        localVis_inp_->setObjectName(QStringLiteral("localVis_inp_"));
        localVis_inp_->setMinimumSize(QSize(100, 25));
        localVis_inp_->setMaximumSize(QSize(100, 25));
        localVis_inp_->setBaseSize(QSize(100, 25));
        localVis_inp_->setAutoFillBackground(false);

        verticalLayout_28->addWidget(localVis_inp_);

        rain_inp_ = new QLineEdit(mPrecipationGrB);
        rain_inp_->setObjectName(QStringLiteral("rain_inp_"));
        rain_inp_->setMinimumSize(QSize(100, 25));
        rain_inp_->setMaximumSize(QSize(100, 25));

        verticalLayout_28->addWidget(rain_inp_);

        snow_inp_ = new QLineEdit(mPrecipationGrB);
        snow_inp_->setObjectName(QStringLiteral("snow_inp_"));
        snow_inp_->setMinimumSize(QSize(100, 0));
        snow_inp_->setMaximumSize(QSize(100, 25));

        verticalLayout_28->addWidget(snow_inp_);

        hmist_inp_ = new QLineEdit(mPrecipationGrB);
        hmist_inp_->setObjectName(QStringLiteral("hmist_inp_"));
        hmist_inp_->setMinimumSize(QSize(100, 25));
        hmist_inp_->setMaximumSize(QSize(100, 25));

        verticalLayout_28->addWidget(hmist_inp_);


        horizontalLayout_11->addLayout(verticalLayout_28);


        verticalLayout_34->addWidget(mPrecipationGrB);

        mWindGrB = new QGroupBox(centralWidget);
        mWindGrB->setObjectName(QStringLiteral("mWindGrB"));
        mWindGrB->setMinimumSize(QSize(620, 92));
        mWindGrB->setMaximumSize(QSize(620, 110));
        mWindGrB->setBaseSize(QSize(620, 0));
        horizontalLayout_12 = new QHBoxLayout(mWindGrB);
        horizontalLayout_12->setSpacing(5);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(5, 5, 5, 5);
        verticalLayout_30 = new QVBoxLayout();
        verticalLayout_30->setSpacing(5);
        verticalLayout_30->setObjectName(QStringLiteral("verticalLayout_30"));
        label_39 = new QLabel(mWindGrB);
        label_39->setObjectName(QStringLiteral("label_39"));
        label_39->setMinimumSize(QSize(280, 25));
        label_39->setMaximumSize(QSize(280, 25));

        verticalLayout_30->addWidget(label_39);

        label_40 = new QLabel(mWindGrB);
        label_40->setObjectName(QStringLiteral("label_40"));
        label_40->setMinimumSize(QSize(280, 25));
        label_40->setMaximumSize(QSize(280, 25));
        label_40->setBaseSize(QSize(280, 25));

        verticalLayout_30->addWidget(label_40);


        horizontalLayout_12->addLayout(verticalLayout_30);

        verticalLayout_31 = new QVBoxLayout();
        verticalLayout_31->setSpacing(6);
        verticalLayout_31->setObjectName(QStringLiteral("verticalLayout_31"));
        windSpeedScroll_ = new QScrollBar(mWindGrB);
        windSpeedScroll_->setObjectName(QStringLiteral("windSpeedScroll_"));
        sizePolicy2.setHeightForWidth(windSpeedScroll_->sizePolicy().hasHeightForWidth());
        windSpeedScroll_->setSizePolicy(sizePolicy2);
        windSpeedScroll_->setMinimumSize(QSize(188, 23));
        windSpeedScroll_->setCursor(QCursor(Qt::UpArrowCursor));
        windSpeedScroll_->setOrientation(Qt::Horizontal);

        verticalLayout_31->addWidget(windSpeedScroll_);

        windPsiScroll_ = new QScrollBar(mWindGrB);
        windPsiScroll_->setObjectName(QStringLiteral("windPsiScroll_"));
        sizePolicy2.setHeightForWidth(windPsiScroll_->sizePolicy().hasHeightForWidth());
        windPsiScroll_->setSizePolicy(sizePolicy2);
        windPsiScroll_->setMinimumSize(QSize(188, 23));
        windPsiScroll_->setCursor(QCursor(Qt::UpArrowCursor));
        windPsiScroll_->setOrientation(Qt::Horizontal);

        verticalLayout_31->addWidget(windPsiScroll_);


        horizontalLayout_12->addLayout(verticalLayout_31);

        verticalLayout_32 = new QVBoxLayout();
        verticalLayout_32->setSpacing(9);
        verticalLayout_32->setObjectName(QStringLiteral("verticalLayout_32"));
        verticalLayout_32->setSizeConstraint(QLayout::SetNoConstraint);
        windSpeed_inp_ = new QLineEdit(mWindGrB);
        windSpeed_inp_->setObjectName(QStringLiteral("windSpeed_inp_"));
        windSpeed_inp_->setMinimumSize(QSize(100, 25));
        windSpeed_inp_->setMaximumSize(QSize(100, 25));

        verticalLayout_32->addWidget(windSpeed_inp_);

        windSpeedPsi_inp_ = new QLineEdit(mWindGrB);
        windSpeedPsi_inp_->setObjectName(QStringLiteral("windSpeedPsi_inp_"));
        windSpeedPsi_inp_->setMinimumSize(QSize(100, 25));
        windSpeedPsi_inp_->setMaximumSize(QSize(100, 25));

        verticalLayout_32->addWidget(windSpeedPsi_inp_);


        horizontalLayout_12->addLayout(verticalLayout_32);


        verticalLayout_34->addWidget(mWindGrB);

        mSightGrB = new QGroupBox(centralWidget);
        mSightGrB->setObjectName(QStringLiteral("mSightGrB"));
        mSightGrB->setMinimumSize(QSize(620, 92));
        mSightGrB->setMaximumSize(QSize(620, 116));
        mSightGrB->setBaseSize(QSize(620, 0));
        horizontalLayout_14 = new QHBoxLayout(mSightGrB);
        horizontalLayout_14->setSpacing(5);
        horizontalLayout_14->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(5, 5, 5, 5);
        verticalLayout_36 = new QVBoxLayout();
        verticalLayout_36->setSpacing(6);
        verticalLayout_36->setObjectName(QStringLiteral("verticalLayout_36"));
        label_47 = new QLabel(mSightGrB);
        label_47->setObjectName(QStringLiteral("label_47"));
        label_47->setMinimumSize(QSize(280, 25));
        label_47->setMaximumSize(QSize(275, 25));

        verticalLayout_36->addWidget(label_47);

        label_48 = new QLabel(mSightGrB);
        label_48->setObjectName(QStringLiteral("label_48"));
        label_48->setMinimumSize(QSize(280, 25));
        label_48->setMaximumSize(QSize(270, 25));

        verticalLayout_36->addWidget(label_48);


        horizontalLayout_14->addLayout(verticalLayout_36);

        verticalLayout_37 = new QVBoxLayout();
        verticalLayout_37->setSpacing(6);
        verticalLayout_37->setObjectName(QStringLiteral("verticalLayout_37"));
        visScroll_ = new QScrollBar(mSightGrB);
        visScroll_->setObjectName(QStringLiteral("visScroll_"));
        sizePolicy2.setHeightForWidth(visScroll_->sizePolicy().hasHeightForWidth());
        visScroll_->setSizePolicy(sizePolicy2);
        visScroll_->setMinimumSize(QSize(188, 23));
        visScroll_->setCursor(QCursor(Qt::UpArrowCursor));
        visScroll_->setOrientation(Qt::Horizontal);

        verticalLayout_37->addWidget(visScroll_);

        starsBrightScroll_ = new QScrollBar(mSightGrB);
        starsBrightScroll_->setObjectName(QStringLiteral("starsBrightScroll_"));
        sizePolicy2.setHeightForWidth(starsBrightScroll_->sizePolicy().hasHeightForWidth());
        starsBrightScroll_->setSizePolicy(sizePolicy2);
        starsBrightScroll_->setMinimumSize(QSize(188, 23));
        starsBrightScroll_->setCursor(QCursor(Qt::UpArrowCursor));
        starsBrightScroll_->setOrientation(Qt::Horizontal);

        verticalLayout_37->addWidget(starsBrightScroll_);


        horizontalLayout_14->addLayout(verticalLayout_37);

        verticalLayout_38 = new QVBoxLayout();
        verticalLayout_38->setSpacing(5);
        verticalLayout_38->setObjectName(QStringLiteral("verticalLayout_38"));
        visibility_inp_ = new QLineEdit(mSightGrB);
        visibility_inp_->setObjectName(QStringLiteral("visibility_inp_"));
        visibility_inp_->setMinimumSize(QSize(100, 25));
        visibility_inp_->setMaximumSize(QSize(100, 25));
        visibility_inp_->setBaseSize(QSize(0, 3));

        verticalLayout_38->addWidget(visibility_inp_);

        starsBright_inp_ = new QLineEdit(mSightGrB);
        starsBright_inp_->setObjectName(QStringLiteral("starsBright_inp_"));
        starsBright_inp_->setMinimumSize(QSize(100, 25));
        starsBright_inp_->setMaximumSize(QSize(100, 25));

        verticalLayout_38->addWidget(starsBright_inp_);


        horizontalLayout_14->addLayout(verticalLayout_38);


        verticalLayout_34->addWidget(mSightGrB);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalSpacer_6 = new QSpacerItem(350, 25, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_6);

        ok_pushb_ = new QPushButton(centralWidget);
        ok_pushb_->setObjectName(QStringLiteral("ok_pushb_"));

        horizontalLayout_13->addWidget(ok_pushb_);

        CancelPB_ = new QPushButton(centralWidget);
        CancelPB_->setObjectName(QStringLiteral("CancelPB_"));

        horizontalLayout_13->addWidget(CancelPB_);


        verticalLayout_34->addLayout(horizontalLayout_13);

        meteoWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(meteoWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 646, 31));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        meteoWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(action);
        menu->addAction(action_2);
        menu->addSeparator();
        menu->addAction(action_4);

        retranslateUi(meteoWindow);

        mNightPushB_->setDefault(false);
        month_cmbB_->setCurrentIndex(5);


        QMetaObject::connectSlotsByName(meteoWindow);
    } // setupUi

    void retranslateUi(QMainWindow *meteoWindow)
    {
        meteoWindow->setWindowTitle(QApplication::translate("meteoWindow", "\320\224\320\260\320\275\320\275\321\213\320\265 \320\276 \320\262\321\200\320\265\320\274\320\265\320\275\320\270 \320\270 \320\277\320\276\320\263\320\276\320\264\320\265", nullptr));
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
        action_3->setText(QApplication::translate("meteoWindow", "\320\262\321\213\320\260\321\213\320\277\320\260", nullptr));
        mTimeGrB->setTitle(QApplication::translate("meteoWindow", "\320\222\321\200\320\265\320\274\321\217", nullptr));
        mWinterPushB_->setText(QApplication::translate("meteoWindow", "\320\227\320\270\320\274\320\260", nullptr));
        mSpringPushB_->setText(QApplication::translate("meteoWindow", "\320\222\320\265\321\201\320\275\320\260", nullptr));
        mSummerPushB_->setText(QApplication::translate("meteoWindow", "\320\233\320\265\321\202\320\276", nullptr));
        mAutumnPushB_->setText(QApplication::translate("meteoWindow", "\320\236\321\201\320\265\320\275\321\214", nullptr));
        mDayPushB_->setText(QApplication::translate("meteoWindow", "\320\224\320\265\320\275\321\214", nullptr));
        mNightPushB_->setText(QApplication::translate("meteoWindow", "\320\235\320\276\321\207\321\214", nullptr));
        label_36->setText(QApplication::translate("meteoWindow", "\320\247\320\270\321\201\320\273\320\276", nullptr));
        label_37->setText(QApplication::translate("meteoWindow", "\320\234\320\265\321\201\321\217\321\206", nullptr));
        month_cmbB_->setItemText(0, QApplication::translate("meteoWindow", "\320\264\320\265\320\272\320\260\320\261\321\200\321\214", nullptr));
        month_cmbB_->setItemText(1, QApplication::translate("meteoWindow", "\321\217\320\275\320\262\320\260\321\200\321\214", nullptr));
        month_cmbB_->setItemText(2, QApplication::translate("meteoWindow", "\321\204\320\265\320\262\321\200\320\260\320\273\321\214", nullptr));
        month_cmbB_->setItemText(3, QApplication::translate("meteoWindow", "\320\274\320\260\321\200\321\202", nullptr));
        month_cmbB_->setItemText(4, QApplication::translate("meteoWindow", "\320\260\320\277\321\200\320\265\320\273\321\214", nullptr));
        month_cmbB_->setItemText(5, QApplication::translate("meteoWindow", "\320\274\320\260\320\271", nullptr));
        month_cmbB_->setItemText(6, QApplication::translate("meteoWindow", "\320\270\321\216\320\275\321\214", nullptr));
        month_cmbB_->setItemText(7, QApplication::translate("meteoWindow", "\320\270\321\216\320\273\321\214", nullptr));
        month_cmbB_->setItemText(8, QApplication::translate("meteoWindow", "\320\260\320\262\320\263\321\203\321\201\321\202", nullptr));
        month_cmbB_->setItemText(9, QApplication::translate("meteoWindow", "\321\201\320\265\320\275\321\202\321\217\320\261\321\200\321\214", nullptr));
        month_cmbB_->setItemText(10, QApplication::translate("meteoWindow", "\320\276\320\272\321\202\321\217\320\261\321\200\321\214", nullptr));
        month_cmbB_->setItemText(11, QApplication::translate("meteoWindow", "\320\275\320\276\321\217\320\261\321\200\321\214", nullptr));

        label_38->setText(QApplication::translate("meteoWindow", "\320\222\321\200\320\265\320\274\321\217", nullptr));
        mCloudGrB->setTitle(QApplication::translate("meteoWindow", "\320\236\320\261\320\273\320\260\321\207\320\275\320\276\321\201\321\202\321\214", nullptr));
        label_41->setText(QApplication::translate("meteoWindow", "\320\222\321\213\321\201\320\276\321\202\320\260 \320\275\320\270\320\266\320\275\320\265\320\271 \320\272\321\200\320\276\320\274\320\272\320\270 \320\276\320\261\320\273\320\260\320\272\320\276\320\262, [\320\274]", nullptr));
        cloudBase_inp_->setText(QApplication::translate("meteoWindow", "1", nullptr));
        label_42->setText(QApplication::translate("meteoWindow", "\320\242\320\276\320\273\321\211\320\270\320\275\320\260 \321\201\320\273\320\276\321\217 \320\276\320\261\320\273\320\260\320\272\320\276\320\262, [\320\274]", nullptr));
        cloudThick_inp_->setText(QApplication::translate("meteoWindow", "2", nullptr));
        label_43->setText(QApplication::translate("meteoWindow", "\320\221\320\260\320\273\321\214\320\275\320\276\321\201\321\202\321\214 \320\276\320\261\320\273\320\260\320\272\320\276\320\262,1...10 [\320\265\320\264]", nullptr));
        cloudSize_inp_->setText(QApplication::translate("meteoWindow", "3", nullptr));
        label_44->setText(QApplication::translate("meteoWindow", "\320\235\320\260\320\273\320\270\321\207\320\270\320\265 \320\262\321\202\320\276\321\200\320\276\320\263\320\276 \321\201\320\273\320\276\321\217 \320\276\320\261\320\273\320\260\320\272\320\276\320\262", nullptr));
        cloudsSecLay_cmbB_->setItemText(0, QApplication::translate("meteoWindow", "\320\275\320\265\321\202", nullptr));
        cloudsSecLay_cmbB_->setItemText(1, QApplication::translate("meteoWindow", "\320\264\320\260", nullptr));

        label_45->setText(QApplication::translate("meteoWindow", "\320\242\320\270\320\277 \320\276\320\261\320\273\320\260\320\272\320\276\320\262 (\320\276\320\261\321\213\321\207\320\275\321\213\320\265, \320\263\321\200\320\276\320\267\320\276\320\262\321\213\320\265)", nullptr));
        cloudsType_cmbB_->setItemText(0, QApplication::translate("meteoWindow", "\320\276\320\261\321\213\321\207\320\275\321\213\320\265", nullptr));
        cloudsType_cmbB_->setItemText(1, QApplication::translate("meteoWindow", "\320\263\321\200\320\276\320\267\320\276\320\262\321\213\320\265", nullptr));

        label_46->setText(QApplication::translate("meteoWindow", "\320\222\321\213\321\201\320\276\321\202\320\260 \320\262\321\202\320\276\321\200\320\276\320\263\320\276 \321\201\320\273\320\276\321\217 \320\276\320\261\320\273\320\260\320\272\320\276\320\262, [\320\274]", nullptr));
        cloudSecLayer_inp_->setText(QApplication::translate("meteoWindow", "0", nullptr));
        mPrecipationGrB->setTitle(QApplication::translate("meteoWindow", "\320\236\321\201\320\260\320\264\320\272\320\270", nullptr));
        label_32->setText(QApplication::translate("meteoWindow", "\320\233\320\276\320\272\320\260\320\273\321\214\320\275\320\260\321\217 \320\264\320\260\320\273\321\214\320\275\320\276\321\201\321\202\321\214 \320\262\320\270\320\264\320\270\320\274\320\276\321\201\321\202\320\270, [\320\274]", nullptr));
        label_33->setText(QApplication::translate("meteoWindow", "\320\230\320\275\321\202\320\265\320\275\321\201\320\270\320\262\320\275\320\276\321\201\321\202\321\214 \320\264\320\276\320\266\320\264\321\217, %", nullptr));
        label_34->setText(QApplication::translate("meteoWindow", "\320\230\320\275\321\202\320\265\320\275\321\201\320\270\320\262\320\275\320\276\321\201\321\202\321\214 \321\201\320\275\320\265\320\263\320\260, %", nullptr));
        label_35->setText(QApplication::translate("meteoWindow", "\320\222\321\213\321\201\320\276\321\202\320\260 \320\264\321\213\320\274\320\272\320\270 \321\202\321\203\320\274\320\260\320\275\320\260, [\320\274]", nullptr));
        localVis_inp_->setText(QApplication::translate("meteoWindow", "4", nullptr));
        rain_inp_->setText(QApplication::translate("meteoWindow", "5", nullptr));
        snow_inp_->setText(QApplication::translate("meteoWindow", "6", nullptr));
        hmist_inp_->setText(QApplication::translate("meteoWindow", "7", nullptr));
        mWindGrB->setTitle(QApplication::translate("meteoWindow", "\320\222\320\265\321\202\320\265\321\200", nullptr));
        label_39->setText(QApplication::translate("meteoWindow", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214 \320\262\320\265\321\202\321\200\320\260, [\320\274/\321\201]", nullptr));
        label_40->setText(QApplication::translate("meteoWindow", "\320\235\320\260\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\262\320\265\321\202\321\200\320\260, 0...360 [\320\263\321\200\320\260\320\264]", nullptr));
        windSpeed_inp_->setText(QApplication::translate("meteoWindow", "8", nullptr));
        windSpeedPsi_inp_->setText(QApplication::translate("meteoWindow", "9", nullptr));
        mSightGrB->setTitle(QApplication::translate("meteoWindow", "\320\222\320\270\320\264\320\270\320\274\320\276\321\201\321\202\321\214", nullptr));
        label_47->setText(QApplication::translate("meteoWindow", "\320\223\320\273\320\276\320\261\320\260\320\273\321\214\320\275\320\260\321\217 \320\264\320\260\320\273\321\214\320\275\320\276\321\201\321\202\321\214 \320\262\320\270\320\264\320\270\320\274\320\276\321\201\321\202\320\270, [\320\274]", nullptr));
        label_48->setText(QApplication::translate("meteoWindow", "\320\257\321\200\320\272\320\276\321\201\321\202\321\214 \320\267\320\262\320\265\320\267\320\264, %", nullptr));
        visibility_inp_->setText(QApplication::translate("meteoWindow", "10", nullptr));
        starsBright_inp_->setText(QApplication::translate("meteoWindow", "11", nullptr));
        ok_pushb_->setText(QApplication::translate("meteoWindow", "OK", nullptr));
        CancelPB_->setText(QApplication::translate("meteoWindow", "Cancel", nullptr));
        menu->setTitle(QApplication::translate("meteoWindow", "\320\244\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class meteoWindow: public Ui_meteoWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_METEOFORM_H
