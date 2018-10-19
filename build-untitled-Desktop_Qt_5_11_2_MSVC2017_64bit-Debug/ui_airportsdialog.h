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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AirportsDialog
{
public:
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QComboBox *departureCity;
    QComboBox *departureCode;
    QLineEdit *departure_airport_code;
    QLineEdit *takeoff_runway_code;
    QLineEdit *takeoff_runway_border_lights;
    QLineEdit *departure_airport_lights_taxiing;
    QLineEdit *departure_airport_lights_illumination;
    QLineEdit *departure_airport_other_lights;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_9;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_8;
    QLabel *label_10;
    QLabel *label_11;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *arrivalCity;
    QComboBox *arrivalCode;
    QLineEdit *arrival_airport_code;
    QLineEdit *landing_runway_code;
    QLineEdit *landing_runway_border_lights;
    QLineEdit *arrival_airport_lights_taxiing;
    QLineEdit *arrival_airport_lights_illumination;
    QLineEdit *arrival_airport_other_lights;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *model_simulation_time;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QPushButton *ok_pb;
    QPushButton *cancel_pb;

    void setupUi(QDialog *AirportsDialog)
    {
        if (AirportsDialog->objectName().isEmpty())
            AirportsDialog->setObjectName(QStringLiteral("AirportsDialog"));
        AirportsDialog->setWindowModality(Qt::ApplicationModal);
        AirportsDialog->resize(740, 717);
        AirportsDialog->setContextMenuPolicy(Qt::NoContextMenu);
        AirportsDialog->setAutoFillBackground(true);
        verticalLayout_5 = new QVBoxLayout(AirportsDialog);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        groupBox = new QGroupBox(AirportsDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout->addWidget(label_6);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
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
        departureCity->setMinimumSize(QSize(0, 0));
        departureCity->setCursor(QCursor(Qt::UpArrowCursor));
        departureCity->setFocusPolicy(Qt::WheelFocus);
        departureCity->setContextMenuPolicy(Qt::DefaultContextMenu);
        departureCity->setAutoFillBackground(false);
        departureCity->setEditable(false);
        departureCity->setCurrentText(QStringLiteral("Moscow DME"));
        departureCity->setInsertPolicy(QComboBox::NoInsert);
        departureCity->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);
        departureCity->setFrame(true);

        horizontalLayout->addWidget(departureCity);

        departureCode = new QComboBox(groupBox);
        departureCode->setObjectName(QStringLiteral("departureCode"));
        departureCode->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        horizontalLayout->addWidget(departureCode);

        departure_airport_code = new QLineEdit(groupBox);
        departure_airport_code->setObjectName(QStringLiteral("departure_airport_code"));

        horizontalLayout->addWidget(departure_airport_code);


        verticalLayout_2->addLayout(horizontalLayout);

        takeoff_runway_code = new QLineEdit(groupBox);
        takeoff_runway_code->setObjectName(QStringLiteral("takeoff_runway_code"));

        verticalLayout_2->addWidget(takeoff_runway_code);

        takeoff_runway_border_lights = new QLineEdit(groupBox);
        takeoff_runway_border_lights->setObjectName(QStringLiteral("takeoff_runway_border_lights"));

        verticalLayout_2->addWidget(takeoff_runway_border_lights);

        departure_airport_lights_taxiing = new QLineEdit(groupBox);
        departure_airport_lights_taxiing->setObjectName(QStringLiteral("departure_airport_lights_taxiing"));

        verticalLayout_2->addWidget(departure_airport_lights_taxiing);

        departure_airport_lights_illumination = new QLineEdit(groupBox);
        departure_airport_lights_illumination->setObjectName(QStringLiteral("departure_airport_lights_illumination"));

        verticalLayout_2->addWidget(departure_airport_lights_illumination);

        departure_airport_other_lights = new QLineEdit(groupBox);
        departure_airport_other_lights->setObjectName(QStringLiteral("departure_airport_other_lights"));

        verticalLayout_2->addWidget(departure_airport_other_lights);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout_5->addWidget(groupBox);

        groupBox_2 = new QGroupBox(AirportsDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_2);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_3->addWidget(label_9);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QStringLiteral("label_12"));

        verticalLayout_3->addWidget(label_12);

        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QStringLiteral("label_13"));

        verticalLayout_3->addWidget(label_13);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_3->addWidget(label_8);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout_3->addWidget(label_10);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QStringLiteral("label_11"));

        verticalLayout_3->addWidget(label_11);


        horizontalLayout_4->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
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
        arrivalCity->setObjectName(QStringLiteral("arrivalCity"));

        horizontalLayout_3->addWidget(arrivalCity);

        arrivalCode = new QComboBox(groupBox_2);
        arrivalCode->setObjectName(QStringLiteral("arrivalCode"));

        horizontalLayout_3->addWidget(arrivalCode);

        arrival_airport_code = new QLineEdit(groupBox_2);
        arrival_airport_code->setObjectName(QStringLiteral("arrival_airport_code"));

        horizontalLayout_3->addWidget(arrival_airport_code);


        verticalLayout_4->addLayout(horizontalLayout_3);

        landing_runway_code = new QLineEdit(groupBox_2);
        landing_runway_code->setObjectName(QStringLiteral("landing_runway_code"));

        verticalLayout_4->addWidget(landing_runway_code);

        landing_runway_border_lights = new QLineEdit(groupBox_2);
        landing_runway_border_lights->setObjectName(QStringLiteral("landing_runway_border_lights"));

        verticalLayout_4->addWidget(landing_runway_border_lights);

        arrival_airport_lights_taxiing = new QLineEdit(groupBox_2);
        arrival_airport_lights_taxiing->setObjectName(QStringLiteral("arrival_airport_lights_taxiing"));

        verticalLayout_4->addWidget(arrival_airport_lights_taxiing);

        arrival_airport_lights_illumination = new QLineEdit(groupBox_2);
        arrival_airport_lights_illumination->setObjectName(QStringLiteral("arrival_airport_lights_illumination"));

        verticalLayout_4->addWidget(arrival_airport_lights_illumination);

        arrival_airport_other_lights = new QLineEdit(groupBox_2);
        arrival_airport_other_lights->setObjectName(QStringLiteral("arrival_airport_other_lights"));

        verticalLayout_4->addWidget(arrival_airport_other_lights);


        horizontalLayout_4->addLayout(verticalLayout_4);


        verticalLayout_5->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(AirportsDialog);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        horizontalLayout_7 = new QHBoxLayout(groupBox_3);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_5->addWidget(label_7);

        horizontalSpacer_2 = new QSpacerItem(78, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        model_simulation_time = new QLineEdit(groupBox_3);
        model_simulation_time->setObjectName(QStringLiteral("model_simulation_time"));

        horizontalLayout_5->addWidget(model_simulation_time);


        horizontalLayout_7->addLayout(horizontalLayout_5);


        verticalLayout_5->addWidget(groupBox_3);

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

        departureCode->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(AirportsDialog);
    } // setupUi

    void retranslateUi(QDialog *AirportsDialog)
    {
        AirportsDialog->setWindowTitle(QApplication::translate("AirportsDialog", "\320\220\321\215\321\200\320\276\320\264\321\200\320\276\320\274\320\275\321\213\320\265 \320\276\320\263\320\275\320\270", nullptr));
        groupBox->setTitle(QApplication::translate("AirportsDialog", "\320\222\320\267\320\273\320\265\321\202", nullptr));
        label->setText(QApplication::translate("AirportsDialog", "\320\220\321\215\321\200\320\276\320\264\321\200\320\276\320\274 \320\262\320\267\320\273\320\265\321\202\320\260", nullptr));
        label_2->setText(QApplication::translate("AirportsDialog", "\320\237\320\276\320\273\320\276\321\201\320\260 \320\262\320\267\320\273\320\265\321\202\320\260", nullptr));
        label_3->setText(QApplication::translate("AirportsDialog", "\320\221\320\276\320\272\320\276\320\262\321\213\320\265 \320\276\320\263\320\275\320\270 \320\277\320\276\320\273\320\276\321\201\321\213", nullptr));
        label_4->setText(QApplication::translate("AirportsDialog", "\320\240\321\203\320\273\320\265\320\266\320\275\321\213\320\265 \320\276\320\263\320\275\320\270 \320\260\321\215\321\200\320\276\320\264\321\200\320\276\320\274\320\260", nullptr));
        label_5->setText(QApplication::translate("AirportsDialog", "\320\236\320\263\320\275\320\270 \320\277\320\276\320\264\321\201\320\262\320\265\321\202\320\260 \321\201\321\202\320\276\321\217\320\275\320\276\320\272 \320\260\321\215\321\200\320\276\320\264\321\200\320\276\320\274\320\260", nullptr));
        label_6->setText(QApplication::translate("AirportsDialog", "\320\257\321\200\320\272\320\276\321\201\321\202\321\214 \320\276\321\201\321\202\320\260\320\273\321\214\320\275\321\213\321\205 \320\276\320\263\320\275\320\265\320\271", nullptr));
        departureCity->setItemText(0, QApplication::translate("AirportsDialog", "Moscow DME", nullptr));
        departureCity->setItemText(1, QApplication::translate("AirportsDialog", "Moscow OST", nullptr));
        departureCity->setItemText(2, QApplication::translate("AirportsDialog", "London", nullptr));
        departureCity->setItemText(3, QApplication::translate("AirportsDialog", "KarlovyVary", nullptr));
        departureCity->setItemText(4, QApplication::translate("AirportsDialog", "Tivat", nullptr));
        departureCity->setItemText(5, QApplication::translate("AirportsDialog", "Bruxelles", nullptr));
        departureCity->setItemText(6, QApplication::translate("AirportsDialog", "Venice", nullptr));
        departureCity->setItemText(7, QApplication::translate("AirportsDialog", "Dublin", nullptr));
        departureCity->setItemText(8, QApplication::translate("AirportsDialog", "Innsbruck", nullptr));
        departureCity->setItemText(9, QApplication::translate("AirportsDialog", "Keflavic", nullptr));
        departureCity->setItemText(10, QApplication::translate("AirportsDialog", "Komsomolsk", nullptr));
        departureCity->setItemText(11, QApplication::translate("AirportsDialog", "Pulkovo", nullptr));
        departureCity->setItemText(12, QApplication::translate("AirportsDialog", "Sochi", nullptr));
        departureCity->setItemText(13, QApplication::translate("AirportsDialog", "Toluca", nullptr));
        departureCity->setItemText(14, QApplication::translate("AirportsDialog", "Moscow SVO", nullptr));
        departureCity->setItemText(15, QApplication::translate("AirportsDialog", "Moscow VKO", nullptr));
        departureCity->setItemText(16, QApplication::translate("AirportsDialog", "Moscow ZIA", nullptr));
        departureCity->setItemText(17, QApplication::translate("AirportsDialog", "Helsinki", nullptr));

        departureCode->setCurrentText(QString());
        takeoff_runway_code->setText(QString());
        groupBox_2->setTitle(QApplication::translate("AirportsDialog", "\320\237\320\276\321\201\320\260\320\264\320\272\320\260", nullptr));
        label_9->setText(QApplication::translate("AirportsDialog", "\320\220\321\215\321\200\320\276\320\264\321\200\320\276\320\274 \320\277\320\276\321\201\320\260\320\264\320\272\320\270", nullptr));
        label_12->setText(QApplication::translate("AirportsDialog", "\320\237\320\276\320\273\320\276\321\201\320\260 \320\277\320\276\321\201\320\260\320\264\320\272\320\270", nullptr));
        label_13->setText(QApplication::translate("AirportsDialog", "\320\221\320\276\320\272\320\276\320\262\321\213\320\265 \320\276\320\263\320\275\320\270 \320\277\320\276\320\273\320\276\321\201\321\213", nullptr));
        label_8->setText(QApplication::translate("AirportsDialog", "\320\240\321\203\320\273\320\265\320\266\320\275\321\213\320\265 \320\276\320\263\320\275\320\270 \320\260\321\215\321\200\320\276\320\264\321\200\320\276\320\274\320\260", nullptr));
        label_10->setText(QApplication::translate("AirportsDialog", "\320\236\320\263\320\275\320\270 \320\277\320\276\320\264\321\201\320\262\320\265\321\202\320\260 \321\201\321\202\320\276\321\217\320\275\320\276\320\272 \320\260\321\215\321\200\320\276\320\264\321\200\320\276\320\274\320\260", nullptr));
        label_11->setText(QApplication::translate("AirportsDialog", "\320\257\321\200\320\272\320\276\321\201\321\202\321\214 \320\276\321\201\321\202\320\260\320\273\321\214\320\275\321\213\321\205 \320\276\320\263\320\275\320\265\320\271", nullptr));
        arrivalCity->setItemText(0, QApplication::translate("AirportsDialog", "Moscow DME", nullptr));
        arrivalCity->setItemText(1, QApplication::translate("AirportsDialog", "London", nullptr));
        arrivalCity->setItemText(2, QApplication::translate("AirportsDialog", "KarlovyVary", nullptr));
        arrivalCity->setItemText(3, QApplication::translate("AirportsDialog", "Tivat", nullptr));
        arrivalCity->setItemText(4, QApplication::translate("AirportsDialog", "Bruxelles", nullptr));
        arrivalCity->setItemText(5, QApplication::translate("AirportsDialog", "Venice", nullptr));
        arrivalCity->setItemText(6, QApplication::translate("AirportsDialog", "Dublin", nullptr));
        arrivalCity->setItemText(7, QApplication::translate("AirportsDialog", "Innsbruck", nullptr));
        arrivalCity->setItemText(8, QApplication::translate("AirportsDialog", "Keflavic", nullptr));
        arrivalCity->setItemText(9, QApplication::translate("AirportsDialog", "Komsomolsk", nullptr));
        arrivalCity->setItemText(10, QApplication::translate("AirportsDialog", "Pulkovo", nullptr));
        arrivalCity->setItemText(11, QApplication::translate("AirportsDialog", "Sochi", nullptr));
        arrivalCity->setItemText(12, QApplication::translate("AirportsDialog", "Toluca", nullptr));
        arrivalCity->setItemText(13, QApplication::translate("AirportsDialog", "Moscow SVO", nullptr));
        arrivalCity->setItemText(14, QApplication::translate("AirportsDialog", "Moscow VKO", nullptr));
        arrivalCity->setItemText(15, QApplication::translate("AirportsDialog", "Moscow ZIA", nullptr));
        arrivalCity->setItemText(16, QApplication::translate("AirportsDialog", "Helsinki", nullptr));

        arrivalCode->setCurrentText(QString());
        groupBox_3->setTitle(QApplication::translate("AirportsDialog", "\320\222\321\200\320\265\320\274\321\217", nullptr));
        label_7->setText(QApplication::translate("AirportsDialog", "\320\242\320\265\320\272\321\203\321\211\320\265\320\265 \320\262\321\200\320\265\320\274\321\217 \320\262 \320\274\320\276\320\264\320\265\320\273\320\270", nullptr));
        ok_pb->setText(QApplication::translate("AirportsDialog", "Ok", nullptr));
        cancel_pb->setText(QApplication::translate("AirportsDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AirportsDialog: public Ui_AirportsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AIRPORTSDIALOG_H
