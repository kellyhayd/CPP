#include "Span.hpp"
#include "colors.hpp"
#include <cstdlib>

std::vector<int>	createRange(int N) {
	std::vector<int>	range;
	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		range.push_back(rand() % N);
	}
	return (range);
}

int	main() {
	// filling the class container
	Span	span1(5);
	int	values[] = {6, 3, 17, 9, 11};
	for (int i = 0; i < 5; i++) {
		span1.addNumber(values[i]);
	}
	std::vector<int>	content = span1.getContent();
	std::cout << BOLD << "span1 =";
	for (std::vector<int>::iterator it = content.begin(); it != content.end(); it++) {
		std::cout << " " << YELLOW << *it;
	}
	std::cout << RESET << std::endl;

	// trying to insert number without space
	int	newValue = 15;
	try {
		span1.addNumber(newValue);
	} catch(std::exception& e) {
		std::cout << BOLD << RED << e.what() << RESET << std::endl;
	}
	std::cout << RESET << std::endl;

	// finding the shortest and longest span
	std::cout << BOLD << "shortest span: " << YELLOW << span1.shortestSpan() << RESET << std::endl;
	std::cout << BOLD << "longest span: " << YELLOW << span1.longestSpan() << RESET << std::endl;
	std::cout << RESET << std::endl;

	// creating a range of number
	std::vector<int>	range = createRange(15000);
	std::cout << BOLD << "range:" << RESET;
	for (std::vector<int>::iterator it = range.begin(); it != (range.begin() + 5); it++) {
		std::cout << " " << YELLOW << *it;
	}
	std::cout << RESET << std::endl;

	// adding the range of number to the container
	Span	span2(15000);
	span2.addRange(range.begin(), range.end());
	std::vector<int> span2Content = span2.getContent();
	std::cout << BOLD << "span2:" << RESET;
	for (std::vector<int>::iterator it = span2Content.begin(); it != (span2Content.begin() + 5); it++) {
		std::cout << " " << YELLOW << *it;
	}
	std::cout << RESET << std::endl;

	// finding the shortest and longest span
	std::cout << BOLD << "shortest span: " << YELLOW << span2.shortestSpan() << RESET << std::endl;
	std::cout << BOLD << "longest span: " << YELLOW << span2.longestSpan() << RESET << std::endl;
	std::cout << RESET << std::endl;

	return (0);
}
