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
		int _fixedPoint;
		static const int _skFractionalBits = 8;
	public:
		Fixed();
		~Fixed();
		// Fixed(const int number);
		Fixed(const Fixed &src);
		Fixed &operator=(const Fixed &rhs);

		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif