#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span {
private:
	std::vector<int>	_content;
	size_t	_maxSize;

public:
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void	addNumber(int value);
	int	shortestSpan();
	int	longestSpan();

	std::vector<int>	getContent();
};

#endif
