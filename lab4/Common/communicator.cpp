#include "communicator.h"
#include <QDateTime>

TCommunicator::TCommunicator(TCommParams& pars, QObject *parent) : QUdpSocket(parent)
{
    params = pars;
    ready = bind(params.rHost, params.rPort,
                 QAbstractSocket::ShareAddress | QAbstractSocket::ReuseAddressHint);
    if (ready) connect(this,SIGNAL(readyRead()),this,SLOT(recieve()));
}

bool TCommunicator::isReady()
{
    return ready;
}

void TCommunicator::send(QByteArray msg)
{
    if (ready)
    {
        writeDatagram(msg, params.sHost, params.sPort);
        
        qDebug() << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") + " sended: " + msg;
    }
}

void TCommunicator::recieve()
{
    if (hasPendingDatagrams())
    {
        quint64 size = pendingDatagramSize();
        QByteArray msg(size,'\0');
        readDatagram(msg.data(), size);

        qDebug()<< QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") + " recieved: " + msg;

        emit recieved(msg);
    }
}
