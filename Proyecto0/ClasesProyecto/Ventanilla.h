#pragma once
#include <string>
#include <iostream>
#include "Tiquete.h"

using std::ostream;
using std::string;

/*
* En este archivo se aloja el objeto Ventanilla y todos sus atributos, esta es la que se encarga de atender los tiquetes.
* Es administrada y usada por el area.
* También hay algunas funciones básicas del objeto
*/

class Ventanilla
{
public:
    string Nombre;
    Tiquete* TiqueteActual;
    int Atendidos;
    float TiempoEspera;

    Ventanilla(const string& nombre)
    {
        Nombre = nombre;
        TiqueteActual = nullptr;
        Atendidos = 0;
        TiempoEspera = 0.f;
    }

    ~Ventanilla()
    {
        delete TiqueteActual;
    }

    void Atender(Tiquete* tiquete)
    {
        delete TiqueteActual;
        TiqueteActual = tiquete;
        TiqueteActual->Atender();
        TiempoEspera += TiqueteActual->getTiempoEspera();
        Atendidos++;
    }
};

inline ostream& operator <<(ostream& os, const Ventanilla& ventanilla) {
    os << "(" << ventanilla.Nombre << ")";
    return os;
}