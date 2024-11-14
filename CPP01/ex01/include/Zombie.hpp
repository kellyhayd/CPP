#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <new>

class Zombie{
private:
		std::string	name;

public:
	Zombie();
	Zombie(std::string name);
	~Zombie();

	void	announce();

	std::string	getName();
};

Zombie* zombieHorde(int N, std::string name);

#endif
