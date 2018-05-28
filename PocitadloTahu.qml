import QtQuick 2.7
Rectangle{
    Text{
        id:prasule
        visible: parent.visible
        width: parent.width
        height: (parent.height/5)*3
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: -height/2
        color: "yellow"
         wrapMode: Text.Wrap
         fontSizeMode: Text.Fit
         font.pixelSize: height
         font.family: "Arial"
         Connections{
         target: procnejede
         onRedrawjed:{
          prasule.text="① "+control.cashHrace()
         }
         }

    }
    id:tahy
    visible:  parent.visible
    color: "blue"
    height: (parent.height/10)*1.3
    width: (parent.height/10)*2.5
    border.color: "darkblue"
    border.width: height/10
    anchors.horizontalCenter: parent.left
    anchors.horizontalCenterOffset: (tahy.width/2)
    anchors.verticalCenter: parent.bottom
    anchors.verticalCenterOffset: -tahy.height

    Tlac{
        id:tahklikpopis
        popisek: "konec tahu"
        width: parent.width/3
        height: parent.height
        visible: parent.visible
        anchors.horizontalCenter: parent.right
        anchors.horizontalCenterOffset: -width/2
        anchors.verticalCenter: parent.verticalCenter
        MouseArea{
            id:tahklik
            enabled: parent.visible
            anchors.fill: parent
            onClicked: {
                tlacklik.play()
                if(tahy.state==""){tahy.state="cerveny"}else{tahy.state=""};
                control.prepnihrace()
                procnejede.resetPolicka()
                procnejede.disablePole()
                procnejede.swichhrac()
                texttahy.text=qsTr("Zbývá tahů: "+control.zbyvaTahu())
                prasule.text="① "+control.cashHrace()
            }
        }
    }
    Text {
        id: texttahy
        visible: parent.visible
        height: parent.height
        width: (parent.width/3)*2
        font.family: "Arial"
        color:"white"
        fontSizeMode: Text.Fit
        anchors.horizontalCenter: parent.left
        anchors.horizontalCenterOffset: width/2
        anchors.verticalCenter: parent.verticalCenter
        wrapMode: Text.Wrap
        Connections{
            target: hlavnimenu
            ignoreUnknownSignals: true
            onNactihru:{
                if(control.modrynatahu()){tahy.state=""}else{tahy.state="cerveny"}
                texttahy.text=qsTr("Zbývá tahů: "+control.zbyvaTahu())
                texttahy.font.pixelSize=parent.height
                prasule.text="①  "+control.cashHrace()
            }
        }

        Connections{
            target: procnejede
            ignoreUnknownSignals: true
            onTahni:{
                prasule.text="① "+control.cashHrace()
                texttahy.text=qsTr("Zbývá tahů: "+control.zbyvaTahu())
                if(control.zbyvaTahu()==="0")
                {
                    if(tahy.state==""){tahy.state="cerveny"}else{tahy.state=""};
                    control.prepnihrace()
                    procnejede.resetPolicka()
                    procnejede.resetPolicka()
                    procnejede.disablePole()
                    procnejede.swichhrac()
                    texttahy.text=qsTr("Zbývá tahů: "+control.zbyvaTahu())
                    prasule.text="①  "+control.cashHrace()

                }

            }
            onDisablePole:{
                tahklik.enabled=false
                tahklikpopis.visible=false

            }
            onEnablePole:{
                tahklik.enabled=true
                tahklikpopis.visible=true
            }
        }
    }




    states: [
        State {
            name: "cerveny"
            PropertyChanges {
                target: tahy
                color:"red"
                border.color: "darkred"
                anchors.horizontalCenter: parent.right
                anchors.horizontalCenterOffset: -tahy.width/2
                anchors.verticalCenter: parent.bottom
                anchors.verticalCenterOffset: -tahy.height
            }
        }
    ]

}
