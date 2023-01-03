#include "taskwidget.h"
#include <QHBoxLayout>
#include <QLabel>

TaskWidget::TaskWidget(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout *chatMainLayout = new QHBoxLayout();
    QLabel *title = new QLabel();
    title->setText("Task Widget");
    chatMainLayout->addWidget(title);
    setLayout(chatMainLayout);
}
