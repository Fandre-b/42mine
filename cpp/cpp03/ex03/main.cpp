/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:46:46 by fandre-b          #+#    #+#             */
/*   Updated: 2025/04/17 11:56:31 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
    // Default constructor test
    std::cout << "=== Default Constructor Test ===" << std::endl;
    DiamondTrap unnamed;
    unnamed.whoAmI();
    std::cout << std::endl;

    // Parameterized constructor test
    std::cout << "=== Parameterized Constructor Test ===" << std::endl;
    DiamondTrap named("Clappy");
    named.whoAmI();
    std::cout << std::endl;

    // Copy constructor test
    std::cout << "=== Copy Constructor Test ===" << std::endl;
    DiamondTrap copy(named);
    named.whoAmI();
    copy.whoAmI();
    std::cout << std::endl;

    // Attack tests
    std::cout << "=== Attack Tests ===" << std::endl;
    unnamed.attack("Target1");
    named.attack("Target2");
    copy.attack("Target3");
    std::cout << std::endl;

    // Take damage tests
    std::cout << "=== Take Damage Tests ===" << std::endl;
    named.takeDamage(5);
    unnamed.takeDamage(5);
    copy.takeDamage(5);
    std::cout << std::endl;

    // Repair tests
    std::cout << "=== Repair Tests ===" << std::endl;
    named.beRepaired(5);
    unnamed.beRepaired(5);
    copy.beRepaired(5);
    std::cout << std::endl;

    // Assignment operator test
    std::cout << "=== Assignment Operator Test ===" << std::endl;
    unnamed.whoAmI();
    unnamed = named;
    unnamed.whoAmI();
    named.attack("Target2");
    unnamed.attack("Target3");
    
    std::cout << std::endl;

    // High fives test
    std::cout << "=== High Fives Test ===" << std::endl;
    named.highFivesGuys();
    named.whoAmI();
    named.guardGate();
    std::cout << std::endl;

    // Destruction test
    std::cout << "=== Destruction Test ===" << std::endl;

    return 0;
}