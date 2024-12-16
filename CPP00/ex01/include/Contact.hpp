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

	std::string getName();
	std::string getLast_name();
	std::string getNickname();
	std::string getDarkest_secret();
	std::string getPhone();
	void setName(const std::string& n);
	void setLast_name(const std::string& ln);
	void setNickname(const std::string& nn);
	void setDarkest_secret(const std::string& ds);
	void setPhone(const std::string& p);
};

#endif
