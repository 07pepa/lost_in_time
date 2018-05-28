import QtQuick 2.0

Rectangle{
    color: "green"
    width: parent.width-parent.width/3
    id:pauz
    height: parent.height-parent.height/3
    radius: height/6
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.verticalCenter: parent.verticalCenter
    border.width: parent.height/60
    border.color:"black"
    visible: false
    Text {
        id: pauztxt
        color:"white"
        fontSizeMode: Text.Fit
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: height
        font.family: "Arial"
        font.pixelSize: height
        width: parent.width-pauz.border.width
        height: parent.height/5-pauz.border.width
        wrapMode: Text.Wrap
        text: "Pauza"
    }

    Tlac{
        width: parent.width/3-pauz.border.width
        height: parent.height/4-pauz.border.width
        anchors.horizontalCenter: parent.left
        anchors.horizontalCenterOffset: width/2
        anchors.verticalCenter: parent.bottom
        anchors.verticalCenterOffset: -height/2
        visible: parent.visible
        popisek: "Vypnout hru"
        barvatextu: "white"
        MouseArea{
            anchors.fill: parent
            enabled: parent.visible
            onClicked:{
                tlacklik.play()
                pauz.visible=false
                procnejede.resetPolicka()
                procnejede.disablePole()
                pauze.visible=false
                endgame.fin()
            }
        }
    }
    Tlac{
        width: parent.width/3-pauz.border.width
        height: parent.height/4-pauz.border.width
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.bottom
        anchors.verticalCenterOffset: -height/2
        visible: parent.visible
        popisek: "Zpět do hl. menu"
        barvatextu: "white"
        MouseArea{
            anchors.fill: parent
            enabled: parent.visible
            onClicked:{
                menupodkres.play()
                tlacklik.play()
                pauz.visible=false
                procnejede.enablePole()
                procnejede.resetPolicka()
                procnejede.state=""
                control.clr()
                hlavnimenu.state=""
                menupodkres.play()
            }
        }
    }
    Tlac{
        width: parent.width/3-pauz.border.width
        height: parent.height/4-pauz.border.width
        anchors.horizontalCenter: parent.right
        anchors.horizontalCenterOffset: -width/2
        anchors.verticalCenter: parent.bottom
        anchors.verticalCenterOffset: -height/2
        visible: parent.visible
        popisek: "pokracovat v hre"
        barvatextu: "white"
        MouseArea{
            anchors.fill: parent
            enabled: parent.visible
            onClicked:{
                tlacklik.play()
                pauz.visible=false
                procnejede.enablePole()
                pauze.visible=true
            }
        }
    }
    Connections{
        target: hlavnimenu
        ignoreUnknownSignals: true
        onNactihru:{
            pauz.visible=false
            pauze.visible=true
        }
    }

}
