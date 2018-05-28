#ifndef MLHA_H
#define MLHA_H
#include "Teren.h"
#include "Jednotka.h"

/**
  * @brief  konkretni implementace terenu (nutný dynamic cast) má metodu uhnul říkající zdali jednotka uhnula před utokem
  * @copyright cc All rights reserved ( inspection of code directly shared by author is alowed)
  * @author Dis. Josef Havranek
  * @warning: je nutno provest dynamic cast
*/
class Mlha :public Teren {


public:
    ///nedělá nic jednotce
    void udelej(Jednotka* komu);
    ///nedělá nic jednoce
    void oddelej(Jednotka* komu);
    ///dává true když jednotka uhla a to zhruba v procentu případů nastavených v kolik
    bool uhnul();
    /// konstruktor pokud bude kolik větší než  49 bude ořezáno na 49
    Mlha (unsigned kolik);
};

#endif // MLHA_H
