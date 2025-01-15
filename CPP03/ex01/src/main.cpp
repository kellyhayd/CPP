#include "../include/ScavTrap.hpp"

int main(void) {
	{
		ScavTrap blop("Valentina");

		std::cout << INVERSE << "Health Points tests" << RESET << std::endl;
		blop.takeDamage(1);
		blop.beRepaired(2);
		blop.takeDamage(11);
		blop.takeDamage(1);
		std::cout << std::endl;

		std::cout << INVERSE << "Energy tests" << RESET << std::endl;

		blop.attack("You");
		blop.beRepaired(1);
		blop.attack("A ghost");
		blop.guardGate();
	}
	std::cout << std::endl;
	std::cout << INVERSE << "Tests done, time to fight." << RESET << std::endl;
	std::cout << std::endl;
	{
		ScavTrap fighterOne("Zorro");
		ScavTrap fighterTwo("Penelope");
		fighterOne.attack("Penelope");
		fighterTwo.takeDamage(fighterOne.getAttackDamage());
		fighterTwo.attack("Zorro");
		fighterOne.takeDamage(fighterTwo.getAttackDamage());
		fighterOne.guardGate();
		fighterTwo.guardGate();
		std::cout << BOLD << MAGENTA << "The fight ends cuz both fighters "\
			"are in defensive mode..." << RESET << std::endl;
	}
	return (0);
}
