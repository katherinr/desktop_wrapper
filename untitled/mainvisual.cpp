#include "mainvisual.h"
#include "ui_mainvisual.h"
#include <qdebug.h>
#include "utilities.h"
#include <QDialog>
MainVisual::MainVisual(QWidget *parent) :
      QDialog(parent),
    ui(new Ui::MainVisual),
    m_data(new _MainVisualData)
{
    setWindowModality(Qt::ApplicationModal);
    ui->setupUi(this);
    //setDataFromDefaut(m_data);
}

MainVisual::~MainVisual()
{
    //printVisualData(m_data);
    delete ui;
    delete m_data;
}

void MainVisual::setDataToShow(_MainVisualData *data)
{
    data->packet_id = NPR_PACKET_TYPE_VISUAL_DATA;

  //  qDebug()<<"setting visual data from received";
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


	//бортовые огни
	ui->SimulationRunning->setText((QString::number(data->SimulationRunning)));
	ui->SimulationReset->setText((QString::number(data->SimulationReset)));
	ui->Alpha->setText((QString::number(data->Alpha)));
	ui->Beta->setText((QString::number(data->Beta)));
	ui->wx->setText((QString::number(data->wx)));
	ui->wy->setText((QString::number(data->wy)));
	ui->wz->setText((QString::number(data->wz)));
	ui->nx->setText((QString::number(data->nx)));
	ui->ny->setText((QString::number(data->ny)));
	ui->nz->setText((QString::number(data->nz)));		
	ui->Vx_ef->setText((QString::number(data->Vx_ef)));
	ui->Vy_ef->setText((QString::number(data->Vy_ef)));
	ui->Vz_ef->setText((QString::number(data->Vz_ef)));
	ui->VCAS->setText((QString::number(data->VCAS)));
	ui->VTAS->setText((QString::number(data->VTAS)));
	ui->M->setText((QString::number(data->M)));

	ui->WOW_L->setText((QString::number(data->WOW_L)));
	ui->WOW_R->setText((QString::number(data->WOW_R)));
	ui->WOW_N->setText((QString::number(data->WOW_N)));
	ui->RadioAltitude->setText((QString::number(data->RadioAltitude)));
    this->update();
}

void MainVisual::on_okpb_clicked()
{
    //printVisualData(m_data);
    emit sendData(m_data);
    this->close();
}

void MainVisual::on_cancelPb_clicked()
{
     this->close();
}

void MainVisual::on_pangle_r_editingFinished()
{
    m_data->p_angle.R = ui->pangle_r->text().toFloat();
}

void MainVisual::on_pcoord_lat_editingFinished()
{
     m_data->p_coord.X = ui->pcoord_lat->text().toDouble();
}

void MainVisual::on_pcoord_lon_editingFinished()
{
    m_data->p_coord.Z = ui->pcoord_lon->text().toDouble();
}

void MainVisual::on_pcoord_h_editingFinished()
{
    m_data->p_coord.H = ui->pcoord_h->text().toFloat();

}

void MainVisual::on_pangle_c_editingFinished()
{
    m_data->p_angle.C = ui->pangle_c->text().toFloat();
}

void MainVisual::on_pangle_p_editingFinished()
{

    m_data->p_angle.P = ui->pangle_p->text().toFloat();
}

void MainVisual::on_n2_l_editingFinished()
{
      m_data->N2_L = ui->n2_l->text().toFloat();
}

void MainVisual::on_n2_r_editingFinished()
{
      m_data->N2_R = ui->n2_r->text().toFloat();
}

void MainVisual::on_flaps_editingFinished()
{
      m_data->Flaps = ui->flaps->text().toFloat();
}

void MainVisual::on_slats_editingFinished()
{
      m_data->Slats = ui->slats->text().toFloat();
}

void MainVisual::on_stabilizer_editingFinished()
{

    m_data->Stabilizer = ui->stabilizer->text().toFloat();
}

void MainVisual::on_elevator_l_editingFinished()
{
     m_data->Elevator_L = ui->elevator_l->text().toFloat();
}

void MainVisual::on_elevator_r_editingFinished()
{
     m_data->Elevator_R = ui->elevator_r->text().toFloat();
}

void MainVisual::on_aileron_l_editingFinished()
{
     m_data->Aileron_L = ui->aileron_l->text().toFloat();
}

void MainVisual::on_aileron_r_editingFinished()
{
     m_data->Aileron_R = ui->aileron_r->text().toFloat();
}

void MainVisual::on_rudder_editingFinished()
{
     m_data->Rudder = ui->rudder->text().toFloat();
}

void MainVisual::on_gear_n_editingFinished()
{
     m_data->Gear_N = ui->gear_n->text().toFloat();
}

void MainVisual::on_gear_l_editingFinished()
{
      m_data->Gear_L = ui->gear_l->text().toFloat();
}

void MainVisual::on_gear_r_editingFinished()
{
      m_data->Gear_R = ui->gear_r->text().toFloat();
}

void MainVisual::on_num_correct_editingFinished()
{
    QString s = ui->num_correct->text();
    qstrcpy(&m_data->num_correct , s.toLatin1());
}

void MainVisual::on_gear_stri_angle_editingFinished()
{
    m_data->Gear_SteeringAngle = ui->gear_stri_angle->text().toFloat();
}

void MainVisual::on_spoiler_lob_editingFinished()
{
    m_data->Spoiler_L_OB = ui->spoiler_lob->text().toFloat();
}

void MainVisual::on_spoiler_lce_editingFinished()
{
    m_data->Spoiler_L_CE = ui->spoiler_lce->text().toFloat();
}

void MainVisual::on_spoiler_lin_editingFinished()
{
    m_data->Spoiler_L_IN = ui->spoiler_lin->text().toFloat();
}

void MainVisual::on_spoiler_rob_editingFinished()
{
    m_data->Spoiler_R_OB = ui->spoiler_rob->text().toFloat();
}

void MainVisual::on_spoiler_rce_editingFinished()
{
      m_data->Spoiler_R_CE = ui->spoiler_rce->text().toFloat();
}

void MainVisual::on_spoiler_rin_editingFinished()
{
    m_data->Spoiler_R_IN = ui->spoiler_rin->text().toFloat();
}

void MainVisual::on_gr_spoiler_lob_editingFinished()
{
    m_data->GroudSpoiler_L_OB = ui->gr_spoiler_lob->text().toFloat();
}

void MainVisual::on_gr_spoiler_lin_editingFinished()
{
    m_data->GroudSpoiler_L_IB = ui->gr_spoiler_lin->text().toFloat();
}

void MainVisual::on_gr_spoiler_rob_editingFinished()
{
    m_data->GroudSpoiler_R_OB = ui->gr_spoiler_rob->text().toFloat();
}

void MainVisual::on_gr_spoiler_rin_editingFinished()
{
    m_data->GroudSpoiler_R_IB = ui->gr_spoiler_rin->text().toFloat();
}

void MainVisual::on_landing_lights_editingFinished()
{
    m_data->LandingLights = ui->landing_lights->text().toFloat();
}

void MainVisual::on_taxi_light_editingFinished()
{
    m_data->TaxiLight = ui->taxi_light->text().toFloat();

}

void MainVisual::on_runway_turnofflights_editingFinished()
{
    m_data->RunwayTurnoffLights = ui->runway_turnofflights->text().toFloat();
}

void MainVisual::on_nav_light_red_editingFinished()
{
    m_data->NavigationLightRed = ui->nav_light_red->text().toFloat();

}

void MainVisual::on_nav_light_green_editingFinished()
{
    m_data->NavigationLightGreen = ui->nav_light_green->text().toFloat();

}

void MainVisual::on_nav_light_white_editingFinished()
{
    m_data->NavigationLightWhite = ui->nav_light_white->text().toFloat();

}

void MainVisual::on_anticollosion_bec_red_editingFinished()
{
    m_data->AntiCollisionBeaconRed = ui->anticollosion_bec_red->text().toFloat();
}

void MainVisual::on_anticoll_bec_white_editingFinished()
{
    m_data->AntiCollisionBeaconWhite = ui->anticoll_bec_white->text().toFloat();
}

void MainVisual::on_internal_lights_editingFinished()
{
    m_data->InternalLights = ui->internal_lights->text().toFloat();

}


void MainVisual::setDataFromDefaut( _MainVisualData *set_data)
{
    set_data->packet_id = NPR_PACKET_TYPE_VISUAL_DATA;

    qDebug()<<"setting from visual data ";
    set_data->num_correct= ui->num_correct->text().toInt();
    set_data->p_coord.X = ui->pcoord_lat->text().toFloat();
    set_data->p_coord.Z= ui->pcoord_lon->text().toFloat();
    set_data->p_coord.H= ui->pcoord_h->text().toFloat();

    set_data->p_angle.C = ui->pangle_c->text().toFloat();
    set_data->p_angle.P= ui->pangle_p->text().toFloat();
    set_data->p_angle.R= ui->pangle_r->text().toFloat();


    //обороты
    set_data->N2_L = ui->n2_l->text().toFloat();
    set_data->N2_R = ui->n2_r->text().toFloat();

    //stabs, mechs
    set_data->Flaps = ui->flaps->text().toFloat();
    set_data->Stabilizer = ui->stabilizer->text().toFloat();
    set_data->Slats = ui->slats->text().toFloat();

    set_data->Elevator_L = ui->elevator_l->text().toFloat();
    set_data->Elevator_R = ui->elevator_r->text().toFloat();
    set_data->Aileron_L = ui->aileron_l->text().toFloat();
    set_data->Aileron_R = ui->aileron_r->text().toFloat();
    set_data->Rudder = ui->rudder->text().toFloat();

    set_data->Spoiler_L_CE = ui->spoiler_lce->text().toFloat();
    set_data->Spoiler_L_IN = ui->spoiler_lin->text().toFloat();
    set_data->Spoiler_L_OB = ui->spoiler_lob->text().toFloat();
    set_data->Spoiler_R_CE = ui->spoiler_rce->text().toFloat();
    set_data->Spoiler_R_IN = ui->spoiler_rin->text().toFloat();
    set_data->Spoiler_R_OB = ui->spoiler_rob->text().toFloat();

    set_data->GroudSpoiler_L_IB = ui->spoiler_lce->text().toFloat();
    set_data->GroudSpoiler_L_OB = ui->spoiler_lin->text().toFloat();
    set_data->GroudSpoiler_R_IB = ui->spoiler_lob->text().toFloat();
    set_data->GroudSpoiler_R_OB = ui->spoiler_rob->text().toFloat();

    set_data->Gear_N = ui->gear_n->text().toFloat();
    set_data->Gear_L = ui->gear_l->text().toFloat();
    set_data->Gear_R = ui->gear_r->text().toFloat();

    //бортовые огни

    set_data->LandingLights = ui->landing_lights->text().toFloat();
    set_data->TaxiLight = ui->taxi_light->text().toFloat();
    set_data->RunwayTurnoffLights = ui->runway_turnofflights->text().toFloat();

    set_data->NavigationLightGreen = ui->nav_light_green->text().toFloat();
    set_data->NavigationLightRed = ui->nav_light_red->text().toFloat();
    set_data->NavigationLightWhite = ui->nav_light_white->text().toFloat();

    set_data->AntiCollisionBeaconWhite = ui->anticoll_bec_white->text().toInt();
    set_data->AntiCollisionBeaconRed = ui->anticollosion_bec_red->text().toInt();
    set_data->InternalLights = ui->internal_lights->text().toInt();
	
	// ход расчетов
	set_data->SimulationRunning = ui->SimulationRunning->text().toFloat();               // Признак того, что моделирование (расчет) идёт
	set_data->SimulationReset = ui->SimulationReset->text().toFloat();                           // Признак перезапуска моделирования

	// дополнительная информация для графиков

	set_data->Alpha = ui->Alpha->text().toFloat();
	set_data->Beta = ui->Beta->text().toFloat();
	set_data->wx = ui->wx->text().toFloat();
	set_data->wy = ui->wy->text().toFloat();
	set_data->wz = ui->wz->text().toFloat();
	set_data->nx = ui->nx->text().toFloat();
	set_data->ny = ui->ny->text().toFloat();
	set_data->nz = ui->nz->text().toFloat();
	set_data->Vx_ef = ui->Vx_ef->text().toFloat();

	set_data->VCAS = ui->VCAS->text().toFloat();
	set_data->VTAS = ui->VTAS->text().toFloat();
	set_data->M = ui->M->text().toFloat();
	set_data->RadioAltitude = ui->RadioAltitude->text().toFloat();
	set_data->WOW_L = ui->WOW_L->text().toFloat();
	set_data->WOW_R = ui->WOW_R->text().toFloat();
	set_data->WOW_N = ui->WOW_N->text().toFloat();


	emit sendData(set_data);
}

void MainVisual::on_RadioAltitude_editingFinished()
{
     m_data->RadioAltitude = ui->RadioAltitude->text().toFloat();

}
