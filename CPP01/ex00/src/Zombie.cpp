#include "Zombie.hpp"

Zombie::Zombie(std::string name){
	this->name = name;
	std::cout << BOLD << GREEN << name << "rose from the tomb" << RESET << std::endl;
}

Zombie::~Zombie(){
	std::cout << BOLD << RED << name << " returned to the tomb!" << RESET << std::endl;
}

std::string Zombie::getName(){
	return (name);
}

void	Zombie::announce(){
	std::cout << BOLD << YELLOW << getName() << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}
