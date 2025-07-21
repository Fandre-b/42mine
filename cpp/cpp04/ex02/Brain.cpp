/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:59:07 by tblaase           #+#    #+#             */
/*   Updated: 2025/04/21 16:05:57 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default Constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain Deconstructor called" << std::endl;
}

Brain::Brain(const Brain &src)
{
	std::cout << "Brain Copy Constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = src._ideas[i];
}

Brain &Brain::operator=(const Brain &src)
{
	std::cout << "Brain Assignation operator called" << std::endl;
	if (this == &src)
		return *this;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = src._ideas[i];
	return *this;
}

const std::string&	Brain::getIdea(int i)const
{
	static const std::string errorMessage = "Only 100 ideas per brain";
	if (i < 100)
		return(this->_ideas[i]);
	else
		return (errorMessage);
}

void	Brain::setIdea(int i, std::string idea)
{
	if (i < 100)
		this->_ideas[i] = idea;
}