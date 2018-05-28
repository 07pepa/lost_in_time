#ifndef OBCHOD_H
#define OBCHOD_h
#include "Jednotka.h"
#include <QString>
#include "Kopirka_Jednotek.h"
#include "Hrac.h"
/**
  * @brief  Trida interagujici s cinskou tovarnou a drzi cenu jednotek
  * @copyright cc All rights reserved ( inspection of code directly shared by author is alowed)
  * @author Dis. Josef Havranek
*/
class Obchod {

private:
    ///cena vojáka
    unsigned m_VojakCena;
    /// cena snipera
    unsigned m_SniperValue;
    /// cena medika
    unsigned m_MedikValue;
    ///pointr na kopírku jednotek
    Kopirka_Jednotek* m_kopirka=nullptr;
    ///generátor jednotek vyhazuje exception špatné parametry
    void generatorek( std::string const &cesta);
    ///nastaví cenu jednotek
    void pocitacCenyJednotek(unsigned &prumCenaJednotky);
public:
    /// převezme parametry a nastaví jednotky
    Obchod(std::string const & cestaProGenerator,unsigned  &avgCenaJednotky);
    ///vrátí cenu vojáka jednotky jaka
    unsigned getCenaJednotky(QString &jaka);
    /// vytvori a vrati vecor jedotek daneho tipu(m,v)( m medik, v=vojak)o počtu kolik pro hrače hráč jinak sniper automaticky
    Jednotka*getJednotky(QString &tip,Hrac* ci);
    ///destruktor
    ~Obchod();
};

#endif // OBCHOD_H
