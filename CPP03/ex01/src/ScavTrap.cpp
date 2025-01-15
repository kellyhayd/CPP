#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	this->name = "noName";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << GREEN << BOLD << "ScavTrap without a name was created with:\n" \
		<< std::setw(10) << YELLOW << hitPoints << RESET << " hit points\n" \
		<< std::setw(10) << YELLOW << energyPoints << RESET << " energy points\n" \
		<< std::setw(10) << YELLOW << attackDamage << RESET << " attack damage" <<  std::endl;
};

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << GREEN << BOLD << "ScavTrap " << YELLOW << name << GREEN << " was created with:\n" \
		<< std::setw(10) << YELLOW << hitPoints << RESET << " hit points\n" \
		<< std::setw(10) << YELLOW << energyPoints << RESET << " energy points\n" \
		<< std::setw(10) << YELLOW << attackDamage << RESET << " attack damage" <<  std::endl;
};

ScavTrap::ScavTrap(const ScavTrap& other) {*this = other;};

ScavTrap::~ScavTrap() {
	std::cout << BOLD << GREEN << "ScavTrap " << YELLOW << name << GREEN << "was destroyed" << std::endl;
};
