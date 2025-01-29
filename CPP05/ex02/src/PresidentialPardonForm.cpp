#include "PresidentialPardonForm.hpp"
#include "Colors.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5) {
	this->_target = target;
};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other) {
	*this = other;
};

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		this->_target = other._target;
	}
	return *this;
};

PresidentialPardonForm::~PresidentialPardonForm() {};

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	if (!this->getSigned()) {
		throw GradeTooLowException();
	}
	if (executor.getGrade() > this->getGradeToExecute()) {
		throw GradeTooLowException();
	}
	std::cout << BOLD << YELLOW << executor.getName() << LIGHTGRAY \
		<< " has been pardoned by Zaphod Beeblebrox" << RESET << std::endl;
	std::cout << BOLD << YELLOW << executor.getName() << LIGHTGRAY << " executed " \
		<< CYAN << this->getName() << std::endl;
};
