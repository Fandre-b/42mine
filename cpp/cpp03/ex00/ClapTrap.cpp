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

ClapTrap::ClapTrap() : _name("Unnamed"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap: " << this->_name << " created" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap: " << this->_name << " destroyed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	*this = src;
	std::cout << "ClapTrap: " << this->_name << " copied" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	std::cout << "ClapTrap: " << this->_name << " ShapeShifts into " << rhs._name << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

void ClapTrap::attack(const std::string &target)
{
	if (this->_hitPoints <= 0)
		std::cout << "ClapTrap: " << this->_name << " is unalive and cannot attack" << std::endl;
	else if (this->_energyPoints <= 0)
		std::cout << "ClapTrap: " << this->_name << " its out of energy and cannot attack" << std::endl;
	else
	{
		std::cout << "ClapTrap: " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage" << std::endl;
        this->_energyPoints--;
	}
	//can't do target checks or changes as per subject
}

void ClapTrap::takeDamage(unsigned int ammount)
{
	if (this->_hitPoints <= 0)
		std::cout << "ClapTrap: " << this->_name << " is unalive and cannot take damage" << std::endl;
	else if (this->_hitPoints <= ammount)
	{
		std::cout << "ClapTrap: " << this->_name << " takes " << this->_hitPoints << " of damage, and Dies" << std::endl;
		this->_hitPoints = 0;
		this->_energyPoints--;
	}
	else
	{
		this->_hitPoints -= ammount;
		std::cout << "ClapTrap: " << this->_name << " takes " << ammount << " of damage, with " << this->_hitPoints << " HitPoints remaining" << std::endl;
		this->_energyPoints--;
	}
}

void ClapTrap::beRepaired(unsigned int ammount)
{
	if (this->_hitPoints <= 0)
	std::cout << "ClapTrap: " << this->_name << " is resurected back to live, now has " << this->_hitPoints + ammount << std::endl;
	else 
	std::cout << "ClapTrap: " << this->_name << " is healed by " << ammount << " points, and now has " << this->_hitPoints + ammount << std::endl;
	this->_hitPoints += ammount;
}