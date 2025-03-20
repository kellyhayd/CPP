#include "BitcoinExchange.hpp"
#include "colors.hpp"
#include <iostream>
#include <fstream>

void	initProgram(char* argv) {
	std::ifstream	file(argv);
	if (!file.is_open()) {
		throw std::runtime_error("Error: could not open file.");
	}

	std::string	line;
	std::getline(file, line);
	while (std::getline(file, line)) {
		// process data and value
	}
}

int main(int argc, char** argv) {
	if (argc == 2) {
		initProgram(argv[1]);

	} else {
		std::cerr << RED("USAGE: ") << WHITE("./btc <filename>") << std::endl;
	}
	
	return (0);
}