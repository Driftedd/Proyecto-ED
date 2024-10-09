#pragma once
#include <string>
#include <iostream>

using std::string;
using std::ostream;

/*
 * En este archivo se aloja la clase "TipoUsuario", contiene atributos con los que trabajar los métodos.
 * También se incluyen funciones muy básicas para esta clase.
 */


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
