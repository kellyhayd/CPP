#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

const std::string RED = "\033[1;31m";
const std::string GREEN = "\033[1;32m";
const std::string CYAN = "\033[1;36m";
const std::string YELLOW = "\033[1;33m";
const std::string MAGENTA = "\033[1;95m";
const std::string BLUE = "\033[1;34m";
const std::string LIGHTGRAY = "\033[0;37m";
const std::string BOLD = "\033[1m";
const std::string INVERSE = "\033[7m";
const std::string RESET = "\033[0m";

template <typename T>
void	swap(T &x, T &y) {
	T tmp = x;
	x = y;
	y = tmp;
};

template <typename T>
T	min(T x, T y) {
	return (x < y ? x : y);
};

template <typename T>
T	max(T x, T y) {
	return (x > y ? x : y);
};

#endif
