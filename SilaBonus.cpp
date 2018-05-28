#include "SilaBonus.h"

void SilaBonus::udelej(Jednotka* komu) {
    if(m_kolik!=0){
        komu->alterSila(m_kolik);
    }
}

void SilaBonus::oddelej(Jednotka* komu) {komu->alterDostrel(0);}

SilaBonus::SilaBonus(unsigned kolik):Teren(kolik,"qrc:/obrazky_origo_vektory/teren_sila.svg") {}
