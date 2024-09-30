#pragma once
#include "Area.h"
#include "Servicio.h"
#include "TipoUsuario.h"
#include "../Estructuras/Abstractas/List.h"

class Local
{
public:
    int Contador = 100;
    List<Area*>* Areas;
    List<Servicio*>* Servicios;
    List<TipoUsuario*>* TiposUsuario;

    void AgregarArea(string Codigo, string Descripcion, int Ventanillas);
    void AgregarServicio(string Descripcion, int Prioridad);
    void AgregarTipoUsuario(string Nombre, int Prioridad);
    void EliminarTipoUsuario();
};
