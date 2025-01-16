#include "Animal.hpp"

Animal::Animal() {
	this->type = "Animal";
	std::cout << YELLOW << "Animal constructor" << RESET << std::endl;
};

Animal::Animal(const Animal& other) {
	*this = other;
	std::cout << YELLOW << "Animal copy constructor" << RESET << std::endl;
};

Animal& Animal::operator=(const Animal& other) {
	if (this != &other) {
		this->type = other.type;
		std::cout << YELLOW << "Animal assignment operator" << RESET << std::endl;
	}
	return (*this);
};

Animal::~Animal() {
	std::cout << YELLOW << "Animal destructor" << RESET << std::endl;
};

std::string	Animal::getType() const { return (this->type); };

void	Animal::makeSound() const {
	std::cout << BOLD << YELLOW << "Grrrrr" << RESET << std::endl;
};
