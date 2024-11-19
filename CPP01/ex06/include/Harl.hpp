#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl{
private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
	size_t	selection;

public:
	Harl();
	~Harl();

	enum selectedlevel{
		DEBUG,
		INFO,
		WARNING,
		ERROR,
	};
	void complain(std::string level);
};

#endif
