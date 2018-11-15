/********************************************************************************
** Form generated from reading UI file 'airportsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AIRPORTSDIALOG_H
#define UI_AIRPORTSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AirportsDialog
{
public:
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *departureCity;
    QLineEdit *departure_airport_code;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QComboBox *depPolosa;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QScrollBar *depBokLightscroll;
    QLineEdit *takeoff_runway_border_lights;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QScrollBar *depRelLightsScroll;
    QLineEdit *departure_airport_lights_taxiing;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QScrollBar *depStoyankScroll;
    QLineEdit *departure_airport_lights_illumination;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_6;
    QScrollBar *depOtherScroll;
    QLineEdit *departure_airport_other_lights;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_9;
    QComboBox *arrivalCity;
    QLineEdit *arrival_airport_code;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_12;
    QSpacerItem *horizontalSpacer_3;
    QComboBox *arrPolosa;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_13;
    QScrollBar *arrYarkBok;
    QLineEdit *landing_runway_border_lights;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_8;
    QScrollBar *arrRulez;
    QLineEdit *arrival_airport_lights_taxiing;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_10;
    QScrollBar *arrPodsvet;
    QLineEdit *arrival_airport_lights_illumination;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_11;
    QScrollBar *arrOther;
    QLineEdit *arrival_airport_other_lights;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QPushButton *ok_pb;
    QPushButton *cancel_pb;

    void setupUi(QDialog *AirportsDialog)
    {
        if (AirportsDialog->objectName().isEmpty())
            AirportsDialog->setObjectName(QStringLiteral("AirportsDialog"));
        AirportsDialog->setWindowModality(Qt::ApplicationModal);
        AirportsDialog->resize(718, 625);
        AirportsDialog->setContextMenuPolicy(Qt::NoContextMenu);
        AirportsDialog->setAutoFillBackground(true);
        verticalLayout_5 = new QVBoxLayout(AirportsDialog);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        groupBox = new QGroupBox(AirportsDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(324, 0));
        label->setMaximumSize(QSize(324, 16777215));

        horizontalLayout->addWidget(label);

        departureCity = new QComboBox(groupBox);
        departureCity->addItem(QString());
        departureCity->addItem(QString());
        departureCity->addItem(QString());
        departureCity->addItem(QString());
        departureCity->addItem(QString());
        departureCity->addItem(QString());
        departureCity->addItem(QString());
        departureCity->addItem(QString());
        departureCity->addItem(QString());
        departureCity->addItem(QString());
        departureCity->addItem(QString());
        departureCity->addItem(QString());
        departureCity->addItem(QString());
        departureCity->addItem(QString());
        departureCity->addItem(QString());
        departureCity->addItem(QString());
        departureCity->addItem(QString());
        departureCity->addItem(QString());
        departureCity->setObjectName(QStringLiteral("departureCity"));
        sizePolicy.setHeightForWidth(departureCity->sizePolicy().hasHeightForWidth());
        departureCity->setSizePolicy(sizePolicy);
        departureCity->setMinimumSize(QSize(250, 0));
        departureCity->setMaximumSize(QSize(250, 16777215));
        departureCity->setCursor(QCursor(Qt::UpArrowCursor));
        departureCity->setFocusPolicy(Qt::WheelFocus);
        departureCity->setContextMenuPolicy(Qt::NoContextMenu);
        departureCity->setAutoFillBackground(false);
        departureCity->setEditable(false);
        departureCity->setCurrentText(QString::fromUtf8("\320\250\320\265\321\200\320\265\320\274\320\265\321\202\321\214\320\265\320\262\320\276 (SVO/UUEE)"));
        departureCity->setInsertPolicy(QComboBox::NoInsert);
        departureCity->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);
        departureCity->setFrame(true);

        horizontalLayout->addWidget(departureCity);

        departure_airport_code = new QLineEdit(groupBox);
        departure_airport_code->setObjectName(QStringLiteral("departure_airport_code"));
        departure_airport_code->setEnabled(true);
        departure_airport_code->setMinimumSize(QSize(70, 25));
        departure_airport_code->setMaximumSize(QSize(70, 25));
        departure_airport_code->setReadOnly(true);

        horizontalLayout->addWidget(departure_airport_code);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(324, 0));
        label_2->setMaximumSize(QSize(324, 16777215));

        horizontalLayout_3->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(250, 25, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        depPolosa = new QComboBox(groupBox);
        depPolosa->addItem(QString());
        depPolosa->addItem(QString());
        depPolosa->addItem(QString());
        depPolosa->addItem(QString());
        depPolosa->setObjectName(QStringLiteral("depPolosa"));
        depPolosa->setMinimumSize(QSize(70, 25));
        depPolosa->setMaximumSize(QSize(70, 25));

        horizontalLayout_3->addWidget(depPolosa);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setMinimumSize(QSize(324, 0));
        label_3->setMaximumSize(QSize(324, 16777215));

        horizontalLayout_4->addWidget(label_3);

        depBokLightscroll = new QScrollBar(groupBox);
        depBokLightscroll->setObjectName(QStringLiteral("depBokLightscroll"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(depBokLightscroll->sizePolicy().hasHeightForWidth());
        depBokLightscroll->setSizePolicy(sizePolicy2);
        depBokLightscroll->setMinimumSize(QSize(250, 25));
        depBokLightscroll->setCursor(QCursor(Qt::UpArrowCursor));
        depBokLightscroll->setValue(99);
        depBokLightscroll->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(depBokLightscroll);

        takeoff_runway_border_lights = new QLineEdit(groupBox);
        takeoff_runway_border_lights->setObjectName(QStringLiteral("takeoff_runway_border_lights"));
        takeoff_runway_border_lights->setMinimumSize(QSize(70, 25));
        takeoff_runway_border_lights->setMaximumSize(QSize(70, 25));
        takeoff_runway_border_lights->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(takeoff_runway_border_lights);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(324, 0));
        label_4->setMaximumSize(QSize(324, 16777215));

        horizontalLayout_5->addWidget(label_4);

        depRelLightsScroll = new QScrollBar(groupBox);
        depRelLightsScroll->setObjectName(QStringLiteral("depRelLightsScroll"));
        sizePolicy2.setHeightForWidth(depRelLightsScroll->sizePolicy().hasHeightForWidth());
        depRelLightsScroll->setSizePolicy(sizePolicy2);
        depRelLightsScroll->setMinimumSize(QSize(250, 25));
        depRelLightsScroll->setCursor(QCursor(Qt::UpArrowCursor));
        depRelLightsScroll->setValue(99);
        depRelLightsScroll->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(depRelLightsScroll);

        departure_airport_lights_taxiing = new QLineEdit(groupBox);
        departure_airport_lights_taxiing->setObjectName(QStringLiteral("departure_airport_lights_taxiing"));
        departure_airport_lights_taxiing->setMinimumSize(QSize(70, 0));
        departure_airport_lights_taxiing->setMaximumSize(QSize(70, 25));
        departure_airport_lights_taxiing->setMaxLength(70);

        horizontalLayout_5->addWidget(departure_airport_lights_taxiing);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(324, 0));
        label_5->setMaximumSize(QSize(324, 16777215));

        horizontalLayout_7->addWidget(label_5);

        depStoyankScroll = new QScrollBar(groupBox);
        depStoyankScroll->setObjectName(QStringLiteral("depStoyankScroll"));
        sizePolicy2.setHeightForWidth(depStoyankScroll->sizePolicy().hasHeightForWidth());
        depStoyankScroll->setSizePolicy(sizePolicy2);
        depStoyankScroll->setMinimumSize(QSize(250, 25));
        depStoyankScroll->setCursor(QCursor(Qt::UpArrowCursor));
        depStoyankScroll->setValue(99);
        depStoyankScroll->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(depStoyankScroll);

        departure_airport_lights_illumination = new QLineEdit(groupBox);
        departure_airport_lights_illumination->setObjectName(QStringLiteral("departure_airport_lights_illumination"));
        departure_airport_lights_illumination->setMinimumSize(QSize(70, 25));
        departure_airport_lights_illumination->setMaximumSize(QSize(70, 25));

        horizontalLayout_7->addWidget(departure_airport_lights_illumination);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(324, 0));
        label_6->setMaximumSize(QSize(324, 16777215));

        horizontalLayout_8->addWidget(label_6);

        depOtherScroll = new QScrollBar(groupBox);
        depOtherScroll->setObjectName(QStringLiteral("depOtherScroll"));
        sizePolicy2.setHeightForWidth(depOtherScroll->sizePolicy().hasHeightForWidth());
        depOtherScroll->setSizePolicy(sizePolicy2);
        depOtherScroll->setMinimumSize(QSize(250, 25));
        depOtherScroll->setCursor(QCursor(Qt::UpArrowCursor));
        depOtherScroll->setMaximum(100);
        depOtherScroll->setPageStep(1);
        depOtherScroll->setValue(99);
        depOtherScroll->setOrientation(Qt::Horizontal);

        horizontalLayout_8->addWidget(depOtherScroll);

        departure_airport_other_lights = new QLineEdit(groupBox);
        departure_airport_other_lights->setObjectName(QStringLiteral("departure_airport_other_lights"));
        departure_airport_other_lights->setMinimumSize(QSize(70, 25));
        departure_airport_other_lights->setMaximumSize(QSize(70, 25));
        departure_airport_other_lights->setClearButtonEnabled(false);

        horizontalLayout_8->addWidget(departure_airport_other_lights);


        verticalLayout->addLayout(horizontalLayout_8);


        verticalLayout_5->addWidget(groupBox);

        groupBox_2 = new QGroupBox(AirportsDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMinimumSize(QSize(324, 25));
        label_9->setMaximumSize(QSize(324, 25));

        horizontalLayout_2->addWidget(label_9);

        arrivalCity = new QComboBox(groupBox_2);
        arrivalCity->addItem(QString());
        arrivalCity->addItem(QString());
        arrivalCity->addItem(QString());
        arrivalCity->addItem(QString());
        arrivalCity->addItem(QString());
        arrivalCity->addItem(QString());
        arrivalCity->addItem(QString());
        arrivalCity->addItem(QString());
        arrivalCity->addItem(QString());
        arrivalCity->addItem(QString());
        arrivalCity->addItem(QString());
        arrivalCity->addItem(QString());
        arrivalCity->addItem(QString());
        arrivalCity->addItem(QString());
        arrivalCity->addItem(QString());
        arrivalCity->addItem(QString());
        arrivalCity->addItem(QString());
        arrivalCity->addItem(QString());
        arrivalCity->setObjectName(QStringLiteral("arrivalCity"));
        arrivalCity->setMinimumSize(QSize(250, 0));
        arrivalCity->setMaximumSize(QSize(250, 16777215));
        arrivalCity->setCursor(QCursor(Qt::UpArrowCursor));
        arrivalCity->setFocusPolicy(Qt::WheelFocus);
        arrivalCity->setContextMenuPolicy(Qt::DefaultContextMenu);
        arrivalCity->setAutoFillBackground(false);
        arrivalCity->setEditable(false);
        arrivalCity->setCurrentText(QString::fromUtf8("\320\232\320\276\320\274\321\201\320\276\320\274\320\276\320\273\321\214\321\201\320\272 (KXK/UHKK)"));
        arrivalCity->setInsertPolicy(QComboBox::NoInsert);
        arrivalCity->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);
        arrivalCity->setFrame(true);

        horizontalLayout_2->addWidget(arrivalCity);

        arrival_airport_code = new QLineEdit(groupBox_2);
        arrival_airport_code->setObjectName(QStringLiteral("arrival_airport_code"));
        arrival_airport_code->setEnabled(true);
        arrival_airport_code->setMinimumSize(QSize(70, 25));
        arrival_airport_code->setMaximumSize(QSize(70, 25));
        arrival_airport_code->setReadOnly(true);

        horizontalLayout_2->addWidget(arrival_airport_code);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setMinimumSize(QSize(324, 25));
        label_12->setMaximumSize(QSize(324, 25));

        horizontalLayout_9->addWidget(label_12);

        horizontalSpacer_3 = new QSpacerItem(250, 25, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);

        arrPolosa = new QComboBox(groupBox_2);
        arrPolosa->addItem(QString());
        arrPolosa->addItem(QString());
        arrPolosa->setObjectName(QStringLiteral("arrPolosa"));
        arrPolosa->setMinimumSize(QSize(70, 25));
        arrPolosa->setMaximumSize(QSize(70, 25));

        horizontalLayout_9->addWidget(arrPolosa);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setMinimumSize(QSize(324, 25));
        label_13->setMaximumSize(QSize(324, 25));

        horizontalLayout_10->addWidget(label_13);

        arrYarkBok = new QScrollBar(groupBox_2);
        arrYarkBok->setObjectName(QStringLiteral("arrYarkBok"));
        sizePolicy2.setHeightForWidth(arrYarkBok->sizePolicy().hasHeightForWidth());
        arrYarkBok->setSizePolicy(sizePolicy2);
        arrYarkBok->setMinimumSize(QSize(250, 25));
        arrYarkBok->setCursor(QCursor(Qt::UpArrowCursor));
        arrYarkBok->setAutoFillBackground(false);
        arrYarkBok->setMaximum(99);
        arrYarkBok->setValue(99);
        arrYarkBok->setOrientation(Qt::Horizontal);

        horizontalLayout_10->addWidget(arrYarkBok);

        landing_runway_border_lights = new QLineEdit(groupBox_2);
        landing_runway_border_lights->setObjectName(QStringLiteral("landing_runway_border_lights"));
        landing_runway_border_lights->setMinimumSize(QSize(70, 25));
        landing_runway_border_lights->setMaximumSize(QSize(70, 25));
        landing_runway_border_lights->setCursorPosition(0);
        landing_runway_border_lights->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        landing_runway_border_lights->setCursorMoveStyle(Qt::LogicalMoveStyle);

        horizontalLayout_10->addWidget(landing_runway_border_lights);


        verticalLayout_2->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(324, 25));
        label_8->setMaximumSize(QSize(324, 25));

        horizontalLayout_11->addWidget(label_8);

        arrRulez = new QScrollBar(groupBox_2);
        arrRulez->setObjectName(QStringLiteral("arrRulez"));
        sizePolicy2.setHeightForWidth(arrRulez->sizePolicy().hasHeightForWidth());
        arrRulez->setSizePolicy(sizePolicy2);
        arrRulez->setMinimumSize(QSize(250, 25));
        arrRulez->setCursor(QCursor(Qt::UpArrowCursor));
        arrRulez->setMaximum(100);
        arrRulez->setValue(99);
        arrRulez->setOrientation(Qt::Horizontal);

        horizontalLayout_11->addWidget(arrRulez);

        arrival_airport_lights_taxiing = new QLineEdit(groupBox_2);
        arrival_airport_lights_taxiing->setObjectName(QStringLiteral("arrival_airport_lights_taxiing"));
        arrival_airport_lights_taxiing->setMinimumSize(QSize(70, 25));
        arrival_airport_lights_taxiing->setMaximumSize(QSize(70, 25));
        arrival_airport_lights_taxiing->setCursorPosition(0);

        horizontalLayout_11->addWidget(arrival_airport_lights_taxiing);


        verticalLayout_2->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMinimumSize(QSize(324, 25));
        label_10->setMaximumSize(QSize(324, 25));

        horizontalLayout_12->addWidget(label_10);

        arrPodsvet = new QScrollBar(groupBox_2);
        arrPodsvet->setObjectName(QStringLiteral("arrPodsvet"));
        sizePolicy2.setHeightForWidth(arrPodsvet->sizePolicy().hasHeightForWidth());
        arrPodsvet->setSizePolicy(sizePolicy2);
        arrPodsvet->setMinimumSize(QSize(250, 25));
        arrPodsvet->setCursor(QCursor(Qt::UpArrowCursor));
        arrPodsvet->setMaximum(100);
        arrPodsvet->setValue(99);
        arrPodsvet->setOrientation(Qt::Horizontal);

        horizontalLayout_12->addWidget(arrPodsvet);

        arrival_airport_lights_illumination = new QLineEdit(groupBox_2);
        arrival_airport_lights_illumination->setObjectName(QStringLiteral("arrival_airport_lights_illumination"));
        arrival_airport_lights_illumination->setMaximumSize(QSize(70, 25));
        arrival_airport_lights_illumination->setCursorPosition(0);

        horizontalLayout_12->addWidget(arrival_airport_lights_illumination);


        verticalLayout_2->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setMinimumSize(QSize(324, 25));
        label_11->setMaximumSize(QSize(324, 25));

        horizontalLayout_13->addWidget(label_11);

        arrOther = new QScrollBar(groupBox_2);
        arrOther->setObjectName(QStringLiteral("arrOther"));
        sizePolicy2.setHeightForWidth(arrOther->sizePolicy().hasHeightForWidth());
        arrOther->setSizePolicy(sizePolicy2);
        arrOther->setMinimumSize(QSize(250, 25));
        arrOther->setCursor(QCursor(Qt::UpArrowCursor));
        arrOther->setMaximum(100);
        arrOther->setPageStep(1);
        arrOther->setValue(100);
        arrOther->setOrientation(Qt::Horizontal);

        horizontalLayout_13->addWidget(arrOther);

        arrival_airport_other_lights = new QLineEdit(groupBox_2);
        arrival_airport_other_lights->setObjectName(QStringLiteral("arrival_airport_other_lights"));
        arrival_airport_other_lights->setMinimumSize(QSize(70, 25));
        arrival_airport_other_lights->setMaximumSize(QSize(70, 25));

        horizontalLayout_13->addWidget(arrival_airport_other_lights);


        verticalLayout_2->addLayout(horizontalLayout_13);


        verticalLayout_5->addWidget(groupBox_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer = new QSpacerItem(308, 28, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        ok_pb = new QPushButton(AirportsDialog);
        ok_pb->setObjectName(QStringLiteral("ok_pb"));

        horizontalLayout_6->addWidget(ok_pb);

        cancel_pb = new QPushButton(AirportsDialog);
        cancel_pb->setObjectName(QStringLiteral("cancel_pb"));

        horizontalLayout_6->addWidget(cancel_pb);


        verticalLayout_5->addLayout(horizontalLayout_6);


        retranslateUi(AirportsDialog);

        departureCity->setCurrentIndex(0);
        arrivalCity->setCurrentIndex(7);


        QMetaObject::connectSlotsByName(AirportsDialog);
    } // setupUi

    void retranslateUi(QDialog *AirportsDialog)
    {
        AirportsDialog->setWindowTitle(QApplication::translate("AirportsDialog", "\320\224\320\260\320\275\320\275\321\213\320\265 \320\276\320\261 \320\260\321\215\321\200\320\276\320\264\321\200\320\276\320\274\320\260\321\205", nullptr));
        groupBox->setTitle(QApplication::translate("AirportsDialog", "\320\222\320\267\320\273\320\265\321\202", nullptr));
        label->setText(QApplication::translate("AirportsDialog", "\320\220\321\215\321\200\320\276\320\264\321\200\320\276\320\274 \320\262\320\267\320\273\320\265\321\202\320\260", nullptr));
        departureCity->setItemText(0, QApplication::translate("AirportsDialog", "\320\250\320\265\321\200\320\265\320\274\320\265\321\202\321\214\320\265\320\262\320\276 (SVO/UUEE)", nullptr));
        departureCity->setItemText(1, QApplication::translate("AirportsDialog", "\320\224\320\276\320\274\320\276\320\264\320\265\320\264\320\276\320\262\320\276 (DME/UUDD)", nullptr));
        departureCity->setItemText(2, QApplication::translate("AirportsDialog", "\320\222\320\275\321\203\320\272\320\276\320\262\320\276 (VKO/UUWW)", nullptr));
        departureCity->setItemText(3, QApplication::translate("AirportsDialog", "\320\226\321\203\320\272\320\276\320\262\321\201\320\272\320\270\320\271 (ZIA/UUBW)", nullptr));
        departureCity->setItemText(4, QApplication::translate("AirportsDialog", "\320\236\321\201\321\202\320\260\321\204\321\214\320\265\320\262\320\276 (OSF/UUMO)", nullptr));
        departureCity->setItemText(5, QApplication::translate("AirportsDialog", "\320\237\321\203\320\273\320\272\320\276\320\262\320\276 (LED/ULLI)", nullptr));
        departureCity->setItemText(6, QApplication::translate("AirportsDialog", "\320\232\320\276\320\274\321\201\320\276\320\274\320\276\320\273\321\214\321\201\320\272 (KXK/UHKK)", nullptr));
        departureCity->setItemText(7, QApplication::translate("AirportsDialog", "\320\241\320\276\321\207\320\270 (AER/URSS)", nullptr));
        departureCity->setItemText(8, QApplication::translate("AirportsDialog", "\320\233\320\276\320\275\320\264\320\276\320\275 (LCY/EGLC)", nullptr));
        departureCity->setItemText(9, QApplication::translate("AirportsDialog", "\320\232\320\260\321\200\320\273\320\276\320\262\321\213 \320\222\320\260\321\200\321\213 (KLV/LKKV)", nullptr));
        departureCity->setItemText(10, QApplication::translate("AirportsDialog", "\320\242\320\270\320\262\320\260\321\202 (TIV/LYTV)", nullptr));
        departureCity->setItemText(11, QApplication::translate("AirportsDialog", "\320\221\321\200\321\216\321\201\321\201\320\265\320\273\321\214 (BRU/EBBR)", nullptr));
        departureCity->setItemText(12, QApplication::translate("AirportsDialog", "\320\222\320\265\320\275\320\265\321\206\320\270\321\217 (VCE/LIPZ)", nullptr));
        departureCity->setItemText(13, QApplication::translate("AirportsDialog", "\320\224\321\203\320\261\320\273\320\270\320\275 (DUB/EIBW)", nullptr));
        departureCity->setItemText(14, QApplication::translate("AirportsDialog", "\320\230\320\275\321\201\320\261\321\200\321\203\320\272 (INN/LOWI)", nullptr));
        departureCity->setItemText(15, QApplication::translate("AirportsDialog", "\320\232\320\265\320\261\320\273\320\260\320\262\320\270\320\272 (KEF/BIKF)", nullptr));
        departureCity->setItemText(16, QApplication::translate("AirportsDialog", "\320\242\320\276\320\273\321\203\320\272\320\260 (TLC/MMTO)", nullptr));
        departureCity->setItemText(17, QApplication::translate("AirportsDialog", "\320\245\320\265\320\273\321\214\321\201\320\270\320\275\320\272\320\270 (HEL/EFHK)", nullptr));

        departure_airport_code->setText(QApplication::translate("AirportsDialog", "UUEE", nullptr));
        departure_airport_code->setPlaceholderText(QString());
        label_2->setText(QApplication::translate("AirportsDialog", "\320\237\320\276\320\273\320\276\321\201\320\260 \320\262\320\267\320\273\320\265\321\202\320\260", nullptr));
        depPolosa->setItemText(0, QApplication::translate("AirportsDialog", "07L", nullptr));
        depPolosa->setItemText(1, QApplication::translate("AirportsDialog", "25R", nullptr));
        depPolosa->setItemText(2, QApplication::translate("AirportsDialog", "07R", nullptr));
        depPolosa->setItemText(3, QApplication::translate("AirportsDialog", "25L", nullptr));

        depPolosa->setCurrentText(QApplication::translate("AirportsDialog", "07L", nullptr));
        label_3->setText(QApplication::translate("AirportsDialog", "\320\257\321\200\320\272\320\276\321\201\321\202\321\214 \320\261\320\276\320\272\320\276\320\262\321\213\321\205 \320\276\320\263\320\275\320\265\320\271 \320\277\320\276\320\273\320\276\321\201\321\213", nullptr));
        takeoff_runway_border_lights->setText(QApplication::translate("AirportsDialog", "100", nullptr));
        label_4->setText(QApplication::translate("AirportsDialog", "\320\257\321\200\320\272\320\276\321\201\321\202\321\214 \321\200\321\203\320\273\320\265\320\266\320\275\321\213\321\205 \320\276\320\263\320\275\320\265\320\271 \320\260\321\215\321\200\320\276\320\264\321\200\320\276\320\274\320\260", nullptr));
        departure_airport_lights_taxiing->setText(QApplication::translate("AirportsDialog", "100", nullptr));
        label_5->setText(QApplication::translate("AirportsDialog", "\320\257\321\200\320\272\320\276\321\201\321\202\321\214 \320\276\320\263\320\275\320\265\320\271 \320\277\320\276\320\264\321\201\320\262\320\265\321\202\320\260 \321\201\321\202\320\276\321\217\320\275\320\276\320\272 \320\260\321\215\321\200\320\276\320\264\321\200\320\276\320\274\320\260", nullptr));
        departure_airport_lights_illumination->setText(QApplication::translate("AirportsDialog", "100", nullptr));
        label_6->setText(QApplication::translate("AirportsDialog", "\320\257\321\200\320\272\320\276\321\201\321\202\321\214 \320\276\321\201\321\202\320\260\320\273\321\214\320\275\321\213\321\205 \320\276\320\263\320\275\320\265\320\271", nullptr));
        departure_airport_other_lights->setText(QApplication::translate("AirportsDialog", "100", nullptr));
        groupBox_2->setTitle(QApplication::translate("AirportsDialog", "\320\237\320\276\321\201\320\260\320\264\320\272\320\260", nullptr));
        label_9->setText(QApplication::translate("AirportsDialog", "\320\220\321\215\321\200\320\276\320\264\321\200\320\276\320\274 \320\277\320\276\321\201\320\260\320\264\320\272\320\270", nullptr));
        arrivalCity->setItemText(0, QApplication::translate("AirportsDialog", "\320\250\320\265\321\200\320\265\320\274\320\265\321\202\321\214\320\265\320\262\320\276 (SVO/UUEE)", nullptr));
        arrivalCity->setItemText(1, QApplication::translate("AirportsDialog", "\320\224\320\276\320\274\320\276\320\264\320\265\320\264\320\276\320\262\320\276 (DME/UUDD)", nullptr));
        arrivalCity->setItemText(2, QApplication::translate("AirportsDialog", "\320\222\320\275\321\203\320\272\320\276\320\262\320\276 (VKO/UUWW)", nullptr));
        arrivalCity->setItemText(3, QApplication::translate("AirportsDialog", "\320\226\321\203\320\272\320\276\320\262\321\201\320\272\320\270\320\271 (ZIA/UUBW)", nullptr));
        arrivalCity->setItemText(4, QApplication::translate("AirportsDialog", "\320\236\321\201\321\202\320\260\321\204\321\214\320\265\320\262\320\276 (OSF/UUMO)", nullptr));
        arrivalCity->setItemText(5, QApplication::translate("AirportsDialog", "\320\237\321\203\320\273\320\272\320\276\320\262\320\276 (LED/ULLI)", nullptr));
        arrivalCity->setItemText(6, QApplication::translate("AirportsDialog", "\320\241\320\276\321\207\320\270 (AER/URSS)", nullptr));
        arrivalCity->setItemText(7, QApplication::translate("AirportsDialog", "\320\232\320\276\320\274\321\201\320\276\320\274\320\276\320\273\321\214\321\201\320\272 (KXK/UHKK)", nullptr));
        arrivalCity->setItemText(8, QApplication::translate("AirportsDialog", "\320\233\320\276\320\275\320\264\320\276\320\275 (LCY/EGLC)", nullptr));
        arrivalCity->setItemText(9, QApplication::translate("AirportsDialog", "\320\232\320\260\321\200\320\273\320\276\320\262\321\213 \320\222\320\260\321\200\321\213 (KLV/LKKV)", nullptr));
        arrivalCity->setItemText(10, QApplication::translate("AirportsDialog", "\320\242\320\270\320\262\320\260\321\202 (TIV/LYTV)", nullptr));
        arrivalCity->setItemText(11, QApplication::translate("AirportsDialog", "\320\221\321\200\321\216\321\201\321\201\320\265\320\273\321\214 (BRU/EBBR)", nullptr));
        arrivalCity->setItemText(12, QApplication::translate("AirportsDialog", "\320\222\320\265\320\275\320\265\321\206\320\270\321\217 (VCE/LIPZ)", nullptr));
        arrivalCity->setItemText(13, QApplication::translate("AirportsDialog", "\320\224\321\203\320\261\320\273\320\270\320\275 (DUB/EIBW)", nullptr));
        arrivalCity->setItemText(14, QApplication::translate("AirportsDialog", "\320\230\320\275\321\201\320\261\321\200\321\203\320\272 (INN/LOWI)", nullptr));
        arrivalCity->setItemText(15, QApplication::translate("AirportsDialog", "\320\232\320\265\320\261\320\273\320\260\320\262\320\270\320\272 (KEF/BIKF)", nullptr));
        arrivalCity->setItemText(16, QApplication::translate("AirportsDialog", "\320\242\320\276\320\273\321\203\320\272\320\260 (TLC/MMTO)", nullptr));
        arrivalCity->setItemText(17, QApplication::translate("AirportsDialog", "\320\245\320\265\320\273\321\214\321\201\320\270\320\275\320\272\320\270 (HEL/EFHK)", nullptr));

        arrival_airport_code->setText(QApplication::translate("AirportsDialog", "UHKK", nullptr));
        label_12->setText(QApplication::translate("AirportsDialog", "\320\237\320\276\320\273\320\276\321\201\320\260 \320\277\320\276\321\201\320\260\320\264\320\272\320\270", nullptr));
        arrPolosa->setItemText(0, QApplication::translate("AirportsDialog", "36", nullptr));
        arrPolosa->setItemText(1, QApplication::translate("AirportsDialog", "18", nullptr));

        arrPolosa->setCurrentText(QApplication::translate("AirportsDialog", "36", nullptr));
        label_13->setText(QApplication::translate("AirportsDialog", "\320\257\321\200\320\272\320\276\321\201\321\202\321\214 \320\261\320\276\320\272\320\276\320\262\321\213\321\205 \320\276\320\263\320\275\320\265\320\271 \320\277\320\276\320\273\320\276\321\201\321\213", nullptr));
        landing_runway_border_lights->setText(QApplication::translate("AirportsDialog", "100", nullptr));
        label_8->setText(QApplication::translate("AirportsDialog", "\320\257\321\200\320\272\320\276\321\201\321\202\321\214 \321\200\321\203\320\273\320\265\320\266\320\275\321\213\321\205 \320\276\320\263\320\275\320\265\320\271 \320\260\321\215\321\200\320\276\320\264\321\200\320\276\320\274\320\260", nullptr));
        arrival_airport_lights_taxiing->setText(QApplication::translate("AirportsDialog", "100", nullptr));
        label_10->setText(QApplication::translate("AirportsDialog", "\320\257\321\200\320\272\320\276\321\201\321\202\321\214 \320\276\320\263\320\275\320\265\320\271 \320\277\320\276\320\264\321\201\320\262\320\265\321\202\320\260 \321\201\321\202\320\276\321\217\320\275\320\276\320\272 \320\260\321\215\321\200\320\276\320\264\321\200\320\276\320\274\320\260", nullptr));
        arrival_airport_lights_illumination->setText(QApplication::translate("AirportsDialog", "100", nullptr));
        label_11->setText(QApplication::translate("AirportsDialog", "\320\257\321\200\320\272\320\276\321\201\321\202\321\214 \320\276\321\201\321\202\320\260\320\273\321\214\320\275\321\213\321\205 \320\276\320\263\320\275\320\265\320\271", nullptr));
        arrival_airport_other_lights->setText(QApplication::translate("AirportsDialog", "100", nullptr));
        ok_pb->setText(QApplication::translate("AirportsDialog", "Ok", nullptr));
        cancel_pb->setText(QApplication::translate("AirportsDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AirportsDialog: public Ui_AirportsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AIRPORTSDIALOG_H
