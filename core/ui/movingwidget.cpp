#include "movingwidget.h"
#include <QMouseEvent>

MovingWidget::MovingWidget(QWidget *parent) : QWidget(parent)
{

}

void MovingWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->globalX() - _lastPos.x();
    int dy = event->globalY() - _lastPos.y();

    _lastPos = event->globalPos();

    move(x() + dx, y() + dy);
}


void MovingWidget::mousePressEvent(QMouseEvent *event)
{
   _lastPos = event->globalPos();
}
