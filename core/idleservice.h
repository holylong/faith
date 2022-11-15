#ifndef IDLESERVICE_H
#define IDLESERVICE_H

#include <QObject>
#include <QUdpSocket>

class IdleService : public QObject
{
    Q_OBJECT
public:
    explicit IdleService(QObject *parent = nullptr);

    void SendBroadcast();

private slots:
    void OnReadyRead();

signals:

private:
    QUdpSocket    _udpSocket;
};

#endif // IDLESERVICE_H
