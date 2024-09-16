
#include <iostream>
#include <string>

int main(int argc, char **argv) {
	std::string	result;

	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << '\n';
		return (0);
	}
	for (int i = 1; i < argc; i++) {
		std::string str(argv[i]);
		for (int j = 0; j < str.size(); j++) {
			str[j] = toupper(str[j]);
		}
		result += str;
	}
	std::cout << result << '\n';
	return (0);
}
