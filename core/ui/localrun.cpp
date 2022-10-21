#include "localrun.h"
#include "ui_localrun.h"

LocalRun::LocalRun(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LocalRun)
{
    ui->setupUi(this);

    QObject::connect(ui->btnCancel, &QPushButton::clicked, [&]{this->hide();});
}

LocalRun::~LocalRun()
{
    delete ui;
}
