#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"
#include <jltcinterface.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    printf("MAIN!\n");
    SmpteLTCDecodeInterface intf;
    QmlApplicationViewer viewer;
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/LTCViz/main.qml"));
    viewer.showExpanded();
    QObject *rootObject = dynamic_cast<QObject*>(viewer.rootObject());
    QObject::connect(&intf, SIGNAL(timeRecieved(QVariant)), rootObject, SLOT(onTimeRecieved(QVariant)));
    return app.exec();
}
