#ifndef HPBONUS_H
#define HPBONUS_H
#include "Teren.h"
#include "Jednotka.h"
/**
  * @brief konkretni implementace terenu  pridava zivoty
  * @copyright cc All rights reserved ( inspection of code directly shared by author is alowed)
  * @author Dis. Josef Havranek
*/
class HealPlace :public Teren {
public:
    /// healuje jednodku komu
    void udelej(Jednotka* komu);
    ///nic nedělá
    void oddelej(Jednotka* komu);
    /// nastaví kolik se bude pridavat jdendotce
    HealPlace(unsigned kolik);
};

#endif // HPBONUS_H
