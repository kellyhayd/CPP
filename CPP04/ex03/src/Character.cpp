#include "Character.hpp"

Character::Character() : name("nobody") {
	for (int i = 0; i < 4; i++) {
		this->inventory[i] = NULL;
	}
};

Character::Character(std::string const& name) : name(name) {
	for (int i = 0; i < 4; i++) {
		this->inventory[i] = NULL;
	}
};

Character::Character(const Character& other) {} {
	*this = other;
};

Character& Character::operator=(const Character& other) {
	if (this != &other) {
		this->_name = other._name;
		for (int i = 0; i < 4; i++) {
			if (other.inventory[i]) {
				this->inventory[i] = other.inventory[i]->clone();
			} else {
				this->inventory[i] = NULL;
			}
		}
	}
	return *this;
};

Character::~Character() {
	// destructor
};

std::string Character::getName() const { return (this->name); }

void Character::equip(AMateria* m) {
	// implementation
}

void Character::unequip(int idx) {
	// implementation
}
