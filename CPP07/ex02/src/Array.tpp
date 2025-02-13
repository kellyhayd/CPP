#include "../include/Array.hpp"
#include "colors.hpp"

template <typename T>
Array<T>::Array() : _data(NULL), _size(0) {};

template <typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]), _size(n) {};

template <typename T>
Array<T>::Array(const Array& other) {
	_data = new T[other._size];
	_size = other._size;
	for (unsigned int i = 0; i < other._size; i++) {
		_data[i] = other._data[i];
	}
};

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
	if (this != &other) {
		delete[] _data;
		_data = new T(other._size);
		_size = other._size;
		for (int i = 0; i < other._size; i++) {
			_data[i] = other._data[i];
		}
	}
	return *this;
};

template <typename T>
Array<T>::~Array() {
	delete[] _data;
};

template <typename T>
unsigned int	Array<T>::size() const { return (this->_size); };

template <typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= this->_size) {
		throw std::out_of_range("Index is out of bounds");
	}
	return (this->_data[index]);
};

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
	if (index >= this->_size) {
		throw std::out_of_range("Index is out of bounds");
	}
	return (this->_data[index]);
};
