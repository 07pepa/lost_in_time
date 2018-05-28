#ifndef JEDNOTKA_H
#define JEDNOTKA_H
#include <QString>
#include "Hrac.h"
/**
  * @brief Trida ktera drzi promene o jednotkach a interaguje s nimi
  * @copyright cc All rights reserved ( inspection of code directly shared by author is alowed)
  * @author Dis. Josef Havranek
*/

class Jednotka {

private:
    ///dostřel jednoky ( jak daleko může utočit
    int m_dostrel;
    ///síla (dmg) jednotky
    int m_sila;
    ///typ jednotky ( odpovída adrese souboru s obrazkem)
    QString m_tipJednotky;
    ///životy
    unsigned m_HP;
    ///kolik políček múže jednotka chodit
    int m_dosah;
    ///vlastník ( hráč)
    Hrac* m_vlastnik;

public:
    ///nastaví všechny atributy... typ nesmí být prázdný řetězec jinak se vyvolá asert
    Jednotka(unsigned hp, unsigned dostrel, unsigned sila, QString tip, unsigned dosah,Hrac* ci);
    ///zkopíruje jednotku jaka s hračem ci
    Jednotka(Jednotka* jaka, Hrac* ci);
    ///vrátí typ jednotky
    QString getTip();
    ///vrátí počet hp jednotky
    unsigned getHP(){return m_HP;}
    ///vrátí dosah ( jak daleko dojde po poly jednotky
    unsigned getDosah(){return m_dosah;}
    ///vrátí sílu jednotky
    unsigned getSIla();
    ///vrátí dostřel
    unsigned getDostrel();
    ///vyhealuje jednotku počtem kolik
    void heal(unsigned kolik);
    ///zraní jednotku počtem kolik
    void dealDMG(unsigned kolik);
    /// změní sílu jednotky +/- kolik, kolik se příčítá
    void alterSila(int kolik);
    /// změní munice jednotky +/- kolik, kolik se přičítá
    void alterDostrel(int kolik);
    /// vrátí vlastníka jednotky (hráče)
    Hrac* getci();
};
#endif
