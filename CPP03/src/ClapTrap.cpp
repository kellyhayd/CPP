#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) {
	this->name = name;
	std::cout << "ClaTrap is called " << name << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap& other) {
	*this = other;
	std::cout << "Now ClapTrap has a clone!" << std::endl;
};

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other) {
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return (*this);
};

ClapTrap::~ClapTrap() {};

void	attack(const std::string& target) {};

void	takeDamage(unsigned int amount) {};

void	beRepaired(unsigned int amount) {};
