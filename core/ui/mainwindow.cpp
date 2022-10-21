#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPushButton>
#include "settingsdialog.h"
#include "localrun.h"
#include <QStackedLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setWindowTitle("");
    setWindowFlags(Qt::FramelessWindowHint);
    ui->setupUi(this);
    setStyleSheet("border-radius:5px;");

    // _settingsDialog = new SettingsDialog(this);
    // QObject::connect(ui->btnSettings, &QPushButton::clicked, [=] { _settingsDialog->show(); });

    // _localRun = new LocalRun();
    // QObject::connect(ui->btnRun, &QPushButton::clicked, [=]{_localRun->show();});
}

void MainWindow::InitLayout()
{

}

MainWindow::~MainWindow()
{
    delete ui;
}

