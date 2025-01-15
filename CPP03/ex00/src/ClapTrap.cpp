#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap() : name(), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << MAGENTA << BOLD << "ClapTrap without a name was created with:\n" \
	<< std::setw(10) << GREEN << hitPoints << RESET << " hit points\n" \
	<< std::setw(10) << GREEN << energyPoints << RESET << " energy points\n" \
	<< std::setw(10) << GREEN << attackDamage << RESET << " attack damage" <<  std::endl;
};

ClapTrap::ClapTrap(std::string name) {
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
	std::cout << BOLD << RED << "ClapTrap was destroyed :(" << RESET << std::endl;
};

// void	attack(const std::string& target) {};

// void	takeDamage(unsigned int amount) {};

// void	beRepaired(unsigned int amount) {};
