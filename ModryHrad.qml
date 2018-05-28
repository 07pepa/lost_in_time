import QtQuick 2.0
import QtMultimedia 5.8
Rectangle{
    Image {
        id:hradblue
        source: "qrc:/obrazky_origo_vektory/blue_hrad.svg"
        visible: parent.visible
        width: parent.width-bluehradraam.border.width
        height: width
        antialiasing: true
        fillMode: Image.PreserveAspectCrop
        MouseArea{
            id:blueklik
            enabled:false
            anchors.fill:parent
            onClicked: {
                procnejede.setUtocila()
                procnejede.poleredraw()
                control.hracdealdmg("b");
                bluehradraam.state=""
                hpreportblue.text="HP: "+control.hracHP("b")
                if(control.hracHP("b")==="0"){
                    procnejede.resetPolicka()
                    procnejede.disablePole()
                    pauze.visible=false
                    endgame.fin()

                }else{
                    control.tahni()
                    procnejede.tahni()}
            }
        }
    }
    id:bluehradraam
    anchors.verticalCenter: parent.verticalCenter
    anchors.horizontalCenter: parent.left
    anchors.horizontalCenterOffset: 20+width/2
    visible: parent.visible
    width: (parent.width-parent.height)/3
    height: width
    color: "transparent"
    border.color: "white"
    border.width: width/50
    Text {
        id: hpreportblue
        color:"white"
        fontSizeMode: Text.Fit
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.bottom
        anchors.verticalCenterOffset: height
        font.pixelSize: height
        width: parent.width
        height: parent.height/5
        wrapMode: Text.Wrap;
    }

    Connections{
        target: hlavnimenu
        ignoreUnknownSignals: true
        onNactihru:{
            hpreportblue.text="HP: "+control.hracHP("b")
        }
    }

    Connections{
        target: procnejede
        ignoreUnknownSignals: true
        onUtoknaHrad:{
            if(!control.modrynatahu())
            {
                bluehradraam.state="kutoku"
            }
        }
    }

    Connections{
        target: procnejede
        ignoreUnknownSignals: true
        onPoleredraw:{
            bluehradraam.state="";
        }
        onResetPolicka:{
            bluehradraam.state=""
        }
    }
    Rectangle{
        id:blueobchod
        signal schovObchod()
        Connections{
            target: blueobchod
            onSchovObchod:{
                voj.visible=false
                arch.visible=false
                med.visible=false
                blueobchod.visible=false
            }
        }
        visible: false
        width: parent.width
        height: width/3
        radius: height/10
        anchors.verticalCenterOffset: -height
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.top
        border.color: "black"
        border.width: height/50
        color: "green"
        Text{
            color:"white"
            fontSizeMode: Text.Fit
            visible: parent.visible
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.top
            anchors.verticalCenterOffset: -height
            font.pixelSize: height
            width: parent.width
            height: parent.height/5
            wrapMode: Text.Wrap
            font.family: "Arial"
            text: "Obchod:"
        }
        Image {
            id: voj
            visible: false
            anchors.horizontalCenter: parent.left
            anchors.horizontalCenterOffset: width/2
            width: ((parent.width-blueobchod.border.width)/3)
            height: parent.height-blueobchod.border.width
            anchors.verticalCenter: parent.verticalCenter
            source: "qrc:/obrazky_origo_vektory/vojak_blue.svg"
            MouseArea{
                anchors.fill: parent
                enabled: parent.visible
                onClicked: {
                    control.kupjednotku("v")
                    blueobchod.schovObchod()
                    procnejede.redrawjed()
                    control.tahni()
                    procnejede.tahni()
                }
            }

        }

        Image {
            id: arch
            visible: false
            anchors.horizontalCenter: parent.horizontalCenter
            width: ((parent.width-blueobchod.border.width)/3)
            height: parent.height-blueobchod.border.width
            anchors.verticalCenter: parent.verticalCenter
            source: "qrc:/obrazky_origo_vektory/archer_blue.svg"
            MouseArea{
                anchors.fill: parent
                enabled: parent.visible
                onClicked: {
                    blueobchod.schovObchod()
                    control.kupjednotku("")
                    procnejede.redrawjed()
                    control.tahni()
                    procnejede.tahni()
                }
            }
        }
        Image {
            id: med
            visible: false
            source: "qrc:/obrazky_origo_vektory/medik_blue.svg"
            anchors.horizontalCenter: parent.right
            anchors.horizontalCenterOffset: -width/2
            width: ((parent.width-blueobchod.border.width)/3)
            height: parent.height-blueobchod.border.width
            anchors.verticalCenter: parent.verticalCenter
            MouseArea{
                anchors.fill: parent
                enabled: parent.visible
                onClicked: {
                    blueobchod.schovObchod()
                    control.kupjednotku("m")
                    procnejede.redrawjed()
                    control.tahni()
                    procnejede.tahni()
                }
            }
        }

        Connections{
            target: procnejede
            ignoreUnknownSignals: true
            onUkazObchod:{
                if(control.modrynatahu()){
                    if(control.dostnajed("m")||control.dostnajed("v")||control.dostnajed("")){blueobchod.visible=true}else{blueobchod.visible=false;}
                    if(control.dostnajed("m")){med.visible=true}else{med.visible=false}
                    if(control.dostnajed("v")){voj.visible=true}else{voj.visible=false}
                    if(control.dostnajed("")){arch.visible=true}else{arch.visible=false}
                }
            }
            onPoleredraw:{
                blueobchod.schovObchod()
            }
            onResetPolicka:{
                blueobchod.schovObchod()
            }
        }
        Connections{
            target: rk
            ignoreUnknownSignals: true
            onPresun:{
                blueobchod.schovObchod()
            }

        }
    }



    states: [
        State {
            name: "kutoku"
            PropertyChanges {
                target: bluehradraam
                border.color: "red"
            }
            PropertyChanges {
                target: blueklik
                enabled:true
            }
        }
    ]
}
