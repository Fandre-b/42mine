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

	// Contructors

Fixed::Fixed() : _fixedPoint(0) {}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
}

Fixed::Fixed(const int number) : _fixedPoint(number << _skFractionalBits) {}

Fixed::Fixed(const float number) : _fixedPoint(static_cast<int> (roundf(number * (1 << _skFractionalBits)))) {}

	// Destructor

Fixed::~Fixed() {}

	// Getters and Setters

int Fixed::getRawBits(void) const
{
	return (this->_fixedPoint);
}

void Fixed::setRawBits(int number)
{
	this->_fixedPoint = number;
}

	// Copy assignment operator

Fixed &Fixed::operator=(const Fixed &rhs)
{
	if (this != &rhs)
	{
		this->_fixedPoint = rhs.getRawBits();
	}
	return (*this);
}

	// Comparison Operators

bool Fixed::operator>(const Fixed &rhs) const
{
	return (this->_fixedPoint > rhs._fixedPoint);
}

bool Fixed::operator<(const Fixed &rhs) const
{
	return (this->_fixedPoint < rhs._fixedPoint);
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	return (this->_fixedPoint >= rhs._fixedPoint);
}

bool Fixed::operator<=(const Fixed &rhs) const
{
	return (this->_fixedPoint <= rhs._fixedPoint);
}

bool Fixed::operator==(const Fixed &rhs) const
{
	return (this->_fixedPoint == rhs._fixedPoint);
}

bool Fixed::operator!=(const Fixed &rhs) const
{
	return (this->_fixedPoint != rhs._fixedPoint);
}

	// Arithmetic Operators

Fixed Fixed::operator+(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
	return (Fixed(toFloat() - rhs.toFloat()));
	// this toFloat alone also works, compiller assumes this->toFloat()
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

	// Increment and Decrement Operators

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->_fixedPoint++;
	return temp;
}

Fixed Fixed::operator++(void)
{
	this->_fixedPoint++;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->_fixedPoint--;
	return temp;
}

Fixed Fixed::operator--(void)
{
	this->_fixedPoint--;
	return *this;
}

	// Min and Max Methods

Fixed &Fixed::min(Fixed &lhs, Fixed &rhs)
{
	if (lhs < rhs)
		return lhs;
	return rhs;
	// return (lhs < rhs ? lhs : rhs); ternary are cool but less readable
}

Fixed &Fixed::max(Fixed &lhs, Fixed &rhs)
{
	if (lhs > rhs)
		return lhs;
	return rhs;
}

const Fixed &Fixed::min(const Fixed &lhs, const Fixed &rhs)
{
	if (lhs < rhs)
		return lhs;
	return rhs;
}

const Fixed &Fixed::max(const Fixed &lhs, const Fixed &rhs)
{
	if (lhs > rhs)
		return lhs;
	return rhs;
}

	// Conversion Methods

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
