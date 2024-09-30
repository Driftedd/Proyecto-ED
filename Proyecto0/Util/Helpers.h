#pragma once
#include <iostream>
#include <string>

class Helpers
{
public:
    static int GetInt()
    {
        std::string Value;
        while (true)
        {
            std::cout << "Ingrese un numero entero: " << std::endl;
            std::cin >> Value;
            try
            {
                int Number = std::stoi(Value);
                return Number;
            }
            catch (...)
            {
                std::cout << "El valor ingresado no es un numero entero\n";
            }
        }
    }
};
