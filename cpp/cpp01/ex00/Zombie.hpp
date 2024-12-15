/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 10:17:35 by fandre-b          #+#    #+#             */
/*   Updated: 2024/12/15 11:07:26 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Zombie
{
private:
    std::string _name;
public:
    Zombie();
    Zombie(std::string name);
    ~Zombie();
    void announce();
};
