import QtQuick 2.7
Rectangle{
    Connections{
        target: rk
        ignoreUnknownSignals: true
        onPresun:{
            if(!tahla&&!utocila){tohlepole.state=control.polcikaPresunjednotky(index);}
             if(control.jeKutoku(index)){tohlepole.state="kutoku"}
        }

    }
    Connections{
        target: procnejede
        ignoreUnknownSignals: true
        onPoleredraw:{
            if(!tahla&&!utocila){tohlepole.state="";}
        }
        onUtokredrawpole:{
            if(control.jeKutoku(index)){tohlepole.state="kutoku"}

        }
        onResetPolicka:{
            if(!(tohlepole.state=="dira")){
                tohlepole.state=""
            }
        }
        onSetUtocila:{
            if(control.utocila(index))
            {
                tohlepole.state="nemuzeUtocit"
            }
        }
    }

    visible: parent.visible
    border.color: "black"
    border.width: 3
    width: parent.width/10
    id:tohlepole
    property bool tahla: false
    property bool utocila: false
    height: parent.height/10
    states: [
        State {
            name: "vdosahu"
            PropertyChanges {
                target: tohlepole
                border.color: "navy"
            }
        },
        State {
            name: "Jedtahla"
            PropertyChanges {
                target: tohlepole
                tahla:true
                border.color: "white"
            }
        },
        State {
            name: "kutoku"
            PropertyChanges {
                target: tohlepole
                border.color:"red"
            }
        },
        State {
            name: "nemuzeUtocit"
            PropertyChanges {
                target:tohlepole
                utocila:true
                border.color: "orange"

            }
        },
        State {
            name: "dira"
            PropertyChanges {
                target:tohlepole
                border.color: "black"

            }
        }

    ]

}
