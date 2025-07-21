/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 10:36:45 by fandre-b          #+#    #+#             */
/*   Updated: 2025/04/02 17:42:26 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main(void)
{
    // Zombie on the stack by default constructor
    Zombie zombie_stack;
    zombie_stack.announce();

    // Zombie on the stack constructor parameter
    Zombie random_zombie("Zombie_stack");
    random_zombie.announce();

    // Zombie on the heap by newZombie
    Zombie* zombie_heap = newZombie("Zombie_heap");
    zombie_heap->announce();

    // delete the heap-allocated Zombie
    delete zombie_heap;
    //notice others are autodeleted by the end of the scope (via destructor)
    return (0);
}
