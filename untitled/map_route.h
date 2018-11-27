#ifndef MAP_ROUTE_H
#define MAP_ROUTE_H

#include <QDialog>

namespace Ui {
class map_route;
}

class map_route : public QDialog
{
    Q_OBJECT

public:
    explicit map_route(QWidget *parent = nullptr);
    ~map_route();

private:
    Ui::map_route *ui;
};

#endif // MAP_ROUTE_H
