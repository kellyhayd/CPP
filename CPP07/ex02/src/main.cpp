#include <cstdlib>
#include <iostream>
#include "Array.hpp"
#include "colors.hpp"

#define MAX_VAL 750

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
	std::cout << BOLD << RED <<  "teste 01" << RESET << std::endl;
    int* mirror = new int[MAX_VAL];
	std::cout << BOLD << RED <<  "teste 02" << RESET << std::endl;
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
		std::cout << BOLD << RED <<  "teste 03" << RESET << std::endl;
        Array<int> test(tmp);
		std::cout << BOLD << RED <<  "teste 04" << RESET << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
		std::cout << BOLD << RED <<  "teste 05" << RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
		std::cout << BOLD << RED <<  "teste 06" << RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
	std::cout << BOLD << RED <<  "teste 08" << RESET << std::endl;
    delete [] mirror;
    return 0;
}
