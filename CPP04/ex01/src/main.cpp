#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void) {
	{
		std::cout << INVERSE << "\n SUBJECT TESTS \n" << RESET << std::endl;

		const Animal *j = new Dog();
		const Animal *i = new Cat();
		delete j; // should not create a leak
		delete i;
	}

	{
		std::cout << INVERSE << "\n SOME TESTS \n" << RESET << std::endl;

		const int arraySize = 4;
		Animal *animals[arraySize];

		for (int i = 0; i < arraySize / 2; ++i) {
			animals[i * 2] = new Dog();
			animals[i * 2 + 1] = new Cat();
		}

	/* Delete animals */
		for (int i = 0; i < arraySize; ++i) {
			delete animals[i];
		}
	}

	std::cout << std::endl;

	{
		Dog basic;
		{ Dog tmp = basic; }
		std::cout << basic.getType() << std::endl;
		basic.makeSound();
	}

	return (0);
}
