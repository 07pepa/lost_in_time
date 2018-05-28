#ifndef ANTIDOSTREL_H
#define ANTIDOSTREL_H
#include "Teren.h"
/**
  * @brief  kokretni implementace terenu ubira dostrel
  * @copyright cc All rights reserved ( inspection of code directly shared by author is alowed)
  * @author Dis. Josef Havranek
*/
class Prolaklina :public  Teren {


public:
    /// ubere dostrel jednotce
    void udelej(Jednotka* komu);
    ///vrati dostrel jednotce
    void oddelej(Jednotka* komu);
    /// konstruktor nastavi kolik se bude odebírat/pridavat jednotce
    Prolaklina(unsigned kolik);
    ~Prolaklina(){}
};

#endif // ANTIDOSTREL
