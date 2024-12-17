#include "Zombie.hpp"

int	main(){
	int i;
	std::cout << BLINK << RED << "----------------------------------------" << RESET << std::endl;
	std::cout << INVERSE << RED << "Creating A Horde of ZOMBIES" << RESET << std::endl;
	std::cout << BLINK << RED << "----------------------------------------" << RESET << std::endl;

	Zombie *zombie;
	zombie = zombieHorde(10, "Bill Murray");

	std::cout << BLINK << RED << "----------------------------------------" << RESET << std::endl;
	std::cout << INVERSE << RED << "CALLING THE HORDE" << RESET << std::endl;
	std::cout << BLINK << RED << "----------------------------------------" << RESET << std::endl;

	for (i = 0; i < 10; i++)
		zombie->announce();

	std::cout << BLINK << RED << "----------------------------------------" << RESET << std::endl;
	std::cout << INVERSE << RED << "RICK GRIMES IS HERE TO SAVE THE DAY" << RESET << std::endl;
	std::cout << BLINK << RED << "----------------------------------------" << RESET << std::endl;

	delete[] zombie;
	return (0);
}
