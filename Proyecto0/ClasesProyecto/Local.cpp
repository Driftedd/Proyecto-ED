#include "Local.h"

#include "../Estructuras/Concretas/ArrayList.h"

Local::Local()
{
    Areas = new ArrayList<Area*>(10, true);
    Servicios = new ArrayList<Servicio*>(10, true);
    TiposUsuario = new ArrayList<TipoUsuario*>(10, true);
}

Local::~Local()
{
    for (int i = 0;i<Servicios->getSize();i++)
    {
        delete Servicios->remove();    
    }
    delete Servicios;
    
    for (int i = 0;i<Areas->getSize();i++)
    {
        delete Areas->remove();    
    }
    delete Areas;
    
    for (int i = 0;i<TiposUsuario->getSize();i++)
    {
        delete TiposUsuario->remove();    
    }
    delete TiposUsuario;
}

void Local::MostarEstadoColas()
{
    
}

void Local::AgregarTipoUsuario(string Nombre, int Prioridad)
{
    TiposUsuario->append(new TipoUsuario(Nombre, Prioridad));
}
void Local::AgregarServicio(string Nombre, int Prioridad, Area* miArea)
{
    Servicios->append(new Servicio(Nombre, Prioridad, miArea));
}

Area* Local::getAreaPos(int Lugar) {
    Areas->goToPos(Lugar);
    return Areas->getElement();
}

void Local::VaciarTiquetes()
{
    for(Areas->goToStart(); !Areas->atEnd(); Areas->next())
    {
        Areas->getElement()->ClearVentanillas();
        //Areas->getElement()->Cola->clear();    
    }
}
