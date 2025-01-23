#include "AMateria.hpp"

AMateria::AMateria() : type("default") {
	std::cout << YELLOW << "AMateria constructor" << RESET << std::endl;
};

AMateria::AMateria(std::string const& type) : type(type) {
	std::cout << YELLOW << "AMateria constructor" << RESET << std::endl;
};

AMateria::AMateria(AMateria const& other) : type(other.type) {};

AMateria&	AMateria::operator=(AMateria const& other) {
	if (this != &other) {
		this->type = other.type;
		std::cout << YELLOW << "AMateria assignment operator" << RESET << std::endl;
	}
	return (*this);
};

AMateria::~AMateria() {
	std::cout << YELLOW << "AMateria destructor" << RESET << std::endl;
};

std::string& const AMateria::getType() const { return (type); };

AMateria*	AMateria::clone() const {
	return nullptr;

};

void	AMateria::use(ICharacter& target) {};
