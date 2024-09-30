#pragma once
#include <iostream>
#include <string>

#include "../Estructuras/Concretas/ArrayList.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

template <typename E>
class Menu
{
public:
    typedef void (*MenuFunc)(E*);
private:
    ArrayList<MenuFunc>* MenuFuncs;
    string MenuText;
    int Options;
    int ExitValue = 0;
    E* Objeto;
    
public:
    Menu(string Text, E* Objeto, ArrayList<MenuFunc>* Functions)
    {
        MenuText = Text;
        MenuFuncs = Functions;
        this->Objeto = Objeto;
        if (Functions)
        {
            Options = Functions->getSize();    
        }
        else
        {
            Options = 0;
        }
    }
    ~Menu()
    {
        delete MenuFuncs;
        delete Objeto;
        
    }
    E* getObjeto()
    {
        return Objeto;
    }
    int MostrarMenu()
    {
        int SelectedOption = -1;
        while (SelectedOption < 0 || SelectedOption > Options)
        {
            cout << MenuText << endl;
            cin >> SelectedOption;
            if (SelectedOption < 0 || SelectedOption > Options)
            {
                system("cls");
                cout<<"\n Error, Ingrese una opcion entre 1 y "<<Options<<"\n";
                continue;
            }
            if (SelectedOption == ExitValue) return -1;
            SelectedOption--;
        }
        MenuFuncs->goToPos(SelectedOption);
        MenuFuncs->getElement()(Objeto);
        return 1;
    }
};
