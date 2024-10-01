#pragma once
#include "Opcion.h"

template <typename E>
class Funcion: public Opcion<E>
{
public:
    typedef void (*MenuFunc)(E*);
    MenuFunc* Delegado;

    Funcion(std::string nombre, MenuFunc* delegado)
    {
        this->Nombre = nombre;
        Delegado = delegado;
    }

    void Ejecutar(E* Objeto)
    {
        Delegado(Objeto);
    }
};
