#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook{
private:
	int		index;
	Contact	contacts[8];

public:

	PhoneBook();
	~PhoneBook();

	int		exit();
	void	add(Contact new_contact);
	void	search();
	int		display(int index);

};

#endif
