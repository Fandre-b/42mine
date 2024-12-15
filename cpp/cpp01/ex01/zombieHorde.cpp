/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 12:02:01 by fandre-b          #+#    #+#             */
/*   Updated: 2024/12/15 13:03:18 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie* horde = new Zombie[N];
    
    if (name.empty())
        return (horde);
    for (int i = 0; i < N; i++)
        horde[i].setname(name);
    return (horde);
}