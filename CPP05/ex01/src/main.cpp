#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Colors.hpp"
#include <iostream>

int main() {
	std::cout << std::endl;
	std::cout << INVERSE << "   Attempting to sign form with low grade   \n" << RESET << std::endl;
	try {
		Form form("Application Form", 50, 25);

		Bureaucrat bureaucrat("Jon Snow", 55);

		std::cout << BOLD << "Form details:" << RESET << std::endl;
		std::cout << form << std::endl;

		std::cout << BOLD << "Attempting to sign the form..." << RESET << std::endl;
		bureaucrat.signForm(form);

		std::cout << BOLD << "Form details:" << RESET << std::endl;
		std::cout << form << std::endl;

	} catch (std::exception& e) {
		std::cout << BOLD << "Exception caught: " << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
	std::cout << INVERSE << "\n   Attempting to sign form with high grade   \n" << RESET << std::endl;
	try {
		Form form2("Approval Form", 5, 10);

		Bureaucrat bureaucrat2("Cersei", 2);

		std::cout << BOLD << "Form details:" << RESET << std::endl;
		std::cout << form2 << std::endl;

		std::cout << BOLD << "Attempting to sign the form..." << RESET << std::endl;
		bureaucrat2.signForm(form2);

		std::cout << BOLD << "Form details:" << RESET << std::endl;
		std::cout << form2 << std::endl;

	} catch (std::exception& e) {
		std::cout << BOLD <<  "Exception caught: " << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
	std::cout << INVERSE << "\n   Attempting to create a form with invalids grades   \n" << RESET << std::endl;
	try {
		Form form3("Wrong Form", 0, 10);
	} catch (std::exception& e) {
		std::cout << BOLD <<  "Exception caught: " << RED << e.what() << RESET << std::endl;
	}
	try {
		Form form4("Wrong Form 2", 10, 155);
	} catch (std::exception& e) {
		std::cout << BOLD <<  "Exception caught: " << RED << e.what() << RESET << std::endl;
	}

	return 0;
}
