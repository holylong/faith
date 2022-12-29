#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "movingwidget.h"
#include <QSize>

class QStackedLayout;
class QStackedWidget;
class QToolBar;
class QHBoxLayout;
class QVBoxLayout;

class StatisticWidget;
class AboutWidget;
class SettingsWidget;
class RoomWidget;
class ChatWidget;
class SettingsDialog;
class TopToolBar;
class FaithFloatBar;


class MainWidget : public MovingWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = nullptr);

private:
    void InitUI();
    void InitMainToolBar();
    void InitSigSlot();
    void LoadStyleSheet();

    void InitAboutUI();
    void InitSettingsUI();
    void InitStatisticUI();
    void InitChatUI();
    void InitRoomUI();
    void InitConfig();
    void InitFloatBar();
    void SwitchFloatBar();

signals:


private:
    SettingsDialog *_settingsDialog;

    QToolBar       *_mainToolBar;
//    QStackedWidget *_mainWidget;
    QStackedWidget *_stackedWidget;
    TopToolBar     *_topToolBar;

    AboutWidget    *_aboutWidget;
    SettingsWidget *_settingsWidget;
    StatisticWidget*_statisticWidget;
    ChatWidget     *_chatWidget;
    RoomWidget     *_roomWidget;
    QWidget        *_mainWidget;
    FaithFloatBar  *_floatBar;

    QHBoxLayout    *_topLayout;
    QHBoxLayout    *_ctxLayout;
    QVBoxLayout    *_mainLayout;

    QSize           _preSize;
    QPoint          _orgPos;
    bool            _bMax{false};
};

#endif // MAINWIDGET_H
