/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:58:40 by fandre-b          #+#    #+#             */
/*   Updated: 2025/04/21 16:54:40 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#define RESET "\033[0m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"

class AAnimal
{
    protected:
        std::string _type;
    public:
        AAnimal();
        AAnimal(const AAnimal &src);
        AAnimal& operator=(const AAnimal &src);
        
        virtual ~AAnimal();
        
        AAnimal(std::string type);
        virtual void makeSound() const = 0;
        const std::string& getType() const;
        
        virtual void setIdea(int i, const std::string idea) = 0;
        virtual void getIdeas() const = 0;
};