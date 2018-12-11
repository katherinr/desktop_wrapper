#include "sound_form.h"
#include "ui_sound_form.h"

Sound_form::Sound_form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Sound_form)
{
    ui->setupUi(this);
	sound_settings = new SOUND_FUNC_SETTINGS;
	setWindowModality(Qt::ApplicationModal);
}

Sound_form::~Sound_form()
{
	delete 		  sound_settings;
    delete ui;
}

void Sound_form::setLimitsToLines()
{
	//ui->loudness_abrks->setValidator(new QDoubleValidatorPrivate(0, 100)); 

}
void Sound_form::setLimitsToScrolls()
{

}
void Sound_form::on_shutdown_beep_editingFinished()
{
      sound_settings->loudness_idle = ui->shutdown_beep->text().toDouble();
}

void Sound_form::on_loudness_idle_editingFinished()
{
    double loudness=ui->loudness_idle->text().toDouble();
    sound_settings->loudness_idle = loudness;
    ui->loudness_idle_scroll->setValue(loudness);
}

void Sound_form::on_loudness_max_editingFinished()
{
    double loudness=ui->loudness_max->text().toDouble();
    sound_settings->loudness_max = loudness;
    ui->loudness_max_SCroll->setValue(loudness);
}

void Sound_form::on_loudness_flaps_editingFinished()
{
    double loudness=ui->loudness_flaps->text().toDouble();
    sound_settings->loudness_flaps = loudness;
    ui->loudness_flapsScroll->setValue(loudness);
}

void Sound_form::on_loudness_abrks_editingFinished()
{
    double loudness=ui->loudness_abrks->text().toDouble();
    sound_settings->loudness_abrks = loudness;
    ui->loudness_abrksScroll->setValue(loudness);
}

void Sound_form::on_loudness_lg_editingFinished()
{
    double loudness=ui->loudness_lg->text().toDouble();
    sound_settings->loudness_lg = loudness;
    ui->loudness_lgScroll->setValue(loudness);
}

void Sound_form::on_ratelim_lg_lower_editingFinished()
{
    double loudness=ui->ratelim_lg_lower->text().toDouble();
    sound_settings->ratelim_lg_lower = loudness;
    ui->ratelim_lg_lowerScroll->setValue(loudness);
}

void Sound_form::on_ratelim_lg_upper_editingFinished()
{
    double loudness=ui->ratelim_lg_upper->text().toDouble();
    sound_settings->ratelim_lg_upper = loudness;
    ui->ratelim_lg_upperScroll->setValue(loudness);
}

void Sound_form::on_loudness_touchdown_l_r_editingFinished()
{
    double loudness=ui->loudness_touchdown_l_r->text().toDouble();
    sound_settings->loudness_touchdown_l_r = loudness;
    ui->loudness_touchdown_l_rScroll->setValue(loudness);
}

void Sound_form::on_loudness_touchdown_n_editingFinished()
{
    double loudness=ui->loudness_touchdown_n->text().toDouble();
    sound_settings->loudness_touchdown_n = loudness;
    ui->loudness_touchdown_nscr->setValue(loudness);
}

void Sound_form::on_loudness_beep_editingFinished()
{
    double loudness=ui->loudness_beep->text().toDouble();
    sound_settings->loudness_beep = loudness;
    ui->loudness_beepScr->setValue(loudness);
}

///scrolls
void Sound_form::on_loudness_beepScr_valueChanged(int value)
{
    double val = ui->loudness_beepScr->value();
    ui->loudness_beep->setText(QString::number(val));
    sound_settings->loudness_beep=val;
}

void Sound_form::on_loudness_touchdown_nscr_valueChanged(int value)
{
    double val = ui->loudness_touchdown_nscr->value();
    ui->loudness_touchdown_n->setText(QString::number(val));
    sound_settings->loudness_touchdown_n=val;
}

void Sound_form::on_loudness_touchdown_l_rScroll_valueChanged(int value)
{
    double val = ui->loudness_touchdown_l_rScroll->value();
    ui->loudness_touchdown_l_r->setText(QString::number(val));
    sound_settings->loudness_touchdown_l_r=val;
}

void Sound_form::on_ratelim_lg_upperScroll_valueChanged(int value)
{
    double val = ui->ratelim_lg_upperScroll->value();
    ui->ratelim_lg_upper->setText(QString::number(val));
    sound_settings->ratelim_lg_upper=val;
}

void Sound_form::on_ratelim_lg_lowerScroll_valueChanged(int value)
{
    double val = ui->ratelim_lg_lowerScroll->value();
    ui->ratelim_lg_lower->setText(QString::number(val));
    sound_settings->ratelim_lg_lower=val;
}

void Sound_form::on_loudness_lgScroll_valueChanged(int value)
{
    double val = ui->loudness_lgScroll->value();
    ui->loudness_lg->setText(QString::number(val));
    sound_settings->loudness_lg=val;
}

void Sound_form::on_loudness_abrksScroll_valueChanged(int value)
{
    double val = ui->loudness_abrksScroll->value();
    ui->loudness_abrks->setText(QString::number(val));
    sound_settings->loudness_abrks=val;
}

void Sound_form::on_loudness_flapsScroll_valueChanged(int value)
{
    double val = ui->loudness_flapsScroll->value();
    ui->loudness_flaps->setText(QString::number(val));
    sound_settings->loudness_flaps=val;
}

void Sound_form::on_loudness_max_SCroll_valueChanged(int value)
{
    double val = ui->loudness_max_SCroll->value();
    ui->loudness_max->setText(QString::number(val));
    sound_settings->loudness_max=val;
}

void Sound_form::on_loudness_idle_scroll_valueChanged(int value)
{
    double val = ui->loudness_idle_scroll->value();
    ui->loudness_idle->setText(QString::number(val));
    sound_settings->loudness_idle=val;
}

void Sound_form::on_ok_pb_clicked()
{
    emit sendData(sound_settings);
    this->close();
}
