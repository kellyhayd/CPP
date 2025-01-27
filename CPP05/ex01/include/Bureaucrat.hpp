#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat {
private:
	const std::string	_name;
	int	_grade;

public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	virtual ~Bureaucrat();

	std::string	getName() const;
	int	getGrade() const;

	void	incrementGrade();
	void	decrementGrade();

	class GradeTooHighException : public std::exception {
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& value);

#endif
