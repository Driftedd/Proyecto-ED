#pragma once
#include <string>
#include <iostream>
#include "Area.h"

using std::string;
using std::ostream;

/*
 * En este archivo se alojan los objetos de tipo "Servicio", los atributos del mismo y un puntero al area asignada.
 * El servicio se utiliza para determinar el area que corresponde a un tiquete y la prioridad del mismo.
 * También se incluyen funciones muy básicas para esta clase.
 */

class Servicio
{
public:
    string Nombre;
    int Prioridad;
    Area* MiArea;
    int Solicitados;

    Servicio(const string& nombre, int prioridad)
    {
        Nombre = nombre;
        Prioridad = prioridad;
        MiArea = nullptr;
        Solicitados = 0;
    }
    
    Servicio(const string& nombre, int prioridad, Area* miArea){
        Nombre=nombre;
        Prioridad=prioridad;
        MiArea=miArea;
    }
    Servicio* Solicitar()
    {
        Solicitados++;
        return this;
    }
};

inline ostream& operator <<(ostream& os, const Servicio& servicio) {
    os << "(" << servicio.Nombre << ", " << servicio.Prioridad << ", " << servicio.MiArea->Descripcion<<")";
    return os;
}
