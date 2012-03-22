
#include <QtCore>
#include <QtNetwork>
#include "SMPTEServer.hpp"

SMPTEServer::SMPTEServer(QObject *parent) :
    QObject(parent)
{
    tcpServer = new QTcpServer();
    QObject::connect(tcpServer, SIGNAL(newConnection()), this, SLOT(newConnection()));
    tcpServer->listen(QHostAddress::Any, 12399);
    goal = 0;

}
SMPTEServer::~SMPTEServer(){
    delete tcpServer;
}
void SMPTEServer::newConnection(){

     QTcpSocket *clientConnection = tcpServer->nextPendingConnection();
     connect(clientConnection, SIGNAL(disconnected()),
             this, SLOT(connectionDisconnected()));
     clients.append(clientConnection);
 }

void SMPTEServer::connectionDisconnected()
{
    clients.removeOne(qobject_cast<QTcpSocket*>(sender()));
    sender()->deleteLater();
}   
void SMPTEServer::setGoal(QVariant goal_arg){
    goal = goal_arg.toUInt();
}
void SMPTEServer::sendTimeInfo(QVariant timestamp, QVariant goal_arg){
   QByteArray block;
   QDataStream out(&block, QIODevice::WriteOnly);
   out.setVersion(QDataStream::Qt_4_0);
   out <<  timestamp;
   if(goal!=0){
       out << (quint32) goal;
   }else{
       out <<  goal_arg;
   }
   foreach(QTcpSocket* client, clients){
        client->write(block);     
   }

}

