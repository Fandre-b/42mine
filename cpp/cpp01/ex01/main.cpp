/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 12:03:11 by fandre-b          #+#    #+#             */
/*   Updated: 2025/03/19 12:19:52 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int argc, char **argv)
{
    int nbr;
    std::string name;
    Zombie* horde;

        // Ease of use parsing
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <number_of_zombies> [zombie_name]" << std::endl;
        return 0;
    }
    nbr = std::atoi(argv[1]);
    if (nbr <= 0) {
        std::cout << "Please use a valid number of Zombie elements" << std::endl;
        return 1;
    }
    if (argc == 3)
        name = argv[2];
    if (name.empty())
        std::cout << "Horde of zombies are nameless" << std::endl;
    
        // Actual testing
    std::cout << "An horde of " << nbr << " has appeared!!" << std::endl;
    std::cout << "Their sudden appeence was at addr: " << &horde << std::endl;

    horde = zombieHorde(nbr, name);
    for (int i = 0; i < nbr; i++)
        horde[i].announce();
    delete[] horde;
    std::cout << "The horde of " << nbr << " zombies dissapeared" << std::endl;
    return (0);
}