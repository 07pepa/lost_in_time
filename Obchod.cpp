#include "Obchod.h"
#include <algorithm>
#include <fstream>
#include <stdexcept>
#include "Jednotka.h"
Obchod::Obchod(std::string const & cestaProGenerator, unsigned  &avgCenaJednotky) {
    generatorek(cestaProGenerator);
    pocitacCenyJednotek(avgCenaJednotky);
}
Obchod::~Obchod(){
    try{
        delete m_kopirka;}catch(std::exception &e){
    }
}

unsigned Obchod::getCenaJednotky(QString &jaka){

    if(jaka=="V"||jaka=="v")
    {
        return m_VojakCena;
    }
    else if(jaka=="M"||jaka=="m"){
        return m_MedikValue;

    }else{
        return m_SniperValue;
    }
}



void Obchod::generatorek(std::string const &cesta){
    std::ifstream soubor;
    soubor.open(cesta);
    if(!soubor.is_open())
    {soubor.close();
        throw std::invalid_argument("Soubor: <i><u>Jednotky.txt</u></i> v adresáři <u>res</u> nelze otevřít");
    }
    else
    {
        Jednotka* Vojak;
        Jednotka* Sniper;
        Jednotka* medik;

        //tvorba vojaka
        std::string nanic;unsigned hp; unsigned silajednotky; unsigned dosah;
        soubor>>nanic;
        soubor>>nanic;
        soubor>>nanic;
        if(!(soubor>>hp)){soubor.close();throw std::invalid_argument("Nelze načíst HP vojáka");}
        soubor>>nanic;
        if(!(soubor>>silajednotky)){soubor.close();throw std::invalid_argument("Nelze načíst sílu vojáka");}
        soubor>>nanic;
        if(!(soubor>>dosah)){soubor.close();throw std::invalid_argument("Nelze načíst dosah vojáka");}
        //hp dostrel sila   munice tip dosah ci
        Vojak=new Jednotka(hp,1,silajednotky,"qrc:/obrazky_origo_vektory/vojak_",dosah,nullptr);
        // reset
        hp=0; silajednotky=0; dosah=0; unsigned dostrel=0;
        //tvorba snipera
        soubor>>nanic;
        soubor>>nanic;
        if(!(soubor>>hp)){delete Vojak;soubor.close();throw std::invalid_argument("Nelze načíst HP archerera");};
        soubor>>nanic;
        if(!(soubor>>dostrel)){delete Vojak;soubor.close();throw std::invalid_argument("Nelze načíst dostřel archerera");};
        soubor>>nanic;
        if(!(soubor>>silajednotky)){delete Vojak;soubor.close();throw std::invalid_argument("Nelze načíst sílu archera");}
        soubor>>nanic;
        if(!(soubor>>dosah)){delete Vojak;soubor.close();throw std::invalid_argument("Nelze načíst dosah archera");}
        Sniper = new Jednotka(hp,dostrel,silajednotky,"qrc:/obrazky_origo_vektory/archer_",dosah,nullptr);
        //sniper hotov... reset
        hp=0;dostrel=0;dosah=0;silajednotky=0;
        soubor>>nanic;
        soubor>>nanic;
        if(!(soubor>>hp)){delete Vojak;delete Sniper;soubor.close();throw std::invalid_argument("Nelze načíst HP archerera");};
        soubor>>nanic;
        if(!(soubor>>dostrel)){delete Vojak;delete Sniper;soubor.close();throw std::invalid_argument("Nelze načíst dostřel archerera");};
        soubor>>nanic;
        if(!(soubor>>silajednotky)){delete Vojak;delete Sniper;soubor.close();throw std::invalid_argument("Nelze načíst sílu archera");}
        soubor>>nanic;
        if(!(soubor>>dosah)){ soubor.close();delete Sniper; delete Vojak; throw std::invalid_argument("Nelze načíst sobor s dosahem  Mága");}
        medik= new Jednotka(hp,dostrel,silajednotky,"qrc:/obrazky_origo_vektory/medik_",dosah,nullptr);
        m_kopirka= new Kopirka_Jednotek(Sniper,Vojak,medik);
    }
}
void Obchod::pocitacCenyJednotek(unsigned & prumCenaJednotky){
    Obchod::m_VojakCena=prumCenaJednotky;
    Obchod::m_MedikValue=(prumCenaJednotky*0.85);
    Obchod::m_SniperValue=(prumCenaJednotky*1.15);
}

Jednotka* Obchod::getJednotky(QString &tip,Hrac* ci){
    return m_kopirka->makejednotky(tip,ci);
}
