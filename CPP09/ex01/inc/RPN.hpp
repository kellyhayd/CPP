#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

enum OPERATOR {
	ADD,
	DIV,
	MUL,
	SUB
};

class RPN {
private:
	std::stack<int>	_stack;

public:
	RPN();
	RPN(const RPN& other);
	RPN&	operator=(const RPN& other);
	~RPN();

	void	polishExpression(std::string expression);
	void	calculate(char op);
};


#endif