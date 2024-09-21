#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>

int	PhoneBook::exit(){
	return -1;
}

void	PhoneBook::add(Contact new_contact){
	contacts[index % 8] = new_contact;
	index++;
}

int	PhoneBook::display(std::string index){
	int	idx = std::atoi(index.c_str()) - 1;

	if (!contacts[idx].name.empty()){
		std::cout << contacts[idx].name << '\n';
		std::cout << contacts[idx].last_name << '\n';
		std::cout << contacts[idx].nickname << '\n';
		std::cout << contacts[idx].darkest_secret << '\n';
		std::cout << contacts[idx].phone << std::endl;
		return (1);
	}
	else
		std::cout << ">> Invalid index. Try again <<" << std::endl;
	return (0);
}

void	PhoneBook::search(){
	if (contacts[0].name.empty()){
		std::cout << ">> Sorry, your phonebook is empty :( <<\n\n";
		return ;
	}
	std::cout << "PhoneBook contacts:\n\n";
	std::cout << std::setw(10) << "Index" << "|" << std::setw(10) << "First Name" << "|"
			<< std::setw(10) << "Last Name" << "|" << std::setw(10) << "Nickname" << std::endl;
	for(size_t i = 0; i < 8 && !contacts[i].name.empty(); i++){
		std::cout << std::setw(10) << (i +1) << "|";
		std::cout << std::setw(10) << (contacts[i].name.length() > 10 ?
			contacts[i].name.substr(0, 9) + "." : contacts[i].name) << "|";
		std::cout << std::setw(10) << (contacts[i].last_name.length() > 10 ?
			contacts[i].last_name.substr(0, 9) + "." : contacts[i].last_name) << "|";
		std::cout << std::setw(10) << (contacts[i].nickname.length() > 10 ?
			contacts[i].nickname.substr(0, 9) + "." : contacts[i].nickname) << std::endl;
	}
	std::string	index;
	int	result;
	do {
		std::cout << "-> Choose the index to display\n";
		std::cin >> index;
		result = display(index);
	} while(result == 0);
}
