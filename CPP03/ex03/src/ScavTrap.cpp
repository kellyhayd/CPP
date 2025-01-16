#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	this->name = "noName";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << MAGENTA << BOLD << "ScavTrap without a name was created with:\n" \
		<< std::setw(10) << GREEN << hitPoints << RESET << " hit points\n" \
		<< std::setw(10) << GREEN << energyPoints << RESET << " energy points\n" \
		<< std::setw(10) << GREEN << attackDamage << RESET << " attack damage" <<  std::endl;
};

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << MAGENTA << BOLD << "ScavTrap " << GREEN << name << MAGENTA << " was created with:\n" \
		<< std::setw(10) << GREEN << hitPoints << RESET << " hit points\n" \
		<< std::setw(10) << GREEN << energyPoints << RESET << " energy points\n" \
		<< std::setw(10) << GREEN << attackDamage << RESET << " attack damage" <<  std::endl;
};

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	*this = other;
};

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other) {
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return (*this);
}

void	ScavTrap::setEnergyPoints(int amount) {this->energyPoints = amount;};

ScavTrap::~ScavTrap() {
	std::cout << BOLD << RED << "ScavTrap " << name << " was destroyed 💀" << std::endl;
};

void	ScavTrap::guardGate() {
	std::cout << BOLD << GREEN << "ScavTrap " << name << " has entered in Gate keeper mode" << std::endl;
}

void	ScavTrap::attack(const std::string& target) {
	if (this->energyPoints <= 0) {
		std::cout << BOLD << YELLOW << "ScavTrap has no energy to attack" << RESET << std::endl;
		return;
	}
	else if (this->hitPoints <= 0) {
		std::cout << BOLD << YELLOW << "ScavTrap has no hit points to attack" << RESET << std::endl;
		return;
	}
	this->energyPoints--;
	this->hitPoints--;
	std::cout << BOLD << CYAN << "ScavTrap " << name \
			<< " attacks " << target << " causing " << RED \
			<< getAttackDamage() << CYAN << " points damage!" << RESET << std::endl;
};
