#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;

	public:
		Point(void);
		Point(const float x, const float y);
		~Point(void);
		Point(const Point &obj);
		Point &operator=(const Point &obj);

		float getX(void) const;
		float getY(void) const;
};

#endif
