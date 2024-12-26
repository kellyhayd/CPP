#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed {
private:
	int	fixedValue;
	static const int	rawBits = 8;

public:
	Fixed();
	Fixed(int const fixedValue);
	Fixed(float const fixedValue);
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, Fixed const &value);

#endif


/*

And add the following function to the Fixed class files:
	• An overload of the insertion («) operator that inserts a floating-point representation
	of the fixed-point number into the output stream object passed as parameter.
*/