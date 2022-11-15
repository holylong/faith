#include "chatwidget.h"
#include <QHBoxLayout>
#include <QLabel>

ChatWidget::ChatWidget(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout *chatMainLayout = new QHBoxLayout();
    QLabel *title = new QLabel();
    title->setText("Chat Widget");
    chatMainLayout->addWidget(title);
    setLayout(chatMainLayout);
}
