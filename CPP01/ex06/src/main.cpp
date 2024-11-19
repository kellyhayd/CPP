#include <iostream>
#include "Harl.hpp"

int	main(int argc, char **argv){
	if (argc != 2)
		return (std::cout << "USAGE: [level]" << std::endl, 1);

	Harl harl;

	harl.complain(argv[1]);

	return (0);
}
