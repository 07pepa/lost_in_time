#include "Prolaklina.h"

void Prolaklina::udelej(Jednotka* komu){
    if((komu->getTip()!="qrc:/obrazky_origo_vektory/vojak_")&&m_kolik!=0){
        int kom=m_kolik*-1;
        komu->alterDostrel(kom);}
}

void Prolaklina::oddelej(Jednotka* komu) {
    if((komu->getTip()!="qrc:/obrazky_origo_vektory/vojak_")&&m_kolik!=0){
        komu->alterDostrel(m_kolik);}
}

Prolaklina::Prolaklina(unsigned kolik):Teren(kolik,"qrc:/obrazky_origo_vektory/teren_prolaklina.svg") {}
