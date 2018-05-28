#include "HealPlace.h"
void  HealPlace::udelej(Jednotka* komu) {
    if(m_kolik!=0){
        komu->heal(m_kolik);
    }
}

void  HealPlace::oddelej(Jednotka* komu) {komu->alterDostrel(0);}

HealPlace::HealPlace(unsigned kolik):Teren(kolik,"qrc:/obrazky_origo_vektory/teren_heal.svg") {
}
