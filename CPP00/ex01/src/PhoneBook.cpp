#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <limits>

PhoneBook::PhoneBook(){
	index = 0;
}

PhoneBook::~PhoneBook(){
}

int	PhoneBook::exit(){
	return -1;
}

void	PhoneBook::add(Contact new_contact){
	contacts[index % 8] = new_contact;
	index++;
}

int	PhoneBook::display(int index){
	int	idx = index - 1;

	if (idx < 0 || idx >= 8)
	{
		std::cout << ">> Invalid index. Try again <<" << std::endl;
		return (0);
	}
	if (!contacts[idx].getName().empty()){
		std::cout << contacts[idx].getName() << '\n';
		std::cout << contacts[idx].getLast_name() << '\n';
		std::cout << contacts[idx].getNickname() << '\n';
		std::cout << contacts[idx].getDarkest_secret() << '\n';
		std::cout << contacts[idx].getPhone() << std::endl;
		return (1);
	}
	else
		std::cout << ">> Invalid index. Try again <<" << std::endl;
	return (0);
}

void	PhoneBook::search(){
	if (contacts[0].getName().empty()){
		std::cout << ">> Sorry, your phonebook is empty :( <<\n\n";
		return ;
	}
	std::cout << "PhoneBook contacts:\n\n";
	std::cout << std::setw(10) << "Index" << "|" << std::setw(10) << "First Name" << "|"
			<< std::setw(10) << "Last Name" << "|" << std::setw(10) << "Nickname" << std::endl;
	for(size_t i = 0; i < 8 && !contacts[i].getName().empty(); i++){
		std::cout << std::setw(10) << (i +1) << "|";
		std::cout << std::setw(10) << (contacts[i].getName().length() > 10 ?
			contacts[i].getName().substr(0, 9) + "." : contacts[i].getName()) << "|";
		std::cout << std::setw(10) << (contacts[i].getLast_name().length() > 10 ?
			contacts[i].getLast_name().substr(0, 9) + "." : contacts[i].getLast_name()) << "|";
		std::cout << std::setw(10) << (contacts[i].getNickname().length() > 10 ?
			contacts[i].getNickname().substr(0, 9) + "." : contacts[i].getNickname()) << std::endl;
	}
	int	index = 0;
	int	result = 0;
	do {
		std::cout << "-> Choose the index to display\n";
		std::clearerr(stdin);
		std::cin.clear();
		std::cin >> index;
		if (std::cin.fail()){
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		result = display(index);
	} while(result == 0);
}
