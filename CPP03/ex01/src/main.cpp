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
	/* setuping for energy tests */
	// blop.setEnergyPoint(0);
	// blop.setHitPoints(10);
	blop.attack("You again");
	blop.beRepaired(1);
	blop.attack("A ghost");
	blop.guardGate();
}
	std::cout << std::endl;
	std::cout << INVERSE << "Tests done, now is time to fight." << RESET << std::endl;
	std::cout << std::endl;
{
	ScavTrap fighterOne("Guile");
	ScavTrap fighterTwo("Tom");
	fighterOne.attack("Tom");
	fighterTwo.takeDamage(fighterOne.getAttackDamage());
	fighterTwo.attack("Guile");
	fighterOne.takeDamage(fighterTwo.getAttackDamage());
	fighterOne.guardGate();
	fighterTwo.guardGate();
	std::cout << BOLD << MAGENTA << "The fight ends cuz both fighters "\
		"are in defensive mode..." << RESET << std::endl;
}
return (0);
}
