#pragma once
#include <list>

#include "Opcion.h"
#include "../../../Estructuras/Abstractas/List.h"

template <typename E>
class Submenu : public Opcion<E>
{
public:
    List<Opcion<E>*>* Opciones;
    
};
