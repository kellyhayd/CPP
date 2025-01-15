#include "../include/ClapTrap.hpp"

// Orthodox Canonical Form rules

ClapTrap::ClapTrap() : name("noName"), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << MAGENTA << BOLD << "ClapTrap without a name was created with:\n" \
	<< std::setw(10) << GREEN << hitPoints << RESET << " hit points\n" \
	<< std::setw(10) << GREEN << energyPoints << RESET << " energy points\n" \
	<< std::setw(10) << GREEN << attackDamage << RESET << " attack damage" <<  std::endl;
};

ClapTrap::ClapTrap(std::string name) : name(), hitPoints(10), energyPoints(10), attackDamage(0) {
	this->name = name;
	std::cout << MAGENTA << BOLD << "ClapTrap called "<< name << " was created with:\n" \
	<< std::setw(10) << GREEN << hitPoints << RESET << " hit points\n" \
	<< std::setw(10) << GREEN << energyPoints << RESET << " energy points\n" \
	<< std::setw(10) << GREEN << attackDamage << RESET << " attack damage" <<  std::endl;
};

ClapTrap::ClapTrap(const ClapTrap& other) {
	*this = other;
	std::cout << BOLD << YELLOW<< "Now ClapTrap has a clone!" << RESET << std::endl;
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

ClapTrap::~ClapTrap() {
	std::cout << BOLD << RED << "ClapTrap " << YELLOW << this->name \
		<< RED << " was destroyed 💀" << RESET << std::endl;
};


// Getters and Setters

std::string	ClapTrap::getName() {return (this->name);};

int		ClapTrap::getAttackDamage() {return (this->attackDamage);};

// Action Functions

void	ClapTrap::attack(const std::string& target) {
	if (this->energyPoints <= 0) {
		std::cout << BOLD << YELLOW << "ClapTrap has no energy to attack" << RESET << std::endl;
		return;
	}
	else if (this->hitPoints <= 0) {
		std::cout << BOLD << YELLOW << "ClapTrap has no hit points to attack" << RESET << std::endl;
		return;
	}
	this->energyPoints--;
	this->hitPoints--;
	std::cout << BOLD << CYAN << "Claptrap " << this->name \
			<< " attacks " << target << " causing " << GREEN \
			<< getAttackDamage() << CYAN << " points damage!" << RESET << std::endl;
};

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->energyPoints <= 0) {
		std::cout << BOLD << RED << "ClapTrap " << this->name \
			<< " is already dead" << RESET << std::endl;
		return;
	}
	else if ((int)amount >= this->energyPoints) {
		std::cout << BOLD << RED << "ClapTrap " << this->name \
			<< " was killed" << RESET << std::endl;
		return;
	}
	this->energyPoints -= amount;
	std::cout << BOLD << CYAN << "ClapTrap " << this->name << " took " \
		<< RED << amount << CYAN << " points of damage." << RESET << std::endl;
};

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->energyPoints <= 0 || this->hitPoints <= 0) {
		std::cout << BOLD << RED << "Sorry! ClapTrap " << this->name \
		<< " has no energy to repair itself" << RESET << std::endl;
		return;
	}
	this->energyPoints--;
	this->hitPoints += amount;
	std::cout << BOLD << CYAN << "ClapTrap " << BLUE << this->name << CYAN \
		<< " repaired itself in " << BLUE << amount << CYAN << " points" << RESET << std::endl;
};
