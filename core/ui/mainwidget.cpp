#include "mainwidget.h"
#include "chatwidget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QApplication>
#include <QDebug>
#include <QApplication>
#include <QScreen>
#include <QFile>
#include <QStackedWidget>
#include <QToolBar>
#include <QAction>
#include <QLabel>

#include "toptoolbar.h"
#include "settingsdialog.h"
#include "animationutil.h"
#include "roomwidget.h"
#include "chatwidget.h"
#include "aboutwidget.h"
#include "settingswidget.h"
#include "taskwidget.h"
#include "statisticwidget.h"
#include "faithfloatbar.h"
#include "config.h"

MainWidget::MainWidget(QWidget *parent)
    : MovingWidget(parent)
{
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground, true);
    resize(910, 537);

    InitUI();
    InitFloatBar();
    InitSigSlot();
    LoadStyleSheet();
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
//            _mainWidget->setFixedSize(qApp->primaryScreen()->size());
        }
        _bMax = !_bMax;
    });
}

void MainWidget::LoadStyleSheet()
{
    QFile file(":/res/BasicTheme.qss");
    file.open(QIODevice::ReadOnly);
    QString cstyle = file.readAll();
    qApp->setStyleSheet(cstyle);

//    setStyleSheet("QWidget#mainWidget{background-color:red;border-image:url(:/res/city_1.jpg);border-radius:5px;}");
}

void MainWidget::InitMainToolBar()
{
    _mainToolBar = new QToolBar();
    _mainToolBar->setOrientation(Qt::Vertical);

    QAction *chatAction = new QAction(QObject::tr("聊天"));
    chatAction->setIcon(QIcon(QPixmap(":/res/chat_blue.svg").scaled(500,500)));
    QAction *roomAction = new QAction(QObject::tr("会议"));
    roomAction->setIcon(QIcon(QPixmap(":/res/meetup_blue.svg").scaled(500,500)));
    QAction *chartAction = new QAction(QObject::tr("分析"));
    chartAction->setIcon(QIcon(QPixmap(":/res/chart_blue.svg").scaled(500,500)));
    QAction *settingAction = new QAction(QObject::tr("设置"));
    settingAction->setIcon(QIcon(QPixmap(":/res/settings.svg").scaled(500,500)));
    QAction *taskAction = new QAction(QObject::tr("任务"));
    taskAction->setIcon(QIcon(QPixmap(":/res/task.svg").scaled(500,500)));
    QAction *aboutAction = new QAction(QObject::tr("关于"));
    aboutAction->setIcon(QIcon(QPixmap(":/res/about_blue.svg").scaled(500,500)));

    QObject::connect(chatAction, &QAction::triggered, [&]{
        qDebug() << "chat view";
        if(0 == _stackedWidget->currentIndex())
            return;
        AnimationUtil::AnimationDoorOpen(_stackedWidget, 0);
    });
    QObject::connect(roomAction, &QAction::triggered, [&]{
        if(1 == _stackedWidget->currentIndex())
            return;
        AnimationUtil::AnimationDoorOpen(_stackedWidget, 1);
    });

    QObject::connect(chartAction, &QAction::triggered, [&]{
        if(2 == _stackedWidget->currentIndex())
            return;
        AnimationUtil::AnimationDoorOpen(_stackedWidget, 2);
    });

    QObject::connect(settingAction, &QAction::triggered, [&]{
        if(3 == _stackedWidget->currentIndex())
            return;
        AnimationUtil::AnimationWndDrop(_stackedWidget, 3);
    });

    QObject::connect(taskAction, &QAction::triggered, [&]{
        if(4 == _stackedWidget->currentIndex())
            return;
        AnimationUtil::AnimationWndDown(_stackedWidget, 4);
    });

    QObject::connect(aboutAction, &QAction::triggered, [&]{
        if(5 == _stackedWidget->currentIndex())
            return;
        AnimationUtil::AnimationWndShake(_stackedWidget, 5);
    });

    _mainToolBar->addAction(chatAction);
    _mainToolBar->addAction(roomAction);
    _mainToolBar->addAction(chartAction);
    _mainToolBar->addAction(settingAction);
    _mainToolBar->addAction(taskAction);
    _mainToolBar->addAction(aboutAction);

    _mainToolBar->setIconSize(QSize(width()/20,width()/20));
    _mainToolBar->layout()->setMargin(5);
    _mainToolBar->layout()->setSpacing(5);

    _ctxLayout->addWidget(_mainToolBar);
}

void MainWidget::InitAboutUI()
{
    _aboutWidget = new AboutWidget();
    _stackedWidget->addWidget(_aboutWidget);
}

void MainWidget::InitSettingsUI()
{
    _settingsWidget = new SettingsWidget(_stackedWidget);
    _stackedWidget->addWidget(_settingsWidget);
    if(_settingsWidget->objectName().isEmpty())
            _settingsWidget->setObjectName("_settingsWidget");
}

void MainWidget::InitStatisticUI()
{
    _statisticWidget = new StatisticWidget();
    _stackedWidget->addWidget(_statisticWidget);
}

void MainWidget::InitConfig()
{
    Config::Instance()->Display();
}

void MainWidget::InitChatUI()
{
    _chatWidget = new ChatWidget();
    _stackedWidget->addWidget(_chatWidget);
}

void MainWidget::InitFloatBar()
{
    _floatBar = new FaithFloatBar();
    _floatBar->show();
}

void MainWidget::SwitchFloatBar()
{
    if(_floatBar->isHidden())_floatBar->show();
    else _floatBar->hide();
}

void MainWidget::InitTaskUI()
{
    _taskWidget = new TaskWidget();
    _stackedWidget->addWidget(_taskWidget);
}

void MainWidget::InitRoomUI()
{
    _roomWidget = new RoomWidget();
    _stackedWidget->addWidget(_roomWidget);
}

void MainWidget::InitUI()
{
    resize(910, 640);
    _ctxLayout = new QHBoxLayout();
    _topLayout = new QHBoxLayout();
    _mainLayout = new QVBoxLayout();

    _topToolBar = new TopToolBar();
    QLabel *title = new QLabel;
    title->setText("Faith");
    QFont font;
    font.setPointSize(15);
    font.setFamily("MicrosoftYaHei");
    title->setFont(font);
    _topLayout->addWidget(title, 0, Qt::AlignRight);
    _topLayout->addWidget(_topToolBar, 0, Qt::AlignRight);
    _topLayout->setStretch(0, 5);
    _topLayout->setStretch(1, 4);
    _topLayout->setMargin(0);
    _topLayout->setContentsMargins(0,0,0,0);
    _topLayout->setSpacing(0);

//    QWidget *upWidget = new QWidget();
//    upWidget->setFixedHeight(50);
//    upWidget->setFixedWidth(100);
//    upWidget->setLayout(_topLayout);
    _mainLayout->addLayout(_topLayout);
//    _mainLayout->addWidget(upWidget, Qt::AlignRight);
//    _mainLayout->setMargin(0);

//    _settingsDialog = new SettingsDialog();
    _stackedWidget = new QStackedWidget(this);

    InitMainToolBar();
    InitChatUI();
    InitRoomUI();
    InitStatisticUI();
    InitSettingsUI();
    InitTaskUI();
    InitAboutUI();

    _ctxLayout->addWidget(_stackedWidget);
    _mainLayout->addLayout(_ctxLayout);
//    _mainLayout->setStretch(0, 1);
//    _mainLayout->setStretch(1, 50);

    _mainWidget = new QWidget();
    _mainWidget->setLayout(_mainLayout);
    if(_mainWidget->objectName().isEmpty())
            _mainWidget->setObjectName("_mainWidget");

    QHBoxLayout *ttLayout = new QHBoxLayout();
    ttLayout->setMargin(0);
    ttLayout->addWidget(_mainWidget);

    setLayout(ttLayout);
}
