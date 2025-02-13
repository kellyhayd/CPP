#include "ScalarConverter.hpp"
#include "Colors.hpp"
#include <iostream>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <limits>

ScalarConverter::ScalarConverter() {};

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	*this = other;
};

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return (*this);
};

ScalarConverter::~ScalarConverter() {};

static void	printDouble(std::string value, double d) {
	std::cout << BOLD << "double: " << RESET;

	if ((d < std::floor(d) || d > std::ceil(d))) {
			std::cout << RED << "impossible" << RESET << std::endl;
			return;
	}
	for (std::string::iterator it = value.begin(); it < value.end(); it++) {
		if ((*it == '.' || std::isnan(d) || std::isinf(d))) {
			std::cout << CYAN << d << RESET << std::endl;
			return;
		}
	}
	std::cout << CYAN << d << ".0" << RESET << std::endl;
}

static void	printFloat(std::string value, float f) {
	std::cout << BOLD << "float: " << RESET;

	if (f < std::floor(f) || f > std::ceil(f)) {
			std::cout << RED << "impossible" << RESET << std::endl;
			return;
	}
	for (std::string::iterator it = value.begin(); it < value.end(); it++) {
		if ((*it == '.' || std::isnan(f) || std::isinf(f))) {
			std::cout << CYAN << f << "f" << RESET << std::endl;
			return;
		}
	}
	std::cout << CYAN << f << ".0f" << RESET << std::endl;
}

static void	printInt(std::string value, double d, int i) {
	if (std::isnan(d) || std::isinf(d) || std::atol(value.c_str()) > static_cast<long int>(std::numeric_limits<int>::max())
		|| std::atol(value.c_str()) < static_cast<long int>(std::numeric_limits<int>::min())) {
		std::cout << BOLD << "int: " << RED << "impossible" << RESET << std::endl;
		return;
	}
	std::cout << BOLD << "int: " << CYAN << i << RESET << std::endl;
}

static void	printChar(std::string value, int i) {
	if (i < -128 || i > 127) {
		std::cout << BOLD << "char: " << RED << "impossible" << RESET << std::endl;
	} else {
		for (std::string::iterator it = value.begin(); it < value.end(); it++) {
			if (*it == '.') {
				std::cout << BOLD << "char: " << RED << "impossible" << RESET << std::endl;
				return;
			}
		}
		if (!std::isprint(i)) {
			std::cout << BOLD << "char: " << RED << "Non displayable" << RESET << std::endl;
			return;
		}
		char	c = static_cast<char>(i);
		std::cout << BOLD << "char: " << CYAN << c << RESET << std::endl;
	}
};

static bool	isFloat(std::string value) {
	return (value[value.length() - 1] =='f' ? true : false);
};

static bool	validateInput(std::string value) {
	if (value == "inf" || value == "+inf" || value == "-inf" || value == "inff" \
		|| value == "+inff" || value == "-inff" || value == "nan")
		return (true);
	if (value.length() > 1) {
		if (!std::isdigit(value[0]) && !(value[0] == '-') && !(value[0] == '+')) {
			return (false);
		}
		if (std::isdigit(value[0]) || value[0] == '-' || value[0] == '+') {
			int dot = 0;
			for (std::string::iterator it = value.begin(); it < value.end(); it++) {
				if (it == value.begin() && (*it == '-' || *it == '+')) {
					continue;
				}
				if (*it == '.') {
					dot++;
					if (dot > 1) {
						return (false);
					}
				}
				else if (*it == 'e' || *it == 'E') {
					if (it + 1 == value.end() || (!std::isdigit(*(it + 1)) && *(it + 1) != '+' && *(it + 1) != '-')) {
						return (false);
					}
					it++;
				}
				else if (!std::isdigit(*it) && !(*value.rbegin() == 'f')) {
					return (false);
				}
			}
		}
	}
	return (true);
}

void	ScalarConverter::convert(const std::string& value) {
	if (!validateInput(value)) {
		std::cout << BOLD << RED << "ERROR: invalid input" << RESET << std::endl;
		return;
	}

	float	f;
	double	d;
	char	c;

	if (value.length() == 1 && std::isdigit(value[0]) && std::isprint(value[0])) {
		f = strtof(value.c_str(), NULL);
		d = static_cast<double>(f);
	}
	else if (value.length() == 1 && !std::isdigit(value[0])) {
		c = value[0];
		f = static_cast<float>(c);
		d = static_cast<double>(f);
	}
	else {
		if (isFloat(value)) {
			f = atof(value.c_str());
			d = static_cast<double>(f);
		} else {
			d = atof(value.c_str());
			f = static_cast<float>(d);
		}
	}
	int	i = static_cast<int>(f);

	printChar(value, i);
	printInt(value, d, i);
	printFloat(value, f);
	printDouble(value, d);
};
