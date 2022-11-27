#include "Fixed.hpp"

Fixed::Fixed(void)
{
	// std::cout << "Default constructor called" << std::endl;
	this->_num_value = 0;
}

Fixed::Fixed(const int value)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_num_value = value << this->_fract_bits;
}

Fixed::Fixed(const float value)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_num_value = roundf(value * (1 << this->_fract_bits));
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed &Fixed::operator=(const Fixed &obj)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	Fixed::_num_value = obj.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (Fixed::_num_value);
}

void Fixed::setRawBits(int const raw)
{
	Fixed::_num_value = raw;
}

int Fixed::toInt(void) const
{
	return (this->_num_value >> this->_fract_bits);
}

float Fixed::toFloat(void) const
{
	return ((float)this->_num_value / (float)(1 << this->_fract_bits));
}

bool Fixed::operator<(const Fixed &obj)
{
	return (this->getRawBits() < obj.getRawBits());
}

bool Fixed::operator>(const Fixed &obj)
{
	return (this->getRawBits() > obj.getRawBits());
}

bool Fixed::operator<=(const Fixed &obj)
{
	return (this->getRawBits() <= obj.getRawBits());
}

bool Fixed::operator>=(const Fixed &obj)
{
	return (this->getRawBits() >= obj.getRawBits());
}

bool Fixed::operator==(const Fixed &obj)
{
	return (this->getRawBits() == obj.getRawBits());
}

bool Fixed::operator!=(const Fixed &obj)
{
	return (this->getRawBits() != obj.getRawBits());
}

Fixed Fixed::operator+(const Fixed &obj)
{
	Fixed result;

	result.setRawBits(this->getRawBits() + obj.getRawBits());
	return (result);
}

Fixed Fixed::operator-(const Fixed &obj)
{
	Fixed result;

	result.setRawBits(this->getRawBits() - obj.getRawBits());
	return (result);
}

Fixed Fixed::operator*(const Fixed &obj)
{
	Fixed result;

	result.setRawBits(this->getRawBits() * obj.getRawBits());
	return (result);
}

Fixed Fixed::operator/(const Fixed &obj)
{
	Fixed result;

	result.setRawBits(this->getRawBits() / obj.getRawBits());
	return (result);
}

Fixed &Fixed::operator++()
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);

	++(*this);
	return (temp);
}

Fixed &Fixed::operator--()
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);

	++(*this);
	return (temp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a.getRawBits() < b.getRawBits() ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a.getRawBits() > b.getRawBits() ? a : b);
}

std::ostream &operator<<(std::ostream &stream, const Fixed &num)
{
	stream << num.toFloat();
	return (stream);
}
