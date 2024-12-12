#include "Zombie.hpp"

Zombie::Zombie(){}

Zombie::Zombie(std::string name){
	this->name = name;
	std::cout << "Zombie " << name << " is born" << std::endl;
}

Zombie::~Zombie(){
	std::cout << "Zombie " << name << " is really dead now" << std::endl;
}

std::string Zombie::getName(){
	return (name);
}

void	Zombie::announce(){
	std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << "\n";
}
