#include "WrongCat.hpp"
#include "Colors.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	this->type = "WrongCat";
	std::cout << LIGHTGRAY << "WrongCat constructor" << RESET << std::endl;
};

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	*this = other;
	std::cout << LIGHTGRAY << "WrongCat copy constructor" << RESET << std::endl;
};

WrongCat& WrongCat::operator=(const WrongCat& other) {
	if (this != &other) {
		this->type = other.type;
		std::cout << LIGHTGRAY << "WrongCat assignment operator" << RESET << std::endl;
	}
	return (*this);
};

WrongCat::~WrongCat() {
	std::cout << LIGHTGRAY << "WrongCat destructor" << RESET << std::endl;
};

void	WrongCat::makeSound() const {
	std::cout << BOLD << LIGHTGRAY << "I'm not a cat" << RESET << std::endl;
};
