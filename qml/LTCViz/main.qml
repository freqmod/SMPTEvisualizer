import QtQuick 1.0

Rectangle {
    width: 1280
    height: 720
    color: "black"
        Text {
            id: centralText
            text: "No signal detected"
            font.pointSize: 300
            color: "white"
        }
        Text {
            anchors.top: centralText.bottom
            anchors.horizontalCenter: centralText.horizontalCenter;
            id: countdownText
        text: "CDNo signal detected"
            font.pointSize: 150
            color: "orange"
        }
        TextInput {
            anchors.top: parent.top;
            anchors.left: parent.left;
            id: goalInput
            text: "1:30:0"
            font.pointSize: 10
            color: "white"
    //        anchors.centerIn: parent
        }
        Text {
            anchors.right: parent.right;
            anchors.top: parent.top;
            id: closeText
            text: "Close"
            height:20
            color: "red"
            font.pointSize: 10
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    Qt.quit();
                }
            }
    }
    function onTimeRecieved(time) {
        centralText.text = time.hours+":"+time.mins+"."+time.secs;
        countdownText.text = "is";
        var goals = goalInput.text.split(":");
        var goalSecs = (parseInt(goals[0])*3600)+(parseInt(goals[1])*60)+parseInt(goals[2]);
        var nowSecs = (time.hours*3600)+(time.mins*60)+time.secs;
        var diff = goalSecs-nowSecs;
        var neg = false;
        var negT = "";
        if(diff<0){
            neg = true;
            diff*=-1;
        }
        var hours = Math.floor(diff/3600);
        var mins = Math.floor((diff-(hours*3600))/60);
        var secs = diff-(hours*3600)-(mins*60);

        if(diff > 300){
            countdownText.color = "green";
        } else if(diff>60){
            countdownText.color = "yellow";
        } else if(diff>10){
            countdownText.color = Qt.rgba(1.0,0.4,0.0,1.0);
        } else if(diff>=0){
            countdownText.color = Qt.rgba(1.0,0.1,0.0,1.0);
        } else if(diff<0){
            countdownText.color = "red";
        }
        if(neg == true){
            countdownText.color = "red";
            negT="-";
        }
        countdownText.text = negT+hours+"."+mins+"."+secs; 
        
        
    }
}
