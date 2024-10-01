#pragma once

#include <iostream>

#include "../../Estructuras/Abstractas/List.h"
#include "../../Estructuras/Concretas/ArrayList.h"
#include "Opciones/Opcion.h"

template <typename E> 
class Menu
{
public:
    List<Opcion<E>*>* Opciones;
    E* Objeto;
    int ExitValue;

    Menu(E* objeto, int exitValue = 0)
    {
        Opciones = new ArrayList<Opcion<E>*>();
        Objeto = objeto;
        ExitValue = exitValue;
    }
    ~Menu()
    {
        delete Opciones;
    }

    int MostrarMenu()
    {
        int SelectedOption = -1;
        while (SelectedOption < 0 || SelectedOption > Opciones)
        {
            int i = 1;
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
        
        Opciones->goToPos(SelectedOption);
        Opcion<E>* Seleccionada = Opciones->getElement();
        Seleccionada->Ejecutar(Objeto);
        return 1;
    }
};
