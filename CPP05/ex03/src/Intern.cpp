#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Colors.hpp"

#include <cstdlib>

Intern::Intern() {
	std::cout << BOLD << LIGHTGRAY << "Intern created" << RESET << std::endl;
};

Intern::Intern(const Intern& other) {
	(void)other;
	Intern();
};

Intern& Intern::operator=(const Intern& other) {
	if (this != &other) {
		*this = other;
	}
	return *this;
};

Intern::~Intern() {
	std::cout << BOLD << LIGHTGRAY << "Intern destroyed" << RESET << std::endl;
};

AForm*	Intern::makeForm(std::string formType, std::string target) {
	std::string	forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	AForm*	form = NULL;

	int	idx = 0;
	for (int i = 0; i < 3; i++) {
		if (!formType.compare(forms[i])) {
			break;
		}
		idx++;
	}
	switch (idx)
	{
		case 0:
			return (form = new PresidentialPardonForm(target));
		case 1:
			return (form = new RobotomyRequestForm(target));
		case 2:
			return (form = new ShrubberyCreationForm(target));
		default:
			std::cout << RED << "Form not found" << RESET << std::endl;
			return NULL;
	}
}
