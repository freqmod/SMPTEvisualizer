#ifndef SMPTECLIENT_H
#define SMPTECLIENT_H

#include <QObject>
#include <QtNetwork>
#include <QVariant>
#include <stdint.h>
class SMPTEClient : public QObject
 {
     Q_OBJECT

 public:
     SMPTEClient(QString address, QObject *parent = 0);

 signals:
     void timeRecieved(QVariant timestamp, QVariant goal);

 private slots:
     void readyRead();

 private:
     QTcpSocket *socket;
 };


#endif

