#include "Dog.hpp"

Dog::Dog() : AAnimal() {
	this->type = "Dog";
	brain = new Brain();
	std::cout << CYAN << "Dog constructor" << RESET << std::endl;
};

Dog::Dog(const Dog& other) : AAnimal(other) {
	this->brain = new Brain();
	*this = other;
	std::cout << CYAN << "Dog copy constructor" << RESET << std::endl;
};

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		this->type = other.type;
		*brain = *(other.brain);
		std::cout << CYAN << "Dog assignment operator" << RESET << std::endl;
	}
	return (*this);
};

Dog::~Dog() {
	delete brain;
	std::cout << CYAN << "Dog destructor" << RESET << std::endl;
};

Brain*	Dog::getBrain() const { return (brain); };

void	Dog::makeSound() const {
	std::cout << BOLD << CYAN << "Wooof" << RESET << std::endl;
};
