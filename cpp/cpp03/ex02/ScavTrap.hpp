/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:13:35 by fandre-b          #+#    #+#             */
/*   Updated: 2025/04/16 08:55:24 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #pragma once
#ifndef ScavTrap_HPP
# define ScavTrap_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap
{
    private:
        bool _guardGate;
	public:
		//orthodox cannonical form
		ScavTrap();
		ScavTrap(const ScavTrap &src);
		ScavTrap &operator=(const ScavTrap &rhs);

		virtual ~ScavTrap(); 
			//virtual destructor to be redineed and its needed

		//constructors oveloading
		ScavTrap(std::string name);
		

		void attack(const std::string &target);
		void guardGate(void);
};

#endif
