#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Colors.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout << GREEN << "Cure constructor" << RESET << std::endl;
};

Cure::Cure(const Cure& other) : AMateria(other) { *this = other; };

Cure& Cure::operator=(const Cure& other) {
	if (this != &other) {
		this->_type = other._type;
	}
	return (*this);
};

Cure::~Cure() {
	std::cout << GREEN << "Cure destructor" << RESET << std::endl;
};

AMateria*	Cure::clone() const { return (new Cure(*this)); };

void	Cure::use(ICharacter& target) {
	std::cout << BOLD << GREEN << "* heals " << RED << target.getName() << GREEN << "’s wounds *" << std::endl;
};
