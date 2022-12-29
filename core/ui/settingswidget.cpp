#include "settingswidget.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QComboBox>
#include <QGroupBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QDebug>
#include <QListWidget>

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

    _layout = new QFormLayout(this);

    InitTransportSettings();
    InitGeneralSettings();
    InitSystemSettings();
    InitRemoteSettings();
    InitIMSettings();

#endif
}

void SettingsWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->globalX() - _lastPos.x();
    int dy = event->globalY() - _lastPos.y();

    _lastPos = event->globalPos();

    //move(x() + dx, y() + dy);
}


void SettingsWidget::mousePressEvent(QMouseEvent *event)
{
   //_lastPos = event->globalPos();
}

void SettingsWidget::InitRemoteSettings()
{
    //title
    QGroupBox *transportGroup = new QGroupBox(this);
    transportGroup->setTitle("Remote");


    //tls
    QVBoxLayout *transportLayout = new QVBoxLayout(transportGroup);
    transportLayout->setContentsMargins(20,20,20,20);
    QCheckBox   *ckBox = new QCheckBox(transportGroup);
    ckBox->setText("Support Tls");
    ckBox->setFixedWidth(600);
    transportLayout->addWidget(ckBox, 0, Qt::AlignRight);

    //theme
    QHBoxLayout *themeLayout = new QHBoxLayout(transportGroup);

    QLabel      *cbBoxTitle = new QLabel(transportGroup);
    cbBoxTitle->setText("Theme:");

    QComboBox *cbBox = new QComboBox(transportGroup);
    QListWidget *list = new QListWidget(cbBox);
    cbBox->setModel(list->model());
    cbBox->setView(list);
    list->addItem(new QListWidgetItem("Light"));
    list->addItem(new QListWidgetItem("Dark"));
    cbBox->setFixedWidth(600);

    themeLayout->addWidget(cbBoxTitle, 0, Qt::AlignRight);
    themeLayout->addWidget(cbBox);

    connect(cbBox, QOverload<const QString &>::of(&QComboBox::currentIndexChanged),
        [=](const QString &text){
        qDebug() << "text:" << text;
    });
    transportLayout->addLayout(themeLayout, Qt::AlignRight);

    //port
    QHBoxLayout *portLayout = new QHBoxLayout(transportGroup);
    QLabel      *portTitle = new QLabel(transportGroup);
    portTitle->setText("Port:");
    QLineEdit   *portEdit = new QLineEdit(transportGroup);
    portEdit->setText("50098");
    portEdit->setFixedWidth(600);
    portLayout->addWidget(portTitle, 0, Qt::AlignRight);
    portLayout->addWidget(portEdit);
    transportLayout->addLayout(portLayout, Qt::AlignRight);

    transportGroup->setLayout(transportLayout);

    _layout->addWidget(transportGroup);
}

void SettingsWidget::InitIMSettings()
{
    //title
    QGroupBox *transportGroup = new QGroupBox(this);
    transportGroup->setTitle("IM");


    //tls
    QVBoxLayout *transportLayout = new QVBoxLayout(transportGroup);
    transportLayout->setContentsMargins(20,20,20,20);
    QCheckBox   *ckBox = new QCheckBox(transportGroup);
    ckBox->setText("Support Tls");
    ckBox->setFixedWidth(600);
    transportLayout->addWidget(ckBox, 0, Qt::AlignRight);

    //theme
    QHBoxLayout *themeLayout = new QHBoxLayout(transportGroup);

    QLabel      *cbBoxTitle = new QLabel(transportGroup);
    cbBoxTitle->setText("Theme:");

    QComboBox *cbBox = new QComboBox(transportGroup);
    QListWidget *list = new QListWidget(cbBox);
    cbBox->setModel(list->model());
    cbBox->setView(list);
    list->addItem(new QListWidgetItem("Light"));
    list->addItem(new QListWidgetItem("Dark"));
    cbBox->setFixedWidth(600);

    themeLayout->addWidget(cbBoxTitle, 0, Qt::AlignRight);
    themeLayout->addWidget(cbBox);

    connect(cbBox, QOverload<const QString &>::of(&QComboBox::currentIndexChanged),
        [=](const QString &text){
        qDebug() << "text:" << text;
    });
    transportLayout->addLayout(themeLayout, Qt::AlignRight);

    //port
    QHBoxLayout *portLayout = new QHBoxLayout(transportGroup);
    QLabel      *portTitle = new QLabel(transportGroup);
    portTitle->setText("Port:");
    QLineEdit   *portEdit = new QLineEdit(transportGroup);
    portEdit->setText("50098");
    portEdit->setFixedWidth(600);
    portLayout->addWidget(portTitle, 0, Qt::AlignRight);
    portLayout->addWidget(portEdit);
    transportLayout->addLayout(portLayout, Qt::AlignRight);

    transportGroup->setLayout(transportLayout);

    _layout->addWidget(transportGroup);
}

void SettingsWidget::InitSystemSettings()
{
    //title
    QGroupBox *transportGroup = new QGroupBox(this);
    transportGroup->setTitle("System");


    //tls
    QVBoxLayout *transportLayout = new QVBoxLayout(transportGroup);
    transportLayout->setContentsMargins(20,20,20,20);
    QCheckBox   *ckBox = new QCheckBox(transportGroup);
    ckBox->setText("Support Tls");
    ckBox->setFixedWidth(600);
    transportLayout->addWidget(ckBox, 0, Qt::AlignRight);

    //theme
    QHBoxLayout *themeLayout = new QHBoxLayout(transportGroup);

    QLabel      *cbBoxTitle = new QLabel(transportGroup);
    cbBoxTitle->setText("Theme:");

    QComboBox *cbBox = new QComboBox(transportGroup);
    QListWidget *list = new QListWidget(cbBox);
    cbBox->setModel(list->model());
    cbBox->setView(list);
    list->addItem(new QListWidgetItem("Light"));
    list->addItem(new QListWidgetItem("Dark"));
    cbBox->setFixedWidth(600);

    themeLayout->addWidget(cbBoxTitle, 0, Qt::AlignRight);
    themeLayout->addWidget(cbBox);

    connect(cbBox, QOverload<const QString &>::of(&QComboBox::currentIndexChanged),
        [=](const QString &text){
        qDebug() << "text:" << text;
    });
    transportLayout->addLayout(themeLayout, Qt::AlignRight);

    //port
    QHBoxLayout *portLayout = new QHBoxLayout(transportGroup);
    QLabel      *portTitle = new QLabel(transportGroup);
    portTitle->setText("Port:");
    QLineEdit   *portEdit = new QLineEdit(transportGroup);
    portEdit->setText("50098");
    portEdit->setFixedWidth(600);
    portLayout->addWidget(portTitle, 0, Qt::AlignRight);
    portLayout->addWidget(portEdit);
    transportLayout->addLayout(portLayout, Qt::AlignRight);

    transportGroup->setLayout(transportLayout);

    _layout->addWidget(transportGroup);
}

void SettingsWidget::InitGeneralSettings(){
    //title
    QGroupBox *transportGroup = new QGroupBox(this);
    transportGroup->setTitle("General");


    //tls
    QVBoxLayout *transportLayout = new QVBoxLayout(transportGroup);
    transportLayout->setContentsMargins(20,20,20,20);
    QCheckBox   *ckBox = new QCheckBox(transportGroup);
    ckBox->setText("Support Tls");
    ckBox->setFixedWidth(600);
    transportLayout->addWidget(ckBox, 0, Qt::AlignRight);

    //theme
    QHBoxLayout *themeLayout = new QHBoxLayout(transportGroup);

    QLabel      *cbBoxTitle = new QLabel(transportGroup);
    cbBoxTitle->setText("Theme:");

    QComboBox *cbBox = new QComboBox(transportGroup);
    QListWidget *list = new QListWidget(cbBox);
    cbBox->setModel(list->model());
    cbBox->setView(list);
    list->addItem(new QListWidgetItem("Light"));
    list->addItem(new QListWidgetItem("Dark"));
    cbBox->setFixedWidth(600);

    themeLayout->addWidget(cbBoxTitle, 0, Qt::AlignRight);
    themeLayout->addWidget(cbBox);

    connect(cbBox, QOverload<const QString &>::of(&QComboBox::currentIndexChanged),
        [=](const QString &text){
        qDebug() << "text:" << text;
    });
    transportLayout->addLayout(themeLayout, Qt::AlignRight);

    //port
    QHBoxLayout *portLayout = new QHBoxLayout(transportGroup);
    QLabel      *portTitle = new QLabel(transportGroup);
    portTitle->setText("Port:");
    QLineEdit   *portEdit = new QLineEdit(transportGroup);
    portEdit->setText("50098");
    portEdit->setFixedWidth(600);
    portLayout->addWidget(portTitle, 0, Qt::AlignRight);
    portLayout->addWidget(portEdit);
    transportLayout->addLayout(portLayout, Qt::AlignRight);

    transportGroup->setLayout(transportLayout);

    _layout->addWidget(transportGroup);
}

void SettingsWidget::InitTransportSettings(){
    //title
    QGroupBox *transportGroup = new QGroupBox(this);
    transportGroup->setTitle("Transport");


    //tls
    QVBoxLayout *transportLayout = new QVBoxLayout(transportGroup);
    transportLayout->setContentsMargins(20,20,20,20);
    QCheckBox   *ckBox = new QCheckBox(transportGroup);
    ckBox->setText("Support Tls");
    ckBox->setFixedWidth(600);
    transportLayout->addWidget(ckBox, 0, Qt::AlignRight);

    //theme
    QHBoxLayout *themeLayout = new QHBoxLayout(transportGroup);

    QLabel      *cbBoxTitle = new QLabel(transportGroup);
    cbBoxTitle->setText("Theme:");

    QComboBox *cbBox = new QComboBox(transportGroup);
    QListWidget *list = new QListWidget(cbBox);
    cbBox->setModel(list->model());
    cbBox->setView(list);
    list->addItem(new QListWidgetItem("Light"));
    list->addItem(new QListWidgetItem("Dark"));
    cbBox->setFixedWidth(600);

    themeLayout->addWidget(cbBoxTitle, 0, Qt::AlignRight);
    themeLayout->addWidget(cbBox);

    connect(cbBox, QOverload<const QString &>::of(&QComboBox::currentIndexChanged),
        [=](const QString &text){
        qDebug() << "text:" << text;
    });
    transportLayout->addLayout(themeLayout, Qt::AlignRight);

    //port
    QHBoxLayout *portLayout = new QHBoxLayout(transportGroup);
    QLabel      *portTitle = new QLabel(transportGroup);
    portTitle->setText("Port:");
    QLineEdit   *portEdit = new QLineEdit(transportGroup);
    portEdit->setText("50098");
    portEdit->setFixedWidth(600);
    portLayout->addWidget(portTitle, 0, Qt::AlignRight);
    portLayout->addWidget(portEdit);
    transportLayout->addLayout(portLayout, Qt::AlignRight);

    transportGroup->setLayout(transportLayout);

    _layout->addWidget(transportGroup);
}
