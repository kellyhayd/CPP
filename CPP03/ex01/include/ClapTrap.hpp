#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <iomanip>

const std::string RED = "\033[1;31m";
const std::string GREEN = "\033[1;32m";
const std::string CYAN = "\033[1;36m";
const std::string YELLOW = "\033[1;33m";
const std::string MAGENTA = "\033[1;95m";
const std::string BLUE = "\033[1;34m";
const std::string BOLD = "\033[1m";
const std::string INVERSE = "\033[7m";
const std::string RESET = "\033[0m";

class ClapTrap {
protected:
	std::string	name;
	int			hitPoints;
	int			energyPoints;
	int			attackDamage;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);
	~ClapTrap();

	std::string	getName();
	int			getAttackDamage();
	void		setHitPoints(int amount);
	void		setEnergyPoints(int amount);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif
