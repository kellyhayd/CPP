#include <iostream>
#include <string>

int	main(){
	std::string		string = "HI THIS IS BRAIN";
	std::string*	stringPTR = &string;
	std::string		&stringREF = string;

	std::cout << "Memory address of string: " << &string << std::endl;
	std::cout << "Memory address of stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory address of stringREF: " << &stringREF << std::endl;
	std::cout << "\n";

	std::cout << "Value of string: " << string << std::endl;
	std::cout << "Value of stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value of stringREF: " << stringREF << std::endl;

	return (0);
}
