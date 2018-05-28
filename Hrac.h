#ifndef HRAC_H
#define HRAC_H
#include<QString>
#include <vector>
/**
  * @brief Trida ktera interaguje s hracem a drzi o nem info
  * @copyright cc All rights reserved ( inspection of code directly shared by author is alowed)
  * @author Dis. Josef Havranek
*/
class Hrac {
private:
    /// ukládá jméno hráče
    QString m_jmeno;
    /// ukládá peníze hráče
    unsigned m_cash;
    unsigned m_hp;

public:
    ///kostruktor. Peníze nastavuje peníze jméno nastavuje jméno
    Hrac(unsigned penize,QString jmeno,unsigned &hp);
    ///vrátí jméno hráče
    QString getJmeno(){return m_jmeno;}
    /// vrátí počet peněz
    unsigned getPenize(){return m_cash;}
    /// přidá peníze
    void alterPenize(int kolik){m_cash+=kolik;}
    unsigned getHP(){return m_hp;}
    void dealdmg(unsigned kolik);
};
#endif
