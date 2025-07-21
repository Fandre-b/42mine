/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:57:57 by fandre-b          #+#    #+#             */
/*   Updated: 2025/04/02 17:31:09 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
        // Weapon sword = Weapon("sword");
        // jim.setWeapon(sword);
        // jim.attack();
    }
    // { //TODO remove this and extra contructors  
    //     Weapon pistol = Weapon("pistol");
    //     HumanB boda("Boda");
    //     boda.attack();
    //     boda.setWeapon(pistol);
    //     boda.attack();
    //     HumanA boda2("Boda", pistol);
    //     boda2.attack();
    // }
    return (0);
}