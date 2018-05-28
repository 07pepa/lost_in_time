#ifndef RADEK_H
#define RADEK_H
#include "Policko.h"
#include <vector>
/**
  * @brief  struktura držici vektor radku
    * @copyright cc All rights reserved ( inspection of code directly shared by author is alowed)
  * @author Dis. Josef Havranek
*/
struct Radek {

public:
    std::vector<Policko*> m_radek;
    Radek();
    ~Radek();

};
#endif // RADEK_H
