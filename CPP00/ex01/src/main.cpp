#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <cstdio>


std::string	phone_define(const std::string msg){
	std::string	number;
	int	ok = 1;

	do{
		std::cout << msg << '\n';
		std::getline(std::cin >> std::ws, number);
		std::clearerr(stdin);
		std::cin.clear();
		for(std::string::const_iterator it = number.begin(); it != number.end(); ++it)
		{
			if (!std::isdigit(*it)){
				std::cout << ">> Invalid phone number. Digits only <<\n";
				number.clear();
				ok = 0;
				break;
			}
			ok = 1;
		}
		if (ok == 1 && (number.size() < 8 || number.size() > 11 || number.empty())){
			std::cout << ">> Phone number must have 8-11 numbers <<\n";
			number.clear();
		}
	} while (number.empty());
	std::cin.clear();
	return (number);
}

std::string	str_define(const std::string msg){
	std::string	input;

	do{
		std::cout << msg << '\n';
		std::clearerr(stdin);
		std::cin.clear();
		std::getline(std::cin >> std::ws, input);
		if (input.size() < 2 || input.empty()){
			std::cout << ">> Field must be longer than one character <<\n";
			input.clear();
		}
	} while (input.empty());
	return (input);
}

void	contact_define(PhoneBook *book){
	Contact		new_contact;

	std::cout << "\nPlease complete the following informations:\n\n";
	new_contact.setName(str_define("First name: "));
	new_contact.setLast_name(str_define("Last name: "));
	new_contact.setNickname(str_define("Nickname: "));
	new_contact.setDarkest_secret(str_define("Darkest secret: "));
	new_contact.setPhone(phone_define("Phone number: "));
	book->add(new_contact);
	std::cout << "\n***Contact successfully created!***\n\n";
}

std::string	to_lower(const std::string &str){
	std::string	lower_str;

	for(std::string::const_iterator it = str.begin(); it != str.end(); ++it){
		lower_str += std::tolower(*it);
	}
	return (lower_str);
}

int	main(){
	std::string	action;
	PhoneBook	book;
	int			exit_code = 0;

	std::cout << "\n☎️  Welcome to your PhoneBook!\n\n";
	do{
		std::cout << "-----------------------------------\n";
		std::cout << "*** What do you like to do now? ***\n";
		std::cout << "-----------------------------------\n";
		std::cout << "1. ADD\n2. SEARCH\n3. EXIT\n\n";
		std::clearerr(stdin);
		std::cin.clear();
		std::cin >> action;
		if (action.compare("1") == 0 || to_lower(action).compare("add") == 0){
			contact_define(&book);
		}
		else if (action.compare("2") == 0 || to_lower(action).compare("search") == 0){
			book.search();
		}
		else if (action.compare("3") == 0 || to_lower(action).compare("exit") == 0){
			exit_code = book.exit();
		}
		else
			std::cout << ">> Invalid option <<\n";
	} while(exit_code != -1);
	return (0);
}
