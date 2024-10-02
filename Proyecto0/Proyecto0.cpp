
#include "ClasesProyecto/Area.h"
#include "ClasesProyecto/Local.h"
#include "Util/Menu/Menu.h"
#include "Util/Menu/Opciones/Funcion.h"
#include "Util/Menu/Opciones/Submenu.h"

using std::string;
using std::cout;

#pragma region FuncsMenuUsuarios
void AgregarUsuario(Local* Local)
{
    cout<<"Agregar Area"<<endl;
}
#pragma endregion 

#pragma region FuncsMenuAreas
void AgregarArea(Local* Local)
{
    cout<<"Agregar Area"<<endl;
}
#pragma endregion 

#pragma region FuncsMenuPrincipal

#pragma endregion 

int main()
{
    //MenuAreas
    Submenu<Local>* SubMenuUsuarios = new Submenu<Local>("SubMenu Usuarios");
    Submenu<Local>* MenuUsuarios = new Submenu<Local>("Menu Usuarios");
    MenuUsuarios->AgregarOpcion(new Funcion<Local>("Agregar Area", AgregarArea));
    MenuUsuarios->AgregarOpcion(SubMenuUsuarios);

    Local* MiLocal = new Local();
    Menu<Local>* MainMenu = new Menu<Local>(MiLocal, "MenuPrincipal");
    MainMenu->AgregarOpcion(MenuUsuarios);
    MainMenu->AgregarOpcion(new Funcion<Local>("Agregar Usuario", AgregarUsuario));

    int ResultadoMenu = 0;
    while (ResultadoMenu != -1)
    {
        ResultadoMenu = MainMenu->MostrarMenu();
    }
    int* a = new int[2];
}
    