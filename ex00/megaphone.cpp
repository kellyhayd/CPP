
#include <iostream>
#include <string>

int main(int argc, char **argv) {
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << '\n';
		return (0);
	}
	int	j = 1;
	while (j < argc) {
		std::string	str = argv[j];
		long unsigned int	i = 0;
		while (i < str.length() && !str.empty()) {
			if (str.at(i) >= 97 && str.at(i) <= 122)
				str.at(i) -= 32;
			i++;
		}
		std::cout << str << ' ';
		str.clear();
		j++;
	}
	std::cout << std::endl;
	return (0);
}
