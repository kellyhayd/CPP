#include "PmergeMe.hpp"

#include <stdlib.h>
#include <cerrno>

void	startSorting(int argc, char** argv) {
	PmergeMe	pmerge;

	for(int i = 1; i < argc; i++) {
		char* end;
		errno = 0;
		long num = std::strtol(argv[i], &end, 10);
		if (end == argv[i] || *end != '\0' || errno == ERANGE || num < 0) {
			std::cerr << "Error" << std::endl;
			throw std::invalid_argument("Invalid input.");
		}
		pmerge.addNumber(num);
	}
	pmerge.printResults();
}

int	main(int argc, char** argv) {
	if (argc < 3) {
		std::cerr << "Usage: " << argv[0] << " <number1> <number2> ..." << std::endl;
		return (1);
	}
	startSorting(argc, argv);
	return (0);
}