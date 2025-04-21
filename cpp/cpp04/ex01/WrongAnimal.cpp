/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:58:51 by fandre-b          #+#    #+#             */
/*   Updated: 2025/04/20 20:16:45 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    this->_type = "WrongAnimal";
    WrongAnimal::_type = "WrongAnimal";
    std::cout << YELLOW << "WrongAnimal: Some Aninal has been created" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src)
{
    // if (this != &src)
    // {
        *this = src;
    // }
    std::cout << YELLOW << "WrongAnimal: was coppied" << RESET << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& src)
{
    if (this == &src)
        return *this;
    this->_type = src._type;
    std::cout << YELLOW << "WrongAnimal: assigned" << RESET << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal() 
{
        std::cout << YELLOW << "WrongAnimal: Destructed" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
    this->_type = "WrongAnimal";
    WrongAnimal::_type = "WrongAnimal";
    std::cout << YELLOW << "WrongAnimal: Some Aninal has been created" << RESET << std::endl;
}

const std::string& WrongAnimal::getType() const
{
    return this->_type;
}

void WrongAnimal::makeSound() const
{
    std::cout << YELLOW << "This WrongAnimal doesn't make any sound." << RESET << std::endl;
}
