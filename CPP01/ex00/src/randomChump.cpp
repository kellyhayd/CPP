#include "Zombie.hpp"

void randomChump(std::string name){
	Zombie	thisZombie(name);
	thisZombie.announce();
}
