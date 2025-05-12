#include "MutantStack.hpp"
#include "colors.hpp"
#include <list>
#include <typeinfo>


template<typename T>void	printStack(MutantStack<T> stack, std::string type) {
	MutantStack<int>::iterator it = stack.begin();
	MutantStack<int>::iterator ite = stack.end();
	std::cout << BOLD << "stack [" << MAGENTA << type << RESET << BOLD << "] = { ";
	while (it != ite) {
		std::cout << YELLOW << *it << " " << RESET;
		++it;
	}
	std::cout << BOLD <<  "}" << RESET << std::endl;
}

int main() {
	std::cout << INVERSE << "   SUBJECT TEST   " << RESET << std::endl;
	MutantStack<int>	mstack;
	mstack.push(5);
	mstack.push(17); // {5, 17}
	std::cout << BOLD << "top: " << YELLOW << mstack.top() << RESET << std::endl; // 17

	mstack.pop(); // {5}
	std::cout << BOLD << "size: " << YELLOW << mstack.size() << RESET << std::endl; // == 1

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0); // {5, 3, 5, 737, 0}

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << BOLD << "stack: { ";
	while (it != ite) {
		std::cout << YELLOW << *it << " " << RESET;
		++it;
	}
	std::cout << BOLD <<  "}" << RESET << std::endl;
	std::stack<int> s(mstack);
	std::cout << std::endl;

	std::cout << INVERSE << "   LIST TEST   " << RESET << std::endl;
	std::list<int> 	list;
	list.push_back(5);
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);

	std::cout << BOLD << "list: { ";
	for (std::list<int>::iterator it = list.begin(); it != list.end(); it++) {
		std::cout << YELLOW << *it << " " << RESET;
	}
	std::cout << "}" << RESET << std::endl;
	std::cout << std::endl;


	std::cout << INVERSE << "   COPY CONSTRUCTOR && ASSIGNMENT OPERATOR   " << RESET << std::endl;
	MutantStack<int>	stackCopy(mstack);
	MutantStack<int>	stackOperator = stackCopy;
	printStack(mstack, "original");
	printStack(stackCopy, "copy");
	printStack(stackOperator, "assignment operator");
	std::cout << std::endl;

	return (0);
}

