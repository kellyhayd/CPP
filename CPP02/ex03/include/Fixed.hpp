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

	bool	operator>(const Fixed &raw) const;
	bool	operator<(const Fixed &raw) const;
	bool	operator>=(const Fixed &raw) const;
	bool	operator<=(const Fixed &raw) const;
	bool	operator==(const Fixed &raw) const;
	bool	operator!=(const Fixed &raw) const;

	Fixed	operator+(const Fixed &raw) const;
	Fixed	operator-(const Fixed &raw) const;
	Fixed	operator*(const Fixed &raw) const;
	Fixed	operator/(const Fixed &raw) const;

	Fixed&	operator++(void);
	Fixed	operator++(int);
	Fixed&	operator--(void);
	Fixed	operator--(int);

	static Fixed&		min(Fixed& raw1, Fixed& raw2);
	static const Fixed&	min(const Fixed& raw1, const Fixed& raw2);
	static Fixed&		max(Fixed& raw1, Fixed& raw2);
	static const Fixed&	max(const Fixed& raw1, const Fixed& raw2);
};

std::ostream& operator<<(std::ostream& out, Fixed const &value);

#endif
