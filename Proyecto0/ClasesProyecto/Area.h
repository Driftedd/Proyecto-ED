#pragma once
#include <string>

#include "Ventanilla.h"
#include "../Estructuras/Abstractas/List.h"
#include "../Estructuras/Abstractas/PriorityQueue.h"

using std::string;
class Area
{
public:
    string Descripcion;
    string Condigo;
    List<Ventanilla*>* Ventanillas;
    PriorityQueue<Tiquete*>* Cola;
    
};
