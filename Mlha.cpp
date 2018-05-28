#include "Mlha.h"
#include <stdlib.h>


void Mlha::udelej(Jednotka* komu) { komu->alterDostrel(0);}

void Mlha::oddelej(Jednotka* komu) {komu->alterDostrel(0);}

Mlha::Mlha(unsigned kolik):Teren(kolik,"qrc:/obrazky_origo_vektory/teren_mlha.svg") {
    m_kolik=(m_kolik>49)?49:m_kolik;
}



bool Mlha::uhnul(){
    unsigned cislo;
    cislo= rand()%100+1;
    if(cislo<m_kolik){return true;}
    else{return false;}
}
