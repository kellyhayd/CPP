#include "Zombie.hpp"
#include <iomanip>

int	main(){
	std::cout << BLINK << RED << "\n----------------------------------------" << RESET << std::endl;
	std::cout << BOLD << RED << "   Testing Allocation in Heap with New" << RESET << std::endl;
	std::cout << BLINK << RED << "----------------------------------------\n" << RESET << std::endl;

	std::cout << "Creating Rick, the first of his kind" << RESET << std::endl;
	Zombie *zombie = newZombie("Rick");
	std::cout << "Announcing Rick" << RESET << std::endl;
	zombie->announce();
	std::cout << "Goodbye Rick" << RESET << std::endl;
	delete zombie;

	std::cout << BLINK << RED << "\n----------------------------------------" << RESET << std::endl;
	std::cout << BOLD << RED << "   Testing Allocation in Stack" << RESET << std::endl;
	std::cout << BLINK << RED << "----------------------------------------\n" << RESET << std::endl;

	std::cout << "Creating Morty, the second of his kind" << RESET << std::endl;
	Zombie zombie2("Morty");
	std::cout << "Announcing Morty" << RESET << std::endl;
	zombie2.announce();
	std::cout << "Goodbye Morty" << RESET << std::endl;

	std::cout << BLINK << RED << "\n---------------------------------------------------" << RESET << std::endl;
	std::cout << BOLD << RED << "   Testing Allocation in Stack with the function" << RESET << std::endl;
	std::cout << BLINK << RED << "---------------------------------------------------\n" << RESET << std::endl;

	std::cout << "Creating Summer the third of his kind" << RESET << std::endl;
	randomChump("Summer");
	std::cout << "Goodbye Summer\n" << RESET << std::endl;

	return (0);
}
