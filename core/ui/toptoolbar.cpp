#include "toptoolbar.h"
#include <QPushButton>
#include <QHBoxLayout>

TopToolBar::TopToolBar(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout *mainLayout = new QHBoxLayout();
    _btnMin = new QPushButton;
    _btnMin->setIcon(QIcon(":/res/minus-icon.png"));
    _btnClose = new QPushButton;
    _btnClose->setIcon(QIcon(":/res/close-icon.png"));
    _btnResize = new QPushButton;
    _btnResize->setIcon(QIcon(":/res/resize-icon.png"));

    mainLayout->addWidget(_btnMin);
    mainLayout->addWidget(_btnResize);
    mainLayout->addWidget(_btnClose);

    setLayout(mainLayout);
}
