
#include <QtCore>
#include <QtNetwork>
#include <QTcpSocket>
#include "SMPTEClient.hpp"

SMPTEClient::SMPTEClient(QString address, QObject *parent) :
    QObject(parent)
{
    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    socket->connectToHost(QHostAddress(address), 12399);
}

void SMPTEClient::readyRead()  {
     QDataStream in(socket);
     in.setVersion(QDataStream::Qt_4_0);
     QVariant timestamp;
     QVariant goal;
     in >> timestamp;
     in >> goal;
     emit timeRecieved(timestamp, goal); 
 }


