/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:58:51 by fandre-b          #+#    #+#             */
/*   Updated: 2025/04/21 17:26:18 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
    this->_type = "Dog";
    this->_brain = new Brain();
    Animal::_type = "Dog"; //Witch one tho?? or both
    std::cout << RED << "An puppy happeared" << RESET << std::endl;
}

Dog::Dog(const Dog& src) : Animal(src)
{
    this->_brain = new Brain(*src._brain); // Deep copy of Brain
    std::cout << RED << "Dog was coppied" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog& src)
{
    if (this == &src)
        return *this;
    Animal::operator=(src);
    // delete old brain 
    delete this->_brain;
    this->_brain = new Brain(*src._brain);
    this->_type = src._type;
    std::cout << RED << "assigned" << RESET << std::endl;
    return *this;
}

Dog::~Dog() 
{
        std::cout << RED << "Dog Destructed" << RESET << std::endl;
        delete this->_brain;
}

const std::string& Dog::getType() const
{
    return this->_type;
}

void Dog::makeSound() const
{
    std::cout << RED << "Woof Woof" << RESET << std::endl;
}

void	Dog::getIdeas(void)const
{
	for (int i = 0; i < 3; i++)// change the 3 to 100 to show all ideas
        std::cout << "\tIdea " << i << " of the Dog is: \"" 
          << this->_brain->getIdea(i) << "\" with reference: " << &this->_brain->getIdea(i) << std::endl;
}

void	Dog::setIdea(int i, std::string idea)
{
		this->_brain->setIdea(i, idea);
}