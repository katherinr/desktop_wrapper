#include "mainvisual.h"
#include "ui_mainvisual.h"
#include <qdebug.h>
MainVisual::MainVisual(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainVisual)
{
    setWindowFlags(Qt::WindowStaysOnTopHint);
    ui->setupUi(this);
}

MainVisual::~MainVisual()
{
    delete ui;
}

void MainVisual::setData(_MainVisualData *data)
{
    //data->packet_id = NPR_PACKET_TYPE_METEO_DATA;//meteo_data->message;

    qDebug()<<"setting visual data from received";
    ui->num_correct->setText(QString::number(data->num_correct));
    ui->pcoord_lat->setText(QString::number(data->p_coord.X));
    ui->pcoord_lon->setText(QString::number(data->p_coord.Z));
    ui->pcoord_h->setText(QString::number(data->p_coord.H));

    ui->pangle_c->setText((QString::number(data->p_angle.C)));
    ui->pangle_p->setText((QString::number(data->p_angle.P)));
    ui->pangle_r->setText((QString::number(data->p_angle.R)));

    //обороты
    ui->n2_l->setText(QString::number(data->N2_L));
    ui->n2_r->setText(QString::number(data->N2_R));

    //stabs, mechs
    ui->flaps->setText(QString::number(data->Flaps));
    ui->stabilizer->setText(QString::number(data->Stabilizer));
    ui->slats->setText(QString::number(data->Slats));

    ui->elevator_l->setText((QString::number(data->Elevator_L)));
    ui->elevator_r->setText((QString::number(data->Elevator_R)));
    ui->aileron_l->setText((QString::number(data->Aileron_L)));
    ui->aileron_r->setText((QString::number(data->Aileron_R)));
    ui->rudder->setText((QString::number(data->Rudder)));

    ui->spoiler_lce->setText((QString::number(data->Spoiler_L_CE)));
    ui->spoiler_lin->setText((QString::number(data->Spoiler_L_IN)));
    ui->spoiler_lob->setText((QString::number(data->Spoiler_L_OB)));
    ui->spoiler_rce->setText((QString::number(data->Spoiler_R_CE)));
    ui->spoiler_rin->setText((QString::number(data->Spoiler_R_IN)));
    ui->spoiler_rob->setText((QString::number(data->Spoiler_R_OB)));

    ui->gr_spoiler_lin->setText((QString::number(data->GroudSpoiler_L_IB)));
    ui->gr_spoiler_lob->setText((QString::number(data->GroudSpoiler_L_OB)));
    ui->gr_spoiler_rin->setText((QString::number(data->GroudSpoiler_R_IB)));
    ui->gr_spoiler_rob->setText((QString::number(data->GroudSpoiler_R_OB)));
    ui->spoiler_rin->setText((QString::number(data->Spoiler_R_IN)));
    ui->gear_n->setText((QString::number(data->Gear_N)));
    ui->gear_l->setText((QString::number(data->Gear_L)));
    ui->gear_r->setText((QString::number(data->Gear_R)));
    ui->gear_stri_angle->setText((QString::number(data->Gear_SteeringAngle)));

    //бортовые огни
    ui->landing_lights->setText((QString::number(data->LandingLights)));
    ui->taxi_light->setText((QString::number(data->TaxiLight)));
    ui->runway_turnofflights->setText((QString::number(data->RunwayTurnoffLights)));
    ui->nav_light_green->setText((QString::number(data->NavigationLightGreen)));
    ui->nav_light_red->setText((QString::number(data->NavigationLightRed)));
    ui->nav_light_white->setText((QString::number(data->NavigationLightWhite)));
    ui->anticoll_bec_white->setText((QString::number(data->AntiCollisionBeaconWhite)));
    ui->anticollosion_bec_red->setText((QString::number(data->AntiCollisionBeaconRed)));
    ui->internal_lights->setText((QString::number(data->InternalLights)));

    this->update();
}
