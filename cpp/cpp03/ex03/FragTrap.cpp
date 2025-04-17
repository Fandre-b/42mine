/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 08:37:22 by fandre-b          #+#    #+#             */
/*   Updated: 2025/04/17 11:32:07 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Constructors
FragTrap::FragTrap(): ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << RED << "FragTrap: " << this->_name << " created" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap &src): ClapTrap(src)
{
	std::cout << RED << "FragTrap: " << this->_name << " copied" << RESET << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
	std::cout << RED << "FragTrap: " << this->_name << " Assigned into " << rhs._name << RESET << std::endl;

    ClapTrap::operator=(rhs);

    return *this;
}

FragTrap::~FragTrap()
{
	std::cout << RED << "FragTrap: " << this->_name << " destroyed" << RESET << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << RED << "FragTrap: " << this->_name << " created" << RESET << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (this->_hitPoints <= 0)
		std::cout << RED << "FragTrap: " << this->_name << " is unalive and cannot attack" << RESET << std::endl;
	else if (this->_energyPoints <= 0)
		std::cout << RED << "FragTrap: " << this->_name << " its out of energy and cannot attack" << RESET << std::endl;
	else
	{
		std::cout << RED << "FragTrap: " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage" << RESET << std::endl;
        this->_energyPoints--;
	}
	//can't do target checks or changes as per subject
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << RED << "FragTrap: " << this->_name << " asked for an high five" << RESET << std::endl;
}
