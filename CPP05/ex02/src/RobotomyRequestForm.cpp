#include "RobotomyRequestForm.hpp"
#include "Colors.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45) {
	this->_target = target;
};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) {
	*this = other;
};

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		this->_target = other._target;
	}
	return *this;
};

RobotomyRequestForm::~RobotomyRequestForm() {};

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if (!this->getSigned() || executor.getGrade() > this->getGradeToExecute()) {
		std::cout << BOLD << YELLOW << executor.getName() << RED << " not executed " \
			<< CYAN << this->getName() << std::endl;
		throw GradeTooLowException();
	}
	std::srand(std::time(0));
	if (std::rand() % 2) {
		std::cout << BOLD << YELLOW << executor.getName() \
			<< GREEN << " has been robotomized successfully" << std::endl;
	} else {
		std::cout << BOLD << YELLOW << executor.getName() \
			<< RED << " robotomization failed" << std::endl;
	}
	std::cout << BOLD << YELLOW << executor.getName() << LIGHTGRAY << " executed " \
		<< CYAN << this->getName() << std::endl;
};
