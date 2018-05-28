import QtQuick 2.5
import QtMultimedia 5.8
Rectangle {
    id: highscore
    visible: false
    opacity: 0
    color: "green"
    border.color: "black"
    border.width: 15
    radius: 20
    width: parent.width*0.6
    height: parent.height*0.6
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.verticalCenter: parent.verticalCenter
    Text {
        id: text1
        anchors.horizontalCenter: parent.horizontalCenter
        visible: parent.visible
        opacity:1
        width: parent.width
        height: parent.height
        text: "High score"
        font.pixelSize:101
        color: "yellow"
        font.bold: true
        font.italic: true
        font.family: "Arial"

    }
    states: [
        State {
            name: "ukaz"

            PropertyChanges {
                target: highscore
                visible: true
                opacity:0.7
            }

        }
    ]
    SoundEffect{
        id: tlacklik
        source: "qrc:/TBP-SoundBible.com.wav"
        volume: 1
        muted: false
    }



}
