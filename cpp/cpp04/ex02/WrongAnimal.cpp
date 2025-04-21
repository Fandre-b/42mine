/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:58:51 by fandre-b          #+#    #+#             */
/*   Updated: 2025/04/20 20:16:45 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAAnimal::WrongAAnimal()
{
    this->_type = "WrongAAnimal";
    WrongAAnimal::_type = "WrongAAnimal";
    std::cout << YELLOW << "WrongAAnimal: Some Aninal has been created" << RESET << std::endl;
}

WrongAAnimal::WrongAAnimal(const WrongAAnimal& src)
{
    // if (this != &src)
    // {
        *this = src;
    // }
    std::cout << YELLOW << "WrongAAnimal: was coppied" << RESET << std::endl;
}

WrongAAnimal &WrongAAnimal::operator=(const WrongAAnimal& src)
{
    if (this == &src)
        return *this;
    this->_type = src._type;
    std::cout << YELLOW << "WrongAAnimal: assigned" << RESET << std::endl;
    return *this;
}

WrongAAnimal::~WrongAAnimal() 
{
        std::cout << YELLOW << "WrongAAnimal: Destructed" << RESET << std::endl;
}

WrongAAnimal::WrongAAnimal(std::string type) : _type(type)
{
    this->_type = "WrongAAnimal";
    WrongAAnimal::_type = "WrongAAnimal";
    std::cout << YELLOW << "WrongAAnimal: Some Aninal has been created" << RESET << std::endl;
}

const std::string& WrongAAnimal::getType() const
{
    return this->_type;
}

void WrongAAnimal::makeSound() const
{
    std::cout << YELLOW << "This WrongAAnimal doesn't make any sound." << RESET << std::endl;
}
