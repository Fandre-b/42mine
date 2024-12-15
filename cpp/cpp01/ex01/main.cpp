/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 12:03:11 by fandre-b          #+#    #+#             */
/*   Updated: 2024/12/15 12:58:39 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <cstdlib>

Zombie* zombieHorde( int N, std::string name );

int main(int argc, char **argv)
{
    int nbr = -1;
    std::string name = "";
    Zombie *horde;

    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <number_of_zombies> [zombie_name]" << std::endl;
        return 0;
    }
    nbr = atoi(argv[1]);
    if (nbr <= 0) {
        std::cout << "Please use a valid number of Zombie elements" << std::endl;
        return 1;
    }
    if (argc > 2) {
        name = argv[2];
    }
    std::cout << "An horde of " << nbr << " has appeared!!" << std::endl;
    horde = zombieHorde(nbr, name);
    for (int i = 0; i < nbr; i++)
        horde[i].announce();
    delete [] horde;
    std::cout << "The horde of " << nbr << " zombies dissapeared" << std::endl;
    return (0);
}