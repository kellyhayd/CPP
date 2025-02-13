#include "iter.hpp"

int	main() {
	std::cout << INVERSE << "   Testing with intengers   " << RESET << std::endl;

	int		numArray[] = {1, 2, 4, 8, 16, 32, 64};
	iter(numArray, 7, ::print);
	std::cout << std::endl;
	iter(numArray, 7, ::increment<int>);
	std::cout << std::endl;

	std::cout << INVERSE << "\n   Testing with characters   " << RESET << std::endl;
	char	charArray[] = {'F', 'o', 'r', 't', 'y', 'T', 'w', 'o'};
	iter(charArray, 8, ::print);
	std::cout << std::endl;
	iter(charArray, 8, ::increment<char>);
	std::cout << std::endl;

	return (0);
}
