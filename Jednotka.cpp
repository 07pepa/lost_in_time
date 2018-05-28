#include "Jednotka.h"
#include <assert.h>

Jednotka::Jednotka(unsigned hp, unsigned dostrel, unsigned sila, QString tip, unsigned dosah, Hrac* ci){
    assert(tip!="");
    m_dostrel=dostrel;
    m_sila=sila;

    m_tipJednotky=tip;
    m_HP=hp;
    m_dosah=dosah;
    m_vlastnik=ci;
}

QString Jednotka::getTip() {
    return m_tipJednotky;
}



unsigned Jednotka::getSIla() {
    return m_sila;
}

unsigned Jednotka::getDostrel() {
    return m_dostrel;
}

void Jednotka::heal(unsigned kolik) {
    m_HP+=kolik;
}

void Jednotka::dealDMG(unsigned kolik) {
    if (kolik>m_HP){m_HP=0;}else
    {m_HP-=kolik;}
}

void Jednotka::alterSila(int kolik) {
    m_sila+=kolik;
}


void Jednotka::alterDostrel(int kolik) {
    m_dostrel+=kolik;
}

Hrac* Jednotka::getci() {
    return m_vlastnik;
}

Jednotka::Jednotka(Jednotka* jaka, Hrac* ci){
    m_dostrel=jaka->m_dostrel;
    m_sila=jaka->m_sila;
    m_tipJednotky=jaka->m_tipJednotky;
    m_HP=jaka->m_HP;
    m_dosah=jaka->m_dosah;
    m_vlastnik=ci;
}

