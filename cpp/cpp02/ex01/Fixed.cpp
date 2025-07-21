/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:52:26 by fandre-b          #+#    #+#             */
/*   Updated: 2025/04/03 17:52:26 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPoint(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(const int number) : _fixedPoint(number << _skFractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
	// this->_fixedPoint = number << _skFractionalBits;
}

// This (int) cast is the old, unsafe method, which forcibly truncates the float value
// without proper rounding, potentially leading to loss of precision.
// Fixed::Fixed(const float number) : _fixedPoint((int)(number * (1 << _skFractionalBits)))

// (roundf) is necessary to ensure that the float value is rounded to the nearest integer
Fixed::Fixed(const float number) : _fixedPoint(static_cast<int> (roundf(number * (1 << _skFractionalBits))))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPoint);
}

void Fixed::setRawBits(int number)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPoint = number;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_fixedPoint = rhs.getRawBits();
	}
	return (*this);
}

int Fixed::toInt(void) const
{
	return (this->_fixedPoint >> _skFractionalBits);
}

float Fixed::toFloat(void) const
{
	return (static_cast<float> (this->_fixedPoint) / (1 << _skFractionalBits));
}

std::ostream &operator<<(std::ostream &os, Fixed const &fixed)
{
    os << fixed.toFloat();
    return os;
}