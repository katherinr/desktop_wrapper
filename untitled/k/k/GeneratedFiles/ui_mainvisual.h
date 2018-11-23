/********************************************************************************
** Form generated from reading UI file 'mainvisual.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINVISUAL_H
#define UI_MAINVISUAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainVisual
{
public:
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_7;
    QGroupBox *mCloudGrB;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *pcoord_lat;
    QLineEdit *pcoord_lon;
    QLineEdit *pcoord_h;
    QLineEdit *pangle_c;
    QLineEdit *pangle_p;
    QLineEdit *pangle_r;
    QGroupBox *mCloudGrB_2;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_9;
    QLabel *label_10;
    QVBoxLayout *verticalLayout_10;
    QLineEdit *n2_l;
    QLineEdit *n2_r;
    QGroupBox *mCloudGrB_3;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_16;
    QVBoxLayout *verticalLayout_11;
    QLineEdit *flaps;
    QLineEdit *slats;
    QLineEdit *stabilizer;
    QLineEdit *elevator_l;
    QLineEdit *elevator_r;
    QLineEdit *aileron_l;
    QLineEdit *aileron_r;
    QLineEdit *rudder;
    QGroupBox *mCloudGrB_4;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_23;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *gear_n;
    QLineEdit *gear_l;
    QLineEdit *gear_r;
    QLineEdit *gear_stri_angle;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *mCloudGrB_6;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_20;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_31;
    QLabel *label_32;
    QLabel *label_33;
    QLabel *label_35;
    QLabel *label_36;
    QLabel *label_34;
    QVBoxLayout *verticalLayout_21;
    QLineEdit *spoiler_lob;
    QLineEdit *spoiler_lce;
    QLineEdit *spoiler_lin;
    QLineEdit *spoiler_rob;
    QLineEdit *spoiler_rce;
    QLineEdit *spoiler_rin;
    QLineEdit *gr_spoiler_lob;
    QLineEdit *gr_spoiler_lin;
    QLineEdit *gr_spoiler_rob;
    QLineEdit *gr_spoiler_rin;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *mCloudGrB_7;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_22;
    QLabel *label_38;
    QLabel *label_39;
    QLabel *label_40;
    QLabel *label_41;
    QLabel *label_42;
    QLabel *label_43;
    QLabel *label_44;
    QLabel *label_45;
    QLabel *label_46;
    QVBoxLayout *verticalLayout_23;
    QLineEdit *landing_lights;
    QLineEdit *taxi_light;
    QLineEdit *runway_turnofflights;
    QLineEdit *nav_light_red;
    QLineEdit *nav_light_green;
    QLineEdit *nav_light_white;
    QLineEdit *anticollosion_bec_red;
    QLineEdit *anticoll_bec_white;
    QLineEdit *internal_lights;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_10;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_25;
    QLineEdit *num_correct;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *okpb;
    QPushButton *cancelPb;

    void setupUi(QWidget *MainVisual)
    {
        if (MainVisual->objectName().isEmpty())
            MainVisual->setObjectName(QStringLiteral("MainVisual"));
        MainVisual->setWindowModality(Qt::ApplicationModal);
        MainVisual->setEnabled(true);
        MainVisual->resize(961, 900);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainVisual->sizePolicy().hasHeightForWidth());
        MainVisual->setSizePolicy(sizePolicy);
        MainVisual->setMinimumSize(QSize(800, 900));
        MainVisual->setMaximumSize(QSize(961, 900));
        horizontalLayout_11 = new QHBoxLayout(MainVisual);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        mCloudGrB = new QGroupBox(MainVisual);
        mCloudGrB->setObjectName(QStringLiteral("mCloudGrB"));
        horizontalLayout = new QHBoxLayout(mCloudGrB);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_3 = new QLabel(mCloudGrB);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(271, 0));

        verticalLayout_4->addWidget(label_3);

        label_4 = new QLabel(mCloudGrB);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_4->addWidget(label_4);

        label_5 = new QLabel(mCloudGrB);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_4->addWidget(label_5);

        label_6 = new QLabel(mCloudGrB);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(271, 0));

        verticalLayout_4->addWidget(label_6);

        label_7 = new QLabel(mCloudGrB);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_4->addWidget(label_7);

        label_8 = new QLabel(mCloudGrB);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_4->addWidget(label_8);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        pcoord_lat = new QLineEdit(mCloudGrB);
        pcoord_lat->setObjectName(QStringLiteral("pcoord_lat"));
        pcoord_lat->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_2->addWidget(pcoord_lat);

        pcoord_lon = new QLineEdit(mCloudGrB);
        pcoord_lon->setObjectName(QStringLiteral("pcoord_lon"));

        verticalLayout_2->addWidget(pcoord_lon);

        pcoord_h = new QLineEdit(mCloudGrB);
        pcoord_h->setObjectName(QStringLiteral("pcoord_h"));

        verticalLayout_2->addWidget(pcoord_h);

        pangle_c = new QLineEdit(mCloudGrB);
        pangle_c->setObjectName(QStringLiteral("pangle_c"));

        verticalLayout_2->addWidget(pangle_c);

        pangle_p = new QLineEdit(mCloudGrB);
        pangle_p->setObjectName(QStringLiteral("pangle_p"));

        verticalLayout_2->addWidget(pangle_p);

        pangle_r = new QLineEdit(mCloudGrB);
        pangle_r->setObjectName(QStringLiteral("pangle_r"));

        verticalLayout_2->addWidget(pangle_r);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_7->addWidget(mCloudGrB);

        mCloudGrB_2 = new QGroupBox(MainVisual);
        mCloudGrB_2->setObjectName(QStringLiteral("mCloudGrB_2"));
        horizontalLayout_4 = new QHBoxLayout(mCloudGrB_2);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        label_9 = new QLabel(mCloudGrB_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMinimumSize(QSize(271, 0));

        verticalLayout_8->addWidget(label_9);

        label_10 = new QLabel(mCloudGrB_2);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout_8->addWidget(label_10);


        horizontalLayout_4->addLayout(verticalLayout_8);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        n2_l = new QLineEdit(mCloudGrB_2);
        n2_l->setObjectName(QStringLiteral("n2_l"));

        verticalLayout_10->addWidget(n2_l);

        n2_r = new QLineEdit(mCloudGrB_2);
        n2_r->setObjectName(QStringLiteral("n2_r"));

        verticalLayout_10->addWidget(n2_r);


        horizontalLayout_4->addLayout(verticalLayout_10);


        verticalLayout_7->addWidget(mCloudGrB_2);

        mCloudGrB_3 = new QGroupBox(MainVisual);
        mCloudGrB_3->setObjectName(QStringLiteral("mCloudGrB_3"));
        horizontalLayout_5 = new QHBoxLayout(mCloudGrB_3);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        label_11 = new QLabel(mCloudGrB_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setMinimumSize(QSize(271, 0));

        verticalLayout_9->addWidget(label_11);

        label_12 = new QLabel(mCloudGrB_3);
        label_12->setObjectName(QStringLiteral("label_12"));

        verticalLayout_9->addWidget(label_12);

        label_13 = new QLabel(mCloudGrB_3);
        label_13->setObjectName(QStringLiteral("label_13"));

        verticalLayout_9->addWidget(label_13);

        label_14 = new QLabel(mCloudGrB_3);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setMinimumSize(QSize(271, 0));

        verticalLayout_9->addWidget(label_14);

        label_15 = new QLabel(mCloudGrB_3);
        label_15->setObjectName(QStringLiteral("label_15"));

        verticalLayout_9->addWidget(label_15);

        label_17 = new QLabel(mCloudGrB_3);
        label_17->setObjectName(QStringLiteral("label_17"));

        verticalLayout_9->addWidget(label_17);

        label_18 = new QLabel(mCloudGrB_3);
        label_18->setObjectName(QStringLiteral("label_18"));

        verticalLayout_9->addWidget(label_18);

        label_16 = new QLabel(mCloudGrB_3);
        label_16->setObjectName(QStringLiteral("label_16"));

        verticalLayout_9->addWidget(label_16);


        horizontalLayout_5->addLayout(verticalLayout_9);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        flaps = new QLineEdit(mCloudGrB_3);
        flaps->setObjectName(QStringLiteral("flaps"));

        verticalLayout_11->addWidget(flaps);

        slats = new QLineEdit(mCloudGrB_3);
        slats->setObjectName(QStringLiteral("slats"));

        verticalLayout_11->addWidget(slats);

        stabilizer = new QLineEdit(mCloudGrB_3);
        stabilizer->setObjectName(QStringLiteral("stabilizer"));

        verticalLayout_11->addWidget(stabilizer);

        elevator_l = new QLineEdit(mCloudGrB_3);
        elevator_l->setObjectName(QStringLiteral("elevator_l"));

        verticalLayout_11->addWidget(elevator_l);

        elevator_r = new QLineEdit(mCloudGrB_3);
        elevator_r->setObjectName(QStringLiteral("elevator_r"));

        verticalLayout_11->addWidget(elevator_r);

        aileron_l = new QLineEdit(mCloudGrB_3);
        aileron_l->setObjectName(QStringLiteral("aileron_l"));

        verticalLayout_11->addWidget(aileron_l);

        aileron_r = new QLineEdit(mCloudGrB_3);
        aileron_r->setObjectName(QStringLiteral("aileron_r"));

        verticalLayout_11->addWidget(aileron_r);

        rudder = new QLineEdit(mCloudGrB_3);
        rudder->setObjectName(QStringLiteral("rudder"));

        verticalLayout_11->addWidget(rudder);


        horizontalLayout_5->addLayout(verticalLayout_11);


        verticalLayout_7->addWidget(mCloudGrB_3);

        mCloudGrB_4 = new QGroupBox(MainVisual);
        mCloudGrB_4->setObjectName(QStringLiteral("mCloudGrB_4"));
        horizontalLayout_6 = new QHBoxLayout(mCloudGrB_4);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        label_19 = new QLabel(mCloudGrB_4);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setMinimumSize(QSize(271, 0));

        verticalLayout->addWidget(label_19);

        label_20 = new QLabel(mCloudGrB_4);
        label_20->setObjectName(QStringLiteral("label_20"));

        verticalLayout->addWidget(label_20);

        label_21 = new QLabel(mCloudGrB_4);
        label_21->setObjectName(QStringLiteral("label_21"));

        verticalLayout->addWidget(label_21);

        label_23 = new QLabel(mCloudGrB_4);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setMinimumSize(QSize(290, 0));
        label_23->setMaximumSize(QSize(290, 25));

        verticalLayout->addWidget(label_23);


        horizontalLayout_6->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        gear_n = new QLineEdit(mCloudGrB_4);
        gear_n->setObjectName(QStringLiteral("gear_n"));

        verticalLayout_3->addWidget(gear_n);

        gear_l = new QLineEdit(mCloudGrB_4);
        gear_l->setObjectName(QStringLiteral("gear_l"));

        verticalLayout_3->addWidget(gear_l);

        gear_r = new QLineEdit(mCloudGrB_4);
        gear_r->setObjectName(QStringLiteral("gear_r"));

        verticalLayout_3->addWidget(gear_r);

        gear_stri_angle = new QLineEdit(mCloudGrB_4);
        gear_stri_angle->setObjectName(QStringLiteral("gear_stri_angle"));

        verticalLayout_3->addWidget(gear_stri_angle);


        horizontalLayout_6->addLayout(verticalLayout_3);


        verticalLayout_7->addWidget(mCloudGrB_4);


        horizontalLayout_11->addLayout(verticalLayout_7);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        mCloudGrB_6 = new QGroupBox(MainVisual);
        mCloudGrB_6->setObjectName(QStringLiteral("mCloudGrB_6"));
        horizontalLayout_9 = new QHBoxLayout(mCloudGrB_6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        verticalLayout_20 = new QVBoxLayout();
        verticalLayout_20->setObjectName(QStringLiteral("verticalLayout_20"));
        label_27 = new QLabel(mCloudGrB_6);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setMinimumSize(QSize(271, 0));

        verticalLayout_20->addWidget(label_27);

        label_28 = new QLabel(mCloudGrB_6);
        label_28->setObjectName(QStringLiteral("label_28"));

        verticalLayout_20->addWidget(label_28);

        label_29 = new QLabel(mCloudGrB_6);
        label_29->setObjectName(QStringLiteral("label_29"));

        verticalLayout_20->addWidget(label_29);

        label_30 = new QLabel(mCloudGrB_6);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setMinimumSize(QSize(271, 0));

        verticalLayout_20->addWidget(label_30);

        label_31 = new QLabel(mCloudGrB_6);
        label_31->setObjectName(QStringLiteral("label_31"));

        verticalLayout_20->addWidget(label_31);

        label_32 = new QLabel(mCloudGrB_6);
        label_32->setObjectName(QStringLiteral("label_32"));

        verticalLayout_20->addWidget(label_32);

        label_33 = new QLabel(mCloudGrB_6);
        label_33->setObjectName(QStringLiteral("label_33"));

        verticalLayout_20->addWidget(label_33);

        label_35 = new QLabel(mCloudGrB_6);
        label_35->setObjectName(QStringLiteral("label_35"));

        verticalLayout_20->addWidget(label_35);

        label_36 = new QLabel(mCloudGrB_6);
        label_36->setObjectName(QStringLiteral("label_36"));

        verticalLayout_20->addWidget(label_36);

        label_34 = new QLabel(mCloudGrB_6);
        label_34->setObjectName(QStringLiteral("label_34"));

        verticalLayout_20->addWidget(label_34);


        horizontalLayout_9->addLayout(verticalLayout_20);

        verticalLayout_21 = new QVBoxLayout();
        verticalLayout_21->setObjectName(QStringLiteral("verticalLayout_21"));
        spoiler_lob = new QLineEdit(mCloudGrB_6);
        spoiler_lob->setObjectName(QStringLiteral("spoiler_lob"));

        verticalLayout_21->addWidget(spoiler_lob);

        spoiler_lce = new QLineEdit(mCloudGrB_6);
        spoiler_lce->setObjectName(QStringLiteral("spoiler_lce"));

        verticalLayout_21->addWidget(spoiler_lce);

        spoiler_lin = new QLineEdit(mCloudGrB_6);
        spoiler_lin->setObjectName(QStringLiteral("spoiler_lin"));

        verticalLayout_21->addWidget(spoiler_lin);

        spoiler_rob = new QLineEdit(mCloudGrB_6);
        spoiler_rob->setObjectName(QStringLiteral("spoiler_rob"));

        verticalLayout_21->addWidget(spoiler_rob);

        spoiler_rce = new QLineEdit(mCloudGrB_6);
        spoiler_rce->setObjectName(QStringLiteral("spoiler_rce"));

        verticalLayout_21->addWidget(spoiler_rce);

        spoiler_rin = new QLineEdit(mCloudGrB_6);
        spoiler_rin->setObjectName(QStringLiteral("spoiler_rin"));

        verticalLayout_21->addWidget(spoiler_rin);

        gr_spoiler_lob = new QLineEdit(mCloudGrB_6);
        gr_spoiler_lob->setObjectName(QStringLiteral("gr_spoiler_lob"));

        verticalLayout_21->addWidget(gr_spoiler_lob);

        gr_spoiler_lin = new QLineEdit(mCloudGrB_6);
        gr_spoiler_lin->setObjectName(QStringLiteral("gr_spoiler_lin"));

        verticalLayout_21->addWidget(gr_spoiler_lin);

        gr_spoiler_rob = new QLineEdit(mCloudGrB_6);
        gr_spoiler_rob->setObjectName(QStringLiteral("gr_spoiler_rob"));

        verticalLayout_21->addWidget(gr_spoiler_rob);

        gr_spoiler_rin = new QLineEdit(mCloudGrB_6);
        gr_spoiler_rin->setObjectName(QStringLiteral("gr_spoiler_rin"));

        verticalLayout_21->addWidget(gr_spoiler_rin);


        horizontalLayout_9->addLayout(verticalLayout_21);


        verticalLayout_6->addWidget(mCloudGrB_6);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        mCloudGrB_7 = new QGroupBox(MainVisual);
        mCloudGrB_7->setObjectName(QStringLiteral("mCloudGrB_7"));
        horizontalLayout_3 = new QHBoxLayout(mCloudGrB_7);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_22 = new QVBoxLayout();
        verticalLayout_22->setObjectName(QStringLiteral("verticalLayout_22"));
        label_38 = new QLabel(mCloudGrB_7);
        label_38->setObjectName(QStringLiteral("label_38"));

        verticalLayout_22->addWidget(label_38);

        label_39 = new QLabel(mCloudGrB_7);
        label_39->setObjectName(QStringLiteral("label_39"));

        verticalLayout_22->addWidget(label_39);

        label_40 = new QLabel(mCloudGrB_7);
        label_40->setObjectName(QStringLiteral("label_40"));
        label_40->setMinimumSize(QSize(271, 0));

        verticalLayout_22->addWidget(label_40);

        label_41 = new QLabel(mCloudGrB_7);
        label_41->setObjectName(QStringLiteral("label_41"));

        verticalLayout_22->addWidget(label_41);

        label_42 = new QLabel(mCloudGrB_7);
        label_42->setObjectName(QStringLiteral("label_42"));

        verticalLayout_22->addWidget(label_42);

        label_43 = new QLabel(mCloudGrB_7);
        label_43->setObjectName(QStringLiteral("label_43"));

        verticalLayout_22->addWidget(label_43);

        label_44 = new QLabel(mCloudGrB_7);
        label_44->setObjectName(QStringLiteral("label_44"));

        verticalLayout_22->addWidget(label_44);

        label_45 = new QLabel(mCloudGrB_7);
        label_45->setObjectName(QStringLiteral("label_45"));

        verticalLayout_22->addWidget(label_45);

        label_46 = new QLabel(mCloudGrB_7);
        label_46->setObjectName(QStringLiteral("label_46"));

        verticalLayout_22->addWidget(label_46);


        horizontalLayout_3->addLayout(verticalLayout_22);

        verticalLayout_23 = new QVBoxLayout();
        verticalLayout_23->setObjectName(QStringLiteral("verticalLayout_23"));
        landing_lights = new QLineEdit(mCloudGrB_7);
        landing_lights->setObjectName(QStringLiteral("landing_lights"));

        verticalLayout_23->addWidget(landing_lights);

        taxi_light = new QLineEdit(mCloudGrB_7);
        taxi_light->setObjectName(QStringLiteral("taxi_light"));

        verticalLayout_23->addWidget(taxi_light);

        runway_turnofflights = new QLineEdit(mCloudGrB_7);
        runway_turnofflights->setObjectName(QStringLiteral("runway_turnofflights"));

        verticalLayout_23->addWidget(runway_turnofflights);

        nav_light_red = new QLineEdit(mCloudGrB_7);
        nav_light_red->setObjectName(QStringLiteral("nav_light_red"));

        verticalLayout_23->addWidget(nav_light_red);

        nav_light_green = new QLineEdit(mCloudGrB_7);
        nav_light_green->setObjectName(QStringLiteral("nav_light_green"));

        verticalLayout_23->addWidget(nav_light_green);

        nav_light_white = new QLineEdit(mCloudGrB_7);
        nav_light_white->setObjectName(QStringLiteral("nav_light_white"));

        verticalLayout_23->addWidget(nav_light_white);

        anticollosion_bec_red = new QLineEdit(mCloudGrB_7);
        anticollosion_bec_red->setObjectName(QStringLiteral("anticollosion_bec_red"));

        verticalLayout_23->addWidget(anticollosion_bec_red);

        anticoll_bec_white = new QLineEdit(mCloudGrB_7);
        anticoll_bec_white->setObjectName(QStringLiteral("anticoll_bec_white"));

        verticalLayout_23->addWidget(anticoll_bec_white);

        internal_lights = new QLineEdit(mCloudGrB_7);
        internal_lights->setObjectName(QStringLiteral("internal_lights"));

        verticalLayout_23->addWidget(internal_lights);


        horizontalLayout_3->addLayout(verticalLayout_23);


        verticalLayout_5->addWidget(mCloudGrB_7);

        groupBox = new QGroupBox(MainVisual);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout_10 = new QHBoxLayout(groupBox);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_25 = new QLabel(groupBox);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setMinimumSize(QSize(271, 0));

        horizontalLayout_2->addWidget(label_25);

        num_correct = new QLineEdit(groupBox);
        num_correct->setObjectName(QStringLiteral("num_correct"));
        num_correct->setMinimumSize(QSize(100, 25));
        num_correct->setMaximumSize(QSize(100, 25));

        horizontalLayout_2->addWidget(num_correct);


        horizontalLayout_10->addLayout(horizontalLayout_2);


        verticalLayout_5->addWidget(groupBox);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer = new QSpacerItem(200, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        okpb = new QPushButton(MainVisual);
        okpb->setObjectName(QStringLiteral("okpb"));

        horizontalLayout_7->addWidget(okpb);

        cancelPb = new QPushButton(MainVisual);
        cancelPb->setObjectName(QStringLiteral("cancelPb"));

        horizontalLayout_7->addWidget(cancelPb);


        horizontalLayout_8->addLayout(horizontalLayout_7);


        verticalLayout_5->addLayout(horizontalLayout_8);


        verticalLayout_6->addLayout(verticalLayout_5);


        horizontalLayout_11->addLayout(verticalLayout_6);


        retranslateUi(MainVisual);

        QMetaObject::connectSlotsByName(MainVisual);
    } // setupUi

    void retranslateUi(QWidget *MainVisual)
    {
        MainVisual->setWindowTitle(QApplication::translate("MainVisual", "\320\236\321\201\320\275\320\276\320\262\320\275\320\276\320\271 \320\277\320\260\320\272\320\265\321\202 \320\264\320\260\320\275\320\275\321\213\321\205 \320\262\320\270\320\267\321\203\320\260\320\273\320\270\320\267\320\260\321\206\320\270\320\270", nullptr));
        mCloudGrB->setTitle(QApplication::translate("MainVisual", "\320\232\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213", nullptr));
        label_3->setText(QApplication::translate("MainVisual", "\320\250\320\270\321\200\320\276\321\202\320\260, [\320\263\321\200\320\260\320\264]", nullptr));
        label_4->setText(QApplication::translate("MainVisual", "\320\224\320\276\320\273\320\263\320\276\321\202\320\260, [\320\263\321\200\320\260\320\264]", nullptr));
        label_5->setText(QApplication::translate("MainVisual", "\320\222\321\213\321\201\320\276\321\202\320\260 \320\275\320\260\320\264 \321\203\321\200\320\276\320\262\320\275\320\265\320\274 \320\274\320\276\321\200\321\217, [\320\274]", nullptr));
        label_6->setText(QApplication::translate("MainVisual", "\320\243\320\263\320\276\320\273 \320\272\321\203\321\200\321\201\320\260, [\320\263\321\200\320\260\320\264]", nullptr));
        label_7->setText(QApplication::translate("MainVisual", "\320\243\320\263\320\276\320\273 \321\202\320\260\320\275\320\263\320\260\320\266\320\260, [\320\263\321\200\320\260\320\264]", nullptr));
        label_8->setText(QApplication::translate("MainVisual", "\320\243\320\263\320\276\320\273 \320\272\321\200\320\265\320\275\320\260, [\320\263\321\200\320\260\320\264]", nullptr));
        pcoord_lat->setText(QApplication::translate("MainVisual", "55.564917", nullptr));
        pcoord_lon->setText(QApplication::translate("MainVisual", "38.137015", nullptr));
        pcoord_h->setText(QApplication::translate("MainVisual", "115", nullptr));
        pangle_c->setText(QApplication::translate("MainVisual", "131", nullptr));
        pangle_p->setText(QApplication::translate("MainVisual", "0", nullptr));
        pangle_r->setText(QApplication::translate("MainVisual", "0", nullptr));
        mCloudGrB_2->setTitle(QApplication::translate("MainVisual", "\320\236\320\261\320\276\321\200\320\276\321\202\321\213, [%]", nullptr));
        label_9->setText(QApplication::translate("MainVisual", "\320\236\320\261\320\276\321\200\320\276\321\202\321\213 \320\273\320\265\320\262\320\276\320\263\320\276 \320\264\320\262\320\270\320\263\320\260\321\202\320\265\320\273\321\217 \320\240\320\243\320\224", nullptr));
        label_10->setText(QApplication::translate("MainVisual", "\320\236\320\261\320\276\321\200\320\276\321\202\321\213 \320\277\321\200\320\260\320\262\320\276\320\263\320\276 \320\264\320\262\320\270\320\263\320\260\321\202\320\265\320\273\321\217 \320\240\320\243\320\224", nullptr));
        n2_l->setText(QApplication::translate("MainVisual", "50", nullptr));
        n2_r->setText(QApplication::translate("MainVisual", "50", nullptr));
        mCloudGrB_3->setTitle(QApplication::translate("MainVisual", "\320\234\320\265\321\205\320\260\320\275\320\270\320\267\320\260\321\206\320\270\321\217, \320\276\321\200\320\263\320\260\320\275\321\213 \321\203\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\321\217, [\320\263\321\200\320\260\320\264]", nullptr));
        label_11->setText(QApplication::translate("MainVisual", "\320\237\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \320\267\320\260\320\272\321\200\321\213\320\273\320\272\320\276\320\262", nullptr));
        label_12->setText(QApplication::translate("MainVisual", "\320\237\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \320\277\321\200\320\265\320\264\320\272\321\200\321\213\320\273\320\272\320\276\320\262", nullptr));
        label_13->setText(QApplication::translate("MainVisual", "\320\237\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \321\201\321\202\320\260\320\261\320\270\320\273\320\270\320\267\320\260\321\202\320\276\321\200\320\260", nullptr));
        label_14->setText(QApplication::translate("MainVisual", "\320\237\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \321\200\321\203\320\273\321\217 \320\262\321\213\321\201\320\276\321\202\321\213 (\320\273\320\265\320\262\320\260\321\217 \321\201\320\265\320\272\321\206\320\270\321\217)", nullptr));
        label_15->setText(QApplication::translate("MainVisual", "\320\237\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \321\200\321\203\320\273\321\217 \320\262\321\213\321\201\320\276\321\202\321\213 (\320\277\321\200\320\260\320\262\320\260\321\217 \321\201\320\265\320\272\321\206\320\270\321\217)", nullptr));
        label_17->setText(QApplication::translate("MainVisual", "\320\237\320\276\320\273\320\276\320\266\320\265\320\275\320\270\321\217 \320\273\320\265\320\262\320\276\320\263\320\276 \321\215\320\273\320\265\321\200\320\276\320\275\320\260", nullptr));
        label_18->setText(QApplication::translate("MainVisual", "\320\237\320\276\320\273\320\276\320\266\320\265\320\275\320\270\321\217 \320\277\321\200\320\260\320\262\320\276\320\263\320\276 \321\215\320\273\320\265\321\200\320\276\320\275\320\260", nullptr));
        label_16->setText(QApplication::translate("MainVisual", "\320\237\320\276\320\273\320\276\320\266\320\265\320\275\320\270\321\217 \321\200\321\203\320\273\321\217 \320\275\320\260\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\321\217", nullptr));
        flaps->setText(QApplication::translate("MainVisual", "25", nullptr));
        slats->setText(QApplication::translate("MainVisual", "20", nullptr));
        stabilizer->setText(QApplication::translate("MainVisual", "1", nullptr));
        elevator_l->setText(QApplication::translate("MainVisual", "0", nullptr));
        elevator_r->setText(QApplication::translate("MainVisual", "0", nullptr));
        aileron_l->setText(QApplication::translate("MainVisual", "0", nullptr));
        aileron_r->setText(QApplication::translate("MainVisual", "0", nullptr));
        rudder->setText(QApplication::translate("MainVisual", "0", nullptr));
        mCloudGrB_4->setTitle(QApplication::translate("MainVisual", "\320\237\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \321\210\320\260\321\201\321\201\320\270, [0/1]", nullptr));
        label_19->setText(QApplication::translate("MainVisual", "\320\237\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \320\275\320\276\321\201\320\276\320\262\320\276\320\271 \320\276\320\277\320\276\321\200\321\213", nullptr));
        label_20->setText(QApplication::translate("MainVisual", "\320\237\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \320\273\320\265\320\262\320\276\320\271 \320\276\320\277\320\276\321\200\321\213", nullptr));
        label_21->setText(QApplication::translate("MainVisual", "\320\237\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \320\277\321\200\320\260\320\262\320\276\320\271 \320\276\320\277\320\276\321\200\321\213", nullptr));
        label_23->setText(QApplication::translate("MainVisual", "\320\243\320\263\320\276\320\273 \320\277\320\276\320\262\320\276\321\200\320\276\321\202\320\260 \320\275\320\276\321\201\320\276\320\262\320\276\320\263\320\276 \320\272\320\276\320\273\320\265\321\201\320\260, [\320\263\321\200\320\260\320\264]", nullptr));
        gear_n->setText(QApplication::translate("MainVisual", "0", nullptr));
        gear_l->setText(QApplication::translate("MainVisual", "1", nullptr));
        gear_r->setText(QApplication::translate("MainVisual", "1", nullptr));
        gear_stri_angle->setText(QApplication::translate("MainVisual", "0", nullptr));
        mCloudGrB_6->setTitle(QApplication::translate("MainVisual", "\320\241\320\277\320\276\320\271\320\273\320\265\321\200\321\213, \320\262\320\276\320\267\320\264\321\203\321\210\320\275\321\213\320\271 \321\202\320\276\321\200\320\274\320\276\320\267,[\320\263\321\200\320\260\320\264]", nullptr));
        label_27->setText(QApplication::translate("MainVisual", "\320\237\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \320\273\320\265\320\262\320\276\320\263\320\276 \320\262\320\275\320\265\321\210\320\275\320\265\320\263\320\276 \320\270\320\275\321\202\320\265\321\200\321\206\320\265\320\277\321\202\320\276\321\200\320\260", nullptr));
        label_28->setText(QApplication::translate("MainVisual", "\320\237\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \320\273\320\265\320\262\320\276\320\263\320\276 \321\206\320\265\320\275\321\202\321\200. \320\270\320\275\321\202\320\265\321\200\321\206\320\265\320\277\321\202\320\276\321\200\320\260", nullptr));
        label_29->setText(QApplication::translate("MainVisual", "\320\237\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \320\273\320\265\320\262\320\276\320\263\320\276 \320\262\320\275\321\203\321\202\321\200. \320\270\320\275\321\202\320\265\321\200\321\206\320\265\320\277\321\202\320\276\321\200\320\260", nullptr));
        label_30->setText(QApplication::translate("MainVisual", "\320\237\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \320\277\321\200\320\260\320\262\320\276\320\263\320\276 \320\262\320\275\320\265\321\210. \320\270\320\275\321\202\320\265\321\200\321\206\320\265\320\277\321\202\320\276\321\200\320\260", nullptr));
        label_31->setText(QApplication::translate("MainVisual", "\320\237\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \320\277\321\200\320\260\320\262\320\276\320\263\320\276 \321\206\320\265\320\275\321\202\321\200. \320\270\320\275\321\202\320\265\321\200\321\206\320\265\320\277\321\202\320\276\321\200\320\260", nullptr));
        label_32->setText(QApplication::translate("MainVisual", "\320\237\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \320\277\321\200\320\260\320\262\320\276\320\263\320\276 \320\262\320\275\321\203\321\202\321\200. \320\270\320\275\321\202\320\265\321\200\321\206\320\265\320\277\321\202\320\276\321\200\320\260", nullptr));
        label_33->setText(QApplication::translate("MainVisual", "\320\237\320\276\320\273\320\276\320\266\320\265\320\275\320\270\321\217 \320\273\320\265\320\262\320\276\320\263\320\276 \320\262\320\275\320\265\321\210\320\275\320\265\320\263\320\276 \321\202\320\276\321\200\320\274\320\276\320\267\320\275\320\276\320\263\320\276 \321\211\320\270\321\202\320\272\320\260", nullptr));
        label_35->setText(QApplication::translate("MainVisual", "\320\237\320\276\320\273\320\276\320\266\320\265\320\275\320\270\321\217 \320\273\320\265\320\262\320\276\320\263\320\276 \320\262\320\275\321\203\321\202\321\200\320\265\320\275\320\275\320\265\320\263\320\276 \321\202\320\276\321\200\320\274\320\276\320\267\320\275\320\276\320\263\320\276 \321\211\320\270\321\202\320\272\320\260", nullptr));
        label_36->setText(QApplication::translate("MainVisual", "\320\237\320\276\320\273\320\276\320\266\320\265\320\275\320\270\321\217 \320\277\321\200\320\260\320\262\320\276\320\263\320\276 \320\262\320\275\320\265\321\210\320\275\320\265\320\263\320\276 \321\202\320\276\321\200\320\274\320\276\320\267\320\275\320\276\320\263\320\276 \321\211\320\270\321\202\320\272\320\260", nullptr));
        label_34->setText(QApplication::translate("MainVisual", "\320\237\320\276\320\273\320\276\320\266\320\265\320\275\320\270\321\217 \320\277\321\200\320\260\320\262\320\276\320\263\320\276 \320\262\320\275\321\203\321\202\321\200\320\265\320\275\320\275\320\265\320\263\320\276 \321\202\320\276\321\200\320\274\320\276\320\267\320\275\320\276\320\263\320\276 \321\211\320\270\321\202\320\272\320\260", nullptr));
        spoiler_lob->setText(QApplication::translate("MainVisual", "0", nullptr));
        spoiler_lce->setText(QApplication::translate("MainVisual", "0", nullptr));
        spoiler_lin->setText(QApplication::translate("MainVisual", "0", nullptr));
        spoiler_rob->setText(QApplication::translate("MainVisual", "0", nullptr));
        spoiler_rce->setText(QApplication::translate("MainVisual", "0", nullptr));
        spoiler_rin->setText(QApplication::translate("MainVisual", "0", nullptr));
        gr_spoiler_lob->setText(QApplication::translate("MainVisual", "0", nullptr));
        gr_spoiler_lin->setText(QApplication::translate("MainVisual", "0", nullptr));
        gr_spoiler_rob->setText(QApplication::translate("MainVisual", "0", nullptr));
        gr_spoiler_rin->setText(QApplication::translate("MainVisual", "0", nullptr));
        mCloudGrB_7->setTitle(QApplication::translate("MainVisual", "\320\241\320\260\320\274\320\276\320\273\320\265\321\202\320\275\321\213\320\265 (\320\261\320\276\321\200\321\202\320\276\320\262\321\213\320\265) \320\276\320\263\320\275\320\270,[ %]", nullptr));
        label_38->setText(QApplication::translate("MainVisual", "\320\237\320\276\321\201\320\260\320\264\320\276\321\207\320\275\321\213\320\265 \321\204\320\260\321\200\321\213", nullptr));
        label_39->setText(QApplication::translate("MainVisual", "\320\240\321\203\320\273\320\265\320\266\320\275\320\260\321\217 \321\204\320\260\321\200\320\260", nullptr));
        label_40->setText(QApplication::translate("MainVisual", "\320\244\320\260\321\200\320\260 \320\277\320\276\320\262\320\276\321\200\320\276\321\202\320\260 \321\201 \320\222\320\237\320\237", nullptr));
        label_41->setText(QApplication::translate("MainVisual", "\320\235\320\260\320\262\320\270\320\263\320\260\321\206\320\270\320\276\320\275\320\275\321\213\320\271 \320\276\320\263\320\276\320\275\321\214 \320\272\321\200\320\260\321\201\320\275\321\213\320\271", nullptr));
        label_42->setText(QApplication::translate("MainVisual", "\320\235\320\260\320\262\320\270\320\263\320\260\321\206\320\270\320\276\320\275\320\275\321\213\320\271 \320\276\320\263\320\276\320\275\321\214 \320\267\320\265\320\273\320\265\320\275\321\213\320\271", nullptr));
        label_43->setText(QApplication::translate("MainVisual", "\320\235\320\260\320\262\320\270\320\263\320\260\321\206\320\270\320\276\320\275\320\275\321\213\320\271 \320\276\320\263\320\276\320\275\321\214 \320\261\320\265\320\273\321\213\320\271", nullptr));
        label_44->setText(QApplication::translate("MainVisual", "\320\232\321\200\320\260\321\201\320\275\321\213\320\265 \320\277\321\200\320\276\320\261\320\273\320\265\321\201\320\272\320\276\320\262\321\213\320\265 \320\274\320\260\321\217\320\272\320\270 (\321\201\320\262\320\265\321\200\321\205\321\203, \321\201\320\275\320\270\320\267\321\203)", nullptr));
        label_45->setText(QApplication::translate("MainVisual", "\320\221\320\265\320\273\321\213\320\265 \320\277\321\200\320\276\320\261\320\273\320\265\321\201\320\272\320\276\320\262\321\213\320\265 \320\274\320\260\321\217\320\272\320\270 (\320\272\321\200\321\213\320\273\321\214\321\217, \321\205\320\262\320\276\321\201\321\202)", nullptr));
        label_46->setText(QApplication::translate("MainVisual", "\320\236\321\201\320\262\320\265\321\211\320\265\320\275\320\270\320\265 \320\272\320\260\320\261\320\270\320\275\321\213 \320\270 \321\201\320\260\320\273\320\276\320\275\320\260 \321\201\320\260\320\274\320\276\320\273\320\265\321\202\320\260", nullptr));
        landing_lights->setText(QApplication::translate("MainVisual", "0", nullptr));
        taxi_light->setText(QApplication::translate("MainVisual", "100", nullptr));
        runway_turnofflights->setText(QApplication::translate("MainVisual", "100", nullptr));
        nav_light_red->setText(QApplication::translate("MainVisual", "100", nullptr));
        nav_light_green->setText(QApplication::translate("MainVisual", "100", nullptr));
        nav_light_white->setText(QApplication::translate("MainVisual", "100", nullptr));
        anticollosion_bec_red->setText(QApplication::translate("MainVisual", "0", nullptr));
        anticoll_bec_white->setText(QApplication::translate("MainVisual", "0", nullptr));
        internal_lights->setText(QApplication::translate("MainVisual", "0", nullptr));
        groupBox->setTitle(QString());
        label_25->setText(QApplication::translate("MainVisual", "\320\232\320\276\321\200\321\200\320\265\320\272\321\206\320\270\321\217 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\217 \320\262 \320\272\320\260\320\261\320\270\320\275\320\265 \320\277\320\270\320\273\320\276\321\202\320\260 (0/1/2)", nullptr));
        num_correct->setText(QApplication::translate("MainVisual", "0", nullptr));
        okpb->setText(QApplication::translate("MainVisual", "Ok", nullptr));
        cancelPb->setText(QApplication::translate("MainVisual", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainVisual: public Ui_MainVisual {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINVISUAL_H
