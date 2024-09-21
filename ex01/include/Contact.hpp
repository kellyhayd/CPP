#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact{
public:
	std::string	name;
	std::string	last_name;
	std::string	nickname;
	std::string	darkest_secret;
	std::string	phone;

	~Contact() { }
	Contact() : name(), last_name(), nickname(), darkest_secret(), phone() { }
	Contact(std::string name, std::string last_name, std::string nickname,
		std::string darkest_secret, std::string phone){
		this->name = name;
		this->last_name = last_name;
		this->nickname = nickname;
		this->darkest_secret = darkest_secret;
		this->phone = phone;
	}
	// void setName(const std::string &name);
	// void setLast_name(const std::string &last_ame);
	// void setNickname(const std::string &nickname);
	// void setDarkest_secret(const std::string &darkest_secret);
	// void setPhone(const std::string &phone);
};

#endif
