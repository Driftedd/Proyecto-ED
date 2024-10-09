#pragma once
#include "Area.h"
#include "Servicio.h"
#include "TipoUsuario.h"
#include "../Estructuras/Abstractas/List.h"

/*
 * Local: Esta clase sirve como administrador de todos los otros objetos necesarios para el proyecto. Facilita la
 * coordinación entre multiples objetos, como al agregar un tiquete, ejecutando lógica en Area, Servicio y TipoUsuario
 */

class Local
{
public:
    int Contador = 100;
    List<Area*>* Areas;
    List<Servicio*>* Servicios;
    List<TipoUsuario*>* TiposUsuario;
    Local();
    ~Local();

    void MostarEstadoColas();
    void AgregarArea(string Codigo, string Descripcion, int Ventanillas);
    void AgregarServicio(string Descripcion, int Prioridad,Area* miArea);
    void AgregarTipoUsuario(string Nombre, int Prioridad);
    Tiquete* AgregarTiquete(Servicio* servicio, TipoUsuario* usuario);
    void VaciarTiquetes();
    void EliminarTipoUsuario();
    void EliminarServicio();
    void EliminarArea();
    Area* getAreaPos(int Lugar);
    void ModificarCantidadVentanillas();
    void EliminarAreas();
};
