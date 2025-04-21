/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:59:07 by tblaase           #+#    #+#             */
/*   Updated: 2025/04/21 14:40:31 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// Constructors
Brain::Brain()
{
	std::cout << "Brain Default Constructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain Copy Constructor called" << std::endl;
	*this = copy;
}

// Deconstructors
Brain::~Brain()
{
	std::cout << "Brain Deconstructor called" << std::endl;
}

// Overloaded Operators
Brain &Brain::operator=(const Brain &src)
{
	std::cout << "Brain Assignation operator called" << std::endl;
	if (this == &src)
		return *this;
	for (int i = 0; i < 100; i++)
	{
		if (src._ideas[i].length() > 0)
			this->_ideas[i].assign(src._ideas[i]);
	}
	return *this;
}

// Public Methods

// Getter
const std::string&	Brain::getIdea(int i)const
{
	if (i < 100)
		return(this->_ideas[i]);
	else
		return ("\033[33mThere is only 100 ideas per brain.\033[0m");
}

// Setter
void	Brain::setIdea(int i, std::string idea)
{
	if (i < 100)
		this->_ideas[i] = idea;
	else
		std::cout << "\033[33mThere is only 100 ideas per brain.\033[0m" << std::endl;
}