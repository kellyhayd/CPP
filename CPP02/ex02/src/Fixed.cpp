#include "Fixed.hpp"

Fixed::Fixed() : fixedValue(0) {
	// std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const int fixedValue) {
	// std::cout << "Int constructor called" << std::endl;
	this->fixedValue = fixedValue << this->rawBits;
};

Fixed::Fixed(const float fixedValue) {
	// std::cout << "Float constructor called" << std::endl;
	this->fixedValue = roundf(fixedValue * (1 << this->rawBits));
};

Fixed::Fixed(const Fixed& other) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
};

Fixed& Fixed::operator=(const Fixed& other) {
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->fixedValue = other.fixedValue;
	}
	return (*this);
};

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
};

int	Fixed::getRawBits() const {
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedValue);
};

void	Fixed::setRawBits(int const newValue) {
	// std::cout << "setRawBits member function called" << std::endl;
	this->fixedValue = newValue;
}

float	Fixed::toFloat(void) const {
	return ((float)this->fixedValue / (1 << this->rawBits));
};

int		Fixed::toInt(void) const {
	return (this->fixedValue >> this->rawBits);
};

std::ostream& operator<<(std::ostream& out, Fixed const &value) {
	out << value.toFloat();
	return (out);
};

bool	Fixed::operator>(const Fixed &raw) const {
	return (this->fixedValue > raw.getRawBits());
};

bool	Fixed::operator<(const Fixed &raw) const {
		return (this->fixedValue < raw.getRawBits());
};

bool	Fixed::operator>=(const Fixed &raw) const {
		return (this->fixedValue >= raw.getRawBits());
};

bool	Fixed::operator<=(const Fixed &raw) const {
		return (this->fixedValue <= raw.getRawBits());
};

bool	Fixed::operator==(const Fixed &raw) const {
		return (this->fixedValue == raw.getRawBits());
};

bool	Fixed::operator!=(const Fixed &raw) const {
		return (this->fixedValue != raw.getRawBits());
};

Fixed	Fixed::operator+(const Fixed &raw) const {
		return (Fixed(this->toFloat() + raw.toFloat()));
};

Fixed	Fixed::operator-(const Fixed &raw) const {
		return (Fixed(this->toFloat() - raw.toFloat()));
};

Fixed	Fixed::operator*(const Fixed &raw) const {
		return (Fixed(this->toFloat() * raw.toFloat()));
};

Fixed	Fixed::operator/(const Fixed &raw) const {
		return (Fixed(this->toFloat() / raw.toFloat()));
};

Fixed&	Fixed::operator++(void) {
	this->fixedValue++;
	return (*this);
};

Fixed	Fixed::operator++(int) {
	Fixed tmp(this->fixedValue);
	operator++();
	return (tmp);
};

Fixed&	Fixed::operator--(void) {
	this->fixedValue--;
	return (*this);
};

Fixed	Fixed::operator--(int) {
	Fixed tmp(this->fixedValue);
	operator--();
	return (tmp);
};

Fixed&		Fixed::min(Fixed& raw1, Fixed& raw2) {
	return (raw1 < raw2 ? raw1 : raw2);
};

const Fixed&	Fixed::min(const Fixed& raw1, const Fixed& raw2) {
	return (raw1 < raw2 ? raw1 : raw2);
};

Fixed&		Fixed::max(Fixed& raw1, Fixed& raw2) {
	return (raw1 > raw2 ? raw1 : raw2);
};

const Fixed&	Fixed::max(const Fixed& raw1, const Fixed& raw2) {
	return (raw1 > raw2 ? raw1 : raw2);
};
