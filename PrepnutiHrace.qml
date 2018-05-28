import QtQuick 2.8

Rectangle{
    id:prep
    visible: false
    opacity: 0.8
    height:  parent.height/2
    width: parent.width/2
    radius: height/6
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.verticalCenter: parent.top
    anchors.verticalCenterOffset: height
    border.color: "azure"
    border.width: height/50
    Text {
        id: textprep
        font.family: "Arial"
        color:"white"
        height: (parent.height/2)
        width: (parent.width-prep.border.width)*0.6
        visible: parent.visible
        font.pixelSize: textprep.height
        fontSizeMode: Text.Fit
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenterOffset: height/2
        anchors.verticalCenter: parent.top
        wrapMode: Text.Wrap
    }
    Tlac{
        id:pokrac
        popisek: "Pokračovat"
        barvatextu:"white"
        color: parent.color
        width: parent.width-prep.border.width
        height: parent.height/4
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.bottom
        anchors.verticalCenterOffset: -height
        visible: parent.visible
        MouseArea{
            anchors.fill: parent
            enabled: parent.visible
            onClicked: {
                procnejede.enablePole()
                prep.state=""
            }
        }
    }
    Connections{
        target: procnejede
        ignoreUnknownSignals: true
        onSwichhrac:{
            textprep.text=" Na tahu je: \n \t"+control.hracNaTahu()
            if(control.modrynatahu())
            {
                prep.state="blue"
            }
            else{prep.state="red"}
        }
    }


    states: [
        State {
            name: "red"
            PropertyChanges {
                target: prep
                color:"red"
                visible:true
                border.color: "pink"
            }
            PropertyChanges{
                target: textprep
                color: "yellow"

            }
        },
        State{
            name:"blue"
            PropertyChanges {
                target: prep
                color:"blue"
                visible:true
                border.color: "azure"
            }
            PropertyChanges{
                target: textprep
                color: "yellow"

            }
        }
    ]
}
