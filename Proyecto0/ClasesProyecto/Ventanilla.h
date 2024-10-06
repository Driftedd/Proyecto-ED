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

    Ventanilla(const string& nombre)
    {
        Nombre = nombre;
        TiqueteActual = nullptr;
    }
};

inline ostream& operator <<(ostream& os, const Ventanilla& ventanilla) {
    os << "(" << ventanilla.Nombre << ")";
    return os;
}