#include "settingswidget.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QComboBox>
#include <QGroupBox>
#include <QFormLayout>

SettingsWidget::SettingsWidget(QWidget *parent) : QWidget(parent)
{
    setAttribute(Qt::WA_TranslucentBackground, false);
#if 0
    //title
    QGroupBox *transportGroup = new QGroupBox(this);
    transportGroup->setTitle("Transport");
//    transportGroup->setContentsMargins(20,20,20,20);

    //tls
    QVBoxLayout *transportLayout = new QVBoxLayout();
    transportLayout->setContentsMargins(20,20,20,20);
    QCheckBox   *ckBox = new QCheckBox();
    ckBox->setText("Support Tls");
    transportLayout->addWidget(ckBox);

    //theme
    QHBoxLayout *themeLayout = new QHBoxLayout();
    QLabel      *cbBoxTitle = new QLabel();
    cbBoxTitle->setText("Theme:");
    themeLayout->addWidget(cbBoxTitle);
    QComboBox *cbBox = new QComboBox();
    cbBox->addItem("Dark");
    cbBox->addItem("Light");
    themeLayout->addWidget(cbBox);
    transportLayout->addLayout(themeLayout);

    transportGroup->setLayout(transportLayout);
#else
    QFormLayout *settingsLayout = new QFormLayout(this);
    //title
    QGroupBox *transportGroup = new QGroupBox(this);
    transportGroup->setTitle("Transport");

    //tls
    QVBoxLayout *transportLayout = new QVBoxLayout();
    transportLayout->setContentsMargins(20,20,20,20);
    QCheckBox   *ckBox = new QCheckBox();
    ckBox->setText("Support Tls");
    transportLayout->addWidget(ckBox);

    //theme
    QHBoxLayout *themeLayout = new QHBoxLayout();
    QLabel      *cbBoxTitle = new QLabel();
    cbBoxTitle->setText("Theme:");
    themeLayout->addWidget(cbBoxTitle);
    QComboBox *cbBox = new QComboBox();
    cbBox->addItem("Dark");
    cbBox->addItem("Light");
    themeLayout->addWidget(cbBox);
    transportLayout->addLayout(themeLayout);
    transportGroup->setLayout(transportLayout);

    settingsLayout->addWidget(transportGroup);
#endif
}
