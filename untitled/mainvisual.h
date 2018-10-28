#ifndef MAINVISUAL_H
#define MAINVISUAL_H

#include <QWidget>
#include <meteo_struct.h>
namespace Ui {
class MainVisual;
}

class MainVisual : public QWidget
{
    Q_OBJECT

public:
    explicit MainVisual(QWidget *parent = nullptr);
    ~MainVisual();
public slots:
    void setData(_MainVisualData * visual_data );
private:
    Ui::MainVisual *ui;
};

#endif // MAINVISUAL_H
