#include "ScalarConverter.hpp"
#include "Colors.hpp"
#include <cctype>
#include <cmath>
#include <cstdlib>

ScalarConverter::~ScalarConverter() {};

static void	printFloat(std::string value, float f) {
	std::cout << BOLD << "float: " << CYAN << f;

	bool	hasDot = false;
	for (size_t i = 0 ; i < value.length(); i++) {
		if (value[i] == '.') {
			hasDot = true;
		}
	}
	if (hasDot == true) {
		std::cout << "f" << RESET << std::endl;
	} else {
		std::cout << ".0f" << RESET << std::endl;
	}
}

static void	printChar(std::string value, int i) {
	if ((value.length() > 1 && !std::isdigit(value[0])) || i < -128 || i > 127) {
		std::cout << BOLD << "char: " << RED << "impossible" << RESET << std::endl;
	}
	else if (!std::isprint(i)) {
		std::cout << BOLD << "char: " << RED << "Non displayable" << RESET << std::endl;
	}
	else {
		char	c = i;
		std::cout << BOLD << "char: " << CYAN << c << RESET << std::endl;
	}
};

static bool	isFloat(std::string value) {
	return (value[value.length() - 1] =='f' ? true : false);
};

void	ScalarConverter::convert(const std::string& value) {
	float	f;
	double	d;

	if (value.length() == 1 && std::isdigit(value[0]) && std::isprint(value[0])) {
		f = strtof(value.c_str(), NULL);
		d = static_cast<double>(f);
	}
	else {
		if (isFloat(value)) {
			f = strtof(value.c_str(), NULL);
			d = static_cast<double>(f);
		} else {
			d = strtod(value.c_str(), NULL);
			f = static_cast<float>(d);
		}
	}
	int	i = static_cast<int>(f);
	printChar(value, i);
	printFloat(value, f);
};


// double strtod(const char *nptr, char **endptr);
// float strtof(const char *nptr, char **endptr);
