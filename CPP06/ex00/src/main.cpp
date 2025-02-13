#include "ScalarConverter.hpp"
#include "Colors.hpp"

int	main(int argc, char** argv) {
	if (argc != 2) {
		std::cout << BOLD << RED << "USAGE: ./Scalar <string>" << RESET << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}

/*
int main() {
	std::cout << std::endl;
	std::cout << YELLOW << ("Testing char: 'A'") << RESET << std::endl;
	ScalarConverter::convert("A");

	std::cout << std::endl;
	std::cout << YELLOW << ("Testing char: '0'") << RESET << std::endl;
	ScalarConverter::convert("0");

	std::cout << std::endl;
	std::cout << YELLOW << ("Testing char: '?'") << RESET << std::endl;
	ScalarConverter::convert("?");

	std::cout << std::endl;
	std::cout << YELLOW << ("Testing char: ' '") << RESET << std::endl;
	ScalarConverter::convert(" ");

	std::cout << std::endl;
	std::cout << YELLOW << ("Testing char: '\\n'") << RESET << std::endl;
	ScalarConverter::convert("\n");

	std::cout << std::endl;
	std::cout << YELLOW << ("Testing char: '.'") << RESET << std::endl;
	ScalarConverter::convert(".");

	std::cout << std::endl;
	std::cout << YELLOW << ("Testing int: '42'") << RESET << std::endl;
	ScalarConverter::convert("42");

	std::cout << std::endl;
	std::cout << YELLOW << ("Testing int: '-1234'") << RESET << std::endl;
	ScalarConverter::convert("-1234");

	std::cout << std::endl;
	std::cout << YELLOW << ("Testing int: '2147483647'") << RESET << std::endl;
	ScalarConverter::convert("2147483647");

	std::cout << std::endl;
	std::cout << YELLOW << ("Testing int: '-2147483648'") << RESET << std::endl;
	ScalarConverter::convert("-2147483648");

	std::cout << std::endl;
	std::cout << YELLOW << ("Testing float: '-1234.5678f'") << RESET << std::endl;
	ScalarConverter::convert("-1234.5678f");

	std::cout << std::endl;
	std::cout << YELLOW << ("Testing float: '3.14159f'") << RESET << std::endl;
	ScalarConverter::convert("3.14159f");

	std::cout << std::endl;
	std::cout << YELLOW << ("Testing float: '-1.2345678e5f'") << RESET << std::endl;
	ScalarConverter::convert("-1.2345678e5f");

	std::cout << std::endl;
	std::cout << YELLOW << ("Testing float: 'inf'") << RESET << std::endl;
	ScalarConverter::convert("inf");

	std::cout << std::endl;
	std::cout << YELLOW << ("Testing float: '-inf'") << RESET << std::endl;
	ScalarConverter::convert("-inf");

	std::cout << std::endl;
	std::cout << YELLOW << ("Testing double: '-1234.5678'") << RESET << std::endl;
	ScalarConverter::convert("-1234.5678");

	std::cout << std::endl;
	std::cout << YELLOW << ("Testing double: '3.14159'") << RESET << std::endl;
	ScalarConverter::convert("3.14159");

	std::cout << std::endl;
	std::cout << YELLOW << ("Testing double: '-1.2345678e5'") << RESET << std::endl;
	ScalarConverter::convert("-1.2345678e5");

	std::cout << std::endl;
	std::cout << YELLOW << ("Testing double: 'inf'") << RESET << std::endl;
	ScalarConverter::convert("inf");

	std::cout << std::endl;
	std::cout << YELLOW << ("Testing double: '-inf'") << RESET << std::endl;
	ScalarConverter::convert("-inf");

}
*/
