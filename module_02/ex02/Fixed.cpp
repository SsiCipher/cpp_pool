#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	setRawBits(0);
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(value << this->_num_fract);
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	setRawBits(roundf(value * (1 << this->_num_fract)));
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
	Fixed::_num_value = obj.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (Fixed::_num_value);
}

void Fixed::setRawBits(int const raw)
{
	Fixed::_num_value = raw;
}

int Fixed::toInt(void) const
{
	return (this->_num_value >> this->_num_fract);
}

float Fixed::toFloat(void) const
{
	return ((float)this->_num_value / (float)(1 << this->_num_fract));
}

bool	Fixed::operator <(const Fixed &obj)
{
	return (this->toFloat() < obj.toFloat());
}

bool	Fixed::operator >(const Fixed &obj)
{
	return (this->toFloat() > obj.toFloat());
}

bool	Fixed::operator <=(const Fixed &obj)
{
	return (this->toFloat() <= obj.toFloat());
}

bool	Fixed::operator >=(const Fixed &obj)
{
	return (this->toFloat() >= obj.toFloat());
}

bool	Fixed::operator ==(const Fixed &obj)
{
	return (this->toFloat() == obj.toFloat());
}

bool	Fixed::operator !=(const Fixed &obj)
{
	return (this->toFloat() != obj.toFloat());
}

float	Fixed::operator +(const Fixed &obj)
{
	return (this->toFloat() + obj.toFloat());
}

float	Fixed::operator -(const Fixed &obj)
{
	return (this->toFloat() - obj.toFloat());
}

float	Fixed::operator *(const Fixed &obj)
{
	return (this->toFloat() * obj.toFloat());
}

float	Fixed::operator /(const Fixed &obj)
{
	return (this->toFloat() / obj.toFloat());
}

// TODO: finish definition of function
Fixed&	Fixed::operator ++()
{
	return (*this);
}

Fixed	Fixed::operator ++(int)
{
	Fixed temp(*this);
	++(*this);
	return (temp);
}

// TODO: finish definition of function
Fixed&	Fixed::operator --()
{
	return (*this);
}

Fixed	Fixed::operator --(int)
{
	Fixed temp(*this);
	++(*this);
	return (temp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a.toFloat() < b.toFloat() ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a.toFloat() > b.toFloat() ? a : b);
}

std::ostream& operator<<(std::ostream& stream, const Fixed& num)
{
	stream << num.toFloat();
	return (stream);
}
