#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
	AMateria*	materiaList[4];

public:
	MateriaSource();
	MateriaSource(MateriaSource const& other);
	MateriaSource& operator=(MateriaSource const& other);
	~MateriaSource();

	void		learnMateria(AMateria* m);
	AMateria*	createMateria(std::string const& type);
};

#endif
