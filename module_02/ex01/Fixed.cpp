#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_num_value = 0;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_num_value = value << this->_num_fract;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_num_value = roundf(value * (1 << this->_num_fract));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed &Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->_num_value = obj.getRawBits();
	}
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_num_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_num_value = raw;
}

int Fixed::toInt(void) const
{
	return (this->_num_value >> this->_num_fract);
}

float Fixed::toFloat(void) const
{
	return ((float)this->_num_value / (float)(1 << this->_num_fract));
}

std::ostream& operator<<(std::ostream& stream, const Fixed& num)
{
	stream << num.toFloat();
	return (stream);
}
