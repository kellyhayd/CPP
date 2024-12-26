#include "Fixed.hpp"

Fixed::Fixed() : fixedValue(0) {
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const int fixedValue) {
	std::cout << "Int constructor called" << std::endl;
	this->fixedValue = fixedValue << this->rawBits;
};

Fixed::Fixed(const float fixedValue) {
	std::cout << "Float constructor called" << std::endl;
	this->fixedValue = roundf(fixedValue * (1 << this->rawBits));
};

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
};

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->fixedValue = other.fixedValue;
	}
	return (*this);
};

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
};

int	Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedValue);
};

void	Fixed::setRawBits(int const newValue) {
	std::cout << "setRawBits member function called" << std::endl;
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
