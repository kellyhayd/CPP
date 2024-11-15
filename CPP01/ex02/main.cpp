#include <iostream>
#include <string>

int	main(){
	std::string		str = "HI THIS IS BRAIN";
	std::string*	ptr = &str;

	std::cout << str << std::endl;
	std::cout << &str << std::endl;
	std::cout << ptr << std::endl;
	
	return (0);
}
