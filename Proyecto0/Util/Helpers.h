#pragma once
#include "../Estructuras/Abstractas/List.h"
#include <iostream>
#include <type_traits>
#include <string>

/*
 * Autor: Mariano Soto
 * Helpers: Clase estática que sirve como biblioteca de funciones que pueden ser utiles, set utilizó principalmente
 * para encapsular funciones que consiguen datos del usuario, note que las funciones son estaticas, permitiendo su
 * utilización sin la necesidad de instanciar un objeto Helper.
 */

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

            std::string Entrada;
            std::getline(std::cin, Entrada);
            try
            {
                SelectedOption = std::stoi(Entrada);
            }
            catch (...)
            {
                system("cls");
                std::cout<<"\n Error, Ingrese una opcion entre 1 y "<<Lista->getSize()<<"\n";
                continue;
            }
            
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
