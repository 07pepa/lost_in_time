#include "NeutralTeren.h"

NeutralTeren::NeutralTeren():Teren(0,"qrc:/obrazky_origo_vektory/teren_neutral.svg")
{}

NeutralTeren::~NeutralTeren()
{}

void NeutralTeren::udelej(Jednotka *komu)
{komu->heal(0);}
void NeutralTeren::oddelej(Jednotka *komu)
{komu->heal(0);}
