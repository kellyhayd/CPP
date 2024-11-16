#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

#include <iostream>
#include <string>

class HumanB{
private:
	std::string name;
	Weapon	*weapon;

public:
	HumanB(std::string name);
	~HumanB();

	const std::string	&getName();
	void	setName(std::string &name);
	void	setWeapon(Weapon &weapon);

	void	attack() const;
};

#endif