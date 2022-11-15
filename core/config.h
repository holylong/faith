#ifndef CONFIG_H
#define CONFIG_H

#include <QObject>
#include <QDebug>

class Config : public QObject
{
    Q_OBJECT
public:
    explicit Config(QObject *parent = nullptr);

    static Config* Instance(){
        static Config fg;
        return &fg;
    }

    void Display(){
        qDebug() << "theme:" << _theme;
    }

    void LoadConfig(){
        qDebug() << __FUNCTION__;
    }

private:
    QString  _theme;
    QString  _dbPath;

signals:

};

#endif // CONFIG_H
