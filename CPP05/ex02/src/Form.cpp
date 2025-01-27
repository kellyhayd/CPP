#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "Colors.hpp"

Form::Form() : _name("random form"), _signed(false), \
		_gradeToSign(150), _gradeToExecute(150) {};

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
		: _name(name), _signed(false), _gradeToSign(gradeToSign),
		_gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other) : _name(other._name), _signed(other._signed),
		_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
	*this = other;
};

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		(std::string &)this->_name = other._name;
		(int &)this->_signed = other._signed;
		(int &)this->_gradeToSign = other._gradeToSign;
		(int &)this->_gradeToExecute = other._gradeToExecute;
	}
	return *this;
};

Form::~Form() {};

std::string	Form::getName() const { return (_name); };
bool	Form::getSigned() const { return (_signed); };
int	Form::getGradeToSigh() const { return (_gradeToSign); };
int	Form::getGradeToExecute() const { return (_gradeToExecute); };

void	Form::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= this->_gradeToSign) {
		this->_signed = true;
	} else {
		throw GradeTooLowException();
	}
};

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade too high";
};

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade too low";
};

std::ostream& operator<<(std::ostream& out, const Form& value) {
	out << BOLD << LIGHTGRAY << "Form " << CYAN << value.getName() << LIGHTGRAY \
		<< ":\nsigned = " << CYAN << value.getSigned() << LIGHTGRAY << "\ngrade to sign = " \
		<< CYAN << value.getGradeToSigh() << LIGHTGRAY << "\ngrade to execute = " \
		<< CYAN << value.getGradeToExecute() << RESET << std::endl;
	return (out);
}
