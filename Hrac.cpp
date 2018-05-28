#include "Hrac.h"
#include <cassert>
#include <QString>
#include <algorithm>
Hrac::Hrac(unsigned penize, QString jmeno, unsigned &hp) {
    m_jmeno=jmeno;
    m_cash=penize;
    m_hp=hp;
}
void Hrac::dealdmg(unsigned kolik){
    m_hp=(m_hp>kolik)?m_hp-kolik:0;
}
