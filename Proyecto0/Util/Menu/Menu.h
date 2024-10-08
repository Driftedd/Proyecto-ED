#pragma once

#include "../../Estructuras/Abstractas/List.h"
#include "../../Estructuras/Concretas/ArrayList.h"
#include "Opciones/Opcion.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

/*
 * Menu: Esta clase se utiliza como la base del menu, tiene un arreglo de opciones,
 * dependiendo de la opción que se escoja se selecciona y se llama a su función Opcion::Ejecutar()
 */

template <typename E> 
class Menu
{
public:
    std::string Nombre;
    List<Opcion<E>*>* Opciones;
    E* Objeto;
    int ExitValue;

    Menu(E* objeto, std::string nombre, int exitValue = 0)
    {
        Nombre = nombre;
        Opciones = new ArrayList<Opcion<E>*>(10, true);
        Objeto = objeto;
        ExitValue = exitValue;
    }
    ~Menu()
    {
        delete Opciones;
    }
    void AgregarOpcion(Opcion<E>* opcion)
    {
        Opciones->append(opcion);
    }

    int MostrarMenu()
    {
        int SelectedOption = -1;
        while (SelectedOption < 0 || SelectedOption > Opciones->getSize())
        {
            int i = 1;
            cout << Nombre << endl;
            for (Opciones->goToStart(); !Opciones->atEnd(); Opciones->next())
            {
                std::cout << "\t" << i<<". " << Opciones->getElement()->Nombre << "\n";
                i++;
            }
            std::cout << "\t" <<ExitValue<<". Salir\n";
            std::cin >> SelectedOption;
            if (SelectedOption < 0 || SelectedOption > Opciones->getSize())
            {
                system("cls");
                std::cout<<"\n Error, Ingrese una opcion entre 1 y "<<Opciones->getSize()<<"\n";
                continue;
            }
            if (SelectedOption == ExitValue) return -1;
            SelectedOption--;
        }
        system("cls");
        Opciones->goToPos(SelectedOption);
        Opcion<E>* Seleccionada = Opciones->getElement();
        Seleccionada->Ejecutar(Objeto);
        return 1;
    }
};
