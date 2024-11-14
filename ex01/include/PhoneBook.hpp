#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook{
private:
	int		index;

public:
	Contact	contacts[8];

	PhoneBook();
	~PhoneBook();

	int		exit();
	void	add(Contact new_contact);
	void	search();
	int		display(std::string index);

};

#endif
