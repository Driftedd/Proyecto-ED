#pragma once
#include "../Estructuras/Abstractas/List.h"
#include <iostream>
#include <type_traits>
#include <string>

class Helpers
{
public:
    static int GetInt(std::string texto = "Ingrese un numero entero: ")
    {
        std::string Value;
        while (true)
        {
            try
            {
                std::cout << texto;
                std::getline(std::cin, Value);
                int Number = std::stoi(Value);
                return Number;
            }
            catch (...)
            {
                std::cout << "El valor ingresado no es un numero entero\n";
            }
        }
    }
    template<typename E>
    static void GetElement(List<E>* Lista, bool& Cancelado, E& Resultado)
    {
        while (true)
        {
            int SelectedOption = -1;
            int i = 1;
            for (Lista->goToStart(); !Lista->atEnd(); Lista->next())
            {
                if (std::is_pointer<E>::value)
                {
                    std::cout << i << ". " << *Lista->getElement()<< std::endl;    
                }
                else
                {
                    std::cout << i << ". " << Lista->getElement() << std::endl;
                }
                i++;
            }
            std::cout << "\t" << "0. Salir\n";

            std::cin >> SelectedOption;
            if (SelectedOption == 0)
            {
                Cancelado = true;
                return;
            }
            if (SelectedOption < 1 || SelectedOption > Lista->getSize())
            {
                system("cls");
                std::cout << "\n Error, Ingrese una opcion entre 1 y " << Lista->getSize() << "\n";
                continue;
            }
            Cancelado = false;
            Lista->goToPos(SelectedOption-1);
            Resultado = Lista->getElement();
            return;
        }
    }
    
};
