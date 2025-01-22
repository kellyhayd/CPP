#include "Brain.hpp"
#include "Colors.hpp"

Brain::Brain() {
	std::cout << LIGHTGRAY << "Brain constructor" << RESET << std::endl;
}

Brain::Brain(const Brain& other) {
	*this = other;
	std::cout << LIGHTGRAY << "Brain copy constructor" << RESET << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
	if (this != &other) {
		for (int i = 0; i < 100; ++i) {
			this->ideas[i] = other.ideas[i];
		}
	}
	return (*this);
}

Brain::~Brain() {
	std::cout << LIGHTGRAY << "Brain destructor" << RESET << std::endl;
}
