#include "Contact.hpp"
#include <iostream>

Contact::Contact(): name(""), last_name(""), nickname(""),
	darkest_secret(""), phone(""){
}

Contact::~Contact(){
}

std::string Contact::getName() {
	return (this->name);
}

std::string Contact::getLast_name(){
	return (this->last_name);
}

std::string Contact::getNickname(){
	return (this->nickname);
}

std::string Contact::getDarkest_secret(){
	return (this->darkest_secret);
}

std::string Contact::getPhone(){
	return (this->phone);
}

void Contact::setName(const std::string& name) {
	this->name = name;
}

void Contact::setLast_name(const std::string& last_name){
	this->last_name = last_name;
}

void Contact::setNickname(const std::string& nick){
	this->nickname = nick;
}

void Contact::setDarkest_secret(const std::string& secret){
	this->darkest_secret = secret;
}

void Contact::setPhone(const std::string& phone){
	this->phone = phone;
}
