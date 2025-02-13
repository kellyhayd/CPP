#ifndef ARRAY_HPP
#define ARRAY_HPP


#include <iostream>

template <typename T>
class Array {
private:
	T*	_data;
	unsigned int	_size;

public:
	Array();
	Array(unsigned int n);
	Array(const Array& other);
	Array& operator=(const Array& other);
	~Array();

	unsigned int	size() const;

	T& operator[](unsigned int index);
	const T& operator[](unsigned int index) const;

};

#include "../src/Array.tpp"

#endif
