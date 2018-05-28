#include "TerRadioactive.h"

void TerRadioactive::udelej(Jednotka* komu) {
    if(m_kolik!=0){
        komu->dealDMG(m_kolik);
    }}

void TerRadioactive::oddelej(Jednotka* komu) {
    if(m_kolik!=0){
        komu->heal(m_kolik/0.6);
    }
}

TerRadioactive::TerRadioactive(unsigned kolik):Teren(kolik,"qrc:/obrazky_origo_vektory/teren_radioactive.svg") {}
