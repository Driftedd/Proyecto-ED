#pragma once
#include "Opcion.h"

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
