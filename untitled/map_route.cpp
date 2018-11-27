#include "map_route.h"
#include "ui_map_route.h"

map_route::map_route(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::map_route)
{
    ui->setupUi(this);
}

map_route::~map_route()
{
    delete ui;
}
