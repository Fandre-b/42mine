/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:54:11 by fandre-b          #+#    #+#             */
/*   Updated: 2025/04/03 16:54:11 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>
#include <string>

class Fixed
{
	private:
		int 				_fixedPoint;
		static const int	_skFractionalBits = 8;
	public:
			//constructors
		Fixed();
		Fixed(const Fixed &src);
		Fixed(const int number);
		Fixed(const float number); //todo

			//destructors
		~Fixed();

			// Getters and Setters	
		void	setRawBits(int const raw);
		int		getRawBits(void) const;

			// operators
		Fixed	&operator=(const Fixed &rhs);

			// Method functions
		int		toInt(void) const;
		float	toFloat(void) const;
};

std::ostream &operator<<(std::ostream &o, Fixed const &rhs);

#endif