#include "Ice.hpp"
#include "ICharacter.hpp"
#include "Colors.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << CYAN << "Ice constructor" << RESET << std::endl;
};

Ice::Ice(const Ice& other) : AMateria(other) { *this = other; };

Ice& Ice::operator=(const Ice& other) {
	if (this != &other) {
		this->_type = other._type;
	}
	return (*this);
};

Ice::~Ice() {
	std::cout << CYAN << "Ice destructor" << RESET << std::endl;
};

AMateria*	Ice::clone() const { return (new Ice(*this)); };

void	Ice::use(ICharacter& target) {
	std::cout << BOLD << CYAN << "* shoots an ice bolt at " << RED << target.getName() << CYAN << " *" << std::endl;
};
