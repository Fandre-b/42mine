/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:41:07 by fandre-b          #+#    #+#             */
/*   Updated: 2025/04/04 15:41:07 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Unnamed"), _hitPoints(10), _energyPoints(10), _attackDamage(0) 
{
	std::cout << GREEN << "ClapTrap: " << this->_name << " created" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	*this = src;
	std::cout << GREEN << "ClapTrap: " << this->_name << " copied" << RESET << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	std::cout << GREEN << "ClapTrap: " << this->_name << " Assigned into " << rhs._name << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << GREEN << "ClapTrap: " << this->_name << " destroyed" << RESET << std::endl;
}


ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << GREEN << "ClapTrap: " << this->_name << " created" << RESET << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->_hitPoints <= 0)
		std::cout << GREEN << "ClapTrap: " << this->_name << " is unalive and cannot attack" << RESET << std::endl;
	else if (this->_energyPoints <= 0)
		std::cout << GREEN << "ClapTrap: " << this->_name << " its out of energy and cannot attack" << RESET << std::endl;
	else
	{
		std::cout << GREEN << "ClapTrap: " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage" << RESET << std::endl;
        this->_energyPoints--;
	}
	//can't do target checks or changes as per subject
}

void ClapTrap::takeDamage(unsigned int ammount)
{
	if (this->_hitPoints <= 0)
		std::cout << GREEN << "ClapTrap: " << this->_name << " is unalive and cannot take damage" << RESET << std::endl;
	else if (this->_hitPoints <= ammount)
	{
		std::cout << GREEN << "ClapTrap: " << this->_name << " takes " << this->_hitPoints << " of damage, and Dies" << RESET << std::endl;
		this->_hitPoints = 0;
		this->_energyPoints--;
	}
	else
	{
		this->_hitPoints -= ammount;
		std::cout << GREEN << "ClapTrap: " << this->_name << " takes " << ammount << " of damage, with " << this->_hitPoints << " HitPoints remaining" << RESET << std::endl;
		this->_energyPoints--;
	}
}

void ClapTrap::beRepaired(unsigned int ammount)
{
	if (this->_hitPoints <= 0)
	std::cout << GREEN << "ClapTrap: " << this->_name << " is resurected back to live, now has " << this->_hitPoints + ammount << std::endl;
	else 
	std::cout << GREEN << "ClapTrap: " << this->_name << " is healed by " << ammount << " points, and now has " << this->_hitPoints + ammount << std::endl;
	this->_hitPoints += ammount;
}
