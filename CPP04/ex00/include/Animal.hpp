#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

const std::string RED = "\033[1;31m";
const std::string GREEN = "\033[1;32m";
const std::string CYAN = "\033[1;36m";
const std::string YELLOW = "\033[1;33m";
const std::string MAGENTA = "\033[1;95m";
const std::string BLUE = "\033[1;34m";
const std::string BOLD = "\033[1m";
const std::string INVERSE = "\033[7m";
const std::string RESET = "\033[0m";

class Animal {
protected:
	std::string type;

public:
	Animal();
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);
	virtual ~Animal();

	virtual std::string	getType() const;

	virtual void	makeSound() const;
};

#endif
