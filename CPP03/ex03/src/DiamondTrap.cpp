#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("noName_clap_name"), ScavTrap(), FragTrap() {
	this->name = "noName";
	this->hitPoints = FragTrap::hitPoints;
	this->attackDamage = FragTrap::attackDamage;
	ScavTrap::setEnergyPoints(50);
	this->energyPoints = ScavTrap::energyPoints;
	std::cout << MAGENTA << BOLD << "DiamonTrap without a name was created with:\n" \
		<< std::setw(10) << GREEN << hitPoints << RESET << " hit points\n" \
		<< std::setw(10) << GREEN << energyPoints << RESET << " energy points\n" \
		<< std::setw(10) << GREEN << attackDamage << RESET << " attack damage" <<  std::endl;
};

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
	this->name = name;
	this->hitPoints = FragTrap::hitPoints;
	this->attackDamage = FragTrap::attackDamage;
	ScavTrap::setEnergyPoints(50);
	this->energyPoints = ScavTrap::energyPoints;
	std::cout << MAGENTA << BOLD << "DiamondTrap " << GREEN << name << MAGENTA << " was created with:\n" \
		<< std::setw(10) << GREEN << hitPoints << RESET << " hit points\n" \
		<< std::setw(10) << GREEN << this->energyPoints << RESET << " energy points\n" \
		<< std::setw(10) << GREEN << attackDamage << RESET << " attack damage" <<  std::endl;
};

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other) {
	*this = other;
};

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other) {
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	return (*this);
};

DiamondTrap::~DiamondTrap() {
	std::cout << BOLD << RED << "DiamondTrap " \
		<< name << " was destroyed 💀" << std::endl;
};

void	DiamondTrap::whoAmI() {
	std::cout << BOLD << CYAN << "DiamondTrap " << RESET << name << CYAN << BOLD \
		<< " is a hybrid of ClapTrap, ScavTrap, and FragTrap" << RESET << std::endl;
	std::cout << BOLD << CYAN << "ClapTrap " << MAGENTA
		<< ClapTrap::name << CYAN << " is a parent class" << RESET << std::endl;
};

void	DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
};
