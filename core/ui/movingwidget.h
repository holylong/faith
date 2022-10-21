#ifndef MOVINGWIDGET_H
#define MOVINGWIDGET_H

#include <QWidget>
#include <QPoint>

class MovingWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MovingWidget(QWidget *parent = nullptr);

protected:
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);

signals:


private:
    QPoint    _lastPos;
};

#endif // MOVINGWIDGET_H
