#pragma once
#include <string>
#include <chrono>
#include <iostream>

using std::string;
using std::ostream;

class Tiquete
{
public:
    string Codigo;
    int PrioridadFinal;
    time_t Creado;
    time_t Atendido;

    Tiquete(string Codigo, int PU, int PS)
    {
        PrioridadFinal = PU * 10 + PS;
        this->Codigo = Codigo;
        Creado = std::time(nullptr);
    }

    void Atender()
    {
        Atendido = std::time(nullptr);
    }

    float getTiempoEspera()
    {
        return (float)difftime(Creado, Atendido);
    }
};

inline ostream& operator <<(ostream& os, const Tiquete& tiquete) {
    os << "(" << tiquete.Codigo << ", " << tiquete.PrioridadFinal << ", " << tiquete.Creado<<")";
    return os;
}
