#pragma once
#include <string>
#include <iostream>
#include "Ventanilla.h"
#include "../Estructuras/Abstractas/List.h"
#include "../Estructuras/Abstractas/PriorityQueue.h"
#include "../Estructuras/Concretas/HeapPriorityQueue.h"
#include "../Estructuras/Concretas/ArrayList.h"

using std::ostream;
using std::string;
class Area
{
public:
    string Descripcion;
    string Codigo;
    List<Ventanilla*>* Ventanillas;
    PriorityQueue<Tiquete*>* Cola;
    int Dispensados;

    Area(const string& descripcion, const string& codigo, int ventanillas)
    {
        Descripcion = descripcion;
        Codigo = codigo;
        Ventanillas = new ArrayList<Ventanilla*>(20, true);
        for (int i = 0; i<ventanillas; i++)
        {
            Ventanillas->append(new Ventanilla(codigo + std::to_string(i+1)));
        }
        Cola = new HeapPriorityQueue<Tiquete*>(10, true);
        
        Dispensados = 0;
    }
    ~Area()
    {
        delete Ventanillas;
        delete Cola;
    }
    void AgregarTiquete(Tiquete* tiquete)
    {
        Cola->insert(tiquete, tiquete->PrioridadFinal);
        Dispensados++;
    }
    void ClearVentanillas()
    {
        
    }
    
};


inline ostream& operator <<(ostream& os, const Area& area) {
    os << "(" << area.Descripcion << ")";
    return os;
}