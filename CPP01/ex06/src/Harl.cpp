#include "Harl.hpp"

Harl::Harl(){};

Harl::~Harl(){};

void Harl::debug(void){
	std::cout << BOLD << RED << "\n[DEBUG]\n" << RESET
	<< "I love having tofu for my 7XL-double-cheese-triple-pickle-"
				"special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void){
	std::cout << BOLD << CYAN << "\n[INFO]\n" << RESET
	<< "I cannot believe adding extra tofu costs more money. You didn’t "
			"put enough tofu in my burger! If you did, I wouldn’t be asking for more!"\
			 << std::endl;
}

void Harl::warning(void){
	std::cout << BOLD << RED << "\n[WARNING]\n" << RESET
	<< "I think I deserve to have some extra tofu for free. I’ve been "
			"coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void){
	std::cout << BOLD << CYAN << "\n[ERROR]\n" << RESET
	<< "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level){
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++){
		if (!level.compare(levels[i]))
			this->selection = i;
	}

	switch(this->selection){
		case DEBUG:
			debug();
			//Fall through
		case INFO:
			info();
			//Fall through
		case WARNING:
			warning();
			//Fall through
		case ERROR:
			error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}
