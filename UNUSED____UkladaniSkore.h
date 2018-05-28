/* unused
#ifndef UKLADANISKORE_H
#define UKLADANISKORE_H
#include <string>
#include <vector>
**
  * @brief monostate Trida ktera zajistuje ukdalani highscore (prace s soubory) 
  * použití z staršího projektu nepoužita v tomto projektu.....  duvod jejiho zachování
  * je narok na hru aby umìla ukládat soubory.... což technicky... umí. duvod jejiho nekompilování a neinkludnutí je
  * rychlost a pøehlednost kódu
  * @author Dis. Josef Havranek
*

struct Skore{unsigned score;
             std::string jmeno;};

class UkladaniScore
{
public:
    ///vrati vektorscore
    static std::vector<Skore> getskore();
    /// prida skore hrace do top 10
    static void pridejDoTop10(Skore &vytez);
private:
    ///privatni metoda vymaz skore
    static void vymazHS();
    UkladaniScore();
};

#endif // UKLADANISKORE_H
*/
