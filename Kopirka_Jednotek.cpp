#include "Kopirka_Jednotek.h"
#include <stdexcept>
#include <cassert>
Kopirka_Jednotek::Kopirka_Jednotek(Jednotka* Sniper, Jednotka* Vojak, Jednotka* Medik)
{
    assert(Sniper!=nullptr);assert(Vojak!=nullptr);assert(Medik!=nullptr);
    assert(Sniper!=Vojak);assert (Vojak!=Medik); assert (Medik!=Sniper);
    m_vzorovySniper=Sniper;
    m_vzorovyVojak=Vojak;
    m_vzorvyMedik=Medik;
}
Kopirka_Jednotek::~Kopirka_Jednotek(){
    delete m_vzorovySniper; m_vzorovySniper=nullptr;
    delete m_vzorovyVojak; m_vzorovyVojak=nullptr;
    delete m_vzorvyMedik;m_vzorvyMedik=nullptr;
}


Jednotka * Kopirka_Jednotek::makejednotky(QString const & tip, Hrac* ci){
    assert(ci!=nullptr);

    if(tip=="V"||tip=="v")
    {
        Jednotka* uzasnajednotka=new Jednotka (m_vzorovyVojak,ci);
        return uzasnajednotka;
    }
    else if(tip=="M"||tip=="m"){

        Jednotka* uzasnajednotka=new Jednotka(m_vzorvyMedik,ci);
        return uzasnajednotka;
    }else{

        Jednotka* uzasnajednotka=new Jednotka(m_vzorovySniper,ci);
        return uzasnajednotka;
    }
}
