#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <new>

class Zombie{
private:
		std::string	name;

public:
	Zombie(std::string name);
	~Zombie();

	void	announce();

	std::string	getName();
	void setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif
