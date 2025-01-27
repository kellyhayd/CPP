#include "Bureaucrat.hpp"
#include "Colors.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _name("default"), _grade(0) {
	std::cout << BOLD << LIGHTGRAY << "Bureaucrat " << YELLOW \
		<< "default " << LIGHTGRAY << "created" << RESET << std::endl;
};

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
	this->_grade = grade;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << BOLD << LIGHTGRAY << "Bureaucrat " << YELLOW \
		<< name << LIGHTGRAY << " created" << RESET << std::endl;
};

Bureaucrat::Bureaucrat(const Bureaucrat& other) { *this = other; };

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		this->_grade = other._grade;
	}
	return (*this);
};

Bureaucrat::~Bureaucrat() {
	std::cout << BOLD << LIGHTGRAY << "Bureaucrat " << YELLOW \
		<< this->_name << LIGHTGRAY << " was destroyed" << RESET << std::endl;
};

std::string	Bureaucrat::getName() const { return (_name); };

int	Bureaucrat::getGrade() const { return (_grade); };

void	Bureaucrat::incrementGrade() {
	if (this->_grade > 1) {
		_grade--;
	} else {
		throw GradeTooHighException();
	}
};

void	Bureaucrat::decrementGrade() {
	if (this->_grade < 150) {
		_grade++;
	} else {
		throw GradeTooLowException();
	}
};

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& value) {
	out << BOLD << YELLOW << value.getName() << LIGHTGRAY \
		 << ", bureaucrat grade " << YELLOW << value.getGrade() << RESET;
	return (out);
};
