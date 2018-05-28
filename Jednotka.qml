import QtQuick 2.7
import QtMultimedia 5.8
Image {
    id:jd
    width: parent.width-2
    height: parent.height-2
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.verticalCenter: parent.verticalCenter
    antialiasing: true
    fillMode: Image.PreserveAspectCrop
    visible: parent.visible
    Connections{
        target: hlavnimenu
        ignoreUnknownSignals: true
        onNactihru:{ jd.visible=true; jedkl.enabled=true;jedkl.hoverEnabled=true
            jd.source=control.getjednotka(index)
            if(jd.source==""){jedkl.enabled=false;jd.visible=false;jedkl.hoverEnabled=false}
        }
    }
    MouseArea{
        id:jedkl
        anchors.fill:parent
        enabled: parent.visible
        hoverEnabled: parent.visible
        onEntered: {if(control.jetomojejednotka(index)){procnejede.hoverJednotka(index)}}
        onExited: {procnejede.hoverExited()}
        onClicked: {

            if(control.jetomojejednotka(index))
            {if(polevhre.state==="")
                {
                    procnejede.poleredraw()
                    control.vyberjednotuAT(index)
                    rk.presun();
                    if(control.vdosahuHradu(index)){procnejede.utoknaHrad()}
                }else{if(polevhre.state==="Jedtahla")
                    {

                        control.vyberjednotuAT(index)
                        procnejede.utokredrawpole()
                        if(control.vdosahuHradu(index)){procnejede.utoknaHrad()}
                    }
                }


            }else{ if(polevhre.state==="kutoku"){
                    control.utokAt(index)
                    procnejede.setUtocila()
                    procnejede.redrawjed()
                    procnejede.poleredraw()
                    control.tahni()
                    procnejede.tahni()

                }}

        }
    }
    Connections{
        target: procnejede
        ignoreUnknownSignals: true
        onRedrawjed:{
            jd.source=control.getjednotka(index);
            jd.visible=true;
            jedkl.enabled=true;
            jedkl.hoverEnabled=true
            if(jd.source==""){jedkl.enabled=false;jd.visible=false;jedkl.hoverEnabled=false}

        }
    }
    Connections{
        target: procnejede
        ignoreUnknownSignals: true
        onDisablePole:{
            jedkl.enabled=false
            jedkl.hoverEnabled=false
        }
        onEnablePole:{
            if(jd.source=="")
            {jedkl.enabled=false; jd.visible=false;jedkl.hoverEnabled=false}
            else{
                jd.visible=true
                jedkl.enabled=true
                jedkl.hoverEnabled=true
            }
        }
    }


}
