/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:58:51 by fandre-b          #+#    #+#             */
/*   Updated: 2025/04/20 19:40:31 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    this->_type = "WrongCat";
    WrongAnimal::_type = "WrongCat"; //Witch one tho?? or both
    std::cout << BLUE << "An kitty happeared" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat& src) : WrongAnimal()
{
    *this = src;
    std::cout << BLUE << "WrongCat was coppied" << RESET << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat& src)
{
    if (this == &src)
        return *this;
    this->_type = src._type;
    std::cout << BLUE << "assigned" << RESET << std::endl;
    return *this;
}

WrongCat::~WrongCat() 
{
        std::cout << BLUE << "Destructed" << RESET << std::endl;
}

const std::string& WrongCat::getType() const
{
    return this->_type;
}

void WrongCat::makeSound() const
{
    std::cout << BLUE << "Miau" << RESET << std::endl;
}
