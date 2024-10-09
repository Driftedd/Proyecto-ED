#pragma once
#include "Opcion.h"

/*
 * Autor: Mariano Soto
 * Funcion: Clase hija de Opcion para que pueda ser agregada a listas de opciones, implementa una versión muy rudimentaria
 * de un patron observador para así poder dinámicamente enlazarse con funciones que pueden proveer de cualquier lugar del programa,
 * estas funciones deberan ser estáticas y su firma debe encajar con el typename E: void NombreFuncion(E* objeto)
 */

template <typename E>
class Funcion: public Opcion<E>
{
public:
    void (*Delegado)(E*);

    Funcion(std::string nombre, void (*delegado)(E*))
    {
        this->Nombre = nombre;
        Delegado = delegado;
    }

    void Ejecutar(E* Objeto)
    {
        Delegado(Objeto);
    }
};
