#include "Contact.hpp"
#include <iostream>

Contact::Contact(): name(""), last_name(""), nickname(""),
	darkest_secret(""), phone(""){
}

Contact::~Contact(){
}

Contact::Contact(std::string name, std::string last_name, std::string nickname,
	std::string darkest_secret, std::string phone) : name(name), last_name(last_name),
	nickname(nickname), darkest_secret(darkest_secret), phone(phone){
}

std::string Contact::getName(){
	return (name);
}

std::string Contact::getLast_name(){
	return (last_name);
}

std::string Contact::getNickname(){
	return (nickname);
}

std::string Contact::getDarkest_secret(){
	return (darkest_secret);
}

std::string Contact::getPhone(){
	return (phone);
}
