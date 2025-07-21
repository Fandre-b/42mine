/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 05:45:59 by fandre-b          #+#    #+#             */
/*   Updated: 2025/04/04 05:45:59 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point vetorize(Point const p1, Point const p2)
{
	return Point(p2.getX() - p1.getX(), p2.getY() - p1.getY());
}

float cross_product(Point const vector1, Point const vector2)
{
    return (vector1.getX() * vector2.getY()) - (vector1.getY() * vector2.getX());
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float cross1 = cross_product(vetorize(a, b), vetorize(a, point));
	float cross2 = cross_product(vetorize(b, c), vetorize(b, point));
	float cross3 = cross_product(vetorize(c, a), vetorize(c, point));

	return (cross1 > 0 && cross2 > 0 && cross3 > 0) || 
		(cross1 < 0 && cross2 < 0 && cross3 < 0);
}
