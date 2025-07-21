/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-rhs <fandre-rhs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:54:11 by fandre-rhs          #+#    #+#             */
/*   Updated: 2025/04/03 16:54:11 by fandre-rhs         ###   ########.fr       */
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
		void			setRawBits(int const raw);
		int				getRawBits(void) const;
				// const allows to call the method without modifying the class

		// Overload Operators
			// copy assignment operator
		Fixed			&operator=(const Fixed &rhs);

			// Comparison Operators 
		bool			operator>(const Fixed &rhs) const;
		bool			operator<(const Fixed &rhs) const;
		bool			operator>=(const Fixed &rhs) const;
		bool			operator<=(const Fixed &rhs) const;
		bool			operator==(const Fixed &rhs) const;
		bool			operator!=(const Fixed &rhs) const;

			// Arithmetic Operators
		Fixed			operator+(const Fixed &rhs) const;
		Fixed			operator-(const Fixed &rhs) const;
		Fixed			operator*(const Fixed &rhs) const;
		Fixed			operator/(const Fixed &rhs) const;

			// Increment and Decrement Operators
		Fixed			operator++(int) ;
		Fixed			operator++(void);
		Fixed			operator--(int);
		Fixed			operator--(void);
		
		// Method functions
			// Min and Max Functions
		static			Fixed &min(Fixed &lhs, Fixed &rhs);
		static			Fixed &max(Fixed &lhs, Fixed &rhs);
		static const	Fixed &min(const Fixed &lhs, const Fixed &rhs);
		static const	Fixed &max(const Fixed &lhs, const Fixed &rhs);
				// static allows the to call the method without intanciating the class

			// Conversion Methods
		int				toInt(void) const;
		float			toFloat(void) const;
};

// Overload the insertion operator
std::ostream &operator<<(std::ostream &o, Fixed const &rhs);
	// Allows to print the object using std::cout

#endif