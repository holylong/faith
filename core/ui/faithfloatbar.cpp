#include "faithfloatbar.h"
#include <QHBoxLayout>
#include <QToolBar>
#include <QAction>
#include <QIcon>

FaithFloatBar::FaithFloatBar(MovingWidget *parent) : MovingWidget(parent)
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::SplashScreen);
    setFixedSize(400, 80);
    move(100,100);
}
