#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat;

class Form {
private:
	const std::string	_name;
	bool	_signed;
	const int	_gradeToSign;
	const int	_gradeToExecute;

public:
	Form();
	Form(const std::string& name, int gradeToSign, int gradeToExecute);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

	std::string	getName() const;
	bool	getSigned() const;
	int	getGradeToSigh() const;
	int	getGradeToExecute() const;

	void	beSigned(Bureaucrat& bureaucrat);

	class GradeTooHighException : public std::exception {
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		virtual const char* what() const throw();
	};
};

std::ostream&	operator<<(std::ostream& out, const Form& value);

#endif
