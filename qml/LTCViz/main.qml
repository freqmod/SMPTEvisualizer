import QtQuick 1.0

Rectangle {
    width: 360
    height: 360
    Text {
        id: centralText
        text: "Hello World"
        anchors.centerIn: parent
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }
    }
    function onTimeRecieved(time) {
        centralText.text = time.hours+":"+time.mins+"."+time.secs+";"+time.frame;
    }
}
