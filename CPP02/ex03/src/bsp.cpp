#include "Fixed.hpp"
#include "Point.hpp"

static Fixed absolute(Fixed n) {
	if (n < 0)
		return (n * -1);
	return (n);
}

static Fixed triagleArea(Point const a, Point const b, Point const c) {
	return (absolute((a.getX() * (b.getY() - c.getY()) \
			+ b.getX() * (c.getY() - a.getY()) \
			+ c.getX() * (a.getY() - b.getY())) / (float)2.0));
};

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	Fixed abc = triagleArea(a, b, c);
	Fixed pbc = triagleArea(point, b, c);
	Fixed apc = triagleArea(a, point, c);
	Fixed abp = triagleArea(a, b, point);

	if (pbc == 0 || apc == 0 || abp == 0)
		return (false);
	return (abc == (pbc + apc + abp));
};
