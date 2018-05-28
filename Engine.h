#ifndef ENGINE_H
#define ENGINE_H
#include "Hrac.h"
#include "Obchod.h"
#include "HraciPole.h"
#include <vector>
/**
  * @brief trida která zajištuje interakci s polem hraci a obchodem a preda jim potrebne veci v kotstuktorech
  * @copyright cc All rights reserved ( inspection of code directly shared by author is alowed)
  * @author Dis. Josef Havranek
*/


class Engine {
private:
    Hrac* m_cerveny;///<proměná s červeným hračem
    Hrac* m_modry;///<proměná s modrým hračem
    HraciPole* m_pole;///<proměná s polem
    Obchod* m_shop=nullptr;///<proměná s obchodem
    void naplnpole();
public:
    ///konstruktor kde pole cesta pole kde teren cesta teren  jmena  = jmena hracu
    Engine(std::string  kdePole, std::string kdeTeren, QString &jmenoCerveny, QString &jmenoModry, unsigned cashHraci, std::string  cestaproJednotky, unsigned avgCenajednotky, unsigned hracHp);
    ///vrati červeného
    Hrac* getRed();
    /// vrati modreho hráče
    Hrac* getBlue();
    ///vratí pointer na třídu starající se o pole a jeho potřebne metody
    HraciPole* getPole();
    ///vrátí instanci obchodu
    Obchod* getObchod();
    /// destruktor (pro mazání pointru v proměných a jejich obsahu a jejich nastavení na výchozá stav nullptr)
    ~Engine();

};

#endif // ENGINE_H
