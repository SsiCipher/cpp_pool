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
	(void)obj;
	std::cout << "[Point] Copy assignment operator has been called!" << std::endl;
	return (*this);
}

Fixed Point::getX(void) const
{
	return (this->_x);
}

Fixed Point::getY(void) const
{
	return (this->_y);
}
