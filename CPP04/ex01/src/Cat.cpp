#include "Cat.hpp"

Cat::Cat() : Animal() {
	this->type = "Cat";
	brain = new Brain();
	std::cout << MAGENTA << "Cat constructor" << RESET << std::endl;
};

Cat::Cat(const Cat& other) : Animal(other) {
	this->brain = new Brain();
	*this = other;
	std::cout << MAGENTA << "Cat copy constructor" << RESET << std::endl;
};

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		this->type = other.type;
		*brain = *(other.brain);
		std::cout << MAGENTA << "Cat assignment operator" << RESET << std::endl;
	}
	return (*this);
};

Cat::~Cat() {
	delete brain;
	std::cout << MAGENTA << "Cat destructor" << RESET << std::endl;
};

Brain*	Cat::getBrain() const { return (this->brain); };

void	Cat::makeSound() const {
	std::cout << BOLD << MAGENTA << "Meoooow" << RESET << std::endl;
};
