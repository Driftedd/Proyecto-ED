#pragma once
#include <string>
#include "Area.h"

using std::string;

class Servicio
{
public:
    string Nombre;
    int Prioridad;
    Area* MiArea;
};
