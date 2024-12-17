#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string CYAN = "\033[36m";
const std::string BOLD = "\033[1m";
const std::string BLINK = "\033[5m";
const std::string RESET = "\033[0m";
const std::string INVERSE = "\033[7m";

class Weapon{
private:
	std::string	type;

public:
	Weapon(const std::string &type);
	~Weapon();

	const std::string	&getType();
	void	setType(std::string newType);
};

#endif
