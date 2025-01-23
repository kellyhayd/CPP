#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << CYAN << "Ice constructor" << RESET << std::endl;
};

Ice::Ice(std::string& type) : AMateria("ice") {
	std::cout << CYAN << "Ice constructor" << RESET << std::endl;
};

Ice::Ice(Ice& const other) : AMateria(other) {};

Ice& Ice::operator=(Ice& const other) {

};

Ice::~Ice() {
	std::cout << CYAN << "Ice destructor" << RESET << std::endl;
};

std::string& const Ice::getType() const { return (type); }; //Returns the materia type

AMateria*	Ice::clone() const { return (new Ice(*this)); };

void	Ice::use(ICharacter& target) {
	std::cout << BOLD << CYAN << "* shoots an ice bolt at " << BLUE << target << CYAN << " *" << std::endl;
};
