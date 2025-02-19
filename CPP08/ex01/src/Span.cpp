#include "Span.hpp"
#include <algorithm>
#include <limits>

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
	if (_content.size() < 2)
		throw std::logic_error("There is no numbers enough to have a span");
	int minSpan = std::numeric_limits<int>::max();
	for (size_t i = 1; i < _content.size(); i++) {
		int	span = _content[i] - _content[i - 1];
		if (abs(span) < minSpan) {
			minSpan = abs(span);
		}
	}
	return (minSpan);
};

int	Span::longestSpan() {
		if (_content.size() < 2)
		throw std::logic_error("There is no numbers enough to have a span");
	int maxSpan = std::numeric_limits<int>::min();
	for (size_t i = 1; i < _content.size(); i++) {
		int	span = _content[i] - _content[i - 1];
		if (abs(span) > maxSpan) {
			maxSpan = abs(span);
		}
	}
	return (maxSpan);
};

std::vector<int>	Span::getContent() { return (this->_content); }
