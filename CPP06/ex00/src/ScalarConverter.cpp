#include "ScalarConverter.hpp"
#include <cctype>
#include <cmath>
#include <cstdlib>

ScalarConverter::~ScalarConverter() {};

void	printChar(char value, bool isChar) {

};

static bool	isFloat(std::string value) {
	return (value[value.length() - 1] =='f' ? true : false);
};

void	ScalarConverter::convert(const std::string& value) {
	float	f;
	double	d;
	bool	isChar = false;

	if (value.length() == 1 && std::isdigit(value[0]) && std::isprint(value[0])) {
		f = strtof(value.c_str(), NULL);
		d = static_cast<double>(f);
	} else {
		if (isFloat(value)) {
			f = strtof(value.c_str(), NULL);
			d = static_cast<double>(f);
		} else {
			d = strtod(value.c_str(), NULL);
			f = static_cast<float>(d);
		}
	}
	int		i = static_cast<int>(f);
	printChar(value[0], isChar);
	// std::cout << "char: " << c << "\nint: " << i << "\nfloat: " << f << "\ndouble: " << d << std::endl;
};


// double strtod(const char *nptr, char **endptr);
// float strtof(const char *nptr, char **endptr);
