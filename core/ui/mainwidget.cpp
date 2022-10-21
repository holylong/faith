#include "mainwidget.h"
#include "toptoolbar.h"
#include "settingsdialog.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QApplication>
#include <QDebug>
#include <QApplication>
#include <QScreen>

MainWidget::MainWidget(QWidget *parent)
    : MovingWidget(parent)
{
    setWindowFlags(Qt::FramelessWindowHint);
    resize(910, 537);

    InitUI();
    InitSigSlot();
}

void MainWidget::InitSigSlot()
{
    QObject::connect(_topToolBar->_btnClose, &QPushButton::clicked, [](){
        QCoreApplication::quit();
    });
    QObject::connect(_topToolBar->_btnMin, &QPushButton::clicked, [&](){
        setWindowState(Qt::WindowMinimized);
    });

    QObject::connect(_topToolBar->_btnResize, &QPushButton::clicked, [&](){
        qDebug() << "bmax:" << _bMax;
        if(_bMax){
            move(_orgPos);
            setFixedSize(_preSize);
        }else{
            _preSize = size();
            _orgPos = pos();
            move(0,0);
            setFixedSize(qApp->primaryScreen()->size());
        }
        _bMax = !_bMax;
    });
}


void MainWidget::InitUI()
{
    _settingsDialog = new SettingsDialog();

    _topToolBar = new TopToolBar();
    _topToolBar->setFixedSize(QSize(100,100));

    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(_topToolBar, 0, Qt::AlignRight);
    QVBoxLayout *mainLayout = new QVBoxLayout();



    mainLayout->addLayout(topLayout);

    setLayout(mainLayout);
}
