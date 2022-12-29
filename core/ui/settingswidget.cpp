#include "settingswidget.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QComboBox>
#include <QGroupBox>
#include <QFormLayout>
#include <QLineEdit>

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
    //tls
    QVBoxLayout *transportLayout = new QVBoxLayout();
    transportLayout->setContentsMargins(20,20,20,20);
    QCheckBox   *ckBox = new QCheckBox();
    ckBox->setText("Support Tls");
    ckBox->setFixedWidth(600);
    transportLayout->addWidget(ckBox, 0, Qt::AlignRight);

    //theme
    QHBoxLayout *themeLayout = new QHBoxLayout();
    QLabel      *cbBoxTitle = new QLabel();
    cbBoxTitle->setText("Theme:");
    themeLayout->addWidget(cbBoxTitle, 0, Qt::AlignRight);
    QComboBox *cbBox = new QComboBox();
    cbBox->addItem("Dark");
    cbBox->addItem("Light");
    themeLayout->addWidget(cbBox, 0, Qt::AlignRight);
    cbBox->setFixedWidth(600);
    transportLayout->addLayout(themeLayout, Qt::AlignRight);

    //port
    QHBoxLayout *portLayout = new QHBoxLayout();
    QLabel      *portTitle = new QLabel();
    portTitle->setText("Port:");
    QLineEdit   *portEdit = new QLineEdit();
    portEdit->setText("50098");
    portLayout->addWidget(portTitle, 0, Qt::AlignRight);
    portLayout->addWidget(portEdit);
    portEdit->setFixedWidth(600);
    transportLayout->addLayout(portLayout, Qt::AlignRight);

    //title
    QGroupBox *transportGroup = new QGroupBox(this);
    transportGroup->setTitle("Transport");
    transportGroup->setLayout(transportLayout);

    QFormLayout *settingsLayout = new QFormLayout(this);
    settingsLayout->addWidget(transportGroup);
#endif
}
