#include "HraciPole.h"
#include <fstream>
#include <stdexcept>
#include "NeutralTeren.h"
#include "Prolaklina.h"
#include "Mlha.h"
#include "TerRadioactive.h"
#include "Vyvysenina.h"
#include "HealPlace.h"
#include "SilaBonus.h"
#include <cstdlib>
#include <iostream>
void HraciPole::generujPole(const std::string &cestaKsouboru) {
    std::fstream soub;
    soub.open(cestaKsouboru);
    if (!soub.is_open()){throw std::invalid_argument("Soubor: <i><u>Pole.txt</u></i> v adresáři <i><u>res</u><i> se nepodařilo otevřít");}
    else{
        std::vector<std::string> VectNactenyline;
        std::string line="";
        if(!(soub>>line)){soub.close();throw std::invalid_argument("Soubor je prazdny");}; // precteni a zahozeni instrukci
        line="";
        if(!(soub>>line))
        {
            soub.close();
            throw std::invalid_argument("je problem s čtením 2. slova (řádku) v souboru  <i><u>Pole.txt</u></i>");
        }else
        {
            if(line.size()==10)
            {VectNactenyline.push_back(line);}
            else
            {
                soub.close();
                throw std::invalid_argument("V souboru <i><u>Pole.txt</u></i> 2. řádek nemá 10 písmen");
            };
        }
        if(!(soub>>line))
        {
            soub.close();
            throw std::invalid_argument("je problem s čtením 3. slova (řádku) v souboru <i><u>Pole.txt</u></i>");
        }else
        {
            if(line.size()==10)
            {VectNactenyline.push_back(line);}
            else
            {
                soub.close();
                throw std::invalid_argument("V souboru <i><u>Pole.txt</u><> 3. řádek nemá 10 písmen");
            };
        }
        if(!(soub>>line))
        {
            soub.close();
            
            throw std::invalid_argument("je problem s čtením 4. slova (řádku) v souboru <i><u>Pole.txt</u></i>");
        }else
        {
            if(line.size()==10)
            {VectNactenyline.push_back(line);}
            else
            {
                soub.close();
                throw std::invalid_argument("V souboru <i><u>Pole.txt</u><> 4. řádek nemá 10 písmen");
            };
        };
        if(!(soub>>line))
        {
            soub.close();
            throw std::invalid_argument("je problem s čtením 5. slova (řádku) v souboru <i><u>Pole.txt</u></i>");
        }else
        {
            if(line.size()==10)
            {VectNactenyline.push_back(line);}
            else
            {
                soub.close();
                throw std::invalid_argument("V souboru <i><u>Pole.txt</u><> 5. řádek nemá 10 písmen");
            };
        };
        if(!(soub>>line))
        {
            soub.close();
            throw std::invalid_argument("je problem s čtením 6. slova (řádku) v souboru <i><u>Pole.txt</u></i>");
        }else
        {
            if(line.size()==10)
            {VectNactenyline.push_back(line);}
            else
            {
                soub.close();
                throw std::invalid_argument("V souboru <i><u>Pole.txt</u><> 6. řádek nemá 10 písmen");
            };
        };
        if(!(soub>>line))
        {
            soub.close();
            throw std::invalid_argument("je problem s čtením 7. slova (řádku) v souboru <i><u>Pole.txt</u></i>");
        }else
        {
            if(line.size()==10)
            {VectNactenyline.push_back(line);}
            else
            {
                soub.close();
                
                throw std::invalid_argument("V souboru <i><u>Pole.txt</u><> 7. řádek nemá 10 písmen");
            };
        }
        if(!(soub>>line))
        {
            soub.close();
            throw std::invalid_argument("je problem s čtením 8. slova (řádku) v souboru <i><u>Pole.txt</u></i>");
        }else
        {
            if(line.size()==10)
            {VectNactenyline.push_back(line);}
            else
            {
                soub.close();
                throw std::invalid_argument("V souboru <i><u>Pole.txt</u><> 8. řádek nemá 10 písmen");
            };
        }
        if(!(soub>>line))
        {
            soub.close();
            throw std::invalid_argument("je problem s čtením 9. slova (řádku) v souboru <i><u>Pole.txt</u></i>");
        }else
        {
            if(line.size()==10)
            {VectNactenyline.push_back(line);}
            else
            {
                soub.close();
                
                throw std::invalid_argument("V souboru <i><u>Pole.txt</u><> 9. řádek nemá 10 písmen");
            };
        }
        if(!(soub>>line))
        {
            soub.close();
            throw std::invalid_argument("je problem s čtením 10. slova (řádku) v souboru <i><u>Pole.txt</u></i>");
        }
        else
        {
            if(line.size()==10)
            {VectNactenyline.push_back(line);}
            else
            {
                soub.close();
                throw std::invalid_argument("V souboru <i><u>Pole.txt</u><> 10. řádek nemá 10 písmen");
            };
        }
        if(!(soub>>line))
        {
            soub.close();
            throw std::invalid_argument("je problem s čtením 11. slova (řádku) v souboru <i><u>Pole.txt</u></i>");
        }else
        {
            if(line.size()==10)
            {VectNactenyline.push_back(line);}
            else
            {
                soub.close();
                throw std::invalid_argument("V souboru <i><u>Pole.txt</u><> 11. řádek nemá 10 písmen");
            };
        }
        
        soub.close();
        auto lambdaZlobi=m_TerenKsmazani;
        auto naPole= [lambdaZlobi](unsigned ci)->Policko* {
            if(ci>47&&ci<55)
            { ci-=48;  Policko* uzasne= new Policko(lambdaZlobi.at(ci));return uzasne;
            }else{return nullptr;};
        };
        m_pole.reserve(10);
        for (unsigned u=0;u<VectNactenyline.size();u++){
            std::string jauznevim=VectNactenyline.at(u);
            Radek* mujradek=new Radek();
            mujradek->m_radek.reserve(10);
            for(unsigned i=0;i<jauznevim.size();i++){
                mujradek->m_radek.push_back(naPole(jauznevim.at(i)));
            }
            m_pole.push_back(mujradek);
        }
    }
}

HraciPole::HraciPole(const std::string &cestaPropole,const std::string &cestaProTeren) {
    
    m_TerenKsmazani= generujTeren(cestaProTeren);
    generujPole(cestaPropole);
}

std::vector<Teren*> HraciPole::generujTeren(const std::string &cestaKsouboru) {
    std::fstream soub;
    soub.open(cestaKsouboru);
    if (!soub.is_open()){throw std::invalid_argument("Soubor: <i><u>Teren.txt</u></i> v adresáři <i><u>res</u><i> se nepodařilo otevřít");}
    else{
        std::vector<Teren*> pom;pom.reserve(7);
        
        std::string uplneNaPrd;
        int mojecislo;
        try{
            auto uprava= [](int pomoc)->unsigned {unsigned vratka=std::abs(pomoc);return vratka;};
            //vzhledem k nulovému vetvení a uplné idiocite kodu porusuji pravidla a delam to inline kbuli citelnosti a délce
            //jedna line= jedna struktura
            //debuff
            //(prvni řádek a ano je to hack .... ale funguje to stejne jako je UTF8 hek)
            if(soub>>uplneNaPrd){NeutralTeren* jsemlinej= new NeutralTeren(); pom.push_back(jsemlinej);}else{throw std::invalid_argument("Problem s čtenim 1. řadku v souboru <i><u>Teren.txt</u></i>");}//<toto není chyba!
            //1
            if(soub>>uplneNaPrd&&soub>>mojecislo){Prolaklina* vymyslet= new Prolaklina(uprava(mojecislo)); pom.push_back(vymyslet);}else{throw std::invalid_argument("Problem s čtenim 2. řadku v souboru <i><u>Teren.txt</u></i>");};;
            //2
            if(soub>>uplneNaPrd&&soub>>mojecislo){ Mlha* smysluplne= new Mlha(uprava(mojecislo));pom.push_back(smysluplne);}else{throw std::invalid_argument("Problem s čtenim 3. řadku v souboru <i><u>Teren.txt</u></i>");};
            //3
            if(soub>>uplneNaPrd&&soub>>mojecislo){TerRadioactive* promene= new TerRadioactive(uprava(mojecislo));pom.push_back(promene);}else{throw std::invalid_argument("Problem s čtenim 4. řadku v souboru <i><u>Teren.txt</u></i>");}
            //buff                              4
            if(soub>>uplneNaPrd&&soub>>mojecislo){Vyvysenina* tak= new Vyvysenina(uprava(mojecislo));pom.push_back(tak);}else{throw std::invalid_argument("Problem s čtenim 5. řadku v souboru <i><u>Teren.txt</u></i>");}
            
            if(soub>>uplneNaPrd&&soub>>mojecislo){HealPlace* na_to= new HealPlace(uprava(mojecislo));pom.push_back(na_to);}else{throw std::invalid_argument("Problem s čtenim 6. řadku v souboru <i><u>Teren.txt</u></i>");}
            
            if(soub>>uplneNaPrd&&soub>>mojecislo){SilaBonus* kaslu= new SilaBonus(uprava(mojecislo));pom.push_back(kaslu);}else{throw std::invalid_argument("Problem s čtenim 7. řadku v souboru <i><u>Teren.txt</u></i>");}
            
            soub.close();
        }catch(std::invalid_argument &e){
            soub.close();
            for (auto neco:pom){delete neco;}
            pom.clear();
            throw e;
        }
        return pom;
    }
}

bool HraciPole::setJendotkaAt(Jednotka *kdo, Koordinaty const &kde){
    if(kde.s_radek>9){return false;}
    else if (kde.s_sloupec>9){return false;}
    else if(getPolickoAt(kde)==nullptr){return false;}
    else {getPolickoAt(kde)->setJednotka(kdo);return true;}
    return false;
}
/*
void HraciPole::spalovacMrtvol(){
    auto hledac= [](Policko* nejake)->bool{if (nejake->getJednotka()!=nullptr){return(nejake->getJednotka()->getHP()==0);}else {return false;}};
    auto  findifka= [hledac](Radek* nejake)->unsigned
    {
        unsigned poc=0;
        while (poc<nejake->m_radek.size())
        {
            if(hledac(nejake->m_radek.at(poc))){return poc;}
            else {poc++;}};
        return poc;};
        
    for (Radek* pomocny:m_pole)
    {
        unsigned itr=findifka(pomocny);
        while(itr!=pomocny->m_radek.size())
        {
            delete(pomocny->m_radek.at(itr)->getJednotka());
            pomocny->m_radek.at(itr)=nullptr;
            itr=findifka(pomocny);
        }
    }
}
*/
HraciPole::~HraciPole(){
    for (Radek* neco: m_pole){delete neco;};
    for(Teren* aa:m_TerenKsmazani){delete aa;}
}

Jednotka* HraciPole::getJednotkaAt(Koordinaty const &kde){
    if(getPolickoAt(kde)==nullptr){return nullptr;}
    else return getPolickoAt(kde)->getJednotka();
}
QUrl HraciPole::getTerenAt(Koordinaty &kde){
    QUrl vystup;
    if(getPolickoAt(kde)==nullptr){vystup="qrc:/obrazky_origo_vektory/teren_dira.svg";}
    else {
        vystup=getPolickoAt(kde)->getTeren()->getjakyTeren();
    }
    
    return vystup;}
Policko* HraciPole::getPolickoAt(Koordinaty const &kde)
{
    return m_pole.at(kde.s_radek)->m_radek.at(kde.s_sloupec);
}
unsigned HraciPole::getPoleindexAt(Koordinaty const &kde){
    Teren* pom=getPolickoAt(kde)->getTeren();
    unsigned vrat= 0;
    bool nalezeno=false;
    while (!nalezeno) {
        nalezeno=pom==m_TerenKsmazani.at(vrat);
        if(!nalezeno){vrat++;}
    }
    return vrat;
}

Teren* HraciPole::getnonQurlTerenAt(Koordinaty const &kde){
    return getPolickoAt(kde)->getTeren();

}
