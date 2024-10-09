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

    /*
    * En este archivo se encuentra el punto de entrada al proyecto, donde se inicializa el Local y el Menu.
    * Este archivo tambien guarda todas las funciones "listener" que el menu utiliza
    */


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
    void ClearCola()
    {
        Cola->clear();
    }
    float GetTiempoEsperaTotal()
    {
        float Resultado = 0.f;
        for (Ventanillas->goToStart(); !Ventanillas->atEnd(); Ventanillas->next())
        {
            Resultado += Ventanillas->getElement()->TiempoEspera;
        }
        return Resultado;
    }
    int GetTotalAtendidos()
    {
        int Resultado = 0;
        for (Ventanillas->goToStart(); !Ventanillas->atEnd(); Ventanillas->next())
        {
            Resultado += Ventanillas->getElement()->Atendidos;
        }
        return Resultado;
    }
    float GetEsperaPromedio()
    {
        if (GetTotalAtendidos() == 0) return 0;
        return GetTiempoEsperaTotal()/((float)GetTotalAtendidos());
    }
    void AtenderSiguiente(Ventanilla* ventanilla)
    {
        auto siguiente = Cola->removeMin();
        ventanilla->Atender(siguiente);
    }
    void VaciarVentanillas() {
        if (Ventanillas != nullptr) {
            for (int i = 0; i < Ventanillas->getSize(); i++) {
                Ventanillas->goToPos(i);
                Ventanilla* ventanilla = Ventanillas->getElement();
                delete ventanilla;
            }
            Ventanillas->clear();
        }
    }
    void EliminarTiquetesAtendidos() {
        PriorityQueue<Tiquete*>* colaTemporal = new HeapPriorityQueue<Tiquete*>(10, true);
        while (!Cola->isEmpty()) {
            Tiquete* tiquete = Cola->removeMin();
            if (tiquete->Atendido <= 0) {
                colaTemporal->insert(tiquete, tiquete->PrioridadFinal);
            }
            else {
                delete tiquete;
            }
        }
        delete Cola;
        Cola = colaTemporal;
    }
};


inline ostream& operator <<(ostream& os, const Area& area) {
    os << "(" << area.Descripcion << ")";
    return os;
}