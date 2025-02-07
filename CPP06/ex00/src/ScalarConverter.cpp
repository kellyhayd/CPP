#include "ScalarConverter.hpp"
#include "Colors.hpp"
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <climits>

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
	std::cout << BOLD << "double: " << CYAN << d;

	for (std::string::iterator it = value.begin(); it < value.end(); it++) {
		if ((*it == '.' || std::isnan(d) || std::isinf(d)) && *value.rbegin() != '0' ) {
			std::cout << RESET << std::endl;
			return;
		}
	}
	std::cout << ".0" << RESET << std::endl;
}

static void	printFloat(std::string value, float f) {
	std::cout << BOLD << "float: " << CYAN << f;

	for (std::string::iterator it = value.begin(); it < value.end(); it++) {
		if ((*it == '.' || std::isnan(f) || std::isinf(f)) && *value.rbegin() != '0') {
			std::cout << "f" << RESET << std::endl;
			return;
		}
	}
	std::cout << ".0f" << RESET << std::endl;
}

static void	printInt(double d, int i) {
	if (std::isnan(d) || d < INT_MIN || d > INT_MAX) {
		std::cout << BOLD << "int: " << RED << "impossible" << RESET << std::endl;
		return;
	}
	std::cout << BOLD << "int: " << CYAN << i << RESET << std::endl;
}

static void	printChar(int i) {
	if (i < -128 || i > 127) {
		std::cout << BOLD << "char: " << RED << "impossible" << RESET << std::endl;
	}
	else if (!std::isprint(i)) {
		std::cout << BOLD << "char: " << RED << "Non displayable" << RESET << std::endl;
	}
	else {
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
				if (value[0] == '-' || value[0] == '+') {
					it++;
				}
				if (*it == '.') {
					dot++;
					if (dot > 1) {
						return (false);
					}
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

	printChar(i);
	printInt(d, i);
	printFloat(value, f);
	printDouble(value, d);
};

/*
	validar:
		* só um caractere == char ou int;
		* mais de um caracter:
			- UM ponto antes do final == double;
				. f no final == float;
			- MAIS de UM ponto == FALSE;
			- Ñ DÍGITO no meio == FALSE;
			- > ou < que LIMITS == FALSE;
			- -inff, +inff, -inf, +inf and nan

*/

// static void	printDouble(std::string value, double d) {
// 	std::cout << BOLD << "double: " << CYAN << d;

// 	bool	hasDot = false;
// 	for (size_t i = 0 ; i < value.length(); i++) {
// 		if (value[i] == '.') {
// 			hasDot = true;
// 			std::cout << RESET << std::endl;
// 			return;
// 		}
// 	}
// 	if (hasDot == false && !std::isnan(d)) {
// 		std::cout << ".0";
// 	}
// 	std::cout << RESET << std::endl;
// }

// static void	printFloat(std::string value, float f) {
// 	std::cout << BOLD << "float: " << CYAN << f;

// 	bool	hasDot = false;
// 	for (size_t i = 0 ; i < value.length(); i++) {
// 		if (value[i] == '.') {
// 			hasDot = true;
// 		}
// 	}
// 	if (hasDot == true || std::isnan(f)) {
// 		std::cout << "f" << RESET << std::endl;
// 	} else {
// 		std::cout << ".0f" << RESET << std::endl;
// 	}
// }

// static void	printInt(double d, int i) {
// 	if (std::isnan(d) || d < INT_MIN || d > INT_MAX) {
// 		std::cout << BOLD << "int: " << RED << "impossible" << RESET << std::endl;
// 		return;
// 	}
// 	std::cout << BOLD << "int: " << CYAN << i << RESET << std::endl;
// }

// static void	printChar(int i) {
// 	if (i < -128 || i > 127) {
// 		std::cout << BOLD << "char: " << RED << "impossible" << RESET << std::endl;
// 	}
// 	else if (!std::isprint(i)) {
// 		std::cout << BOLD << "char: " << RED << "Non displayable" << RESET << std::endl;
// 	}
// 	else {
// 		char	c = static_cast<char>(i);
// 		std::cout << BOLD << "char: " << CYAN << c << RESET << std::endl;
// 	}
// };

// static bool	isFloat(std::string value) {
// 	return (value[value.length() - 1] =='f' ? true : false);
// };




// // double strtod(const char *nptr, char **endptr);
// // float strtof(const char *nptr, char **endptr);
