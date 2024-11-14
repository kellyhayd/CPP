#include "Zombie.hpp"

int	main(){
	Zombie*	zombie1 = newZombie("Rick");
	zombie1->announce();
	delete zombie1;

	randomChump("Morty");

	return (0);
}
