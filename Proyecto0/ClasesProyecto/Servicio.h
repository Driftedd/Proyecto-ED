#pragma once
#include <string>
#include <iostream>
#include "Area.h"

using std::string;
using std::ostream;

class Servicio
{
public:
    string Nombre;
    int Prioridad;
    Area* MiArea;
};

inline ostream& operator <<(ostream& os, const Servicio& servicio) {
    os << "(" << servicio.Nombre << ", " << servicio.Prioridad << ")";
    return os;
}
