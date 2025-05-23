#include "BitcoinExchange.hpp"
#include "colors.hpp"
#include <iostream>
#include <fstream>

void	initProgram(char* argv) {
	std::ifstream	file(argv);
	if (!file.is_open()) {
		throw std::runtime_error("Error: could not open file.");
	}
	BitcoinExchange	btc;
	btc.processInput(file);
}

int main(int argc, char** argv) {
	if (argc == 2) {
		initProgram(argv[1]);
	} else {
		std::cerr << RED("USAGE: ") << WHITE("./btc <filename>") << std::endl;
	}
	
	return (0);
}