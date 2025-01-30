#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "Colors.hpp"

int main() {
	Intern someRandomIntern;
	AForm *tmp;

	std::cout << INVERSE << "\nROBOTOMY REQUEST" << RESET << std::endl;
	try {
		tmp = someRandomIntern.makeForm("robotomy request", "Jon");
		if (tmp) {
			std::cout << GREEN << "Form created successfully!" << RESET << std::endl;
			delete tmp;
	}
	} catch (std::exception &e) {
		std::cout << BOLD << "Exception caught: " << RED << e.what() << RESET << std::endl;
	}

	std::cout << INVERSE << "\nSHRUBBERY CREATION" << RESET << std::endl;
	try {
		tmp = someRandomIntern.makeForm("shrubbery creation", "Arya");
		if (tmp) {
			std::cout << GREEN << "Form created successfully!" << RESET << std::endl;
			delete tmp;
	}
	} catch (std::exception &e) {
		std::cout << BOLD << "Exception caught: " << RED << e.what() << RESET << std::endl;
	}

	std::cout << INVERSE << "\nPRESIDENTIAL PARDON" << RESET << std::endl;
	try {
		tmp =
			someRandomIntern.makeForm("presidential pardon", "Bozo");
		if (tmp) {
			std::cout << GREEN << "Form created successfully!" << RESET << std::endl;
			delete tmp;
	}
	} catch (std::exception &e) {
		std::cout << BOLD << "Exception caught: " << RED << e.what() << RESET << std::endl;
	}

	std::cout << INVERSE << "\nTAX EXEMPTION" << RESET << std::endl;
	try {
		tmp = someRandomIntern.makeForm("tax exemption", "Ygritte");
		if (tmp) {
			std::cout << GREEN << "Form created successfully!" << RESET << std::endl;
			delete tmp;
	}
	} catch (std::exception &e) {
		std::cout << BOLD << "Exception caught: " << RED << e.what() << RESET << std::endl;
	}

	std::cout << std::endl;

	return 0;
}
