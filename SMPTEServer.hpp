#ifndef SMPTESERVER_H
#define SMPTESERVER_H

#include <QObject>
#include <QtNetwork>
#include <QVariant>
#include <stdint.h>
class SMPTEServer : public QObject
 {
     Q_OBJECT

 public:
     SMPTEServer(QObject *parent = 0);
     virtual ~SMPTEServer();

 public slots:
     void sendTimeInfo(QVariant timestamp, QVariant goal);
     void setGoal(QVariant goal);
 private slots:
     void newConnection();
     void connectionDisconnected();

 private:
     QTcpServer *tcpServer;
     QNetworkSession *networkSession;
     QList<QTcpSocket*> clients;
     uint32_t goal;
 };


#endif // JLTCINTERFACE_H

