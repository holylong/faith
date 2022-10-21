#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <faith/config.h>

class SettingsDialog;
class LocalRun;
class QStackedLayout;
class QToolBar;
class QListWidget;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class FAITH_EXPORT MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void InitLayout();

private:
    Ui::MainWindow *ui;

    SettingsDialog *_settingsDialog;
    LocalRun       *_localRun;

    QToolBar       *_mainToolBar;
    QStackedLayout *_mainLayout;
};
#endif // MAINWINDOW_H
