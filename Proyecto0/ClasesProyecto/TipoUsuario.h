#pragma once
#include <string>
#include <iostream>

using std::string;
using std::ostream;

/*
 * Autor: Javier Vega
 * En este archivo se aloja la clase "TipoUsuario", contiene atributos con los que trabajar los métodos.
 * Es uno de los 2 elemetos que se toman en cuenta para determinar prioridad en una cola.
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
