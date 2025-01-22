#include "WrongAnimal.hpp"
#include "Colors.hpp"

WrongAnimal::WrongAnimal() {
	this->type = "WrongAnimal";
	std::cout << RED << "WrongAnimal constructor" << RESET << std::endl;
};

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	*this = other;
	std::cout << RED << "WrongAnimal copy constructor" << RESET << std::endl;
};

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other) {
		this->type = other.type;
		std::cout << RED << "WrongAnimal assignment operator" << RESET << std::endl;
	}
	return (*this);
};

WrongAnimal::~WrongAnimal() {
	std::cout << RED << "WrongAnimal destructor" << RESET << std::endl;
};

std::string	WrongAnimal::getType() const { return (this->type); };

void	WrongAnimal::makeSound() const {
	std::cout << BOLD << RED << "Kwak!" << RESET << std::endl;
};
