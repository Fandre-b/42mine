/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:51:41 by fandre-b          #+#    #+#             */
/*   Updated: 2025/03/19 21:52:33 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanB {
private:
    std::string name;
    Weapon* weapon; // Pointer to a Weapon object
    // Weapon      &_weapon;
    // Weapon      _weapon;
public:
    HumanB(const std::string& name);
    HumanB(const std::string& name, Weapon& weapon);

    void setWeapon(Weapon& weapon);
    void attack() const;
};

#endif