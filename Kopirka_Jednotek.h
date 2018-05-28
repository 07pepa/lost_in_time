#ifndef KOPIRKAJEDNOTEK_H
#define KOPIRKAJEDNOTEK_H
#include <QString>
#include "Jednotka.h"

/**
  * @brief Trida ktera je cinstkou tovarnou a vyrabi (ehm kopíruje) jednotky
  * @copyright cc All rights reserved ( inspection of code directly shared by author is alowed)
  * @author Dis. Josef Havranek
*/

class Kopirka_Jednotek {

private:
    ///archer aka sniper co se kopíruje
    Jednotka* m_vzorovySniper;
    ///vojak aka ritir v brneni co se kopiruje
    Jednotka* m_vzorovyVojak;
    /// medik aka healer co se kopíruje
    Jednotka* m_vzorvyMedik;

public:
    /// konstruktor.... jednotky nesmí být nullptr a jednotky se nesmí rovnat jinak vyvolá assert
    Kopirka_Jednotek(Jednotka* Sniper, Jednotka* Vojak, Jednotka* Medik);
    /// zkopíruje jednotku typ muže být: "v"(vojak) či "m" nic z toho tak sniper
    Jednotka* makejednotky(QString const & tip, Hrac* ci);
    /// destruktor
    ~Kopirka_Jednotek();
    unsigned getHpVojak(){return m_vzorovyVojak->getHP();}
    unsigned getHpMedik(){return m_vzorvyMedik->getHP();}
    unsigned getHPSnier(){return m_vzorovySniper->getHP();}
};

#endif // KOPIRKAJEDNOTEK_H
