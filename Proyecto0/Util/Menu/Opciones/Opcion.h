#pragma once
#include <string>

template <typename E>
class Opcion
{
public:
    std::string Nombre;
    virtual void Ejecutar(E* Objeto) = 0;
};
