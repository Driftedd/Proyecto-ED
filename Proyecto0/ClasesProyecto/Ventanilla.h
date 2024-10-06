#pragma once
#include <string>
#include <iostream>
#include "Tiquete.h"

using std::ostream;

using std::string;
class Ventanilla
{
public:
    string Nombre;
    Tiquete* TiqueteActual;
    int Atendidos;

    Ventanilla(const string& nombre)
    {
        Nombre = nombre;
        TiqueteActual = nullptr;
        Atendidos = 0;
    }

    void Atender(Tiquete* tiquete)
    {
        delete TiqueteActual;
        TiqueteActual = tiquete;
        TiqueteActual->Atender();
        Atendidos++;
    }
};

inline ostream& operator <<(ostream& os, const Ventanilla& ventanilla) {
    os << "(" << ventanilla.Nombre << ")";
    return os;
}