/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 04:25:43 by yanab             #+#    #+#             */
/*   Updated: 2022/08/23 05:13:48 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	Fixed::num_value = 0;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	Fixed::num_value = value;
	Fixed::num_fract = 8;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	Fixed::num_value = roundf(value);
	Fixed::num_fract = value % 1;
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
	Fixed::num_value = obj.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (Fixed::num_value);
}

void Fixed::setRawBits(int const raw)
{
	Fixed::num_value = raw;
}

float	Fixed::toFloat(void) const
{
	// std::cout << "toFloat" << std::endl;
	return (1.1);
}

int		Fixed::toInt(void) const
{
	// std::cout << "toInt" << std::endl;
	return (this->num_value);
}

std::ostream	&operator<<(std::ostream &output, const Fixed &obj)
{
	(void)obj;
	output << "<< operator";
	return (output);
}
