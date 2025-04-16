/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:13:35 by fandre-b          #+#    #+#             */
/*   Updated: 2025/04/16 11:38:34 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #pragma once
#ifndef FragTrap_HPP
# define FragTrap_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : virtual public ClapTrap
{
	public:
		//orthodox cannonical form
		FragTrap();
		FragTrap(const FragTrap &src);
		FragTrap &operator=(const FragTrap &rhs);

		virtual ~FragTrap(); 
			//virtual destructor to be redineed and its needed

		//constructors oveloading
		FragTrap(std::string name);
		

		void attack(const std::string &target);
        void highFivesGuys(void);
};

#endif
