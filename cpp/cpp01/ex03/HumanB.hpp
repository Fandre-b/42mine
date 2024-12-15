/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:51:41 by fandre-b          #+#    #+#             */
/*   Updated: 2024/12/15 14:59:24 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB {
private:
    std::string name;
    Weapon* weapon; // Pointer to a Weapon object
    // Weapon      &_weapon;
    // Weapon      _weapon;
public:
    HumanB(const std::string& name);
    void setWeapon(Weapon& weapon);
    void attack() const;
};

#endif