import QtQuick 2.7
Rectangle {
    property alias popisek:popisek.text
    onParentChanged: {tlacitko.state=""}
    id: tlacitko
    color: "green"
    opacity: 0.7
    border.width: 6
    border.color: "black"
    visible: parent.visible
    radius: height/10
    property alias barvatextu: popisek.color
    Text{
        id: popisek
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        opacity: parent.opacity
        visible: parent.visible
        height: parent.height-border.width
        width: parent.width-border.width
        color: "white"
        font.bold: true
        font.family: "Arial"
        font.pixelSize: height
        fontSizeMode: Text.Fit
        text: "Initiaze me"
        wrapMode: Text.Wrap
        topPadding: height/12
        bottomPadding: height/12
        leftPadding: width/12
        rightPadding:width/12
    }

    MouseArea{
        id: tlarea
        anchors.fill: parent
        hoverEnabled: true
        onEntered: {tlacitko.state="najet"}
        onExited: {tlacitko.state="odjet"}
    }
    states:[
        State {
            name: "najet"
            PropertyChanges {
                target: tlacitko
                opacity: 1
            }
        }
        ,State {
            name: "odjet"
            PropertyChanges {
                target: tlacitko
                opacity: 0.7
            }
        }
    ]
}

