import QtQuick 2.7
import QtQuick.Window 2.2
import QtMultimedia 5.8
Window {
    id:rk
    visible: true
    width: Screen.desktopAvailableWidth
    height:  Screen.desktopAvailableHeight
    visibility: "FullScreen"
    title: "Hra"
    Audio{id: menupodkres
        source: "qrc:/menuBG.wav"
        autoPlay: true
        volume: 1
        muted: false
        loops: Audio.Infinite
    }
    SoundEffect{
        id: tlacklik
        source: "qrc:/TBP-SoundBible.com.wav"
        volume: 1
        muted: false
    }
    MainMenu{id:hlavnimenu
        signal nactihru
    }
    Hra{id:hra
    }
    signal presun
}

