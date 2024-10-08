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
    int Solicitados;

    Servicio(const string& nombre, int prioridad)
    {
        Nombre = nombre;
        Prioridad = prioridad;
        MiArea = nullptr;
        Solicitados = 0;
    }
    
    Servicio(const string& nombre, int prioridad, Area* miArea){
        Nombre=nombre;
        Prioridad=prioridad;
        MiArea=miArea;
    }
    Servicio* Solicitar()
    {
        Solicitados++;
        return this;
    }
};

inline ostream& operator <<(ostream& os, const Servicio& servicio) {
    os << "(" << servicio.Nombre << ", " << servicio.Prioridad << ", " << servicio.MiArea->Descripcion<<")";
    return os;
}
