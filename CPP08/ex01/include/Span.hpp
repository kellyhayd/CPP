#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span {
private:
	std::vector<int>	_content;
	unsigned int	_maxSize;

public:
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void	addNumber(int value);
	int	shortestSpan();
	int	longestSpan();

	template <typename T>
	void addRange(T begin, T end) {
		if (std::distance(begin, end) > _maxSize \
			|| std::distance(begin, end) > (_maxSize - static_cast<unsigned int>(_content.size()))) {
			throw std::overflow_error("There is not enough space for this range");
		}
		_content.insert(_content.end(), begin, end);
	};

	std::vector<int>	getContent();
};

#endif
