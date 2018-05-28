#ifndef POLICKO_H
#define POLICKO_H
#include "Jednotka.h"
#include "Teren.h"
/**
  * @brief  drzi jednotku a teren
  * @copyright cc All rights reserved ( inspection of code directly shared by author is alowed)
  * @author Dis. Josef Havranek
*/
class Policko {

private:
    ///jednotka na políčku  výchozí nullprt
    Jednotka* m_jednotka;
    ///teren políčka
    Teren* m_Teren;

public:
    ///konstruktor políčka nastaví oboje
    Policko(Teren* teren);
    ///vrati jendotku na policku pozor muze byt i nullptr! ( není tu jednotka)
    Jednotka* getJednotka();
    ///vrati teren muze  být i nullptr!
    Teren* getTeren();
    /// nastavi jednotku na jaka
    void setJednotka(Jednotka* jaka);
    ~Policko();
};
#endif // POLICKO_H
