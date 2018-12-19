#ifndef SOUND_FORM_H
#define SOUND_FORM_H
#include "elbird_sound_data.h"
#include <QWidget>

namespace Ui {
class Sound_form;
}

class Sound_form : public QWidget
{
    Q_OBJECT

public:
    explicit Sound_form(QWidget *parent = nullptr);
    ~Sound_form();

private slots:
    void on_shutdown_beep_editingFinished();

    void on_loudness_idle_editingFinished();

    void on_loudness_max_editingFinished();

    void on_loudness_flaps_editingFinished();

    void on_loudness_abrks_editingFinished();

    void on_loudness_lg_editingFinished();

    void on_ratelim_lg_lower_editingFinished();

    void on_ratelim_lg_upper_editingFinished();

    void on_loudness_touchdown_l_r_editingFinished();

    void on_loudness_touchdown_n_editingFinished();

    void on_loudness_beep_editingFinished();

    void on_loudness_beepScr_valueChanged(int value);

    void on_loudness_touchdown_nscr_valueChanged(int value);

    void on_loudness_touchdown_l_rScroll_valueChanged(int value);

    void on_ratelim_lg_upperScroll_valueChanged(int value);

    void on_ratelim_lg_lowerScroll_valueChanged(int value);

    void on_loudness_lgScroll_valueChanged(int value);

    void on_loudness_abrksScroll_valueChanged(int value);

    void on_loudness_flapsScroll_valueChanged(int value);

    void on_loudness_max_SCroll_valueChanged(int value);

    void on_loudness_idle_scroll_valueChanged(int value);

	void on_cancel_pb_clicked();

    void on_ok_pb_clicked();
	void setLimitsToLines();
	void setLimitsToScrolls();
	void setScrolls();
	void readSettings();
	void writeSettings();

private:
    Ui::Sound_form *ui;
    SOUND_FUNC_SETTINGS sound_settings;
protected:
	void showEvent(QShowEvent * ev) override;
	void hideEvent(QHideEvent * ev) override;

signals:
    void sendData(const SOUND_FUNC_SETTINGS &data);
};

#endif // SOUND_FORM_H
