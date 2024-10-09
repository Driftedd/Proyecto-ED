#pragma once
#include <string>
#include <chrono>
#include <iostream>

using std::string;
using std::ostream;

/*
 * En este archivo se maneja la clase "tiquete". Representa un espacio en las
 * colas, guarda estadisticas para su tiempo de espera.
 */

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
        return (float)difftime(Atendido, Creado);
    }
};

inline ostream& operator <<(ostream& os, const Tiquete& tiquete) {
    os << "( "<< tiquete.Codigo<<" )";
    return os;
}
