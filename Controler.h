#ifndef CONTROLER_H
#define CONTROLER_H
#include "Engine.h"
#include <QObject>
#include "Koordinaty.h"
#include <QString>
#include "Hrac.h"
#include "Jednotka.h"
/**
  * @brief trida která zajištuje interface mezi gui a C++
  * @copyright cc All rights reserved ( inspection of code directly shared by author is alowed)
  * @author  Josef Havranek
  * @note odpusťte delku nelze zkrátit
*/


class Controler : public QObject
{
    Q_OBJECT
public:
    explicit Controler(QObject *parent = 0);
    ///vraci cestu k terenu
    Q_INVOKABLE QUrl getteren (int kde);
    ///vraci cestu k jednotce
    Q_INVOKABLE QUrl getjednotka(int kde);
    Q_INVOKABLE void init();
    ///maže proměné (skoro destruktor)
    Q_INVOKABLE void clr();
    /// vraci zdali je problem
    Q_INVOKABLE bool getjeproblem(){return m_jeproblem;}
    /// vraci text problemu
    Q_INVOKABLE QString getproblem(){return m_problem;}
    /// pokud je vlastnik jednoky hrac na tahu vrací true
    Q_INVOKABLE bool jetomojejednotka(int koordinaty);
    ///prepne hráče
    Q_INVOKABLE void prepnihrace();
    /// vrací stav políček pro přesun jednotky
    Q_INVOKABLE QString polcikaPresunjednotky(int koordinaty);
    /// nastaví m_posledni vybrana jednotka na koordináty ( funguje pouze pro pole 10x10)
    Q_INVOKABLE void vyberjednotuAT(int koordinaty);
    ///presune jednotku na pozici koordinaty
    Q_INVOKABLE void presunjednotuAT(int koordinaty);
    ///vrací true pokud je jednotka v dosahu jednotky z m posledni vybrana
    Q_INVOKABLE bool jeKutoku(int koordinaty);
    /// zautoci na jednotku na koordinatech
    Q_INVOKABLE void utokAt(int koordinaty);
    /// vrati pocet zbyvajicich tahu
    Q_INVOKABLE QString zbyvaTahu();
    /// přida cislo k tahu
    Q_INVOKABLE void tahni();
    /// vrati true je li modry na tahu
    Q_INVOKABLE bool modrynatahu(){return m_natahu==m_mujengine->getBlue();}
    ///vrati jmeno hrace na tahu
    Q_INVOKABLE QString hracNaTahu();
    /// vrati true na jednotku která jako poslední utocila
    Q_INVOKABLE bool utocila(int koor);
    /// vrati hracovo hp (b= modry)
    Q_INVOKABLE QString hracHP(QString kdo);
    /// vrati zdali je jednotka v dosahu hradu vzhledem k hracovi na tahu
    Q_INVOKABLE bool vdosahuHradu(int koor);
    /// dealuje hraci demage
    Q_INVOKABLE void hracdealdmg(QString komu);
    /// vrati true zdali je obchod v dosahu vzhledem k akualnimu hraci
    Q_INVOKABLE bool obchVdosahu(int koor);
    /// koupi jednotku a nastavi na posledni zvolena jednotka ( v = vojak, m= medik)
    Q_INVOKABLE void kupjednotku(QString jakou);
    /// vraci zdali je dost peněz na jednotku ( pismena jako předtim)
    Q_INVOKABLE bool dostnajed(QString jakou);
    ///vraci cash hrace  na tahu
    Q_INVOKABLE QString cashHrace();
    ///vyresi problem
    Q_INVOKABLE void resolveproblem(){m_problem="";m_jeproblem=false;}
    /// vrati jmeno vytěze
    Q_INVOKABLE QString getJmenoVyteze(){return getVytez()->getJmeno();}
    /// nastavi jmena hracu
    Q_INVOKABLE void setJmenaHracu(QString red, QString blue){m_nameRed=red;m_nameBlue=blue;}
    /// vrati true pokud jsou jmena uz zadana
    Q_INVOKABLE bool dalsirundu(){return m_nameBlue.size()!=0&&m_nameRed.size()!=0;}
    /// vrati jmena hracu ktere jsou v tu v controleru ulozene ( kdo =b = jmeno modreho hrace)
    Q_INVOKABLE QString specificGetNameHrac(QString kdo);
    ///vrati richtext info o jednotce
    Q_INVOKABLE QString getInfoJednotka(int koor);
    ///vrati richtext info o poly
    Q_INVOKABLE QString getInfoPole(int koor);
    ///vrati jmeno vytěze
    Q_INVOKABLE bool vyhralModry();

signals:

public slots:

private:
    unsigned m_maxtahu=10;///<ukazuje maximum tahu
    unsigned m_tah=0;///<drzí si počet aktualniho tahu
    Engine* m_mujengine=nullptr;///<drží si ukazatel na engine
    bool m_jeproblem=false;///< drzi si stav zdali je problem
    QString m_problem="";///<drži what při vijímce při problemu vyjímkou při
    Koordinaty m_k_urichleni;///<použiva se k urychlení translace při převodu z  qstr na koordinaty
    QString m_modrysufix="blue.svg";///<obsahuje sufix modrých jednotek
    QString m_cervenysufix="red.svg";///<obsahuje suffix červených jednotek
    QString m_naQURlurychl;///<používá se při převodu z qstring na qurl
    Hrac* m_natahu=nullptr;///<drzi kdo je na tahu
    Koordinaty m_poslednizvolenajednotka;///<drzí poslední zvolenou jednotku
    QString m_nameRed;///<drzi jmeno cerveneho
    QString m_nameBlue;///<drzi jmeno modreho
    QString m_k_urichleniInfo;///<urychluje terén info
    Jednotka * m_jendzrychlGetinfo=nullptr;///<zrychluje getinfo;
    //soukrome metody
    Koordinaty prevodnik (int &koord);///<převádí qstring na koordinaty
    unsigned prepocetnaVzdal(Koordinaty &moje);///<prepočte   vzdálenost od posledni vybrané jednotky s pomocí newyorkské metriky
    Hrac* m_vytez;///drzi si viteze
    Hrac* getVytez();///<vrati vytěze
};

#endif // CONTROLER_H
