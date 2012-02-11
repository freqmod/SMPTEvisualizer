# Add more folders to ship with the application, here
folder_01.source = qml/LTCViz
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

QT+= multimedia
CONFIG += qt debug

# If your application uses the Qt Mobility libraries, uncomment the following

# CONFIG += mobility
# MOBILITY +=

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \
    jltcinterface.cpp

# Please do not modify the following two lines. Required for deployment.
include(qmlapplicationviewer/qmlapplicationviewer.pri)
qtcAddDeployment()

HEADERS += \
    jltcinterface.h

unix|win32: LIBS += -lltcsmpte

macx: LIBS += -L$$PWD/ltcsmpte/src/.libs/ -lltcsmpte

INCLUDEPATH += $$PWD/ltcsmpte/src/
