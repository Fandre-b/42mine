/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:58:51 by fandre-b          #+#    #+#             */
/*   Updated: 2025/04/21 16:57:21 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    this->_type = "Animal";
    Animal::_type = "Animal";
    std::cout << YELLOW << "Animal: Some Aninal has been created" << RESET << std::endl;
}

Animal::Animal(const Animal& src)
{
    this->_type = src._type;
    std::cout << YELLOW << "Animal: was coppied" << RESET << std::endl;
}

Animal &Animal::operator=(const Animal& src)
{
    if (this == &src)
        return *this;
    this->_type = src._type;
    std::cout << YELLOW << "Animal: assigned" << RESET << std::endl;
    return *this;
}

Animal::~Animal() 
{
        std::cout << YELLOW << "Animal: Destructed" << RESET << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
    this->_type = "Animal";
    Animal::_type = "Animal";
    std::cout << YELLOW << "Animal: Some Aninal has been created" << RESET << std::endl;
}

const std::string& Animal::getType() const
{
    return this->_type;
}

void Animal::makeSound() const
{
    std::cout << YELLOW << "This animal doesn't make any sound." << RESET << std::endl;
}

void Animal::setIdea(int i , std::string idea) 
{
    (void) i;
    (void) idea;
}

void Animal::getIdeas() const {}
