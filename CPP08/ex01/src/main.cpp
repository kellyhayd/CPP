#include "Span.hpp"
#include "colors.hpp"

int	main() {
	Span	span(5);
	int	values[] = {6, 3, 17, 9, 11};
	for (int i = 0; i < 5; i++) {
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

	std::cout << BOLD << "shortest span: " << YELLOW << span.shortestSpan() << RESET << std::endl;
	std::cout << BOLD << "longest span: " << YELLOW << span.longestSpan() << RESET << std::endl;
	std::cout << RESET << std::endl;

	return (0);
}
