#include "Harl.hpp"

Harl::Harl(){
	std::cout << BOLD << GREEN << "Harl is here to complain" << RESET << std::endl;
};

Harl::~Harl(){
	std::cout << BOLD << GREEN << "Finally, Harl is gone" << RESET << std::endl;
};

void Harl::debug(void){
	std::cout << "I love having tofu for my 7XL-double-cheese-triple-pickle-"
				"special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void){
	std::cout << "I cannot believe adding extra tofu costs more money. You didn’t "
			"put enough tofu in my burger! If you did, I wouldn’t be asking for more!"\
			 << std::endl;
}

void Harl::warning(void){
	std::cout << "I think I deserve to have some extra tofu for free. I’ve been "
			"coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void){
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level){
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*functions[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for(int i = 0; i < 4; i++){
		if (!level.compare(levels[i])){
			(this->*functions[i])();
			return;
		}
	}
	std::cout << BOLD << RED << "Not a valid level" << RESET << std::endl;
}
