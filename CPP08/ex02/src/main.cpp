#include "MutantStack.hpp"
#include <list>

int main() {
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	// {17, 5}
	std::cout << mstack.top() << std::endl; // 17

	mstack.pop();
	// {5}
	std::cout << mstack.size() << std::endl; // == 1

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	// {5, 3, 5, 737, 0}
	MutantStack<int>::iterator it = mstack.begin();
	std::cout << *it << std::endl; // test
	MutantStack<int>::iterator ite = mstack.end();
	std::cout << *ite << std::endl; // test

	++it;
	--it;

	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::list<int> list;
	
	return (0);
}

