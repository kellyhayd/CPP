#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void) {

	ScavTrap fighterOne("Luke");
	FragTrap fighterTwo("Rey");
	DiamondTrap fighterThree("Kyle");
	std::cout << std::endl;

	fighterOne.attack("Kyle");
	fighterTwo.takeDamage(fighterOne.getAttackDamage());
	fighterTwo.attack("Kyle");
	fighterThree.takeDamage(fighterTwo.getAttackDamage());
	fighterThree.attack("Luke");
	fighterOne.takeDamage(fighterThree.getAttackDamage());

	std::cout << "\nThe fight ends because fighter one is in defensive mode,\n"
		<< "fighter two is trying to make peace with a high five!\n"
		"and fighter three doesn't know who he is.\n" << std::endl;

	fighterOne.guardGate();
	fighterTwo.highFivesGuys();
	fighterThree.whoAmI();
	std::cout << std::endl;

	return (0);
}
