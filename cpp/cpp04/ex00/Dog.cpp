/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:58:51 by fandre-b          #+#    #+#             */
/*   Updated: 2025/04/21 16:08:44 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
    this->_type = "Dog";
    Animal::_type = "Dog"; //Witch one tho?? or both
    std::cout << RED << "An puppy happeared" << RESET << std::endl;
}

Dog::Dog(const Dog& src) : Animal(src)
{
    std::cout << RED << "Dog was coppied" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog& src)
{
    if (this == &src)
        return *this;
    Animal::operator=(src);
    this->_type = src._type;
    std::cout << RED << "assigned" << RESET << std::endl;
    return *this;
}

Dog::~Dog() 
{
        std::cout << RED << "Destructed" << RESET << std::endl;
}

const std::string& Dog::getType() const
{
    return this->_type;
}

void Dog::makeSound() const
{
    std::cout << RED << "Woof Woof" << RESET << std::endl;
}
    // delete old brain 
