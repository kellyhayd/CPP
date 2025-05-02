#include "BitcoinExchange.hpp"
#include "colors.hpp"

#include <fstream>
#include <stdlib.h>
#include <sstream>

static void	fillData(std::map<std::string, float>& data) {
	std::ifstream	file("data.csv");
	if (file.is_open()) {
		std::string	line;
		std::getline(file, line);
		while (std::getline(file, line)) {
			std::string	date = line.substr(0, line.find(','));
			std::string	value  = line.substr(line.find(',') + 1);
			if (date.empty() || value.empty()) {
				std::cerr << "Error: Invalid data format" << std::endl;
				continue;
			}
			std::stringstream	ss(value);
			float	price;
			ss >> price;
			if (price < 0) {
				std::cerr << "Error: Negative price" << std::endl;
				continue;
			}
			data[date] = price;
		}
	}
}

BitcoinExchange::BitcoinExchange() {
	fillData(this->data);
	if (this->data.empty()) {
		std::cerr << "Error: No data found" << std::endl;
		return;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
	this->data = copy.data;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &copy) {
	if (this != &copy) {
		this->data = copy.data;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

std::map<std::string, float>	BitcoinExchange::getData() const { return (this->data); }
