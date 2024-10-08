
#include "ClasesProyecto/Area.h"
#include "ClasesProyecto/Local.h"
#include "Util/Helpers.h"
#include "Util/Menu/Menu.h"
#include "Util/Menu/Opciones/Funcion.h"
#include "Util/Menu/Opciones/Submenu.h"

using std::string;
using std::cout;
int NumServicios = 0;

#pragma region FuncsMenuUsuarios
void AddServicio(Local* Local) {
    string ServicioName;
    cout << "Ingrese el nombre del servicio: ";
    cin.ignore();
    std::getline(std::cin, ServicioName);
    int Prioridad = Helpers::GetInt("Ingrese la prioridad: ");
    Area* AreaDeServicio = Local->getAreaPos(NumServicios);

    

    Local->AgregarServicio(ServicioName, Prioridad,AreaDeServicio);
    NumServicios++;
    cout << "Servicio agregado exitosamente" << endl;
    Local->Servicios->print();
}
void AgregarUsuario(Local* Local)
{
    string Nombre;
    cout << "Ingrese el nombre del tipo de usuario: ";
    cin.ignore();
    std::getline (std::cin, Nombre);

    int Prioridad = Helpers::GetInt("Ingrese la prioridad: ");
    Local->AgregarTipoUsuario(Nombre, Prioridad);
    cout<<"Usuario agregado exitosamente"<<endl;
    Local->TiposUsuario->print();
    system("pause");
    system("cls");
}
void DelServicio(Local* Local) {
    int i = 1;
    cout << "Seleccione un servicio para eliminar" << endl;
    bool Cancelado;
    Servicio* Seleccionado = new Servicio("", -1,Local->Areas->getElement());
    Helpers::GetElement(Local->Servicios, Cancelado, Seleccionado);
    if (Cancelado)
    {
        cout << "Se cancelo la eliminacion" << endl;
        system("pause");
        return;
    }
    cout << "Usuario a eliminar: " << *Local->Servicios->getElement() << endl;
    Local->Servicios->remove();
    Local->VaciarTiquetes();
    NumServicios--;
    system("pause");
}
void EliminarUsuario(Local* Local)
{
    int i = 1;
    cout<<"Seleccione un usuario para eliminar"<<endl;
    bool Cancelado;
    TipoUsuario* Seleccionado = new TipoUsuario("", -1);
    Helpers::GetElement(Local->TiposUsuario, Cancelado, Seleccionado);
    if (Cancelado)
    {
        cout<<"Se cancelo la eliminacion"<<endl;
        system("pause");
        return;
    }
    cout<<"Usuario a eliminar: "<<*Local->TiposUsuario->getElement()<<endl;
    Local->TiposUsuario->remove();
    Local->VaciarTiquetes();
    system("pause");
}

void ModificarCantidadVentanillas(Local* Local)
{
    Local->ModificarCantidadVentanillas();
}
#pragma endregion 

#pragma region FuncsMenuAreas
void AgregarArea(Local* Local)
{
    string Descripcion;
    string Codigo;

    cout << "Ingrese la descripcion del area nueva: ";
    cin.ignore();
    std::getline (std::cin, Descripcion);

    cout << "Ingrese el codigo del area nueva: ";
    cin.ignore();
    std::getline (std::cin, Codigo);
    
    int Ventanillas = Helpers::GetInt("Ingrese la cantidad de ventanillas: ");
    Local->Areas->append(new Area(Descripcion, Codigo, Ventanillas));
    cout<<"Area agregada exitosamente!"<<endl;
    system("pause");
    
}
#pragma endregion 

#pragma region FuncsMenuPrincipal

#pragma endregion 

int main()
{
    //Administracion
    
    //Tipos Usuario
    Submenu<Local>* AdminUsuarios = new Submenu<Local>("Tipos de Usuario");
    AdminUsuarios->AgregarOpcion(new Funcion<Local>("Agregar", AgregarUsuario));
    AdminUsuarios->AgregarOpcion(new Funcion<Local>("Eliminar", EliminarUsuario));

    //Servicios
    Submenu<Local>* AdminServicios = new Submenu<Local>("Servicios");
    AdminServicios->AgregarOpcion(new Funcion<Local>("Agregar", AddServicio));
    AdminServicios->AgregarOpcion(new Funcion<Local>("Eliminar", DelServicio));

    //Areas
    Submenu<Local>* AdminAreas = new Submenu<Local>("Areas");
    AdminAreas->AgregarOpcion(new Funcion<Local>("Agregar", AgregarArea));
    AdminAreas->AgregarOpcion(new Funcion<Local>("Modificar Ventanillas", ModificarCantidadVentanillas));

    
    Submenu<Local>* Admin = new Submenu<Local>("Administracion");
    Admin->AgregarOpcion(AdminUsuarios);
    Admin->AgregarOpcion(AdminAreas);
    Admin->AgregarOpcion(AdminServicios);

    //Menu Principal
    Local* MiLocal = new Local();
    Menu<Local>* MainMenu = new Menu<Local>(MiLocal, "MenuPrincipal");
    MainMenu->AgregarOpcion(Admin);

    int ResultadoMenu = 0;
    while (ResultadoMenu != -1)
    {
        ResultadoMenu = MainMenu->MostrarMenu();
    }
}
    