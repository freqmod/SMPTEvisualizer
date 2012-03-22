#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"
#include <SMPTEClient.hpp>
#include <stdio.h>
#include <stdint.h>
#include <QGraphicsObject>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    printf("MAIN!\n");
    QmlApplicationViewer viewer;
    if(argc<2){
        printf("Server ip required as first argument\n");
        return 1;
    }
    QString addr(argv[1]);
    SMPTEClient client(addr);

    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/LTCVizCli/main.qml"));
    viewer.showExpanded();
    QObject *rootObject = dynamic_cast<QObject*>(viewer.rootObject());
    QObject::connect(&client, SIGNAL(timeRecieved(QVariant, QVariant)), rootObject, SLOT(onTimeRecieved(QVariant, QVariant)));
    return app.exec();
}
