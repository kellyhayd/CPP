#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <new>

const std::string RED = "\033[31m";
const std::string CYAN = "\033[36m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BOLD = "\033[1m";
const std::string BLINK = "\033[5m";
const std::string INVERSE = "\033[7m";
const std::string RESET = "\033[0m";

class Zombie{
private:
		std::string	name;

public:
	Zombie();
	Zombie(std::string name);
	~Zombie();

	void	announce();

	std::string	getName();
	void	setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif
