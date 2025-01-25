#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Colors.hpp"

AMateria::AMateria() : type("default") {
	std::cout << YELLOW << "AMateria constructor" << RESET << std::endl;
};

AMateria::AMateria(std::string const& type) : type(type) {
	std::cout << YELLOW << "AMateria constructor" << RESET << std::endl;
};

AMateria::AMateria(AMateria const& other) { *this = other; };

AMateria&	AMateria::operator=(AMateria const& other) {
	if (this != &other) {
		this->type = other.type;
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

void	AMateria::use(ICharacter& target) {
	std::cout << "Nothing in use yet for" << target.getName() << std::endl;
};
