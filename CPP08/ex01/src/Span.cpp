#include "Span.hpp"
#include <algorithm>

Span::Span(unsigned int N) : _maxSize(N) {};

Span::Span(const Span& other) {
	*this = other;
};

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		this->_content = other._content;
	}
	return *this;
};

Span::~Span() {};

void	Span::addNumber(int value) {
	if (_content.size() >= _maxSize)
		throw std::overflow_error("There is no empty space anymore");
	_content.push_back(value);
};

int	Span::shortestSpan() {
	return (*std::min_element(_content.begin(), _content.end()));
};

int	Span::longestSpan() {
	return (*std::max_element(_content.begin(), _content.end()));
};

std::vector<int>	Span::getContent() { return (this->_content); }
