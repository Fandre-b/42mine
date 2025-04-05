/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 05:37:41 by fandre-b          #+#    #+#             */
/*   Updated: 2025/04/04 05:37:41 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const Point &src) : _x(src.getX()), _y(src.getY()) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point &Point::operator=(const Point &rhs)
{
    if (this != &rhs)
		std::cout << "Assignment operator called, but const members cannot be changed." << std::endl;
    return *this;
}

Point::~Point() {}

float Point::getX() const
{
	return this->_x.toFloat();
}

float Point::getY() const
{
	return this->_y.toFloat();
}