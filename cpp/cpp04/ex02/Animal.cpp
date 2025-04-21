/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:58:51 by fandre-b          #+#    #+#             */
/*   Updated: 2025/04/21 16:06:21 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

AAnimal::AAnimal()
{
    this->_type = "AAnimal";
    AAnimal::_type = "AAnimal";
    std::cout << YELLOW << "AAnimal: Some Aninal has been created" << RESET << std::endl;
}

AAnimal::AAnimal(const AAnimal& src)
{
    this->_type = src._type;
    std::cout << YELLOW << "AAnimal: was coppied" << RESET << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal& src)
{
    if (this == &src)
        return *this;
    this->_type = src._type;
    std::cout << YELLOW << "AAnimal: assigned" << RESET << std::endl;
    return *this;
}

AAnimal::~AAnimal() 
{
        std::cout << YELLOW << "AAnimal: Destructed" << RESET << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
    this->_type = "AAnimal";
    AAnimal::_type = "AAnimal";
    std::cout << YELLOW << "AAnimal: Some Aninal has been created" << RESET << std::endl;
}

const std::string& AAnimal::getType() const
{
    return this->_type;
}

void AAnimal::makeSound() const
{
    std::cout << YELLOW << "This AAnimal doesn't make any sound." << RESET << std::endl;
}
