#pragma once
#include <iostream>

#include "Opcion.h"
#include "../../../Estructuras/Abstractas/List.h"
#include "../../../Estructuras/Concretas/ArrayList.h"

using std::cout;
using std::cin;
using std::endl;

template <typename E>
class Submenu : public Opcion<E>
{
public:
    List<Opcion<E>*>* Opciones;
    int ExitValue = 0;
    bool ExitMenu = false;
    
    Submenu(std::string Nombre, int exitValue = 0)
    {
        this->Nombre = Nombre;
        Opciones = new ArrayList<Opcion<E>*>(10, true);
        ExitValue = exitValue;   
    }
    ~Submenu()
    {
        delete Opciones; 
    }
    void AgregarOpcion(Opcion<E>* opcion)
    {
        Opciones->append(opcion);
    }
    void MostrarMenu(E* Objeto)
    {
        int SelectedOption = -1;
        while (SelectedOption < 0 || SelectedOption > Opciones->getSize())
        {
            int i = 1;
            cout << this->Nombre << endl;
            for (Opciones->goToStart(); !Opciones->atEnd(); Opciones->next())
            {
                cout << "\t" << i<<". " << Opciones->getElement()->Nombre << "\n";
                i++;
            }
            cout << "\t" <<ExitValue<<". Salir\n";
            cin >> SelectedOption;
            if (SelectedOption < 0 || SelectedOption > Opciones->getSize())
            {
                system("cls");
                cout<<"\n Error, Ingrese una opcion entre 1 y "<<Opciones->getSize()<<"\n";
                continue;
            }
            if (SelectedOption == ExitValue)
            {
                ExitMenu = true;
                system("cls");
                return;
            }
            SelectedOption--;
        }
        system("cls");
        Opciones->goToPos(SelectedOption);
        Opcion<E>* Seleccionada = Opciones->getElement();
        Seleccionada->Ejecutar(Objeto);
    }
    void Ejecutar(E* Objeto)
    {
        ExitMenu = false;
        while (!ExitMenu)
        {
            MostrarMenu(Objeto);
        }
    }
};
