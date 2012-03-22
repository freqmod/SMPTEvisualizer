#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"
#include <jltcinterface.h>
#include <SMPTEServer.hpp>
#include <stdio.h>
#include <stdint.h>
#include <QGraphicsObject>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    printf("MAIN!\n");
    SmpteLTCDecodeInterface intf;
    QmlApplicationViewer viewer;
    SMPTEServer server;
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/LTCViz/main.qml"));
    viewer.showExpanded();
    QObject *rootObject = dynamic_cast<QObject*>(viewer.rootObject());
    QObject::connect(&intf, SIGNAL(timeRecieved(QVariant, QVariant)), rootObject, SLOT(onTimeRecieved(QVariant, QVariant)));
    QObject::connect(&intf, SIGNAL(timeRecieved(QVariant, QVariant)), &server, SLOT(sendTimeInfo(QVariant, QVariant)));
    QObject::connect(rootObject, SIGNAL(goalChanged(QVariant)), &server, SLOT(setGoal(QVariant)));
    return app.exec();
}
