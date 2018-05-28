#include "Controler.h"
#include "Jednotka.h"
#include "Teren.h"
#include <string>
#include <QApplication>
#include <exception>
#include <stdlib.h>
#include <time.h>
#include <Mlha.h>

Controler::Controler(QObject *parent) : QObject(parent)
{    
    m_k_urichleniInfo.reserve(200);
    m_naQURlurychl.reserve(11);
    srand (time(NULL));
}

Koordinaty Controler::prevodnik(int &koord){
    m_k_urichleni.s_sloupec=koord%10;
    m_k_urichleni.s_radek=koord/10;
    return m_k_urichleni;
}
unsigned Controler::prepocetnaVzdal(Koordinaty &moje){
    unsigned vzdalenost=abs(moje.s_radek-m_poslednizvolenajednotka.s_radek)+ abs(moje.s_sloupec-m_poslednizvolenajednotka.s_sloupec);
    return vzdalenost;
}

QUrl Controler::getteren (int kde){
    Koordinaty moje=prevodnik(kde);
    QUrl  stav= m_mujengine->getPole()->getTerenAt(moje);
    return stav;
}
QUrl Controler::getjednotka(int kde){
    Koordinaty moje=prevodnik(kde);
    Jednotka* napozici=m_mujengine->getPole()->getJednotkaAt(moje);
    if(napozici==nullptr) {QUrl prd("");return prd;}
    else{
        if(napozici->getHP()==0) {QUrl prd("");return prd;}
        else{
            m_naQURlurychl=napozici->getTip();
            if(napozici->getci()==m_mujengine->getBlue()){
                m_naQURlurychl=m_naQURlurychl+m_modrysufix;
            }else{m_naQURlurychl=m_naQURlurychl+m_cervenysufix;};
            QUrl out(m_naQURlurychl);
            return out;
        }
    }

}
void Controler::init(){
    unsigned sede=80; unsigned trinact=13;
    m_maxtahu=10;
    std::string cesta=QCoreApplication::applicationDirPath().toStdString();
    try{
        m_mujengine= new Engine(cesta+"/res/Pole.txt",cesta+"/res/Teren.txt",m_nameRed,m_nameBlue,sede,cesta+"/res/Jednotky.txt",trinact,20);
        std::vector<Hrac*> rumble;
        rumble.push_back(m_mujengine->getBlue());
        rumble.push_back(m_mujengine->getRed());
        std::random_shuffle(rumble.begin(),rumble.end());
        std::random_shuffle(rumble.begin(),rumble.end());
        std::random_shuffle(rumble.begin(),rumble.end());
        std::random_shuffle(rumble.begin(),rumble.end());
        std::random_shuffle(rumble.begin(),rumble.end());
        std::random_shuffle(rumble.begin(),rumble.end());
        m_natahu=rumble.at(0);
    }
    catch(std::exception &e)
    {

        m_problem=QString::fromStdString(e.what());
        m_jeproblem=true;
          clr();
    }
}
void Controler::clr(){
    m_natahu=nullptr;
    delete m_mujengine;
    m_vytez=nullptr;
    m_natahu=nullptr;
    m_tah=0;
    m_jendzrychlGetinfo=nullptr;
}
bool Controler::jetomojejednotka(int koordinaty){
    Koordinaty moje=prevodnik(koordinaty);
    if(m_mujengine->getPole()->getJednotkaAt(moje)==nullptr){return false;}
    if(m_mujengine->getPole()->getJednotkaAt(moje)->getci()==m_natahu)
    {return true;}else return false;
}
void Controler::prepnihrace(){
    m_natahu=(m_natahu==m_mujengine->getBlue())?m_mujengine->getRed():m_mujengine->getBlue();
    m_tah=0;
}

void Controler::vyberjednotuAT(int koordinaty){
    m_poslednizvolenajednotka=prevodnik(koordinaty);
}
void Controler::presunjednotuAT(int koordinaty){
    Jednotka*docasna=m_mujengine->getPole()->getJednotkaAt(m_poslednizvolenajednotka);
    m_mujengine->getPole()->getnonQurlTerenAt(m_poslednizvolenajednotka)->oddelej(docasna);
    m_mujengine->getPole()->setJendotkaAt(nullptr,m_poslednizvolenajednotka);
    Koordinaty moje=prevodnik(koordinaty);
    m_mujengine->getPole()->setJendotkaAt(docasna,moje);
    m_mujengine->getPole()->getnonQurlTerenAt(moje)->udelej(docasna);
}
QString Controler::polcikaPresunjednotky(int koordinaty){
    Koordinaty moje=prevodnik(koordinaty);
    if (m_mujengine->getPole()->getPolickoAt(moje)==nullptr){return "dira";}
    if(!(prepocetnaVzdal(moje)>(m_mujengine->getPole()->getJednotkaAt(m_poslednizvolenajednotka)->getDosah())))
    {
        if((m_mujengine->getPole()->getJednotkaAt(moje))==nullptr)
        {return "vdosahu";}
        else{return "";}
    }else return "";

}
bool Controler::jeKutoku(int koordinaty){
    Koordinaty moje=prevodnik(koordinaty);
    if(m_mujengine->getPole()->getJednotkaAt(moje)==nullptr){return false;};
    if(m_mujengine->getPole()->getJednotkaAt(moje)->getci()==m_natahu){return false;}
    if(m_mujengine->getPole()->getJednotkaAt(m_poslednizvolenajednotka)->getDostrel()<prepocetnaVzdal(moje))
    {return false;};
    return true;
}
void Controler::utokAt(int koordinaty){
    Koordinaty moje=prevodnik(koordinaty);
    Mlha* zkus;
    if((zkus=dynamic_cast<Mlha*>(m_mujengine->getPole()->getnonQurlTerenAt(moje)))){if(zkus->uhnul())return;}
    if(m_mujengine->getPole()->getJednotkaAt(moje)->getSIla()<=m_mujengine->getPole()->getJednotkaAt(m_poslednizvolenajednotka)->getSIla())
    {
        m_mujengine->getPole()->getJednotkaAt(moje)->dealDMG(m_mujengine->getPole()->getJednotkaAt(m_poslednizvolenajednotka)->getSIla());
        if( m_mujengine->getPole()->getJednotkaAt(moje)->getHP()==0){
            Jednotka* kaput=m_mujengine->getPole()->getJednotkaAt(moje);
            m_mujengine->getPole()->setJendotkaAt(nullptr,moje);
            delete kaput;QString v="v"; QString m="m"; QString a="";
            m_natahu->alterPenize(+(m_mujengine->getObchod()->getCenaJednotky(v)+m_mujengine->getObchod()->getCenaJednotky(m)+m_mujengine->getObchod()->getCenaJednotky(a))/3);

        }
    }
    else
    {
        m_mujengine->getPole()->getJednotkaAt(m_poslednizvolenajednotka)->dealDMG(m_mujengine->getPole()->getJednotkaAt(moje)->getSIla()/2);
        m_mujengine->getPole()->getJednotkaAt(moje)->dealDMG((m_mujengine->getPole()->getJednotkaAt(m_poslednizvolenajednotka)->getSIla()));
        if( m_mujengine->getPole()->getJednotkaAt(moje)->getHP()==0){
            Jednotka* kaput=m_mujengine->getPole()->getJednotkaAt(moje);
            m_mujengine->getPole()->setJendotkaAt(nullptr,moje);
            delete kaput;QString v="v"; QString m="m"; QString a="";
            m_natahu->alterPenize(+(m_mujengine->getObchod()->getCenaJednotky(v)+m_mujengine->getObchod()->getCenaJednotky(m)+m_mujengine->getObchod()->getCenaJednotky(a))/3);
        }
        if(m_mujengine->getPole()->getJednotkaAt(m_poslednizvolenajednotka)->getHP()==0){
            Jednotka* kaput=m_mujengine->getPole()->getJednotkaAt(m_poslednizvolenajednotka);
            m_mujengine->getPole()->setJendotkaAt(nullptr,m_poslednizvolenajednotka);
            delete kaput;
        }
    }}


void Controler::tahni()
{
    m_tah++;
}
QString Controler::zbyvaTahu()
{
    if (m_tah>=m_maxtahu){return "0";}
    else return QString::number(m_maxtahu-m_tah);
}
QString Controler::hracNaTahu(){
    if(m_natahu==nullptr){return "";}else{return m_natahu->getJmeno();}

}
bool Controler::utocila(int koor){
    Koordinaty pom=prevodnik(koor);
    return m_poslednizvolenajednotka.s_radek==pom.s_radek&&pom.s_sloupec==m_poslednizvolenajednotka.s_sloupec;
}
QString Controler::hracHP(QString kdo){
    if(kdo=="r")
    {return QString::number(m_mujengine->getRed()->getHP());}
    else if (kdo=="b")
    {return QString::number(m_mujengine->getBlue()->getHP());}
    else
        return "programator udělal chybu omlouváme se";
}

bool Controler::vdosahuHradu(int koor){
    Koordinaty moje=prevodnik(koor);
    if(Controler::modrynatahu())
    {
        if(!(moje.s_sloupec>6)){return false;}
        if(moje.s_sloupec==9){return true;}
        Koordinaty pom=moje;
        while(pom.s_sloupec<9){
            pom.s_sloupec++;
            if(m_mujengine->getPole()->getJednotkaAt(pom)!=nullptr)
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        if(!(moje.s_sloupec<3)){return false;}
        if(moje.s_sloupec==0){return true;}
        Koordinaty pom=moje;bool jed=true;
        while(jed){
            pom.s_sloupec=pom.s_sloupec-1;
            if(m_mujengine->getPole()->getJednotkaAt(pom)!=nullptr)
            {
                return false;
            }
            jed=!(pom.s_sloupec==0);
        }
        return true;
    }

}

void Controler::hracdealdmg(QString komu){
    Hrac* pom=(komu=="b")?m_mujengine->getBlue():m_mujengine->getRed();
    pom->dealdmg(m_mujengine->getPole()->getJednotkaAt(m_poslednizvolenajednotka)->getSIla()/2);
}
bool Controler::obchVdosahu(int koor){
    Koordinaty moje=prevodnik(koor);
    unsigned kolik=(Controler::modrynatahu())?0:9;
    return (moje.s_sloupec==kolik);
}
void Controler::kupjednotku(QString jakou){
    Jednotka* nova=m_mujengine->getObchod()->getJednotky(jakou,m_natahu);
    m_mujengine->getPole()->setJendotkaAt(nova,m_poslednizvolenajednotka);
    int uber=m_mujengine->getObchod()->getCenaJednotky(jakou); uber=uber*-1;
    m_natahu->alterPenize(uber);
}
bool Controler::dostnajed(QString jakou){
    return (m_natahu->getPenize()>=m_mujengine->getObchod()->getCenaJednotky(jakou));
}
QString Controler::cashHrace(){
    return QString::number(m_natahu->getPenize()) ;
}

Hrac* Controler::getVytez(){
    Hrac* vratka;
    if((m_mujengine->getBlue()->getHP())==(m_mujengine->getRed()->getHP())){
        std::vector<Hrac*> rumble;
        rumble.push_back(m_mujengine->getBlue());
        rumble.push_back(m_mujengine->getRed());
        std::random_shuffle(rumble.begin(),rumble.end());
        std::random_shuffle(rumble.begin(),rumble.end());
        std::random_shuffle(rumble.begin(),rumble.end());
        std::random_shuffle(rumble.begin(),rumble.end());
        std::random_shuffle(rumble.begin(),rumble.end());
        std::random_shuffle(rumble.begin(),rumble.end());
        vratka=rumble.at(1);m_vytez=vratka;
    }else{
        vratka=((m_mujengine->getBlue()->getHP())>(m_mujengine->getRed()->getHP()))?m_mujengine->getBlue():m_mujengine->getRed();}
    return vratka;
}
QString Controler::specificGetNameHrac(QString kdo)
{
    QString pom=(kdo=="b")?m_nameBlue:m_nameRed;

    return pom;
}

QString Controler::getInfoJednotka(int koor){
    Koordinaty moje=prevodnik(koor);
    m_jendzrychlGetinfo=m_mujengine->getPole()->getJednotkaAt(moje);
    m_k_urichleniInfo="<font color='red'> ♥ "+QString::number(m_jendzrychlGetinfo->getHP())+"<font><br>";
    m_k_urichleniInfo=m_k_urichleniInfo+"<font color='yellow'> ✊ "+QString::number(m_jendzrychlGetinfo->getSIla())+"</font><br>";
    m_k_urichleniInfo=m_k_urichleniInfo+"<font color='green'> 👣 "+QString::number(m_jendzrychlGetinfo->getDosah())+"</font><br>";
    m_k_urichleniInfo=m_k_urichleniInfo+"<font color='magenta'> ♐ "+QString::number(m_jendzrychlGetinfo->getDostrel())+"</font>";
    return m_k_urichleniInfo;
}
QString Controler::getInfoPole(int koor){
    Koordinaty moje=prevodnik(koor);
    QString kolik;
    switch (m_mujengine->getPole()->getPoleindexAt(moje)) {
    case 1:
        kolik= QString::number(m_mujengine->getPole()->getnonQurlTerenAt(moje)->getKolik());
        m_k_urichleniInfo="<font color='magenta'> ♐ -"+kolik+"</font>";
        break;
    case 2:
        kolik= QString::number(m_mujengine->getPole()->getnonQurlTerenAt(moje)->getKolik());
        m_k_urichleniInfo="<font color='white'> Mlha<br> "+kolik+"% šance<br> na vyhnutí se</font>";
        break;
    case 3:
        kolik= QString::number(m_mujengine->getPole()->getnonQurlTerenAt(moje)->getKolik());
        m_k_urichleniInfo="<font color='red'> ♥  -"+kolik+"</font>";
        break;
    case 4:
        kolik= QString::number(m_mujengine->getPole()->getnonQurlTerenAt(moje)->getKolik());
        m_k_urichleniInfo="<font color='magenta'> ♐ +"+kolik+"</font>";
        break;
    case 5:
        kolik= QString::number(m_mujengine->getPole()->getnonQurlTerenAt(moje)->getKolik());
        m_k_urichleniInfo="<font color='red'> ♥ +"+kolik+"</font>";
        break;
    case 6:
        kolik= QString::number(m_mujengine->getPole()->getnonQurlTerenAt(moje)->getKolik());
        m_k_urichleniInfo="<font color='yellow'> ✊ +"+kolik+"</font>";
        break;
    default: m_k_urichleniInfo="";
        break;
    }

    
    return m_k_urichleniInfo;
}
bool Controler::vyhralModry(){
    return  m_vytez==m_mujengine->getBlue();
}
