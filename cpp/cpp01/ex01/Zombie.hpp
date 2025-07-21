/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 10:17:35 by fandre-b          #+#    #+#             */
/*   Updated: 2025/03/19 11:18:21 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include <cctype>

class Zombie
{
private:
    std::string _name;
public:
    Zombie();
    ~Zombie();
    Zombie(std::string name);
    void setname(std::string name);
    void announce();
};

Zombie* zombieHorde( int N, std::string name );