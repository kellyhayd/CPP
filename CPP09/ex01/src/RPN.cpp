#include "RPN.hpp"
#include <sstream>

RPN::RPN() {}
RPN::RPN(const RPN& other) : _stack(other._stack) {}
RPN& RPN::operator=(const RPN& other) {
	if (this != &other) {
		_stack = other._stack;
	}
	return *this;
}
RPN::~RPN() {}

static int	defineOperator(char op) {
	int opCode = -1;

	if (op == '+') {
		opCode = ADD;
	} else if (op == '-') {
		opCode = SUB;
	} else if (op == '*') {
		opCode = MUL;
	} else if (op == '/') {
		opCode = DIV;
	} else {
		throw std::invalid_argument("Invalid operator");
	}
	return (opCode);
}

void	RPN::calculate(char op) {
	int b = _stack.top();
	_stack.pop();
	int	a = _stack.top();
	_stack.pop();

	int  opCode = defineOperator(op); 
	switch (opCode) {
		case ADD:
			_stack.push(a + b);
			break;
		case SUB:
			_stack.push(a - b);
			break;
		case MUL:
			_stack.push(a * b);
			break;
		case DIV:
			if (b == 0) {
				std::cerr << "Error: Division by zero." << std::endl;
				return;
			} else {
				_stack.push(a / b);
			}
			break;
		default:
			break;
	}
}

void	RPN::polishExpression(std::string expression) {
	std::istringstream	iss(expression);
	std::string token;

	while (iss >> token) {
		if (token.size() == 1 && isdigit(token[0])) {
			_stack.push(token[0] - '0');
		} else if (token.size() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')) {
			calculate(token[0]);
		} else {
			std::cerr << "Error: Invalid token '" << token << "' in expression." << std::endl;
			return;
		}
	}
	if (!_stack.empty()) {
		std::cout << "Result: " << _stack.top() << std::endl;
		_stack.pop();
	} else {
		std::cerr << "Error: No result to display." << std::endl;
	}
}