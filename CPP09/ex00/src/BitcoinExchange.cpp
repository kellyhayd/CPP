#include "BitcoinExchange.hpp"
#include "colors.hpp"

#include <fstream>
#include <stdlib.h>
#include <string>
#include <iomanip>

static void	fillData(std::map<t_date, float>& data) {
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
			t_date key = {atoi(date.substr(0, date.find('-')).c_str()), 
				atoi(date.substr(date.find('-') + 1, date.rfind('-') - date.find('-') - 1).c_str()), 
				atoi(date.substr(date.rfind('-') + 1).c_str())};
			data[key] = rate;
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

std::map<t_date, float>	BitcoinExchange::getData() const { return (this->_data); }

void	BitcoinExchange::processInput(std::ifstream& file) {
	std::string	line;
	std::getline(file, line);
	while (std::getline(file, line)) {
		std::string	date = line.substr(0, line.find('|'));
		if (!validateDate(date)) {
			std::cerr << RED("Error: bad input => ") << line << std::endl;
		}
		std::string value = line.substr(line.find('|') + 1);
		if (validateValue(value, line))
			printOutput(date, value);
	}
}

bool	BitcoinExchange::validateDate(std::string& date) {
	if (date.empty()) {
		return (false);
	}
	for (std::string::iterator it = date.begin();  it != date.end(); it++) {
		if (std::isdigit(*it)) {
			break;
		}
	}
	
	size_t firstDash = date.find('-');
	size_t secondDash = date.find('-', firstDash + 1);
	if (firstDash == std::string::npos || secondDash == std::string::npos) {
		return (false);
	}
	_year = atoi(date.substr(0, firstDash).c_str());
	if (_year > 2025 || _year < 2009) {
		return (false);
	}
	_month = atoi(date.substr(firstDash + 1, secondDash - firstDash - 1).c_str());
	if (_month > 12 || _month < 1) {
		return (false);
	}
	_day = atoi(date.substr(secondDash + 1).c_str());
	if (_day < 1 || _day > 31) {
		return (false);
	}
	if (((_month == 2 && _day > 29) || (_month == 2 && _day == 29 && _year % 4 != 0)) ||
		((_month == 4 || _month == 6 || _month == 9 || _month == 11) && _day > 30)) {
		return (false);
	}
	return (true); 
}

bool	BitcoinExchange::validateValue(std::string& value, std::string& line) {
	_value = std::strtof(value.c_str(), 0);
	if (!_value) {
		std::cerr << RED("Error: bad input => ") << line << std::endl;
		return (false);
	} else if (_value < 0) {
		std::cerr << RED("Error: not a positive number") << std::endl;
		return (false);
	} else if (_value > 1000) {
		std::cerr << RED("Error: too large a number") << std::endl;
		return (false);
	}
	return (true);
}

void	BitcoinExchange::printOutput(std::string& date, std::string& value) {
	float rate = findMatch();
	float result = rate * _value;

	std::cout << std::fixed << std::setprecision(2);
	std::cout << YELLOW(date) << " => " << YELLOW(value) << " = " << CYAN(result) << std::endl;
}

float	BitcoinExchange::findMatch() {
	float	closestRate = 0;
	for (std::map<t_date, float>::iterator it = _data.begin(); it != _data.end(); it++) {
		if (it->first.year == _year && it->first.month == _month && it->first.day == _day) {
			return (it->second);
		}
		if (it->first.year < _year || (it->first.year == _year && it->first.month < _month) ||
			(it->first.year == _year && it->first.month == _month && it->first.day < _day)) {
			closestRate = it->second;
		}
	}
	return (closestRate);
}
