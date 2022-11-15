#include "idleservice.h"
#include <QNetworkAddressEntry>

IdleService::IdleService(QObject *parent) : QObject(parent)
{
    if (!_udpSocket.bind(QHostAddress::AnyIPv4, 36636))
    {
        qDebug() << "error msg:" << _udpSocket.errorString();
    }
    QObject::connect(&_udpSocket, &QUdpSocket::readyRead, this, &IdleService::OnReadyRead);
}

void IdleService::OnReadyRead()
{
    while (_udpSocket.hasPendingDatagrams()) {

            // Capture both the data and the address
            QByteArray data;
            QHostAddress address;

            // Receive the packet
            data.resize(_udpSocket.pendingDatagramSize());
            _udpSocket.readDatagram(data.data(), data.size(), &address);
            qDebug() << "recv:" << data.toStdString().c_str();
    }
}


void IdleService::SendBroadcast()
{
    QString qs = "nihao woshi qt";
    foreach (QNetworkInterface interface, QNetworkInterface::allInterfaces()) {
            if (interface.flags() & QNetworkInterface::CanBroadcast) {
                foreach (QNetworkAddressEntry entry, interface.addressEntries()) {
                    if (!entry.broadcast().isNull()) {
                        qDebug() << "entry broadcast:" << entry.broadcast().toString() << " " << _udpSocket.localPort();
                        _udpSocket.writeDatagram(qs.toLatin1(), entry.broadcast(), _udpSocket.localPort());
                    }
                }
            }
        }
}
