/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 10:17:39 by fandre-b          #+#    #+#             */
/*   Updated: 2024/12/15 11:24:30 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
{
    _name = "Unnamed";
}

Zombie::Zombie(std::string name)
{
    _name = name;
}

Zombie::~Zombie()
{
    std::cout << _name << " is dead" << std::endl;
}

void Zombie::announce()
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


