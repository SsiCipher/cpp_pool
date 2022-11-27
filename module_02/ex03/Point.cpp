#include "Point.hpp"

Point::Point(void): _x(0), _y(0)
{
	std::cout << "[Point] Default constructor has been called!" << std::endl;
}

Point::Point(const float x, const float y): _x(x), _y(y)
{
	std::cout << "[Point] constructor has been called!" << std::endl;
}

Point::~Point()
{
	std::cout << "[Point] Destructor has been called!" << std::endl;
}

Point::Point(const Point &obj): _x(obj._x), _y(obj._y)
{
	*this = obj;
	std::cout << "[Point] Copy constructor has been called!" << std::endl;
}

Point &Point::operator=(const Point &obj)
{
	std::cout << "[Point] Copy assignment operator has been called!" << std::endl;
	if (this != &obj)
	{
	}
	return (*this);
}

float Point::getX(void) const
{
	return (this->_x.toFloat());
}

float Point::getY(void) const
{
	return (this->_y.toFloat());
}
