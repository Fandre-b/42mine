/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 08:37:22 by fandre-b          #+#    #+#             */
/*   Updated: 2025/04/16 18:57:03 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Constructors
FragTrap::FragTrap(): ClapTrap()
{
	
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << RED << "DiamondTrap: " << this->_name << " created" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src): ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	std::cout << RED << "DiamondTrap: " << this->_name << " copied" << RESET << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
	std::cout << RED << "DiamondTrap: " << this->_name << " Assigned into " << rhs._name << std::endl;

    ClapTrap::operator=(rhs);

    return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << RED << "DiamondTrap: " << this->_name << " destroyed" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << RED << "DiamondTrap: " << this->_name << " created" << RESET << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	if (this->_hitPoints <= 0)
		std::cout << RED << "DiamondTrap: " << this->_name << " is unalive and cannot attack" << RESET << std::endl;
	else if (this->_energyPoints <= 0)
		std::cout << RED << "DiamondTrap: " << this->_name << " its out of energy and cannot attack" << RESET << std::endl;
	else
	{
		std::cout << RED << "DiamondTrap: " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage" << RESET << std::endl;
        this->_energyPoints--;
	}
	//can't do target checks or changes as per subject
}

