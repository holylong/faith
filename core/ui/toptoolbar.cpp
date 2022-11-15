#include "toptoolbar.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QDebug>
#include "widgetutil.h"

TopToolBar::TopToolBar(QWidget *parent) : QWidget(parent)
{
    setAttribute(Qt::WA_TranslucentBackground, true);
    QHBoxLayout *mainLayout = new QHBoxLayout();
    _btnMin = new QPushButton;
    _btnMin->setIcon(QIcon(":/res/minus-icon.png"));
    WidgetUtil::Resize(_btnMin, 25, 25);
    _btnClose = new QPushButton;
    _btnClose->setIcon(QIcon(":/res/close-icon.png"));
    WidgetUtil::Resize(_btnClose, 25, 25);
    _btnResize = new QPushButton;
    _btnResize->setIcon(QIcon(":/res/resize-icon.png"));
    WidgetUtil::Resize(_btnResize, 25, 25);


    mainLayout->addWidget(_btnMin);
    mainLayout->addWidget(_btnResize);
    mainLayout->addWidget(_btnClose);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setMargin(0);

    QWidget *toolBarWidget = new QWidget();
    toolBarWidget->setLayout(mainLayout);
    if(toolBarWidget->objectName().isEmpty()){
       toolBarWidget->setObjectName("topToolBar");
       qDebug() << "update object name";
    }

    QHBoxLayout *innerLayout = new QHBoxLayout();
    innerLayout->addWidget(toolBarWidget);

    setLayout(innerLayout);
}
