#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Colors.hpp"

AMateria::AMateria() : _type("default") {
	std::cout << BOLD << LIGHTGRAY << "AMateria constructor" << RESET << std::endl;
};

AMateria::AMateria(const std::string& type) : _type(type) {
	std::cout << BOLD << LIGHTGRAY << "AMateria constructor" << RESET << std::endl;
};

AMateria::AMateria(const AMateria& other) { *this = other; };

AMateria&	AMateria::operator=(const AMateria& other) {
	if (this != &other) {
		this->_type = other._type;
	}
	return (*this);
};

AMateria::~AMateria() {
	std::cout << BOLD << LIGHTGRAY << "AMateria destructor" << RESET << std::endl;
};

const std::string& AMateria::getType() const { return (this->_type); };

void	AMateria::use(ICharacter& target) {
	std::cout << "Nothing in use yet for" << target.getName() << std::endl;
};
