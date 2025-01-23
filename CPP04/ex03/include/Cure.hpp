#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
private:
	std::string&	type;

public:
	Cure();
	Cure(std::string& type);
	Cure(Cure& const other);
	Cure& operator=(Cure& const other);
	~Cure();

	std::string& const getType() const; //Returns the materia type

	AMateria*	clone() const;
	void	use(ICharacter& target);

};

#endif
