#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void) {
	{
		std::cout << INVERSE<< "\nSubject test\n" << RESET << std::endl;

		const Animal	*alpha = new Animal();
		const Animal	*beta = new Dog();
		const Animal	*gamma = new Cat();
		std::cout << std::endl;

		std::cout << BOLD << alpha->getType() << " " << RESET << std::endl;
		std::cout << BOLD << beta->getType() << " " << RESET << std::endl;
		std::cout << BOLD << gamma->getType() << " " << RESET << std::endl;
		std::cout << std::endl;

		alpha->makeSound();
		beta->makeSound();
		gamma->makeSound();

		delete alpha;
		delete beta;
		delete gamma;
	}

	std::cout << INVERSE<< "\nWrong animal test\n" << RESET<< std::endl;
	{
		const WrongCat		*delta = new WrongCat();
		const WrongAnimal	*epsilon = new WrongCat();
		const Animal		*zeta = new Dog();
		std::cout << std::endl;

		std::cout << BOLD << delta->getType() << " " << RESET << std::endl;
		std::cout << BOLD << epsilon->getType() << " " << RESET << std::endl;
		std::cout << BOLD << zeta->getType() << " " << RESET << std::endl;
		std::cout << BOLD << std::endl;

		delta->makeSound();
		epsilon->makeSound();
		zeta->makeSound();

		delete delta;
		delete epsilon;
		delete zeta;
	}

	return (0);
}
