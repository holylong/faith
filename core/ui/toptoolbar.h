#ifndef TOPTOOLBAR_H
#define TOPTOOLBAR_H

#include <QWidget>

class QPushButton;

class TopToolBar : public QWidget
{
    Q_OBJECT
public:
    explicit TopToolBar(QWidget *parent = nullptr);

signals:

public:
    QPushButton *_btnMin;
    QPushButton *_btnClose;
    QPushButton *_btnResize;
};

#endif // TOPTOOLBAR_H
