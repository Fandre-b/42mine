/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 08:37:22 by fandre-b          #+#    #+#             */
/*   Updated: 2025/04/17 12:56:13 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Constructors
DiamondTrap::DiamondTrap(): ClapTrap()
{
	this->_name = this->ClapTrap::_name;
	this->ClapTrap::_name = this->ClapTrap::_name + "_clap_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << YELLOW << "DiamondTrap: " << this->_name << " created" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src): ClapTrap(src), ScavTrap(src), FragTrap(src), _name(src._name)
{
	std::cout << YELLOW << "DiamondTrap: " << this->_name << " copied" << RESET << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
	std::cout << YELLOW << "DiamondTrap: " << this->_name << " Assigned into " << rhs._name << RESET << std::endl;

    if (this != &rhs) 
	{
        // ClapTrap::operator=(rhs);   // Assign ClapTrap members
		ScavTrap::operator=(rhs);   // Assign ScavTrap members
		FragTrap::operator=(rhs);   // Assign FragTrap members
		// both will also call claptrap relevant members
        this->_name = rhs._name;    // Set the DiamondTrap _name manually after base assignment
    }

    return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << YELLOW << "DiamondTrap: " << this->_name << " destroyed" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), _name(name)
{
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << YELLOW << "DiamondTrap: " << this->_name << " created" << RESET << std::endl;
}

// void DiamondTrap::attack(const std::string &target)
// {
// 	ScavTrap::attack(target);
// }

void	DiamondTrap::whoAmI(void)
{
	std::cout << MAGENTA << "--> DiamondTrap named: " << this->_name << RESET << std::endl;
	std::cout << MAGENTA << "--> Originated from ClapTrap named " << ClapTrap::_name << RESET << std::endl;
}
