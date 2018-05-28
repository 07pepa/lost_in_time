import QtQuick 2.0

Rectangle{
    signal zadejjmena()
    id:vstupjmen
    width: parent.width*0.7
    height: parent.height*0.7
    border.color: "black"
    color: "green"
    visible: false
    opacity: 1
    border.width: height/50
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.verticalCenter: parent.verticalCenter

    Text{
        anchors.verticalCenter: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenterOffset: height
        height: parent.height/4
        color: "yellow"
        font.family: "Arial"
        font.pixelSize: parent.height-border.width
        fontSizeMode: Text.Fit
        text: "Nastaveni jmen hračů"
        wrapMode: Text.Wrap
    }
Rectangle{
    id:redbg
     width: (parent.width-vstupjmen.border.width)*0.8
     height: parent.height/6
     visible: parent.visible
     color: "white"
     border.color: "black"
     border.width: width/100
     anchors.verticalCenter: parent.verticalCenter
     anchors.horizontalCenter: parent.horizontalCenter
     anchors.verticalCenterOffset: -height/2
    TextEdit {
        id: redname
        width: (parent.width-redbg.border.width)*0.6
        height: (parent.height-redbg.border.width)*0.6
        opacity: 1
        visible: parent.visible
        color: "red"
        text: qsTr("Jméno červeného hráče")
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenterOffset: width/2+redbg.border.width
        anchors.verticalCenterOffset: -bluebg.border.width
        anchors.horizontalCenter: parent.left
        font.pixelSize: height
    }
}
Rectangle{
    id:bluebg
     width: (parent.width-vstupjmen.border.width)*0.8
     height: parent.height/6
     visible: parent.visible
     color: "white"
     border.color: "black"
     border.width: width/100
     anchors.verticalCenter: parent.verticalCenter
     anchors.horizontalCenter: parent.horizontalCenter
     anchors.verticalCenterOffset: +height/2+10+vstupjmen.parent.height/1000
    TextEdit {
        id: bluename
        width: (parent.width-bluebg.border.width)*0.6
        height: (parent.height-bluebg.border.width)*0.6
        opacity: 1
        visible: parent.visible
        color: "Blue"
        text: qsTr("Jméno modrého hráče")
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: -bluebg.border.width
        anchors.horizontalCenterOffset: width/2+bluebg.border.width
        anchors.horizontalCenter: parent.left
        font.pixelSize: height
    }
}
    Tlac{
        visible: parent.visible
        anchors.horizontalCenter: parent.right
        anchors.verticalCenter: parent.bottom
        width: parent.width/2
        height: parent.height/5
        popisek: "Potvrdit"
        anchors.horizontalCenterOffset: -width/2
        anchors.verticalCenterOffset: -height/2
        MouseArea{
            enabled: parent.visible
            anchors.fill:parent
            onClicked: {tlacklik.play()
                vstupjmen.state=""
                control.setJmenaHracu(redname.text,bluename.text)
                control.init()
                if(control.getjeproblem())
                {
                problemy.jeProblem()
                }else{
                 tlacitka.state=""
                hlmenu.state="Znevid"
                 menupodkres.stop()
                hlavnimenu.nactihru()
                hra.state="hrajem"}
            }
        }
    }
    Tlac{
        visible: parent.visible
        anchors.horizontalCenter: parent.left
        anchors.verticalCenter: parent.bottom
        width: parent.width/2
        height: parent.height/5
        popisek: "Zpět"
        anchors.horizontalCenterOffset: width/2
        anchors.verticalCenterOffset: -height/2
        MouseArea{
            enabled: parent.visible
            anchors.fill:parent
            onClicked: {
                tlacklik.play()
                vstupjmen.state=""
                tlacitka.state=""
            }
        }

    }
    Connections{
        ignoreUnknownSignals: true
        target: vstupjmen
        onZadejjmena:{
            if(control.dalsirundu()){bluename.text=control.specificGetNameHrac("b");redname.text=control.specificGetNameHrac("")}
            vstupjmen.state="ukaz"

        }
    }


    states: [
        State {
            name: "ukaz"
            PropertyChanges {
                target:vstupjmen
                visible:true
            }
        }
    ]



}
