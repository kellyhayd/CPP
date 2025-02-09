#include "Base.hpp"
#include "Colors.hpp"

int	main() {
	std::cout << INVERSE << "   Generating random base   " << RESET << std::endl;
	Base*	base = generate();

	std::cout << INVERSE << "   Identify by pointer   " << RESET << std::endl;
	identify(base);

	std::cout << INVERSE << "   Identify by reference   " << RESET << std::endl;
	identify(*base);

	delete base;
	return (0);
}
