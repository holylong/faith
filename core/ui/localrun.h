#ifndef LOCALRUN_H
#define LOCALRUN_H

#include <QWidget>

namespace Ui {
class LocalRun;
}

class LocalRun : public QWidget
{
    Q_OBJECT

public:
    explicit LocalRun(QWidget *parent = nullptr);
    ~LocalRun();

private:
    Ui::LocalRun *ui;
};

#endif // LOCALRUN_H
