#include "BitcoinExchange.hpp"
#include "colors.hpp"

#include <fstream>

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
			float	rate = std::strtof(value.c_str(), 0);
			if (rate < 0) {
				std::cerr << "Error: Negative rate" << std::endl;
				continue;
			}
			data[date] = rate;
		}
	}
}

BitcoinExchange::BitcoinExchange() {
	fillData(this->_data);
	if (this->_data.empty()) {
		std::cerr << "Error: No data found" << std::endl;
		return;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
	this->_data = copy._data;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &copy) {
	if (this != &copy) {
		this->_data = copy._data;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

std::map<std::string, float>	BitcoinExchange::getData() const { return (this->_data); }

void	BitcoinExchange::processInput(std::ifstream& file) {
	std::string	line;
	std::getline(file, line);
	std::string	date = line.substr(0, line.find('|'));
	if (date.empty()) {
		// invalid input
	} else if (!validateDate(date)) {
		// invalid data
	} 
}