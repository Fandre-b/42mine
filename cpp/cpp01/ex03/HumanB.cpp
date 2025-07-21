/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:57:59 by fandre-b          #+#    #+#             */
/*   Updated: 2025/04/04 11:56:50 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : name(name), weapon(NULL) {}

void HumanB::setWeapon(Weapon& weapon) {
    this->weapon = &weapon;
}


void HumanB::attack() const {
    if (weapon) {
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    } else {
        std::cout << name << " has no weapon to attack with!" << std::endl;
    }
}



// // TODO remove this extra onescontructor

// // preset weapon
// HumanB::HumanB(const std::string& name, Weapon& weapon) : name(name), weapon(&weapon) {}

// // This has the same result with different process order, 
// // sets the parameters after initialization, slower than the first one
// HumanB::HumanB(const std::string& name)
// {
//     this->name = name;
//     this->weapon = NULL;
// }
