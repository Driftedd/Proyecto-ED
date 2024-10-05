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

    TipoUsuario(const string& nombre, int prioridad)
        : Nombre(nombre),
          Prioridad(prioridad)
    {
    }
};

inline ostream& operator <<(ostream& os, const TipoUsuario& usuario) {
    os << "(" << usuario.Nombre << ", " << usuario.Prioridad << ")";
    return os;
}
