# Add more folders to ship with the application, here
folder_01.source = qml/LTCVizCli
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

# Additional import path used to resolve QML modules in Creators code model
QML_IMPORT_PATH =

QT += network 
CONFIG += qt debug

# If your application uses the Qt Mobility libraries, uncomment the following

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \
    SMPTEClient.cpp


# Please do not modify the following two lines. Required for deployment.
include(qmlapplicationviewer/qmlapplicationviewer.pri)
qtcAddDeployment()

HEADERS += \
    SMPTEClient.hpp

