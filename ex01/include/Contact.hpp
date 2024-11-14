#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact{
private:
	std::string	name;
	std::string	last_name;
	std::string	nickname;
	std::string	darkest_secret;
	std::string	phone;

public:
	Contact();
	~Contact();
	Contact(std::string name, std::string last_name, std::string nickname,
		std::string darkest_secret, std::string phone);
	std::string getName();
	std::string getLast_name();
	std::string getNickname();
	std::string getDarkest_secret();
	std::string getPhone();
};

#endif
