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

void Local::ModificarCantidadVentanillas() {
    int area_seleccionada = 0;
    int ventanillas_nuevas = 0;
    std::cout << "Seleccione el area para modificar la cantidad de ventanillas:\n";
    for (int i = 0; i < Areas->getSize(); i++) {
        Areas->goToPos(i);
        Area* area = Areas->getElement();
        std::cout << i + 1 << ". " << area->Descripcion << std::endl;
    }
    std::cout << endl << "Ingrese el numero del area que desea modificar: ";
    std::cin >> area_seleccionada;
    std::cout << endl;

    if (area_seleccionada < 1 || area_seleccionada > Areas->getSize()) {
        std::cout << "Numero de area invalido. Intente nuevamente." << std::endl;
        return;
    }
    Areas->goToPos(area_seleccionada - 1);
    Area* area = Areas->getElement();
    int cantidad_inicial = area->Ventanillas->getSize();
    std::cout << "El area seleccionada tiene " << cantidad_inicial << " ventanillas." << std::endl;
    std::cout << "Ingrese la nueva cantidad de ventanillas: ";
    std::cin >> ventanillas_nuevas;

    List<Ventanilla*>* ventanillas = area->Ventanillas;
    ventanillas->clear();

    for (int j = 0; j < ventanillas_nuevas; j++) {
        ventanillas->append(new Ventanilla(area->Codigo + std::to_string(j + 1)));
    }

    std::cout << "El area ahora tendra " << ventanillas_nuevas << " ventanillas." << std::endl;
    system("pause");
    system("cls");
}
