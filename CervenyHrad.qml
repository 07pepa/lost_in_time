import QtQuick 2.0
import QtMultimedia 5.8
Rectangle{
    Image {
        id:hradred
        source: "qrc:/obrazky_origo_vektory/red_hrad.svg"
        visible: parent.visible
        width: parent.width-redhradram.border.width
        height: width
        antialiasing: true
        fillMode: Image.PreserveAspectCrop
        anchors.centerIn: parent
        MouseArea{
            id:redhradklik
            enabled:false
            anchors.fill: parent
            onClicked: {procnejede.setUtocila()
                procnejede.poleredraw()
                control.hracdealdmg("");
                redhradram.state=""
                hpreportred.text="HP: "+control.hracHP("r")
                if(control.hracHP("r")==="0"){
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
    id:redhradram
    anchors.verticalCenter: parent.verticalCenter
    anchors.verticalCenterOffset: 0
    anchors.horizontalCenter: parent.right
    anchors.horizontalCenterOffset: -width+width*0.2;
    visible: parent.visible
    width: (parent.width-parent.height)/3
    height: width
    color: "transparent"
    border.color: "white"
    border.width: width/50
    Text {
        id: hpreportred
        color:"white"
        fontSizeMode: Text.Fit
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.bottom
        anchors.verticalCenterOffset: height
        font.pixelSize: height
        font.family: "Arial"
        width: parent.width
        height: parent.height/5
        wrapMode: Text.Wrap;
    }

    Connections{
        target: hlavnimenu
        ignoreUnknownSignals: true
        onNactihru:{
            hpreportred.text="HP: "+control.hracHP("r")
        }
    }


    Connections{
        target: procnejede
        ignoreUnknownSignals: true
        onUtoknaHrad:{
            if(control.modrynatahu())
            {
                redhradram.state="kutoku"
            }
        }
    }
    Connections{
        target: procnejede
        ignoreUnknownSignals: true
        onPoleredraw:{
            redhradram.state="";
        }
        onResetPolicka:{
            redhradram.state=""
        }
    }
    Rectangle{
        id:redobchod
        signal schovObchod()
        Connections{
            target: redobchod
            onSchovObchod:{
                voj.visible=false
                arch.visible=false
                med.visible=false
                redobchod.visible=false
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
            wrapMode: Text.Wrap;text: "Obchod:"
        }
        Image {
            id: voj
            visible: false
            anchors.horizontalCenter: parent.left
            anchors.horizontalCenterOffset: width/2
            width: ((parent.width-redobchod.border.width)/3)
            height: parent.height-redobchod.border.width
            anchors.verticalCenter: parent.verticalCenter
            source: "qrc:/obrazky_origo_vektory/vojak_red.svg"
            MouseArea{
                anchors.fill: parent
                enabled: parent.visible
                onClicked: {
                    control.kupjednotku("v")
                    redobchod.schovObchod()
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
            width: ((parent.width-redobchod.border.width)/3)
            height: parent.height-redobchod.border.width
            anchors.verticalCenter: parent.verticalCenter
            source: "qrc:/obrazky_origo_vektory/archer_red.svg"
            MouseArea{
                anchors.fill: parent
                enabled: parent.visible
                onClicked: {
                    redobchod.schovObchod()
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
            source: "qrc:/obrazky_origo_vektory/medik_red.svg"
            anchors.horizontalCenter: parent.right
            anchors.horizontalCenterOffset: -width/2
            width: ((parent.width-redobchod.border.width)/3)
            height: parent.height-redobchod.border.width
            anchors.verticalCenter: parent.verticalCenter
            MouseArea{
                anchors.fill: parent
                enabled: parent.visible
                onClicked: {
                    redobchod.schovObchod()
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
                if(!(control.modrynatahu())){
                    if(control.dostnajed("m")||control.dostnajed("v")||control.dostnajed("")){redobchod.visible=true}else{redobchod.visible=false;}
                    if(control.dostnajed("m")){med.visible=true}else{med.visible=false}
                    if(control.dostnajed("v")){voj.visible=true}else{voj.visible=false}
                    if(control.dostnajed("")){arch.visible=true}else{arch.visible=false}
                }
            }
            onPoleredraw:{
                redobchod.schovObchod()
            }
            onResetPolicka:{
                redobchod.schovObchod()
            }
        }
        Connections{
            target: rk
            ignoreUnknownSignals: true
            onPresun:{
                redobchod.schovObchod()
            }

        }
    }

    states: [
        State {
            name: "kutoku"
            PropertyChanges {
                target: redhradram
                border.color: "red"
            }
            PropertyChanges {
                target: redhradklik
                enabled:true
            }
        }
    ]
}
