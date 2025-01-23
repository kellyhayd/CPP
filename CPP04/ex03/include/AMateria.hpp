#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>

#include "Colors.hpp"
#include "ICharacter.hpp"

class AMateria {
protected:
	std::string& const	type;

public:

	AMateria();
	AMateria(std::string& const type);
	AMateria(AMateria& const other);
	AMateria& operator=(AMateria& const other);
	virtual ~AMateria();

	std::string& const getType() const; //Returns the materia type

	virtual AMateria*	clone() const = 0;
	virtual void	use(ICharacter& target);
};

#endif
