import QtQuick 2.0

Rectangle{
    id:info
    anchors.top:parent.top
    anchors.left: parent.left
    width:((parent.width-parent.height)/2)*0.9
    visible: parent.visible
    height: parent.height/4
    color: "steelblue"
    opacity: 0.89
    border.width: height/100
    border.color: "black"

    Text{
        id:infotext
        width:parent.width-info.border.width
        height: parent.height-info.border.width
        visible: parent.visible
        opacity: 1
        anchors.top:parent.top
        anchors.horizontalCenterOffset: info.border.width
        anchors.verticalCenterOffset: info.border.width
        fontSizeMode: Text.Fit
        textFormat: Text.StyledText
        anchors.left: parent.left
        font.pixelSize: height
        Connections{
            target: procnejede
            ignoreUnknownSignals: true
            onHoverJednotka:{
            infotext.text=control.getInfoJednotka(kde)
            }
            onHoverExited:{
            infotext.text=""
            }
            onHoverPole:{
            infotext.text=control.getInfoPole(kde)
            }
        }
    }
}
