#include "Radek.h"
Radek::Radek(){m_radek.clear();}
Radek::~Radek(){for (Policko* rad: m_radek){delete rad;}}
