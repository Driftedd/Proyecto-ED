
#include "ClasesProyecto/Area.h"
#include "ClasesProyecto/Local.h"
#include "ClasesProyecto/TipoUsuario.h"
#include "Util/Menu.h"

using std::string;
using std::cout;

#pragma region FuncsMenuUsuarios
typedef List<TipoUsuario*> ListaUsuarios;

void AgregarUsuario(ListaUsuarios* Objeto)
{
    cout<<"AgregarUsuario\n";
}
void EliminarUsuario(ListaUsuarios* Objeto)
{
    cout<<"AgregarUsuario\n";
}
Menu<ListaUsuarios>* CrearMenuUsuarios()
{
    string TextMenuUsuarios = "Menu Tipos de Usuario:\n\t1. Agregar\n\t2. Eliminar\n\t0. Regresar\n";
    auto FuncsMenuUsuarios = new ArrayList<Menu<ListaUsuarios>::MenuFunc>();
    FuncsMenuUsuarios->append(AgregarUsuario);
    FuncsMenuUsuarios->append(EliminarUsuario);
    
    auto Usuarios = new ArrayList<TipoUsuario*>(); 
    auto MenuUsuarios = new Menu<ListaUsuarios>(TextMenuUsuarios, Usuarios, FuncsMenuUsuarios);
    return MenuUsuarios;
}
#pragma endregion 

#pragma region FuncsMenuAreas
typedef List<Area*> ListaAreas;

void AgregarArea(ListaAreas* Areas)
{
    cout<<"AgregarArea\n";
}
void ModificarVentanillas(ListaAreas* Areas)
{
    cout<<"ModificarVentanilla\n";
}
void EliminarArea(ListaAreas* Areas)
{
    cout<<"EliminarArea\n";
}

Menu<ListaAreas>* CrearMenuAreas()
{
    string TextoMenuAreas= "Menu Areas:\n\t1. Agregar\n\t2. Modificar Ventanillas\n\t3. Eliminar\n\t0. Regresar\n";
    auto FuncsMenuAreas = new ArrayList<Menu<ListaAreas>::MenuFunc>();
    FuncsMenuAreas->append(AgregarArea);
    FuncsMenuAreas->append(ModificarVentanillas);
    FuncsMenuAreas->append(EliminarArea);

    ListaAreas* Areas = new ArrayList<Area*>();
    auto MenuAreas = new Menu<ListaAreas>(TextoMenuAreas, Areas, FuncsMenuAreas);
    return MenuAreas;
}
#pragma endregion 

#pragma region FuncsMenuPrincipal

void TipoUsuario(int* Objeto)
{
    *Objeto = 1;
}

Menu<int>* CrearMenuPrincipal()
{
    string TextMenuPrincipal = "";
    auto MenuPrincipalFuncs = new ArrayList<Menu<int>::MenuFunc>();
    MenuPrincipalFuncs->append(TipoUsuario);
    
    Menu<int>* MenuPrincipal = new Menu<int>(TextMenuPrincipal, new int(), MenuPrincipalFuncs);
    return MenuPrincipal;
}
#pragma endregion 

int main()
{
    //Menu<Local>* MenuLocal = new Menu<Local>();
    Menu<ListaAreas>* MenuAreas = CrearMenuAreas();
    Menu<int>* MenuPrincipal = CrearMenuPrincipal();
    int MenuResult = 0;
    while (MenuResult != -1)
    {
        MenuResult = MenuPrincipal->MostrarMenu();
        switch (MenuPrincipal->getObjeto())
        {
        case 0:
            break;
        default:
            break;
        };
        
        system("pause");
    }
    delete MenuPrincipal;
    delete MenuAreas;
}
    