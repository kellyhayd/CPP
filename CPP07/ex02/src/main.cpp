#include <cstdlib>
#include <iostream>
#include "Array.hpp"
#include "colors.hpp"

#define MAX_VAL 750

// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;
//     return 0;
// }


int	main(void)
{

	std::cout << INVERSE << "   Default constructor      " << RESET << std::endl;
	::Array<int> array1;
	std::cout << BOLD << "array1 size: " << YELLOW << array1.size() << " " << RESET << std::endl;
	std::cout << BOLD << "array1 member[0]: " << YELLOW << array1[0] << RESET << std::endl;
	std::cout << std::endl;


	std::cout << INVERSE << "   Constructor with size   " << RESET << std::endl;
	::Array<int> array2(5);
	std::cout << BOLD << "array2 size: " << YELLOW << array1.size() << " " << RESET << std::endl;
	std::cout << BOLD << "array2 member[0]: " << YELLOW << array1[0] << RESET << std::endl;
	std::cout << std::endl;


	std::cout << INVERSE << "   Copy constructor   " << RESET << std::endl;
	::Array<int> array3(array2);
	std::cout << BOLD << "array3 size: " << YELLOW << array1.size() << " " << RESET << std::endl;
	std::cout << BOLD << "array3 member[0]: " << YELLOW << array1[0] << RESET << std::endl;
	std::cout << std::endl;


	std::cout << INVERSE << "   array2 shouldn't change array3   " << RESET << std::endl;
	srand(time(NULL));
	std::cout << YELLOW << "array2:" << RESET << std::endl;
	for (unsigned int i = 0; i < array2.size(); i++) {
		array2[i] = rand();
		std::cout << BOLD << array2[i] << " ";
	}
	std::cout << std::endl;
	std::cout << YELLOW << "array3:" << RESET << std::endl;
	for (unsigned int i = 0; i < array3.size(); i++) {
		std::cout << BOLD << array3[i] << " ";
	}
	std::cout << std::endl;



	std::cout << INVERSE << "   Assignment operator   " << RESET << std::endl;



	std::cout << INVERSE << "   Printing array size   " << RESET << std::endl;
	unsigned int	size = array1.size();
	std::cout << YELLOW << size << RESET << std::endl;
	std::cout << std::endl;


	std::cout << INVERSE << "   Testing assignation operator, array1 numbers + 10   " << RESET << std::endl;
	::Array<int> array2(5);
	for (unsigned int i = 0; i < array2.size(); i++)
	{
		array2[i] = i + 10;
	}

	std::cout << INVERSE << "   Testing copy constructor   " << RESET << std::endl;

	::Array<int> array4(array1);

	for (unsigned int i = 0; i < array4.size(); i++)
	{
		::printColor("array4[" + ::toString(i) + "] = " + ::toString(array4[i]), CYAN);
	}
	std::cout << INVERSE << "   Try to access an element out of limits   " << RESET << std::endl;

	try
	{
		::printColor("array4[5] = " + ::toString(array4[5]), CYAN);
	}
	catch (std::exception& e)
	{
		::printColor(e.what(), RED);
	}

	std::cout << INVERSE << "   Try to access an element a const out of limits   " << RESET << std::endl;

	const ::Array<int> array5(array4);
	try
	{
		::printColor("array5[5] = " + ::toString(array5[5]), CYAN);
	}
	catch (std::exception& e)
	{
		::printColor(e.what(), RED);
	}

	::Array<std::string> strArray(3);
    strArray[0] = "Hello";
    strArray[1] = "World";
    strArray[2] = "!";

    std::cout << INVERSE << "   Printing strArray   " << RESET << std::endl;

    for (unsigned int i = 0; i < strArray.size(); i++)
    {
        ::printColor("strArray[" + ::toString(i) + "] = " + strArray[i], CYAN);
    }

	return (0);
}
