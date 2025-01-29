#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "Colors.hpp"

int main() {
	// std::cout << std::endl;
	// {
	// 	std::cout << INVERSE << "   Attempting to execute form with low grade   \n" << RESET << std::endl;
	// 	try {
	// 		Bureaucrat sansa("Sansa", 143);
	// 		ShrubberyCreationForm treeForm("Westerland");

	// 		std::cout << BOLD << "Form details:" << RESET << std::endl;
	// 		std::cout << treeForm << std::endl;

	// 		sansa.signForm(treeForm);

	// 		std::cout << BOLD << "Attempting to execute the form..." << RESET << std::endl;
	// 		sansa.executeForm(treeForm);
	// 	} catch (std::exception& e) {
	// 		std::cout << std::endl;
	// 		std::cout << BOLD << "Exception caught: " << RED << e.what() << RESET << std::endl;
	// 	}

	// 	std::cout << std::endl;

	// 	try {
	// 		Bureaucrat sansa("Sansa", 80);
	// 		RobotomyRequestForm robotForm("Westerland");

	// 		std::cout << BOLD << "Form details:" << RESET << std::endl;
	// 		std::cout << robotForm << std::endl;

	// 		sansa.signForm(robotForm);

	// 		std::cout << BOLD << "Attempting to execute the form..." << RESET << std::endl;
	// 		sansa.executeForm(robotForm);
	// 	} catch (std::exception& e) {
	// 		std::cout << std::endl;
	// 		std::cout << BOLD << "Exception caught: " << RED << e.what() << RESET << std::endl;
	// 	}

	// 	std::cout << std::endl;

	// 	try {
	// 		Bureaucrat sansa("Sansa", 42);
	// 		PresidentialPardonForm pardomForm("Westerland");

	// 		std::cout << BOLD << "Form details:" << RESET << std::endl;
	// 		std::cout << pardomForm << std::endl;

	// 		sansa.signForm(pardomForm);

	// 		std::cout << BOLD << "Attempting to execute the form..." << RESET << std::endl;
	// 		sansa.executeForm(pardomForm);
	// 	} catch (std::exception& e) {
	// 		std::cout << std::endl;
	// 		std::cout << BOLD << "Exception caught: " << RED << e.what() << RESET << std::endl;
	// 	}

	// }

	// std::cout << std::endl;

	// {
	// 	std::cout << INVERSE << "   Attempting to execute form with high grade   \n" << RESET << std::endl;
	// 	try {
	// 		Bureaucrat arya("Arya", 35);
	// 		ShrubberyCreationForm treeForm("Winterfell");

	// 		std::cout << BOLD << "Form details:" << RESET << std::endl;
	// 		std::cout << treeForm << std::endl;

	// 		arya.signForm(treeForm);

	// 		std::cout << BOLD << "Attempting to execute the form..." << RESET << std::endl;
	// 		arya.executeForm(treeForm);
	// 	} catch (std::exception& e) {
	// 		std::cout << std::endl;
	// 		std::cout << BOLD << "Exception caught: " << RED << e.what() << RESET << std::endl;
	// 	}

	// 	std::cout << std::endl;

	// 	try {
	// 		Bureaucrat arya("Arya", 17);
	// 		RobotomyRequestForm robotForm("Winterfell");

	// 		std::cout << BOLD << "Form details:" << RESET << std::endl;
	// 		std::cout << robotForm << std::endl;

	// 		arya.signForm(robotForm);

	// 		std::cout << BOLD << "Attempting to execute the form..." << RESET << std::endl;
	// 		arya.executeForm(robotForm);
	// 	} catch (std::exception& e) {
	// 		std::cout << std::endl;
	// 		std::cout << BOLD << "Exception caught: " << RED << e.what() << RESET << std::endl;
	// 	}

	// 	std::cout << std::endl;

	// 	try {
	// 		Bureaucrat arya("Arya", 1);
	// 		PresidentialPardonForm pardomForm("Winterfell");

	// 		std::cout << BOLD << "Form details:" << RESET << std::endl;
	// 		std::cout << pardomForm << std::endl;

	// 		arya.signForm(pardomForm);

	// 		std::cout << BOLD << "Attempting to execute the form..." << RESET << std::endl;
	// 		arya.executeForm(pardomForm);
	// 	} catch (std::exception& e) {
	// 		std::cout << std::endl;
	// 		std::cout << BOLD << "Exception caught: " << RED << e.what() << RESET << std::endl;
	// 	}
	// }



	Intern someRandomIntern;
	AForm *tmp;

	std::cout << INVERSE << "\nROBOTOMY REQUEST" << RESET << std::endl;
	try {
		tmp = someRandomIntern.makeForm("robotomy request", "Bender");
		if (tmp) {
			std::cout << GREEN << "Form created successfully!" << RESET << std::endl;
			delete tmp;
	}
	} catch (std::exception &e) {
		std::cout << BOLD << "Exception caught: " << RED << e.what() << RESET << std::endl;
	}

	std::cout << INVERSE << "\nSHRUBBERY CREATION" << RESET << std::endl;
	try {
		tmp = someRandomIntern.makeForm("shrubbery creation", "Downtown");
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
			someRandomIntern.makeForm("presidential pardon", "corrupt politician");
		if (tmp) {
			std::cout << GREEN << "Form created successfully!" << RESET << std::endl;
			delete tmp;
	}
	} catch (std::exception &e) {
		std::cout << BOLD << "Exception caught: " << RED << e.what() << RESET << std::endl;
	}

	std::cout << INVERSE << "\nTAX EXEMPTION" << RESET << std::endl;
	try {
		tmp = someRandomIntern.makeForm("tax exemption", "Bruno Moretti");
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
