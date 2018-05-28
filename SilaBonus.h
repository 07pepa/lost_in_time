#ifndef SILABONUS_H
#define SILABONUS_H
#include "Jednotka.h"
#include "Teren.h"
/**
  * @brief  konkretni implementace pridava silu jednotce
  * @copyright cc All rights reserved ( inspection of code directly shared by author is alowed)
  * @author Dis. Josef Havranek
*/

class SilaBonus : public Teren {


public:
    /// prida jednotce silu
    void udelej(Jednotka* komu);
    /// nic nedela
    void oddelej(Jednotka* komu);

    SilaBonus(unsigned kolik);
};

#endif // SILABONUS_H
