/* unused
#ifndef UKLADANISKORE_H
#define UKLADANISKORE_H
#include <string>
#include <vector>
**
  * @brief monostate Trida ktera zajistuje ukdalani highscore (prace s soubory) 
  * pou�it� z star��ho projektu nepou�ita v tomto projektu.....  duvod jejiho zachov�n�
  * je narok na hru aby um�la ukl�dat soubory.... co� technicky... um�. duvod jejiho nekompilov�n� a neinkludnut� je
  * rychlost a p�ehlednost k�du
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
