#ifndef TEREN_H
#define TEREN_H
#include <QUrl>
#include <QString>
#include "Jednotka.h"
/**
  * @brief  abstraktní implementace teren která se dedí drzici informace o terenu
  * @copyright cc All rights reserved ( inspection of code directly shared by author is alowed)
  * @author Dis. Josef Havranek
*/
class Teren {
protected:
    /// drzí kolik se toho bude dělat jednotce
    unsigned m_kolik;
    ///drzi adresu s terenem
    QUrl m_jaky;
public:
    ///virualní metoda udělej nutno naimplementovat
    virtual void udelej(Jednotka* komu)=0;
    ///virtualní metoda oddelej nutno naimplementovat
    virtual void oddelej(Jednotka* komu)=0;
    ///virtualní destruktor konkretni je nutno naimplementovat
    virtual ~Teren(){}
    ///vraci adresu terenu
    QUrl getjakyTeren(){return m_jaky;}
    unsigned getKolik(){return m_kolik;}
protected:
    ///chraneni konstruktor nutno naimplemetovat v potomcích
    Teren(unsigned  kolik, QString jaky){m_kolik=kolik;
                                         QUrl taky(jaky);m_jaky=taky;}

};

#endif // TEREN_H
