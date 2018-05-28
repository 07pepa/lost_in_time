import QtMultimedia 5.8
import QtQuick 2.7
Rectangle{
    id: hlmenu
    width: parent.width
    height: parent.height
    visible: true


    Image {
        id: obrHlmenu
        anchors.centerIn: parent
        width: parent.width
        visible: parent.visible
        height: parent.height
        antialiasing: true
        fillMode: Image.PreserveAspectCrop
        anchors.verticalCenterOffset: 0
        anchors.horizontalCenterOffset: 0
        source: "qrc:/obrazky_origo_vektory/MainMenuPozadi.svg"
    }

    HigHscore {id: hs
        Tlac{
            anchors.horizontalCenter: parent.right
            anchors.verticalCenter: parent.top
            width: parent.height/10
            height: parent.height/10
            radius: parent.height/10
            popisek: "X"
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    tlacklik.play()
                    hs.state=""
                    tlacitka.state=""
                }

            }
        }
    }

    Column {
        id: tlacitka
        width: parent.width/5
        height: parent.height/4
        anchors.horizontalCenterOffset: -width/2
        visible: true
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.right

        Tlac {
            id: tlac
            width: parent.width
            height: parent.height/3
            popisek: "Nová hra"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenterOffset: height/2
            anchors.verticalCenter: parent.top
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    tlacitka.state="Znevid"
                    tlacklik.play()
                    vstupjmen.zadejjmena()
                }

            }}
        /*Tlac {

            id: hsruntla
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            width: parent.width
            height: parent.height/3
            popisek: "High-Score"
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    tlacklik.play()
                    tlacitka.state="Znevid"
                    hs.state="ukaz"
                }
            }


        }*/
        Tlac {
            id: tlac2
            popisek: "Konec"
            anchors.horizontalCenter: parent.horizontalCenter
            width: parent.width
            height: parent.height/3
            anchors.verticalCenter: parent.verticalCenter
            MouseArea{
                anchors.fill: parent
                propagateComposedEvents: true
                onClicked: {
                    tlacklik.play()
                    Qt.quit()
                }
            }

        }
        states: [
            State {
                name: "Znevid"
                PropertyChanges {
                    target: tlacitka
                    visible:false
                }
            }  ]
    }
    Tlac{
        popisek: " ♪"
        height: parent.height/10
        width: height
        radius: height
        barvatextu: "white"
        id:toglemusic
        color: "blue"
        visible: parent.visible
        anchors.horizontalCenter: parent.left
        anchors.verticalCenter: parent.bottom
        anchors.horizontalCenterOffset: width
        anchors.verticalCenterOffset: -width
        MouseArea{
            anchors.fill: parent
            hoverEnabled: true
            onEntered: {toglemusic.opacity=1}
            onExited: {toglemusic.opacity=0.7}
            onClicked: {
                tlacklik.play()
                if(toglemusic.state=="vy"){menupodkres.play();toglemusic.state=""
                }else{menupodkres.pause();toglemusic.state="vy"
                }       }
        }
        states: [
            State {
                name: "vy"
                PropertyChanges {
                    target: toglemusic
                    color:"red"
                }
            }
        ]
    }
    states: [
        State {
            name: "Znevid"
            PropertyChanges {
                target: hlavnimenu
                visible:false
            }
            PropertyChanges {
                target: toglemusic
                state:""
            }
        }
    ]

NameImput{id:vstupjmen}
ProblemDealer{id:problemy

}
}
