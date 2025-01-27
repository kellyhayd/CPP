#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Colors.hpp"

AForm::AForm() : _name("random form"), _signed(false), \
		_gradeToSign(150), _gradeToExecute(150) {};

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
		: _name(name), _signed(false), _gradeToSign(gradeToSign),
		_gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other) : _name(other._name), _signed(other._signed),
		_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
	*this = other;
};

AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		(std::string &)this->_name = other._name;
		(int &)this->_signed = other._signed;
		(int &)this->_gradeToSign = other._gradeToSign;
		(int &)this->_gradeToExecute = other._gradeToExecute;
	}
	return *this;
};

AForm::~AForm() {};

std::string	AForm::getName() const { return (_name); };
bool	AForm::getSigned() const { return (_signed); };
int	AForm::getGradeToSigh() const { return (_gradeToSign); };
int	AForm::getGradeToExecute() const { return (_gradeToExecute); };

void	AForm::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= this->_gradeToSign) {
		this->_signed = true;
	} else {
		throw GradeTooLowException();
	}
};

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade too high";
};

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade too low";
};

std::ostream& operator<<(std::ostream& out, const AForm& value) {
	out << BOLD << LIGHTGRAY << "AForm " << CYAN << value.getName() << LIGHTGRAY \
		<< ":\nsigned = " << CYAN << value.getSigned() << LIGHTGRAY << "\ngrade to sign = " \
		<< CYAN << value.getGradeToSigh() << LIGHTGRAY << "\ngrade to execute = " \
		<< CYAN << value.getGradeToExecute() << RESET << std::endl;
	return (out);
}
