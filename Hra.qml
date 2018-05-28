import QtMultimedia 5.8
import QtQuick 2.7
Rectangle {
    Image {
        id: pozadihra
        source: "qrc:/obrazky_origo_vektory/hra_pozadi.jpeg"
        visible: parent.visible
        anchors.centerIn: parent
        width: parent.width
        height: parent.height
        antialiasing: true
        fillMode: Image.PreserveAspectCrop
        anchors.verticalCenterOffset: 0
        anchors.horizontalCenterOffset: 0
    }
    id:procnejede
    visible:false
    signal poleredraw()
    signal redrawjed()
    signal utokredrawpole()
    signal setUtocila()
    signal resetPolicka()
    signal tahni()
    signal disablePole()
    signal swichhrac()
    signal enablePole()
    signal utoknaHrad()
    signal ukazObchod()
    signal hoverExited()
    signal hoverJednotka(string kde)
    signal hoverPole(string kde)
    width: parent.width
    height: parent.height
    color: "grey"
    Tlac{
        id:pauze
        anchors.horizontalCenter: parent.right
        anchors.horizontalCenterOffset: -parent.height/10
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: +parent.height/10
        visible: parent.visible
        height: parent.height/10
        width:parent.height/10
        radius: parent.height/10
        popisek:" ||"
        MouseArea{
            enabled: parent.visible
            anchors.fill: parent
            onClicked:{
                tlacklik.play()
                halt.visible=true
                procnejede.disablePole()
                pauze.visible=false
            }
        }}
    Infobox{}
    PocitadloTahu{}
    CervenyHrad{}
    ModryHrad{}
    Grid{
        id:po
        width: parent.height
        height: parent.height
        anchors.horizontalCenter: parent.horizontalCenter
        rows:10
        visible: parent.visible
        columns:10
        anchors.verticalCenter: parent.verticalCenter
        Repeater{
            model: 100
            width: parent.width
            height: parent.height
            visible: parent.visible

            Políčko{
                id:polevhre
                Teren{id:tervhre
                }
                Jednotka{id:jedvhre

                }
            }
        }
    }


    states: [
        State {
            name: "hrajem"
            PropertyChanges {
                target: hra
                visible:true

            }
        }
    ]

    PrepnutiHrace{}
    Pauza{id:halt}
    KonecHry{id:endgame; signal fin()}
}
