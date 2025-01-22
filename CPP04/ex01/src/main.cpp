#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void) {
	{
		std::cout << INVERSE << "\n  SUBJECT TESTS  \n" << RESET << std::endl;

		const Animal *j = new Dog();
		const Animal *i = new Cat();
		delete j; // should not create a leak
		delete i;
	}

	{
		std::cout << INVERSE << "\n  MORE TESTS  \n" << RESET << std::endl;

		const int arraySize = 4;
		Animal *animals[arraySize];

		for (int i = 0; i < arraySize / 2; ++i) {
			animals[i * 2] = new Dog();
			animals[i * 2 + 1] = new Cat();
		}
		std::cout << std::endl;

		std::cout << BOLD << "\nDeleting animals\n" << RESET << std::endl;

	/* Delete animals */
		for (int i = 0; i < arraySize; ++i) {
			delete animals[i];
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	{
		std::cout << INVERSE << "\n  COPY TESTS  \n" << RESET << std::endl;

		std::cout << BOLD << "\nCreating a copy\n" << RESET << std::endl;
		Dog original;
		{
			Dog copy = original;
			std::cout << copy.getType() << std::endl;
			copy.makeSound();
		}
		std::cout << "\n" << original.getType() << std::endl;
		original.makeSound();
	}

	return (0);
}
