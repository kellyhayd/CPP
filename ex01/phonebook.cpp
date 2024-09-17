#include <iostream>

class Contact{
	public:
		std::string	name;
		std::string	last_name;
		std::string	nickname;
		std::string	darkest_secret;
		std::string	phone_number;
	Contact() : name(), last_name(), nickname(), darkest_secret(), phone_number() { }
	Contact(std::string name, std::string last_name, std::string nick, std::string secret, std::string number){
		this->name = name;
		this->last_name = last_name;
		this->nickname = nick;
		this->darkest_secret = secret;
		this->phone_number = number;
	}
};

class PhoneBook{
private:
	int		index;

public:
	Contact	contacts[8];

	PhoneBook() :  index(0), contacts() { }

	int	exit(){
		return -1;
	}
	void	add(Contact new_contact){
		contacts[index % 8] = new_contact;
		index++;
	}
	void	search(){
		if (contacts[0].name.empty()){
			std::cout << "Sorry, you have no friend saved in this phonebook :(\n\n";
			return ;
		}
		std::cout << "PhoneBook contacts:\n\n";
		for(size_t i = 0; i < 8 && !contacts[i].name.empty(); i++){
			std::cout << "#" << i + 1 << ' ';
			for(size_t j = 0; j < contacts[i].name.size() && j < 9; j++){
				std::cout << contacts[i].name[j];
			}
			std::cout << " | ";
			for(size_t j = 0; j < contacts[i].last_name.size() && j < 10; j++){
				std::cout << contacts[i].last_name[j];
			}
			if (contacts[i].last_name[10] != '\0'){
				std::cout << '.';
			}
			std::cout << " | ";
			for(size_t j = 0; j < contacts[i].nickname.size() && j < 10; j++){
				std::cout << contacts[i].nickname[j];
			}
			if (contacts[i].last_name[10] != '\0'){
				std::cout << '.';
			}
			std::cout << '\n';
		}
	}
};

void	create_contact(PhoneBook *book){
	std::string	name;
	std::string	last_name;
	std::string	nick;
	std::string	secret;
	std::string	number;

	std::cout << "Please complete the following informations:\n\n";
	std::cout << "First name: ";
	std::cin >> name;
	std::cout << "Last name: ";
	std::cin >> last_name;
	std::cout << "Nickname: ";
	std::cin >> nick;
	std::cout << "The darkest secret of this contact: ";
	std::getline(std::cin >> std::ws, secret);
	std::cout << "Phone number: ";
	std::cin >> number;
	Contact new_contact = Contact(name, last_name, nick, secret, number);
	book->add(new_contact);
	std::cout << "\nThe contact was created and saved in phonebook!\n\n";
}

int	main(){
	std::string	action;
	Contact		contacts[8];
	PhoneBook	book;
	int			exit_code;

	std::cout << "☎️  Welcome to the PhoneBook!  📔\n\n";
	do{
		std::cout << "*********************************\n";
		std::cout << "***What do you like to do now?***\n\n";
		std::cout << "1. ADD  ✏️\n2. SEARCH  🔍\n3. EXIT  ❌\n";
		std::cin >> action;
		if (action.compare("1") == 0 || action.compare("ADD") == 0 || action.compare("add") == 0){
			create_contact(&book);
		}
		else if (action.compare("2") == 0 || action.compare("SEARCH") == 0 || action.compare("search") == 0){
			book.search();
		}
		else if (action.compare("3") == 0 || action.compare("EXIT") == 0 || action.compare("exit") == 0){
			exit_code = book.exit();
		}
	} while(exit_code != -1);
	return (0);
}
