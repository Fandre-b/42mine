/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 10:36:45 by fandre-b          #+#    #+#             */
/*   Updated: 2024/12/15 11:29:14 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie* newZombie(std::string name);
void	randomChump(std::string name);

int main(void)
{
    // Zombie on stack called by variable
    Zombie zombie_stack;
    zombie_stack.announce();
    // Zombie on stack called
    Zombie random_zombie("Zombie_stack");
    random_zombie.announce();
    Zombie* zombie_heap = newZombie("Zombie_heap");
    zombie_heap->announce();
    // delete zombie_heap;
}