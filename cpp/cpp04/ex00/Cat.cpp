/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:58:51 by fandre-b          #+#    #+#             */
/*   Updated: 2025/04/20 19:40:31 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
    this->_type = "Cat";
    Animal::_type = "Cat"; //Witch one tho?? or both
    std::cout << BLUE << "An kitty happeared" << RESET << std::endl;
}

Cat::Cat(const Cat& src) : Animal()
{
    *this = src;
    std::cout << BLUE << "Cat was coppied" << RESET << std::endl;
}

Cat &Cat::operator=(const Cat& src)
{
    if (this == &src)
        return *this;
    this->_type = src._type;
    std::cout << BLUE << "assigned" << RESET << std::endl;
    return *this;
}

Cat::~Cat() 
{
        std::cout << BLUE << "Destructed" << RESET << std::endl;
}

const std::string& Cat::getType() const
{
    return this->_type;
}

void Cat::makeSound() const
{
    std::cout << BLUE << "Miau" << RESET << std::endl;
}
