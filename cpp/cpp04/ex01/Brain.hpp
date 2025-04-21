/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:58:58 by tblaase           #+#    #+#             */
/*   Updated: 2025/04/21 14:36:33 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Header-protection
#pragma once

// Includes
#include <string>
#include <iostream>

// classes

class Brain
{
	private:
		std::string _ideas[100];

	public:
		Brain();
		Brain(const Brain &copy);
		Brain &operator=(const Brain &src);
		virtual ~Brain();

            //Getter
		const std::string& getIdea(int i)const;
            //setter
		void setIdea(int i, std::string idea);
};