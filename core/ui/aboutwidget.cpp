#include "aboutwidget.h"
#include <QHBoxLayout>
#include <QLabel>

AboutWidget::AboutWidget(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout *chatMainLayout = new QHBoxLayout();
    QLabel *title = new QLabel();
    title->setText("About Widget");
    chatMainLayout->addWidget(title);
    setLayout(chatMainLayout);
}
