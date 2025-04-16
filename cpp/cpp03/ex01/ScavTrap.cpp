/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 08:37:22 by fandre-b          #+#    #+#             */
/*   Updated: 2025/04/16 10:41:21 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Constructors
ScavTrap::ScavTrap(): ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_guardGate = false;
	std::cout << BLUE << "ClapTrap: " << this->_name << " created" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src): ClapTrap(src)
{
	this->_guardGate = src._guardGate;
	std::cout << BLUE << "ClapTrap: " << this->_name << " copied" << RESET << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	std::cout << BLUE << "ClapTrap: " << this->_name << " Assigned into " << rhs._name << std::endl;

    ClapTrap::operator=(rhs);
    this->_guardGate = rhs._guardGate;

    return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << BLUE << "ScavTrap: " << this->_name << " destroyed" << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_guardGate = false;
	std::cout << BLUE << "ClapTrap: " << this->_name << " created" << RESET << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->_guardGate == true)
		std::cout << BLUE << "ScavTrap: " << this->_name << " is in Gate Keeper mode and cannot attack" << RESET << std::endl;
	else if (this->_hitPoints <= 0)
		std::cout << BLUE << "ScavTrap: " << this->_name << " is unalive and cannot attack" << RESET << std::endl;
	else if (this->_energyPoints <= 0)
		std::cout << BLUE << "ScavTrap: " << this->_name << " its out of energy and cannot attack" << RESET << std::endl;
	else
	{
		std::cout << BLUE << "ScavTrap: " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage" << RESET << std::endl;
        this->_energyPoints--;
	}
	//can't do target checks or changes as per subject
}

void ScavTrap::guardGate(void)
{
	if (this->_guardGate == false)
	{
		this->_guardGate = true;
		std::cout << BLUE << "ScavTrap: " << this->_name << " in Gate Keeper mode" << RESET << std::endl;
	}
	else
		std::cout << BLUE << "ScavTrap: " << this->_name << " already in Gate Keeper duty" << RESET << std::endl;
}
