#include <cstdlib>
#include <iostream>
#include "Array.hpp"
#include "colors.hpp"


int	main(void)
{

	std::cout << INVERSE << "   Default constructor      " << RESET << std::endl;
	::Array<int> array1;
	std::cout << BOLD << "array1 size: " << YELLOW << array1.size() << " " << RESET << std::endl;
	std::cout << std::endl;


	std::cout << INVERSE << "   Constructor with size 5  " << RESET << std::endl;
	::Array<int> array2(5);
	std::cout << BOLD << "array2 size: " << YELLOW << array2.size() << " " << RESET << std::endl;
	std::cout << std::endl;


	std::cout << INVERSE << "   Copy constructor   " << RESET << std::endl;
	::Array<int> array3(array2);
	std::cout << BOLD << "array3 size: " << YELLOW << array3.size() << " " << RESET << std::endl;
	std::cout << std::endl;


	std::cout << INVERSE << "   array2 shouldn't change array3   " << RESET << std::endl;
	srand(time(NULL));
	std::cout << YELLOW << "array2:" << RESET << std::endl;
	for (unsigned int i = 0; i < array2.size(); i++) {
		array2[i] = rand() % 300;
		std::cout << BOLD << array2[i] << " ";
	}
	std::cout << std::endl;
	std::cout << YELLOW << "array3:" << RESET << std::endl;
	for (unsigned int i = 0; i < array3.size(); i++) {
		std::cout << BOLD << array3[i] << " ";
	}
	std::cout << RESET << std::endl;


	std::cout << INVERSE << "\n   Assignment operator   " << RESET << std::endl;
	array3 = array2;
	std::cout << YELLOW << "array3:" << RESET << std::endl;
	for (unsigned int i = 0; i < array3.size(); i++) {
		std::cout << BOLD << array3[i] << " ";
	}
	std::cout << RESET << std::endl;


	std::cout << INVERSE << "\n   Try to access an index out of bounds   " << RESET << std::endl;
	try {
		std::cout << YELLOW << "array2[6]: " << array2[6] << RESET << std::endl;
	} catch (std::exception& e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}


	std::cout << INVERSE << "\n   Array of strings   " << RESET << std::endl;
	::Array<std::string> strArray(3);
	strArray[0] = "CPP";
	strArray[1] = "module";
	strArray[2] = "07";

	std::cout << YELLOW << "strArray:" << RESET << std::endl;
	for (unsigned int i = 0; i < strArray.size(); i++) {
		std::cout << BOLD << strArray[i] << " ";
	}
	std::cout << RESET << std::endl;

	return (0);
}




// #define MAX_VAL 750
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
//     //SCOPE
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
