#ifndef HRACIPOLE_H
#define HRACIPOLE_H
#include<vector>
#include <QString>
#include"Radek.h"
#include"Teren.h"
#include"Koordinaty.h"
#include "Jednotka.h"
#include "Policko.h"
/**
  * @brief Trida ktera interaguje s policky a jednotkamy a terenem na koordinatech.... a drzi o nem info
  * @copyright cc All rights reserved ( inspection of code directly shared by author is alowed)
  * @author Dis. Josef Havranek
*/


class HraciPole {

private:
    ///drží vektor řádků, je to de facto první sloupec obsahující řádky
    std::vector<Radek*> m_pole;
    ///obsahuje terény v hře,
    std::vector<Teren*> m_TerenKsmazani;
    ///na indexu 0 počet řádku na idexu 1 počet sloupců
public:
    ///Konstruktor převezme cesty a předá je privátním metodám( generátorům)
    HraciPole(const std::string &cestaProPole,const std::string &cestaProteren);
    ///destruktor
    ~HraciPole();
    /// nastaví jednoku na řádku a sloupci vyhodí true v případě uspěchu false v případě chyby
    bool setJendotkaAt(Jednotka* kdo, Koordinaty const &kde);
    /// vrati jednotu na koordinatech (muze bit i nullptr)
    Jednotka* getJednotkaAt(const Koordinaty &kde);
    /// vrati adresu terenu na indexu
    QUrl getTerenAt(Koordinaty &kde);
    ///@note další zakomentovaná metoda není chyba byl to narok projektu na složitější lambdy avšak je nepoužívaná tudíž ji vyhazuji
    /*///zničí všechny mrtvoly (pouze pro splnení pouzivani sloziejsich lambda přikazu (narok projektu))
    void spalovacMrtvol();*/
    unsigned getPoleindexAt(const Koordinaty &kde);
    Teren* getnonQurlTerenAt(Koordinaty const &kde);
    /// vrátí pointr na policko na koordinatech ( muze vratit i nullptr)
    Policko* getPolickoAt(Koordinaty const &kde);
private:
    ///převezme cestu k souboru pro terén vygeneruje ho a nastaví ho
    std::vector<Teren*> generujTeren(const std::string &cestaKsouboru);
    /// převezme cestu k souboru pro pole vygeneruje ho a nastaví ho
    void generujPole(const std::string &cestaKsouboru);

};
#endif // HRACIPOLE_H
