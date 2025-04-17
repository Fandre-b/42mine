/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:13:35 by fandre-b          #+#    #+#             */
/*   Updated: 2025/04/04 13:13:35 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #pragma once
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

#define RESET "\033[0m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"

class ClapTrap
{
	protected:
		std::string	_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
	public:
		//orthodox cannonical form
		ClapTrap();
		ClapTrap(const ClapTrap &src);
		ClapTrap &operator=(const ClapTrap &rhs);

		virtual ~ClapTrap(); 
			//virtual destructor to be redineed and its needed

		//constructors oveloading
		ClapTrap(std::string name);
		

		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

			//accesser for testing porpouses
};

#endif
