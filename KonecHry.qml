import QtQuick 2.0

Rectangle{
    color: "green"
    width: parent.width-parent.width/3
    height: parent.height-parent.height/3
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.verticalCenter: parent.verticalCenter
    radius: height/6
    visible: false
    border.color: "black"
    border.width: height/50
    Text {
        id: endgametxt
        fontSizeMode: Text.Fit
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: parent.height/50
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: height+parent.height/50
        font.pixelSize: height
        width: parent.width
        font.family: "Arial"
        height: parent.height/5
        wrapMode: Text.Wrap;

    }
    Connections{
        target: endgame
        ignoreUnknownSignals: true
        onFin:{endgame.visible=true
            endgametxt.text="  Konec hry!\n\tVyhrál: "+control.getJmenoVyteze();
        if (control.vyhralModry()){
        endgametxt.color="blue"
        }else{endgametxt.color="red"}
        }
    }

    Tlac{
        anchors.horizontalCenter: parent.left
        anchors.verticalCenter: parent.bottom
        anchors.verticalCenterOffset: -height/2
        anchors.horizontalCenterOffset: width/2
        width: parent.width/2
        height: parent.height/4
        visible: parent.visible
        popisek: "Ukončit program"
        barvatextu: "white"
        MouseArea{
            anchors.fill: parent
            enabled: parent.visible
            onClicked:{control.clr()
                tlacklik.play()
                Qt.quit()}
        }
    }
    Tlac{
        width: parent.width/2
        height: parent.height/4
        anchors.horizontalCenter: parent.right
        anchors.horizontalCenterOffset: -width/2
        anchors.verticalCenterOffset: -height/2
        anchors.verticalCenter: parent.bottom
        visible: parent.visible
        popisek: "Zpět do hl. menu"
        barvatextu: "white"
        MouseArea{
            anchors.fill: parent
            enabled: parent.visible
            onClicked:{
                tlacklik.play()
                menupodkres.play()
                endgame.visible=false
                procnejede.state=""
                control.clr()
                hlavnimenu.state=""
            }
        }
    }

}
