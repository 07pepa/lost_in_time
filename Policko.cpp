#include "Policko.h"

Policko::Policko(Teren* teren) {
    m_jednotka=nullptr;
    m_Teren=teren;
}

Jednotka* Policko::getJednotka() {
    return m_jednotka;
}

void Policko::setJednotka(Jednotka* jaka) {
    m_jednotka=jaka;
}

Teren* Policko::getTeren() {
    return m_Teren;
}

Policko::~Policko(){delete m_jednotka;}
