#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon): name(name), weapon(weapon){};

HumanA::~HumanA(){};

void HumanA::attack(){
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
};

const std::string&	HumanA::getName(){
	return (name);
};

void	HumanA::setName(const std::string& name){
	this->name = name;
}

const std::string&	HumanA::getWeapon(){
	return (weapon.getType());
};

void	HumanA::setWeapon(Weapon weapon){
	this->weapon = weapon;
}
