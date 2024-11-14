#include "Zombie.hpp"

Zombie::Zombie(std::string name){
	this->name = name;
	std::cout << "Zombie " << name << " is born" << std::endl;
}

Zombie::~Zombie(){
	std::cout << "Zombie " << name << " ressurected" << std::endl;
}

std::string Zombie::getName(){
	return (name);
}

void	Zombie::announce(){
	std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << "\n";
}
