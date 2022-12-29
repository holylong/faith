#include "faithfloatbar.h"
#include <QHBoxLayout>
#include <QToolBar>
#include <QAction>
#include <QIcon>

FaithFloatBar::FaithFloatBar(MovingWidget *parent) : MovingWidget(parent)
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::SplashScreen);
    setAttribute(Qt::WA_TranslucentBackground, true);
    setFixedSize(400, 80);
    setStyleSheet("{border-radius:10px; background-color: rgb(125,15,125)}");
    move(100,100);
}
