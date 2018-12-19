#include "sound_form.h"
#include "ui_sound_form.h"

#include <qsettings.h>

Sound_form::Sound_form(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Sound_form)
{
	ui->setupUi(this);
	//sound_settings = new SOUND_FUNC_SETTINGS;
	setWindowModality(Qt::ApplicationModal);

	readSettings();
}

Sound_form::~Sound_form()
{
	//delete 		  sound_settings;
	delete ui;
}

void Sound_form::setLimitsToLines()
{
	//ui->loudness_abrks->setValidator(new QDoubleValidatorPrivate(0, 100)); 

}
void Sound_form::setLimitsToScrolls()
{

}

void Sound_form::setScrolls()
{
	ui->loudness_idle_scroll->setValue(ui->loudness_idle->text().toInt());
	ui->loudness_abrksScroll->setValue(ui->loudness_abrks->text().toInt());
	ui->loudness_beepScr->setValue(ui->loudness_beep->text().toInt());
	ui->loudness_flapsScroll->setValue(ui->loudness_flaps->text().toInt());
	ui->loudness_lgScroll->setValue(ui->loudness_lg->text().toInt());
	ui->loudness_max_SCroll->setValue(ui->loudness_max->text().toInt());
	ui->loudness_touchdown_l_rScroll->setValue(ui->loudness_touchdown_l_r->text().toInt());
	ui->loudness_touchdown_nscr->setValue(ui->loudness_touchdown_n->text().toInt());
	ui->ratelim_lg_lowerScroll->setValue(ui->ratelim_lg_lower->text().toInt());
	ui->ratelim_lg_upperScroll->setValue(ui->ratelim_lg_upper->text().toInt());

}

void Sound_form::readSettings()
{
	QSettings settings("bird_wrapper.ini", QSettings::IniFormat);

	settings.beginGroup("Sound");

	ui->shutdown_beep->setText(settings.value("shutdown_beep", 5).toString());
	ui->loudness_abrks->setText(settings.value("loudness_abrks", 10).toString());
	ui->loudness_flaps->setText(settings.value("loudness_flaps", 10).toString());
	ui->loudness_idle->setText(settings.value("loudness_idle", 10).toString());
	ui->loudness_lg->setText(settings.value("loudness_lg", 10).toString());
	ui->loudness_max->setText(settings.value("loudness_max", 10).toString());
	ui->loudness_touchdown_l_r->setText(settings.value("loudness_touchdown_l_r", 10).toString());
	ui->loudness_touchdown_n->setText(settings.value("loudness_touchdown_n", 10).toString());
	ui->ratelim_lg_lower->setText(settings.value("ratelim_lg_lower", 10).toString());
	ui->ratelim_lg_upper->setText(settings.value("ratelim_lg_upper", 10).toString());

	settings.endGroup();
	setScrolls();

}

void Sound_form::writeSettings()
{
	QSettings settings("bird_wrapper.ini", QSettings::IniFormat);

	settings.beginGroup("Sound");

	settings.setValue("geometry", this->geometry());
	settings.setValue("shutdown_beep", ui->shutdown_beep->text());
	settings.setValue("loudness_abrks", ui->loudness_abrks->text());
	settings.setValue("loudness_flaps", ui->loudness_flaps->text());
	settings.setValue("loudness_idle", ui->loudness_idle->text());
	settings.setValue("loudness_lg", ui->loudness_lg->text());
	settings.setValue("loudness_max", ui->loudness_max->text());
	settings.setValue("loudness_touchdown_l_r", ui->loudness_touchdown_l_r->text());
	settings.setValue("loudness_touchdown_n", ui->loudness_touchdown_n->text());
	settings.setValue("ratelim_lg_lower", ui->ratelim_lg_lower->text());
	settings.setValue("ratelim_lg_upper", ui->ratelim_lg_upper->text());

	settings.endGroup();
}

void Sound_form::showEvent(QShowEvent * ev)
{
	readSettings();
}

void Sound_form::hideEvent(QHideEvent * ev)
{
	writeSettings();
}

void Sound_form::on_shutdown_beep_editingFinished()
{
	sound_settings.shutdown_counter = ui->shutdown_beep->text().toUInt();
	emit sendData(sound_settings);

}

void Sound_form::on_loudness_idle_editingFinished()
{
	double loudness = ui->loudness_idle->text().toDouble();
	sound_settings.loudness_idle = loudness;
	ui->loudness_idle_scroll->setValue(loudness);
}

void Sound_form::on_loudness_max_editingFinished()
{
	double loudness = ui->loudness_max->text().toDouble();
	sound_settings.loudness_max = loudness;
	ui->loudness_max_SCroll->setValue(loudness);
}

void Sound_form::on_loudness_flaps_editingFinished()
{
	double loudness = ui->loudness_flaps->text().toDouble();
	sound_settings.loudness_flaps = loudness;
	ui->loudness_flapsScroll->setValue(loudness);
}

void Sound_form::on_loudness_abrks_editingFinished()
{
	double loudness = ui->loudness_abrks->text().toDouble();
	sound_settings.loudness_abrks = loudness;
	ui->loudness_abrksScroll->setValue(loudness);
}

void Sound_form::on_loudness_lg_editingFinished()
{
	double loudness = ui->loudness_lg->text().toDouble();
	sound_settings.loudness_lg = loudness;
	ui->loudness_lgScroll->setValue(loudness);
}

void Sound_form::on_ratelim_lg_lower_editingFinished()
{
	double loudness = ui->ratelim_lg_lower->text().toDouble();
	sound_settings.lg_down_time = loudness;
	ui->ratelim_lg_lowerScroll->setValue(loudness);
}

void Sound_form::on_ratelim_lg_upper_editingFinished()
{
	double loudness = ui->ratelim_lg_upper->text().toDouble();
	sound_settings.lg_up_time = loudness;
	ui->ratelim_lg_upperScroll->setValue(loudness);
}

void Sound_form::on_loudness_touchdown_l_r_editingFinished()
{
	double loudness = ui->loudness_touchdown_l_r->text().toDouble();
	sound_settings.loudness_touchdown_l_r = loudness;
	ui->loudness_touchdown_l_rScroll->setValue(loudness);
}

void Sound_form::on_loudness_touchdown_n_editingFinished()
{
	double loudness = ui->loudness_touchdown_n->text().toDouble();
	sound_settings.loudness_touchdown_n = loudness;
	ui->loudness_touchdown_nscr->setValue(loudness);
}

void Sound_form::on_loudness_beep_editingFinished()
{
	double loudness = ui->loudness_beep->text().toDouble();
	sound_settings.loudness_beep = loudness;
	ui->loudness_beepScr->setValue(loudness);
}

///scrolls
void Sound_form::on_loudness_beepScr_valueChanged(int value)
{
	double val = ui->loudness_beepScr->value();
	ui->loudness_beep->setText(QString::number(val));
	sound_settings.loudness_beep = val;
}

void Sound_form::on_loudness_touchdown_nscr_valueChanged(int value)
{
	double val = ui->loudness_touchdown_nscr->value();
	ui->loudness_touchdown_n->setText(QString::number(val));
	sound_settings.loudness_touchdown_n = val;
	emit sendData(sound_settings);

}

void Sound_form::on_loudness_touchdown_l_rScroll_valueChanged(int value)
{
	double val = ui->loudness_touchdown_l_rScroll->value();
	ui->loudness_touchdown_l_r->setText(QString::number(val));
	sound_settings.loudness_touchdown_l_r = val;
	emit sendData(sound_settings);

}

void Sound_form::on_ratelim_lg_upperScroll_valueChanged(int value)
{
	double val = ui->ratelim_lg_upperScroll->value();
	ui->ratelim_lg_upper->setText(QString::number(val));
	sound_settings.lg_up_time = val;
	emit sendData(sound_settings);

}

void Sound_form::on_ratelim_lg_lowerScroll_valueChanged(int value)
{
	double val = ui->ratelim_lg_lowerScroll->value();
	ui->ratelim_lg_lower->setText(QString::number(val));
	sound_settings.lg_down_time = val;
	emit sendData(sound_settings);

}

void Sound_form::on_loudness_lgScroll_valueChanged(int value)
{
	double val = ui->loudness_lgScroll->value();
	ui->loudness_lg->setText(QString::number(val));
	sound_settings.loudness_lg = val;
	emit sendData(sound_settings);

}

void Sound_form::on_loudness_abrksScroll_valueChanged(int value)
{
	double val = ui->loudness_abrksScroll->value();
	ui->loudness_abrks->setText(QString::number(val));
	sound_settings.loudness_abrks = val;
	emit sendData(sound_settings);

}

void Sound_form::on_loudness_flapsScroll_valueChanged(int value)
{
	double val = ui->loudness_flapsScroll->value();
	ui->loudness_flaps->setText(QString::number(val));
	sound_settings.loudness_flaps = val;
	emit sendData(sound_settings);

}

void Sound_form::on_loudness_max_SCroll_valueChanged(int value)
{
	double val = ui->loudness_max_SCroll->value();
	ui->loudness_max->setText(QString::number(val));
	sound_settings.loudness_max = val;
	emit sendData(sound_settings);

}

void Sound_form::on_loudness_idle_scroll_valueChanged(int value)
{
	double val = ui->loudness_idle_scroll->value();
	ui->loudness_idle->setText(QString::number(val));
	sound_settings.loudness_idle = val;
	emit sendData(sound_settings);

}

void Sound_form::on_ok_pb_clicked()
{
	emit sendData(sound_settings);
	this->close();
}

void Sound_form::on_cancel_pb_clicked()
{
	this->close();
}
