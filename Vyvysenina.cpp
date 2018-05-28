#include "Vyvysenina.h"

void Vyvysenina::udelej(Jednotka* komu) {
    if((komu->getTip()!="qrc:/obrazky_origo_vektory/vojak_")&&m_kolik!=0){
        komu->alterDostrel(+m_kolik);};
}

void Vyvysenina::oddelej(Jednotka* komu) {
    if((komu->getTip()!="qrc:/obrazky_origo_vektory/vojak_")&&m_kolik!=0){
        komu->alterDostrel(-m_kolik);}
}

Vyvysenina::Vyvysenina(unsigned kolik):Teren(kolik,"qrc:/obrazky_origo_vektory/teren_vyvysenina.svg") {}
