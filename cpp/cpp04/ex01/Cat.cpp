/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:58:51 by fandre-b          #+#    #+#             */
/*   Updated: 2025/04/21 17:05:25 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
    this->_type = "Cat";
    Animal::_type = "Cat"; //Witch one tho?? or both
    std::cout << BLUE << "An kitty happeared" << RESET << std::endl;
}

Cat::Cat(const Cat& src) : Animal(src)
{
    this->_brain = new Brain(*src._brain); // Deep copy of Brain
    std::cout << BLUE << "Cat was coppied" << RESET << std::endl;
}

Cat &Cat::operator=(const Cat& src)
{
    if (this == &src)
        return *this;
    Animal::operator=(src);
    // delete old brain 
    delete this->_brain;
    this->_brain = new Brain(*src._brain);
    this->_type = src._type;
    std::cout << BLUE << "assigned" << RESET << std::endl;
    return *this;
}

Cat::~Cat() 
{
    delete this->_brain;
    std::cout << BLUE << "Cat Destructed" << RESET << std::endl;
}

const std::string& Cat::getType() const
{
    return this->_type;
}

void Cat::makeSound() const
{
    std::cout << BLUE << "Miau" << RESET << std::endl;
}

void	Cat::getIdeas(void)const
{
	for (int i = 0; i < 3; i++)// change the 3 to 100 to show all ideas
        std::cout << "\tIdea " << i << " of the Cat is: \"" 
          << this->_brain->getIdea(i) << "\" with reference: " << &this->_brain->getIdea(i) << std::endl;
}

void	Cat::setIdea(int i, std::string idea)
{
		this->_brain->setIdea(i, idea);
}