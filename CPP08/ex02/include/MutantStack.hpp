#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template<typename T> class MutantStack : public std::stack<T> {
public:
	MutantStack();
	MutantStack(T value);
	MutantStack(const MutantStack& other);
	MutantStack& operator=(const MutantStack& other);
	~MutantStack();

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin();
	iterator end();

	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	const_iterator begin() const;
	const_iterator end() const;
};

#include "../src/MutantStack.tpp"

#endif
