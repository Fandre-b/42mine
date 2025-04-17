/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:13:35 by fandre-b          #+#    #+#             */
/*   Updated: 2025/04/17 12:13:14 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #pragma once
#ifndef DiamondTrap_HPP
# define DiamondTrap_HPP

// #include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string _name; 
	public:
		//orthodox cannonical form
		DiamondTrap();
		DiamondTrap(const DiamondTrap &src);
		DiamondTrap &operator=(const DiamondTrap &rhs);

		virtual ~DiamondTrap(); 
			//virtual destructor to be redineed and its needed

		//constructors oveloading
		DiamondTrap(std::string name);
		
		using ScavTrap::attack;
		// void attack(const std::string &target);
		void whoAmI(void);
};

#endif
