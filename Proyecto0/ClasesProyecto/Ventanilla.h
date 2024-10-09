#pragma once
#include <string>
#include <iostream>
#include "Tiquete.h"

using std::ostream;

using std::string;
class Ventanilla

    /*
    * En este archivo se aloja el objeto Ventanilla y todos sus atributos.
    * También hay algunas funciones básicas del objeto.
    */
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