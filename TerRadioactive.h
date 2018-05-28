#ifndef DMG_TEREN_H
#define DMG_TEREN_H
#include "Teren.h"
#include "Jednotka.h"
/**
  * @brief  konkretní implementace terenu ubírá životy
  * @copyright cc All rights reserved ( inspection of code directly shared by author is alowed)
  * @author Dis. Josef Havranek
*/
class TerRadioactive :public Teren {


public:
    ///ubere jednoce zivoty
    void udelej(Jednotka* komu);
    ///vraci cast zivotu
    void oddelej(Jednotka* komu);
    /// konstruktor
    TerRadioactive(unsigned kolik);
};

#endif // DMG_TEREN_H
