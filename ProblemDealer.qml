import QtQuick 2.0

Rectangle {
    id:prd
    signal jeProblem()
    width:  parent.width*0.7
    height:  parent.height*0.7
    color: "green"
    radius: height/50
    visible: false
    border.color: "black"
    border.width: height/100
    anchors.centerIn: parent
    Text {
        id:popisproblemu
        textFormat: Text.StyledText
        wrapMode: Text.Wrap
        height: parent.height/4
        width: parent.width-prd.border.width
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        fontSizeMode: Text.Fit
        font.pixelSize: height
        font.bold: true
        color: "red"
        opacity: 1
        visible: parent.visible
    }

    Tlac{
        anchors.horizontalCenter: parent.left
        anchors.horizontalCenterOffset:width/2
        anchors.verticalCenter: parent.bottom
        anchors.verticalCenterOffset: -height/2
        width: parent.width/2
        height: parent.height/4
        visible: parent.visible
        popisek: "Ukončit program!"
        MouseArea{
            enabled: parent.visible
            anchors.fill: parent
            onClicked:{
                tlacklik.play()
                Qt.quit()
            }
        }
    }
    Tlac{
        anchors.horizontalCenter: parent.right
        anchors.horizontalCenterOffset: -width/2
        anchors.verticalCenter: parent.bottom
        anchors.verticalCenterOffset: -height/2
        width: parent.width/2
        height: parent.height/4
        visible: parent.visible
        popisek: "Ukaž hlavní menu"
        MouseArea{
            enabled: parent.visible
            anchors.fill: parent
            onClicked:{
                tlacklik.play()
                hra.state=""
                tlacitka.state=""
                control.resolveproblem()
                hlmenu.state=""
                popisproblemu.text=""
                prd.visible=false
            }
        }
    }

    onJeProblem:{
        prd.visible=true
        popisproblemu.text=" Vyskytla se chyba: <br>"+control.getproblem()
    }
}
