#include "Local.h"
#include "../Estructuras/Concretas/ArrayList.h"
#include "../Util/Helpers.h"


    /*
    * Aquí se encuentran muchas de las funciones usadas en el codigo principal, pues el local es el "centro" de todo.
    * También se encuentran distintas listas para permitir el acceso a todos los objetos creados.
    */


Local::Local()
{
    Areas = new ArrayList<Area*>(10, true);
    Servicios = new ArrayList<Servicio*>(10, true);
    TiposUsuario = new ArrayList<TipoUsuario*>(10, true);
}

Local::~Local()
{
    /*
    for (int i = 0;i<Servicios->getSize();i++)
    {
        delete Servicios->remove();    
    }
    */
    delete Servicios;

    /*
    for (int i = 0;i<Areas->getSize();i++)
    {
        delete Areas->remove();    
    }
    */
    delete Areas;

    /*
    for (int i = 0;i<TiposUsuario->getSize();i++)
    {
        delete TiposUsuario->remove();    
    }
    */
    delete TiposUsuario;
}

void Local::MostarEstadoColas()
{
    
}

void Local::AgregarTipoUsuario(string Nombre, int Prioridad)
{
    TiposUsuario->append(new TipoUsuario(Nombre, Prioridad));
}

Tiquete* Local::AgregarTiquete(Servicio* servicio, TipoUsuario* usuario)
{
    if (!servicio || !usuario)
    {
        throw runtime_error("servicio o usuario invalido");
    }
    string Codigo = servicio->MiArea->Codigo + std::to_string(Contador);
    Contador++;
    Tiquete* NuevoTiquete = new Tiquete(Codigo, usuario->Prioridad, servicio->Prioridad);
    servicio->MiArea->AgregarTiquete(NuevoTiquete);
    //servicio->MiArea->Cola->insert(NuevoTiquete, NuevoTiquete->PrioridadFinal);
    
    servicio->Solicitados++;
    usuario->Emitidos++;
    return NuevoTiquete;
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
        Areas->getElement()->ClearCola();
    }
}

void Local::ModificarCantidadVentanillas() {
    int area_seleccionada = 0;
    int ventanillas_nuevas = 0;
    std::cout << "Seleccione el area para modificar la cantidad de ventanillas:\n";
    for (int i = 0; i < Areas->getSize(); i++) {
        Areas->goToPos(i);
        Area* area = Areas->getElement();
        std::cout << i + 1 << ". " << area->Descripcion << std::endl;
    }
    std::cout << endl;
    area_seleccionada = Helpers::GetInt("Ingrese el numero del area que desea modificar: ");
    std::cout << endl;

    if (area_seleccionada < 1 || area_seleccionada > Areas->getSize()) {
        std::cout << "Numero de area invalido. Intente nuevamente." << std::endl;
        return;
    }
    Areas->goToPos(area_seleccionada - 1);
    Area* area = Areas->getElement();
    int cantidad_inicial = area->Ventanillas->getSize();
    std::cout << "El area seleccionada tiene " << cantidad_inicial << " ventanillas." << std::endl;
    ventanillas_nuevas = Helpers::GetInt("Ingrese la cantidad de ventanillas: ");
    while (ventanillas_nuevas <= 0) {
        ventanillas_nuevas=Helpers::GetInt("El número ingresado debe ser mayor a 0: ");
    }


    List<Ventanilla*>* ventanillas = area->Ventanillas;
    for (ventanillas->goToStart(); !ventanillas->atEnd(); ventanillas->next())
    {
        delete ventanillas->getElement();
    }
    ventanillas->clear();

    for (int j = 0; j < ventanillas_nuevas; j++) {
        ventanillas->append(new Ventanilla(area->Codigo + std::to_string(j + 1)));
    }

    std::cout << "El area ahora tendra " << ventanillas_nuevas << " ventanillas." << std::endl;
    system("pause");
    system("cls");
}
