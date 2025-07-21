/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:58:00 by fandre-b          #+#    #+#             */
/*   Updated: 2025/04/04 11:56:54 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon) : name(name), weapon(weapon) {}

void HumanA::attack() const {
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}


// // TODO remove this 

// // exemple of an initializer list.
// // provides an way to set the numbers of the members during the construction of the object
// // essencial for read only members or references
// HumanA::HumanA(const std::string& name) : name(name) {}
// // Not possible as an reference cannot be uninitialized
