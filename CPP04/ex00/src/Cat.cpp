#include "Cat.hpp"

Cat::Cat() : Animal() {
	this->type = "Cat";
	std::cout << MAGENTA << "Cat constructor" << RESET << std::endl;
};

Cat::Cat(const Cat& other) : Animal(other) {
	*this = other;
	std::cout << MAGENTA << "Cat copy constructor" << RESET << std::endl;
};

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		this->type = other.type;
		std::cout << MAGENTA << "Cat assignment operator" << RESET << std::endl;
	}
	return (*this);
};

Cat::~Cat() {
	std::cout << MAGENTA << "Cat destructor" << RESET << std::endl;
};

void	Cat::makeSound() const {
	std::cout << BOLD << MAGENTA << "Meoooow" << RESET << std::endl;
};
