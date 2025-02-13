#include "whatever.hpp"
#include "colors.hpp"

int	main() {
	std::cout << INVERSE << "   Testing with an int   \n" << RESET << std::endl;
	int	num1 = 42;
	int	num2 = 84;
	std::cout << BOLD << "num1 = " << YELLOW << num1 << RESET \
			<< BOLD << "\nnum2 = " << YELLOW << num2 << RESET << std::endl;

	std::cout << BOLD << CYAN << "Swaping values" << RESET << std::endl;
	::swap(num1, num2);
	std::cout << BOLD << "num1 = " << YELLOW << num1 << RESET \
			<< BOLD << "\nnum2 = " << YELLOW << num2 << RESET << std::endl;

	int	numMin = min(num1, num2);
	std::cout << BOLD << "Smalest value = " << YELLOW << numMin << RESET << std::endl;
	int	numMax = max(num1, num2);
	std::cout << BOLD << "Greatest value = " << YELLOW << numMax << RESET << std::endl;

	std::cout << std::endl;
	std::cout << INVERSE << "   Testing with a char   \n" << RESET << std::endl;
	char	char1 = 'a';
	char	char2 = 'A';
	std::cout << BOLD << "char1 = " << YELLOW << char1 << RESET \
			<< BOLD << "\nchar2 = " << YELLOW << char2 << RESET << std::endl;

	std::cout << BOLD << CYAN << "Swaping values" << RESET << std::endl;
	::swap(char1, char2);
	std::cout << BOLD << "char1 = " << YELLOW << char1 << RESET \
			<< BOLD << "\nchar2 = " << YELLOW << char2 << RESET << std::endl;

	char	charMin = min(char1, char2);
	std::cout << BOLD << "Smalest value = " << YELLOW << charMin << RESET << std::endl;
	char	charMax = max(char1, char2);
	std::cout << BOLD << "Greatest value = " << YELLOW << charMax << RESET << std::endl;

	std::cout << std::endl;
	std::cout << INVERSE << "   Subject test   \n" << RESET << std::endl;
	const int a = 2;
	const int b = 3;
	::swap(a, b);
	std::cout << BOLD << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << RESET << std::endl;
	return (0);

}
