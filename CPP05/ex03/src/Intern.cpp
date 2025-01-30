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

static AForm*	presidentialForm(std::string target) {
	return (new PresidentialPardonForm(target));
};

static AForm*	robotomyForm(std::string target) {
	return (new RobotomyRequestForm(target));
};

static AForm*	shrubberyForm(std::string target) {
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::makeForm(std::string formType, std::string target) {
	std::string	forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	AForm* (*fun[3])(std::string) = {&presidentialForm, &robotomyForm, &shrubberyForm};

	for (int i = 0; i < 3; i++) {
		if (!formType.compare(forms[i])) {
			return (fun[i](target));
		}
	}
	std::cout << BOLD << RED << "Type of form not found" << RESET << std::endl;
	return (NULL);
}
