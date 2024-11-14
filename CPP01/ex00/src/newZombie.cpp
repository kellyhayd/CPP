#include "Zombie.hpp"

Zombie* newZombie(std::string name){
	Zombie*	thisZombie = new Zombie(name);
	return (thisZombie);
}
