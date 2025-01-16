#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) {
	{
		FragTrap blep("Nestor");

		std::cout << INVERSE << "Health Points tests" << RESET << std::endl;

		blep.takeDamage(1);
		blep.beRepaired(2);
		blep.takeDamage(11);
		blep.takeDamage(1);
		std::cout << std::endl;

		std::cout << INVERSE << "Energy tests" << RESET << std::endl;

		blep.attack("You");
		blep.beRepaired(1);
		blep.attack("A ghost");
		blep.highFivesGuys();
	}
	std::cout << std::endl;
	std::cout << INVERSE << "Tests done, time to fight." << RESET << std::endl;
	std::cout << std::endl;
	{
		ScavTrap fighterOne("João");
		FragTrap fighterTwo("Maria");

		fighterOne.attack("Maria");
		fighterTwo.takeDamage(fighterOne.getAttackDamage());
		fighterTwo.attack("João");
		fighterOne.takeDamage(fighterTwo.getAttackDamage());
		fighterOne.guardGate();
		fighterTwo.highFivesGuys();
		std::cout << "The fight ends cuz one fighter are in defensive mode "
							<< "and the other guy are trying to make peace with a high five!" << std::endl;
	}

  return (0);
}