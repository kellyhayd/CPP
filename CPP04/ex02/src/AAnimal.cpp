#include "AAnimal.hpp"

AAnimal::AAnimal() {
	this->type = "AAnimal";
	std::cout << YELLOW << "AAnimal constructor" << RESET << std::endl;
};

AAnimal::AAnimal(const AAnimal& other) {
	*this = other;
	std::cout << YELLOW << "AAnimal copy constructor" << RESET << std::endl;
};

AAnimal& AAnimal::operator=(const AAnimal& other) {
	if (this != &other) {
		this->type = other.type;
		std::cout << YELLOW << "AAnimal assignment operator" << RESET << std::endl;
	}
	return (*this);
};

AAnimal::~AAnimal() {
	std::cout << YELLOW << "AAnimal destructor" << RESET << std::endl;
};

std::string	AAnimal::getType() const { return (this->type); };

void	AAnimal::makeSound() const {
	std::cout << BOLD << YELLOW << "Grrrrr" << RESET << std::endl;
};
