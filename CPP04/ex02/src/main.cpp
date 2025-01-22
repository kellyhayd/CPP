#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void) {
	{
		std::cout << INVERSE<< "\n RIGHT TESTS\n" << RESET<< std::endl;

		const Cat		*delta = new Cat();
		const WrongAnimal	*epsilon = new WrongCat();
		const AAnimal		*zeta = new Dog();
		std::cout << std::endl;

		std::cout << BOLD << delta->getType() << RESET << std::endl;
		std::cout << BOLD << epsilon->getType() << RESET << std::endl;
		std::cout << BOLD << zeta->getType() << RESET << std::endl;
		std::cout << BOLD << std::endl;

		delta->makeSound();
		epsilon->makeSound();
		zeta->makeSound();

		delete delta;
		delete epsilon;
		delete zeta;
	}

	// {
	// 	// WRONG TEST

	// 	const AAnimal	x;

	// 	std::cout << x.getType() << std::endl;
	// 	x.makeSound();
	// }

	return (0);
}
