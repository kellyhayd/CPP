#include "Character.hpp"
#include "Colors.hpp"

Character::Character() : _name("nobody") {
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
	std::cout << YELLOW << "Character " << MAGENTA << "nobody" \
		<< YELLOW << " constructor" << RESET << std::endl;
};

Character::Character(const std::string& name) : _name(name) {
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
	std::cout << YELLOW << "Character " << MAGENTA << name \
		<< YELLOW << " constructor" << RESET << std::endl;
};

Character::Character(const Character& other) { *this = other; };

Character& Character::operator=(const Character& other) {
	if (this != &other) {
		this->_name = other._name;
		for (int i = 0; i < 4; i++) {
			if (other._inventory[i]) {
				this->_inventory[i] = other._inventory[i]->clone();
			} else {
				this->_inventory[i] = NULL;
			}
		}
	}
	return *this;
};

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i]) {
			delete this->_inventory[i];
		}
	};
};

const std::string& Character::getName() const { return (this->_name); }

void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] == NULL) {
			this->_inventory[i] = m;
			break;
		}
	}
};

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4) {
		_inventory[idx] = NULL;
	}
};

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4 && _inventory[idx] != NULL) {
		_inventory[idx]->use(target);
	}
};
