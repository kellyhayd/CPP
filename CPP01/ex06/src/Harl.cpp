#include "Harl.hpp"

Harl::Harl(){};

Harl::~Harl(){};

void Harl::debug(void){
	std::cout << "[DEBUG]\n"
	<< "I love having tofu for my 7XL-double-cheese-triple-pickle-"
				"special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void){
	std::cout << "[INFO]\n"
	<< "I cannot believe adding extra bacon costs more money. You didn’t "
			"put enough bacon in my burger! If you did, I wouldn’t be asking for more!"\
			 << std::endl;
}

void Harl::warning(void){
	std::cout << "[WARNING]\n"
	<< "I think I deserve to have some extra bacon for free. I’ve been "
			"coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void){
	std::cout << "[ERROR]\n"
	<< "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level){
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	size_t i = 0;
	while(i < 4){
		if (!level.compare(levels[i])){
			break;
		}
		i++;
	}

	switch(i){
		case 0:
			debug();
		case 1:
			info();
		case 2:
			warning();
		case 3:
			error();
		default:
			std::cout << "No Valid Level\n";
			break;
	}
}
