#include "roomwidget.h"
#include <QLabel>
#include <QHBoxLayout>

RoomWidget::RoomWidget(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout *chatMainLayout = new QHBoxLayout();
    QLabel *title = new QLabel();
    title->setText("Room Widget");
    chatMainLayout->addWidget(title);
    setLayout(chatMainLayout);
}
