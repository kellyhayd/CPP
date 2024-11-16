#include "Weapon.hpp"

Weapon::Weapon(const std::string &type){
	this->type = type;
}

Weapon::~Weapon(){}

const std::string	&Weapon::getType(){
	return (type);
}

void	Weapon::setType(std::string newType){
	this->type = newType;
}
