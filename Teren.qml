import QtQuick 2.0
Image {
    id:ter
    property alias normalnipole:termisovaci.lzeklikat
    width: parent.width-2
    height: parent.height-2
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.verticalCenter: parent.verticalCenter
    antialiasing: true
    fillMode: Image.PreserveAspectCrop
    visible: parent.visible
    MouseArea{
        id:termisovaci
        anchors.fill: parent
        property bool lzeklikat: false
        onEntered: {if(!lzeklikat){zakaz.visible=true} else if(ter.source!="qrc:/obrazky_origo_vektory/teren_neutral.svg"){
                procnejede.hoverPole(index)
            }
        
        
        }
        onExited: {if(!lzeklikat){zakaz.visible=false}if(ter.source!="qrc:/obrazky_origo_vektory/teren_neutral.svg"){
                procnejede.hoverExited()
            }
        }
        onClicked: {
            if(lzeklikat){
                if(polevhre.state==="vdosahu")
                {
                    control.tahni()
                    procnejede.tahni()
                    control.presunjednotuAT(index)
                    procnejede.redrawjed()
                    polevhre.state="Jedtahla"
                    procnejede.poleredraw()
                }else {if(control.obchVdosahu(index)){
                    control.vyberjednotuAT(index)
                    procnejede.ukazObchod()
                }else{procnejede.poleredraw()}}
            }else{lzeklikat=false}

        }

    }
    Connections{
        target: hlavnimenu
        ignoreUnknownSignals: true
        onNactihru:{
             termisovaci.hoverEnabled=true
            ter.source=control.getteren(index)
            if(ter.source=="qrc:/obrazky_origo_vektory/teren_dira.svg")
            {
                polevhre.state="dira"  
            } else{termisovaci.lzeklikat=true}
        }
    }

    Image {
        id: zakaz
        width: parent.width
        height: parent.height
        source: "qrc:/obrazky_origo_vektory/zakaz.svg"
        visible: false
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        antialiasing: true
        fillMode: Image.PreserveAspectCrop
    }
    Connections{
        target: procnejede
        ignoreUnknownSignals: true
        onDisablePole:{
              termisovaci.enabled=false
            termisovaci.hoverEnabled=false

        }
        onEnablePole:{
            termisovaci.enabled=true
            termisovaci.hoverEnabled=true
        }
    }

}
