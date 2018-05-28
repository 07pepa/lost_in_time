#ifndef NEUTRALTEREN_H
#define NEUTRALTEREN_H
#include "Teren.h"
/**
  * @brief  konkretni implementace terenu neutrální nedelá nic
  * @copyright cc All rights reserved ( inspection of code directly shared by author is alowed)
  * @author Dis. Josef Havranek
*/
class NeutralTeren:public Teren
{
public:
    /// konstruktor
    NeutralTeren();
    ///destruktor
    ~NeutralTeren();
    ///udělej nic nedělá
    void udelej(Jednotka* komu);
    /// oddelej nic nedělá
    void oddelej(Jednotka* komu);
};

#endif // NEUTRALTEREN_H
