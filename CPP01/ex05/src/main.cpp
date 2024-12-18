#include <iostream>
#include "Harl.hpp"

int	main(){
	Harl harl;

	std::cout << BLINK << RED << "\n------ DEBUG Level ------" << RESET << std::endl;
	harl.complain("DEBUG");
	std::cout << BLINK << RED << "\n------ INFO Level ------" << RESET << std::endl;
	harl.complain("INFO");
	std::cout << BLINK << RED << "\n------ WARNING Level ------" << RESET << std::endl;
	harl.complain("WARNING");
	std::cout << BLINK << RED << "\n------ ERROR Level ------" << RESET << std::endl;
	harl.complain("ERROR");
	std::cout << BLINK << RED << "\n------ No valid Level ------" << RESET << std::endl;
	harl.complain("42");

	return (0);
}
