#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
protected:
	std::string&	type;

public:
	Ice();
	Ice(std::string& type);
	Ice(Ice& const other);
	Ice& operator=(Ice& const other);
	virtual ~Ice();

	std::string& const getType() const; //Returns the materia type

	AMateria*	clone() const;
	void	use(ICharacter& target);

};

#endif
