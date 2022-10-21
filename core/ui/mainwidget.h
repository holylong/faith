#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "movingwidget.h"
#include <QSize>

class QStackedLayout;
class QToolBar;
class SettingsDialog;
class TopToolBar;

class MainWidget : public MovingWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = nullptr);

private:
    void InitUI();
    void InitSigSlot();

signals:


private:
    SettingsDialog *_settingsDialog;

    QToolBar       *_mainToolBar;
    QStackedLayout *_mainLayout;
    TopToolBar     *_topToolBar;

    QSize           _preSize;
    QPoint          _orgPos;
    bool            _bMax{false};
};

#endif // MAINWIDGET_H
