#include "Base.hpp"
#include "Colors.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <ctime>
#include <cstdlib>

Base::~Base() {};

Base*	generate(void) {
	srand(time(0));
	int	num = rand() % 3;

	if (num % 3 == 0) {
		std::cout << CYAN << "Base A instanciated" << RESET << std::endl;
		return (new A);
	} else if (num % 3 == 1) {
		std::cout << GREEN << "Base B instanciated" << RESET << std::endl;
		return (new B);
	} else {
		std::cout << MAGENTA << "Base C instanciated" << RESET << std::endl;
		return (new C);
	}
};

void	identify(Base* p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << CYAN << "Base A" << RESET << std::endl;
	} else if (dynamic_cast<B*>(p)) {
		std::cout << GREEN << "Base B" << RESET << std::endl;
	} else if (dynamic_cast<C*>(p)) {
		std::cout << MAGENTA << "Base C" << RESET << std::endl;
	} else {
		std::cout << RED << "Base not recognized" << RESET << std::endl;
	}
};

void	identify(Base& p) {
	try {
		A a = dynamic_cast<A&>(p);
		std::cout << CYAN << "Base A" << RESET << std::endl;
		return;
	} catch(std::exception& e) {
		try {
			B b = dynamic_cast<B&>(p);
			std::cout << GREEN << "Base B" << RESET << std::endl;
			return;
		} catch(std::exception& e) {
			try {
				C c = dynamic_cast<C&>(p);
				std::cout << MAGENTA << "Base C" << RESET << std::endl;
				return;
			} catch(std::exception& e) {
			std::cout << RED << "Bad casting" << RESET << std::endl;
			}
		}
	}
};
