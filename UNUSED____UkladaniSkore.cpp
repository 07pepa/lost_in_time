/*#include "UkladaniSkore.h"
#include <cstdlib>
#include <fstream>
#include <algorithm>
///pouziva se ciste pro pridani skore a vypsani top 10 do souboru

void  UkladaniScore::vymazHS()
{

    std::ofstream out;
    out.open("/score.txt",std::ios_base::trunc);
    out.close();
}
void UkladaniScore::pridejDoTop10(Skore &vytez)
{

    std::vector<Skore>vystupniVC;
    std::ifstream in;
    in.open ("/score.txt");
    if (in. is_open ()){
        bool canRead;
        do{
            Skore ls;
            canRead=false;
            if(in>>ls.score){in>>ls.jmeno;vystupniVC.push_back(ls);canRead=true;}

        }while(canRead);
    }
    in. close ();
    while (vystupniVC.size()>10)
        vystupniVC.pop_back();
    vystupniVC.push_back(vytez);
    bool konec;
    if(vystupniVC.size()>1) {
        do{
            konec=true;
            for (unsigned i=1;i<vystupniVC.size()-1;i++)
            {
                if (vystupniVC.at(i-1).score<vystupniVC.at(i).score)
                {
                    Skore pom=vystupniVC.at(i-1);
                    vystupniVC.at(i-1)=vystupniVC.at(i);
                    vystupniVC.at(i)=pom;
                    konec=false;
                }
            }
        }while(!konec);
        while (vystupniVC.size()>10)
            vystupniVC.pop_back();
    };

    std::ofstream out;
    out.open("//score.txt",std::ios_base::trunc);
    if (out.is_open())
    {
        for(unsigned i=0;i<vystupniVC.size();i++)
        {
            out<<vystupniVC.at(i).score;
            out<<" ";
            out<<vystupniVC.at(i).jmeno;
        }
        out.close();
    }
    else {throw "nelze otevrit soubor";}

}

std::vector<Skore>   UkladaniScore::getskore()
{ std::string neco;
    std::vector<Skore>vstupniVC;
    Skore ls;
    std::ifstream in;
    in.open ("\\score.txt");
    if (in. is_open ()){
        bool canRead;
        do{
            canRead=false;
            if((in>>ls.score)){in>>ls.jmeno;vstupniVC.push_back(ls);canRead=true;}

        }while(canRead);

        in. close ();
        while (vstupniVC.size()>10) vstupniVC.pop_back();
        return vstupniVC;
    }
    else
        throw "soubor se nepodařilo otevřit";
}
*/
