#include "../include/ClapTrap.hpp"

int	main(void)
{
	ClapTrap blip("Jorge");

	std::cout << std::endl;
	std::cout << INVERSE << "Health Points tests" << RESET << std::endl;

	blip.takeDamage(1);
	blip.beRepaired(2);
	blip.takeDamage(11);
	blip.takeDamage(1);

	std::cout << std::endl;
	std::cout << INVERSE << "Energy tests" << RESET << std::endl;

	/* setuping for energy tests */
	blip.setEnergyPoints(0);
	blip.setHitPoints(10);

	blip.attack("you");
	blip.beRepaired(1);
	blip.attack("a ghost");

	return (0);
}
