#include "Span.hpp"
#include "colors.hpp"

int	main() {
	int	N = 7;
	Span	span(N);
	int	values[] = {1, 2, 3, 5, 7, 11, 13};
	for (int i = 0; i < N; i++) {
		span.addNumber(values[i]);
	}

	std::vector<int>	content = span.getContent();
	std::cout << BOLD << "span =";
	for (std::vector<int>::iterator it = content.begin(); it != content.end(); it++) {
		std::cout << " " << YELLOW << *it;
	}
	std::cout << RESET << std::endl;

	int	newValue = 15;
	try {
		span.addNumber(newValue);
	} catch(std::exception& e) {
		std::cout << BOLD << RED << e.what() << RESET << std::endl;
	}
	std::cout << RESET << std::endl;

	std::cout << BOLD << "min value: " << YELLOW << span.shortestSpan() << RESET << std::endl;
	std::cout << BOLD << "max value: " << YELLOW << span.longestSpan() << RESET << std::endl;
	std::cout << RESET << std::endl;

	return (0);
}
