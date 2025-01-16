#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	this->name = "noName";
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << MAGENTA << BOLD << "FragTrap without a name was created with:\n" \
		<< std::setw(10) << GREEN << hitPoints << RESET << " hit points\n" \
		<< std::setw(10) << GREEN << energyPoints << RESET << " energy points\n" \
		<< std::setw(10) << GREEN << attackDamage << RESET << " attack damage" <<  std::endl;
};

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << MAGENTA << BOLD << "FragTrap " << GREEN << name << MAGENTA << " was created with:\n" \
		<< std::setw(10) << GREEN << hitPoints << RESET << " hit points\n" \
		<< std::setw(10) << GREEN << energyPoints << RESET << " energy points\n" \
		<< std::setw(10) << GREEN << attackDamage << RESET << " attack damage" <<  std::endl;
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
	std::cout << BOLD << RED << "FragTrap " << name << " was destroyed 💀" << std::endl;
};

void	FragTrap::setHitPoints(int amount) {this->hitPoints = amount;};

void	FragTrap::setEnergyPoints(int amount) {this->energyPoints = amount;};


void	FragTrap::highFivesGuys() {
	std::cout << BOLD << GREEN << "FragTrap "<< name << " says: \"High five!\"" << std::endl;
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
			<< " attacks " << target << " causing " << RED \
			<< getAttackDamage() << CYAN << " points damage!" << RESET << std::endl;
};
