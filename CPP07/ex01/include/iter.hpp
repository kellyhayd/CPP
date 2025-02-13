#ifndef ITER_HPP
#define ITER_HPP

#include "colors.hpp"

#include <iostream>

template <typename T>
void	iter(T* array, size_t lengh, void (*func)(T&)) {
	for (size_t i = 0; i < lengh; i++) {
		func(array[i]);
	}
}

template <typename T>
void	iter(T* array, size_t lengh, void (*func)(const T&)) {
	for (size_t i = 0; i < lengh; i++) {
		func(array[i]);
	}
}

template <typename T>
void	print(const T& value) {
	std::cout << CYAN << value << " " << RESET;
}

template <typename T>
void	increment(T& value) {
	value += 1;
	std::cout << MAGENTA << value << " " << RESET;
}

#endif
