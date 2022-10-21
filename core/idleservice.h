#ifndef IDLESERVICE_H
#define IDLESERVICE_H

#include <QObject>

class IdleService : public QObject
{
    Q_OBJECT
public:
    explicit IdleService(QObject *parent = nullptr);

signals:

};

#endif // IDLESERVICE_H
