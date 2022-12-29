#ifndef FAITHFLOATBAR_H
#define FAITHFLOATBAR_H

#include <QWidget>
#include "movingwidget.h"

class FaithFloatBar : public MovingWidget
{
    Q_OBJECT
public:
    explicit FaithFloatBar(MovingWidget *parent = nullptr);

signals:

};

#endif // FAITHFLOATBAR_H
