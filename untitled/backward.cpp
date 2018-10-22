#include "backward.h"

backwardW::backwardW(QWidget *parent) :
    QDialog(),
    ui(new Ui::backwardW),
    backw_data(new _DataToModel)
{
    backw_data->packet_id = 205;
    setWindowFlags(Qt::WindowStaysOnTopHint);
    ui->setupUi(this);
}

backwardW::~backwardW()
{
    delete ui;
    delete backw_data;
}

void backwardW::on_simulation_timeLE_editingFinished()
{
    backw_data->simulation_time = ui->simulation_timeLE->text().toDouble();
}

void backwardW::on_lat_le_editingFinished()
{
    backw_data->p_coord.X = ui->lat_le->text().toDouble();
}

void backwardW::on_lon_le_editingFinished()
{
    backw_data->p_coord.Z = ui->lon_le->text().toDouble();
}

void backwardW::on_h_le_editingFinished()
{
    backw_data->p_coord.H = ui->h_le->text().toFloat();
}

void backwardW::on_buttonBox_accepted()
{
    emit sendData(this->backw_data);
    this->close();
}

void backwardW::writeDataToFields(_DataToModel *_data)
{
    backw_data->packet_id = _data->packet_id;
    backw_data->p_coord.H = _data->p_coord.H ;
    backw_data->p_coord.X  = _data->p_coord.X ;
    backw_data->p_coord.Z  = _data->p_coord.Z;
    backw_data->simulation_time = _data->simulation_time;
}
