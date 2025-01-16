#include "Dog.hpp"

Dog::Dog() : Animal() {
	this->type = "Dog";
	std::cout << CYAN << "Dog constructor" << RESET << std::endl;
};

Dog::Dog(const Dog& other) : Animal(other) {
	*this = other;
	std::cout << CYAN << "Dog copy constructor" << RESET << std::endl;
};

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		this->type = other.type;
		std::cout << CYAN << "Dog assignment operator" << RESET << std::endl;
	}
	return (*this);
};

Dog::~Dog() {
	std::cout << CYAN << "Dog destructor" << RESET << std::endl;
};

void	Dog::makeSound() const {
	std::cout << BOLD << CYAN << "Wooof" << RESET << std::endl;
};
