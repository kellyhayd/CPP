#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat;

class AForm {
private:
	const std::string	_name;
	bool				_signed;
	const int			_gradeToSign;
	const int			_gradeToExecute;

public:
	AForm();
	AForm(const std::string& name, int gradeToSign, int gradeToExecute);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();

	std::string	getName() const;
	bool	getSigned() const;
	int	getGradeToSigh() const;
	int	getGradeToExecute() const;

	virtual void	beSigned(Bureaucrat& bureaucrat);
	virtual void	execute(const Bureaucrat& executor) const = 0;

	class GradeTooHighException : public std::exception {
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		virtual const char* what() const throw();
	};
};

std::ostream&	operator<<(std::ostream& out, const AForm& value);

#endif
