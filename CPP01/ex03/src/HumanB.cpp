#include "HumanB.hpp"

HumanB::HumanB(std::string name){
	this->name = name;
	this->weapon = NULL;
};

HumanB::~HumanB(){};

void	HumanB::setWeapon(Weapon &weapon){
	this->weapon = &weapon;
};

void HumanB::attack() const{
	std::cout << name << " attacks with their " << (weapon != NULL ?
		weapon->getType() : "hand") << std::endl;
};
