#include "Engine.h"
#include "Radek.h"
#include "Policko.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <QFuture>
#include <QtConcurrent/QtConcurrent>
Engine::Engine(std::__cxx11::string kdePole, std::__cxx11::string kdeTeren, QString &jmenoCerveny, QString &jmenoModry, unsigned cashHraci, std::__cxx11::string cestaproJednotky,  unsigned avgCenajednotky, unsigned hracHp){
    std::srand (unsigned(std::time(0)));
    auto polectr=[&kdePole,&kdeTeren]()->HraciPole*{
        return new HraciPole(kdePole,kdeTeren);
    };
    auto hracctrr=[&hracHp,&cashHraci,&jmenoCerveny]()->Hrac*{
        return new Hrac(cashHraci,jmenoCerveny,hracHp);
    };
    auto hracctrb=[&hracHp,&cashHraci,&jmenoModry]()->Hrac*{
        return new Hrac(cashHraci,jmenoModry,hracHp);
    };

    QFuture<HraciPole*> pole= QtConcurrent::run(polectr);
    QFuture<Hrac*> r=QtConcurrent::run(hracctrr);
    QFuture<Hrac*> b=QtConcurrent::run(hracctrb);

    m_shop= new Obchod(cestaproJednotky,avgCenajednotky);;
    m_pole= pole.result();
    m_cerveny=r.result();
    m_modry=b.result();
    naplnpole();
}

Hrac* Engine::getRed() {
    return m_cerveny;
}

Hrac* Engine::getBlue() {
    return m_modry;
}

HraciPole* Engine::getPole() {
    return m_pole;
}


Obchod* Engine::getObchod() {
    return m_shop;
}

Engine::~Engine(){
    if (m_shop!=nullptr){delete m_shop;}
    m_shop=nullptr;if(m_pole!=nullptr){ delete m_pole;}
    m_pole=nullptr;
    delete m_modry;m_modry=nullptr;
    delete m_cerveny;m_cerveny=nullptr;
}


void Engine::naplnpole(){
    std::vector<Jednotka*>modri;  std::vector<Jednotka*> bordel;
    modri.reserve(10);QString qv="v";QString qm="m"; QString qa= "a";
    std::vector<Jednotka*>v;
    ;
    while (v.size()!=3) {
        v.push_back(m_shop->getJednotky(qv,m_modry));
    }
    modri.insert(modri.end(),v.begin(),v.end());
    std::vector<Jednotka*>m;
    while (m.size()!=3){
        m.push_back(m_shop->getJednotky(qm,m_modry));
    }
    modri.insert(modri.end(),m.begin(),m.end());
    std::vector<Jednotka*>a; std::vector<Jednotka*>prazd;
    while (a.size()!=4) {
        a.push_back(m_shop->getJednotky(qa,m_modry));
    }
    modri.insert(modri.end(),a.begin(),a.end());
    std::random_shuffle(modri.begin(),modri.end());
    std::vector<Jednotka*>cerveni;
    v=prazd;m=prazd;a=prazd;
    cerveni.reserve(10);

    while (v.size()!=3) {
        v.push_back(m_shop->getJednotky(qv,m_cerveny));
    }
    while (m.size()!=3){
        m.push_back(m_shop->getJednotky(qm,m_cerveny));
    }

    while (a.size()!=4) {
        a.push_back(m_shop->getJednotky(qa,m_cerveny));
    }

    cerveni.insert(cerveni.end(),v.begin(),v.end());
    cerveni.insert(cerveni.end(),m.begin(),m.end());
    cerveni.insert(cerveni.end(),a.begin(),a.end());
    std::random_shuffle(cerveni.begin(),cerveni.end());
    Koordinaty moje;
    moje.s_sloupec=0;
    for (unsigned i=0;i<=9;i++)
    {
        moje.s_radek=i;

        if(!m_pole->setJendotkaAt(modri.at(i),moje)){bordel.push_back(modri.at(i));}
    }
    moje.s_sloupec=9;
    for (unsigned i=0;i<=9;i++)
    {
        moje.s_radek=i;
        if(!m_pole->setJendotkaAt(cerveni.at(i),moje)){bordel.push_back(cerveni.at(i));}
    }


}
