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
