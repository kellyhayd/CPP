#include "Ice.hpp"
#include "ICharacter.hpp"
#include "Colors.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << CYAN << "Ice constructor" << RESET << std::endl;
};

Ice::Ice(Ice& const other) : AMateria(other) { *this = other; };

Ice& Ice::operator=(Ice& const other) {
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
};

Ice::~Ice() {
	std::cout << CYAN << "Ice destructor" << RESET << std::endl;
};

AMateria*	Ice::clone() const { return (new Ice(*this)); };

void	Ice::use(ICharacter& target) {
	std::cout << BOLD << CYAN << "* shoots an ice bolt at " << BLUE << target.getName() << CYAN << " *" << std::endl;
};
