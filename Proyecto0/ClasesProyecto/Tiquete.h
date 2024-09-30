#pragma once
#include <string>
#include <chrono>

using std::string;

class Tiquete
{
public:
    string Codigo;
    int PrioridadFinal;
    time_t Creado;

    Tiquete(string Codigo, int PU, int PS)
    {
        PrioridadFinal = PU * 10 + PS;
        this->Codigo = Codigo;
        Creado = std::time(nullptr);
    }
};
