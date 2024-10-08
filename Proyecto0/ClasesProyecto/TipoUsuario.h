#pragma once
#include <string>
#include <iostream>

using std::string;
using std::ostream;

class TipoUsuario
{
public:
    string Nombre;
    int Prioridad;
    int Emitidos;

    TipoUsuario(const string& nombre, int prioridad)
    {
        Nombre = nombre;
        Prioridad = prioridad;
        Emitidos = 0;
    }
    
    TipoUsuario* Emitir()
    {
        Emitidos++;
        return this;
    }
};

inline ostream& operator <<(ostream& os, const TipoUsuario& usuario) {
    os << "(" << usuario.Nombre << ", " << usuario.Prioridad << ")";
    return os;
}
