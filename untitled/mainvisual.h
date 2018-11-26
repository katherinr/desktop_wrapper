#ifndef MAINVISUAL_H
#define MAINVISUAL_H

#include <QDialog>
#include "meteo_struct.h"
namespace Ui {
class MainVisual;
}

class MainVisual : public QDialog
{
    Q_OBJECT

public:
    explicit MainVisual(QWidget *parent = nullptr);
    ~MainVisual();
	void setDataFromDefaut(_MainVisualData *set_data);
    void setDataToShow(_MainVisualData * visual_data );

private slots:
    void on_okpb_clicked();
    void on_cancelPb_clicked();
    void on_pangle_r_editingFinished();

    void on_pcoord_lat_editingFinished();

    void on_pcoord_lon_editingFinished();

    void on_pcoord_h_editingFinished();

    void on_pangle_c_editingFinished();

    void on_pangle_p_editingFinished();

    void on_n2_l_editingFinished();

    void on_n2_r_editingFinished();

    void on_flaps_editingFinished();

    void on_slats_editingFinished();

    void on_stabilizer_editingFinished();

    void on_elevator_l_editingFinished();

    void on_elevator_r_editingFinished();

    void on_aileron_l_editingFinished();

    void on_aileron_r_editingFinished();

    void on_rudder_editingFinished();

    void on_gear_n_editingFinished();

    void on_gear_l_editingFinished();

    void on_gear_r_editingFinished();

    void on_num_correct_editingFinished();

    void on_gear_stri_angle_editingFinished();

    void on_spoiler_lob_editingFinished();

    void on_spoiler_lce_editingFinished();

    void on_spoiler_lin_editingFinished();

    void on_spoiler_rob_editingFinished();

    void on_spoiler_rce_editingFinished();

    void on_spoiler_rin_editingFinished();

    void on_gr_spoiler_lob_editingFinished();

    void on_gr_spoiler_lin_editingFinished();

    void on_gr_spoiler_rob_editingFinished();

    void on_gr_spoiler_rin_editingFinished();

    void on_landing_lights_editingFinished();

    void on_taxi_light_editingFinished();

    void on_runway_turnofflights_editingFinished();

    void on_nav_light_red_editingFinished();

    void on_nav_light_green_editingFinished();

    void on_nav_light_white_editingFinished();

    void on_anticollosion_bec_red_editingFinished();

    void on_anticoll_bec_white_editingFinished();

    void on_internal_lights_editingFinished();


    void on_RadioAltitude_editingFinished();

signals:
    void sendData(_MainVisualData *);		
	void dataUpdated(_MainVisualData *);
private:
    Ui::MainVisual *ui;
    _MainVisualData *m_data;

};

#endif // MAINVISUAL_H
