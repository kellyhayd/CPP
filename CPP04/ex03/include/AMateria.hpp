#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>

class ICharacter;

class AMateria {
protected:
	std::string	_type;

public:
	AMateria();
	AMateria(const std::string& _type);
	AMateria(const AMateria& other);
	AMateria& operator=(const AMateria& other);
	virtual ~AMateria();

	const std::string& getType() const;

	virtual AMateria*	clone() const = 0;
	virtual void	use(ICharacter& target);
};

#endif
