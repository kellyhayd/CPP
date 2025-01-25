#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4, i++) {
		materiaList[i] = NULL;
	}
};

MateriaSource::MateriaSource(MateriaSource const& other) { *this = other; };

MateriaSource::MateriaSource& operator=(MateriaSource const& other) {
	if (this != &other) {
		for (int i = 0; i < 4, i++) {
			materiaList[i] = other.materiaList[i]->clone();
		} else {
			materiaList[i] = NULL;
		}
	}
	return (*this);
};

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		delete materiaList[i];
	}
};

void	MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (materiaList[i] == NULL) {
			materiaList[i] = m;
			break;
		}
	}
};

AMateria*	MateriaSource::createMateria(std::string const& type) {
	for (int i = 0; i < 4; i++) {
		if (materiaList[i] != NULL && materiaList[i]->getType() == type) {
			return (materiaList[i]->clone());
		}
	}
	return (0);
};
