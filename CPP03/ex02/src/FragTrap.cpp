#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	this->name = "noName";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << GREEN << BOLD << "FragTrap without a name was created with:\n" \
		<< std::setw(10) << YELLOW << hitPoints << RESET << " hit points\n" \
		<< std::setw(10) << YELLOW << energyPoints << RESET << " energy points\n" \
		<< std::setw(10) << YELLOW << attackDamage << RESET << " attack damage" <<  std::endl;
};

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << GREEN << BOLD << "FragTrap " << YELLOW << name << GREEN << " was created with:\n" \
		<< std::setw(10) << YELLOW << hitPoints << RESET << " hit points\n" \
		<< std::setw(10) << YELLOW << energyPoints << RESET << " energy points\n" \
		<< std::setw(10) << YELLOW << attackDamage << RESET << " attack damage" <<  std::endl;
};

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	*this = other;
};

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other) {
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << BOLD << RED << "FragTrap " << YELLOW << name << RED << " was destroyed 💀" << std::endl;
};

void	FragTrap::highFivesGuys() {
	std::cout << BOLD << GREEN << "FragTrap " << YELLOW << name << GREEN << " says: \"High five!\"" << std::endl;
}

void	FragTrap::attack(const std::string& target) {
	if (this->energyPoints <= 0) {
		std::cout << BOLD << YELLOW << "FragTrap has no energy to attack" << RESET << std::endl;
		return;
	}
	else if (this->hitPoints <= 0) {
		std::cout << BOLD << YELLOW << "FragTrap has no hit points to attack" << RESET << std::endl;
		return;
	}
	this->energyPoints--;
	this->hitPoints--;
	std::cout << BOLD << CYAN << "FragTrap " << name \
			<< " attacks " << target << " causing " << GREEN \
			<< getAttackDamage() << CYAN << " points damage!" << RESET << std::endl;
};
