#include "Point.hpp"

Point::Point() : x(Fixed()), y(Fixed()) {};

Point::Point(const float x, const float y) : x(Fixed(x)), y(Fixed(y)) {};

Point::Point(const Point& other) {
	*this = other;
};

Point& Point::operator=(const Point& other) {
	if (this != &other) {
		(Fixed&)this->x = other.getX();
		(Fixed&)this->y = other.getY();
	}
	return (*this);
};

Point::~Point() {};

Fixed Point::getX() const {
	return (this->x);
};

Fixed Point::getY() const {
	return (this->y);
};
