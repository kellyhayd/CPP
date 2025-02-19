
#include "easyfind.hpp"
#include "colors.hpp"
#include <vector>
#include <list>
#include <deque>

int	main() {
	// values to search for
	int	toFind[] = {7, 10};
	std::cout << CYAN << INVERSE << "\n Value to be found = " << toFind[0] \
		<< " " << RESET << std::endl;
	std::cout << RED << INVERSE << " Value to not be found = " << toFind[1] \
		<< " " << RESET << std::endl;

	// intengers for the containers
	int	values[] = {1, 2, 3, 7, 11, 13};

	// vector container
	std::cout << INVERSE << "\n   Vector of int   " << RESET << std::endl;
	std::vector<int>	vector(values, values + sizeof(values)/sizeof(int));
	std::cout << BOLD << "vector =";
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++) {
		std::cout << " " << YELLOW << *it;
	}
	std::cout << RESET << std::endl;

	// list container
	std::cout << INVERSE << "\n   List of int   " << RESET << std::endl;
	std::list<int>	list(values, values + sizeof(values)/sizeof(int));
	std::cout << BOLD << "list =";
	for (std::list<int>::iterator it = list.begin(); it != list.end(); it++) {
		std::cout << " " << YELLOW << *it;
	}
	std::cout << RESET << std::endl;

	// deque container
	std::cout << INVERSE << "\n   Deque of int   " << RESET << std::endl;
	std::deque<int>	deque(values, values + sizeof(values)/sizeof(int));
	std::cout << BOLD << "deque =";
	for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); it++) {
		std::cout << " " << YELLOW << *it;
	}
	std::cout << RESET << std::endl;

	// searching for the value that exists in the containers
	std::cout << BOLD << MAGENTA << "Searching for the value 7" << RESET << std::endl;
	try {
		std::cout << BOLD << "vector = " << YELLOW << *easyfind(vector, toFind[0]) << RESET << std::endl;
		std::cout << BOLD << "list = " << YELLOW << *easyfind(list, toFind[0]) << RESET << std::endl;
		std::cout << BOLD << "deque = " << YELLOW << *easyfind(deque, toFind[0]) << RESET << std::endl;
	} catch (std::exception& e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	std::cout << RESET << std::endl;

	// searching for the value that doesn't exist in the containers
	std::cout << BOLD << MAGENTA << "Searching for the value 10" << RESET << std::endl;
	try {
		std::cout << BOLD << "vector = " << RED << *easyfind(vector, toFind[1]) << RESET << std::endl;
	} catch (std::exception& e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try {
		std::cout << BOLD << "list = " << RED << *easyfind(list, toFind[1]) << RESET << std::endl;
	} catch (std::exception& e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try {
		std::cout << BOLD << "deque = " << RED << *easyfind(deque, toFind[1]) << RESET << std::endl;
	} catch (std::exception& e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	std::cout << RESET << std::endl;

	return (0);
}
