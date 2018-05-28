#ifndef DostrelBonus_H
#include "Teren.h"
#include "Jednotka.h"
/**
  * @brief  konkretní implementace terenu přidá dostřel
  * @copyright cc All rights reserved ( inspection of code directly shared by author is alowed)
  * @author Dis. Josef Havranek
*/
class Vyvysenina : public Teren {


public:
    ///přidá dostřel
    void udelej(Jednotka* komu);
    ///odebere dostřel
    void oddelej(Jednotka* komu);
    ///konstruktor
    Vyvysenina(unsigned kolik);
};

#endif // DostrelBonus_H
