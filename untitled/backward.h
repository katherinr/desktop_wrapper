#ifndef BACKWARD_H
#define BACKWARD_H
#include "ui_backward.h"
#include "meteo_struct.h"
#endif // BACKWARD_H
namespace Ui {
class backwardW;
}

class backwardW : public QDialog
{
    Q_OBJECT
public:
    explicit backwardW(QWidget *parent = nullptr);
    ~backwardW();
	void setCurrentTime(QTime *time);
	void updateBackwardPacket(_MainVisualData data);
	void readDefault(_DataToModel * _data);
private slots:

    void on_lat_le_editingFinished();

    void on_lon_le_editingFinished();

    void on_h_le_editingFinished();

    void on_buttonBox_accepted();
public slots:
    void writeDataToFields(_DataToModel *data);
private:
    Ui::backwardW *ui;
    _DataToModel *backw_data;
signals:
    void  sendData(_DataToModel *data);
};
