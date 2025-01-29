#ifndef PRESIDENTIALPARDOMFORM_HPP
#define PRESIDENTIALPARDOMFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
	std::string	_target;

public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	~PresidentialPardonForm();

	void	execute(const Bureaucrat& executor) const;
};

#endif
