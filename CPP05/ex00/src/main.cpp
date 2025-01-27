#include "Bureaucrat.hpp"
#include "Colors.hpp"
#include <iostream>

int main() {
	std::cout << std::endl;
	std::cout << INVERSE << "   Testing increment a high grade   " << RESET << std::endl;
	{
		try {
			Bureaucrat highestGrade("Jon Snow", 1);
			std::cout << highestGrade << std::endl;

			highestGrade.incrementGrade();
			std::cout << highestGrade << std::endl;
			// this should throw GradeTooHighException

			highestGrade.decrementGrade();
			std::cout << highestGrade << std::endl;
			// this should not be executed

		} catch (std::exception &e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << INVERSE << "   Testing decrement a low grade   " << RESET << std::endl;
	{
		try {
			Bureaucrat lowestGrade("Cersei", 150);
			std::cout << lowestGrade << std::endl;

			lowestGrade.decrementGrade();
			std::cout << lowestGrade << std::endl;
			// this should throw GradeTooLowException

			lowestGrade.incrementGrade();
			std::cout << lowestGrade << std::endl;
			// this should not be executed

		} catch (std::exception &e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << INVERSE << "   Testing random grade   " << RESET << std::endl;
	{
		try {
			Bureaucrat bureaucrat("Ygritte", 75);
			std::cout << bureaucrat << std::endl;

			bureaucrat.incrementGrade();
			std::cout << bureaucrat << std::endl;

			bureaucrat.decrementGrade();
			std::cout << bureaucrat << std::endl;

			while (bureaucrat.getGrade() > 42)
				bureaucrat.incrementGrade();
			std::cout << bureaucrat << std::endl;
		} catch (std::exception &e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}

	return 0;
}
