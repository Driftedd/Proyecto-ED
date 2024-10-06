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
    
    Servicio(const string& nombre, int prioridad, Area* miArea){
        Nombre=nombre;
        Prioridad=prioridad;
        MiArea=miArea;
    
    }
};

inline ostream& operator <<(ostream& os, const Servicio& servicio) {
    os << "(" << servicio.Nombre << ", " << servicio.Prioridad << ", " << servicio.MiArea<<")";
    return os;
}
