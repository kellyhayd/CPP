#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap : public ClapTrap {
public:
	FragTrap();
	FragTrap(const std::string name);
	FragTrap(const FragTrap& other);
	FragTrap& operator=(const FragTrap& other);
	~FragTrap();

	const std::string	getName();
	void		setHitPoints(int amount);
	void		setEnergyPoints(int amount);

	void	highFivesGuys();
	void	attack(const std::string& target);
};


#endif
