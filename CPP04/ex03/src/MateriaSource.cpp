#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Colors.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++) {
		_materiaList[i] = NULL;
	}
};

MateriaSource::MateriaSource(const MateriaSource& other) { *this = other; };

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		for (int i = 0; i < 4; i++) {
			if (_materiaList[i] != NULL) {
				this->_materiaList[i] = other._materiaList[i]->clone();
			} else {
				this->_materiaList[i] = NULL;
			}
		}
	}
	return (*this);
};

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		delete _materiaList[i];
	}
};

void	MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (_materiaList[i] == NULL) {
			_materiaList[i] = m;
			std::cout << RED << "Learned " << RESET << m->getType() << std::endl;
			break;
		}
	}
};

AMateria*	MateriaSource::createMateria(const std::string& type) {
	for (int i = 0; i < 4; i++) {
		if (_materiaList[i] != NULL && _materiaList[i]->getType() == type) {
			return (_materiaList[i]->clone());
		}
	}

	return (0);
};
