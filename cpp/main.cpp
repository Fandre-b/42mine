/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:46:46 by fandre-b          #+#    #+#             */
/*   Updated: 2025/04/04 17:46:46 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap unnamed;
	DiamondTrap named("Clappy");
	DiamondTrap copy(named);

	unnamed.attack("Target1");
	named.attack("Target2");

	named.takeDamage(5);
	named.takeDamage(10);

	named.beRepaired(15);
	unnamed.beRepaired(5);

	named.attack("Target2");
	unnamed = named;
	unnamed.attack("Target3");
	named.highFivesGuys();
	std::cout << "this is the base Class new name " << named.ClapTrap::getName() << std::endl;

	return 0;
}
