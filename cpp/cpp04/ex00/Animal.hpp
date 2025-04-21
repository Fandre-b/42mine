/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:58:40 by fandre-b          #+#    #+#             */
/*   Updated: 2025/04/20 19:25:37 by fandre-b         ###   ########.fr       */
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

class Animal
{
    protected:
        std::string _type;
    public:
        Animal();
        Animal(const Animal &src);
        Animal& operator=(const Animal &src);
        
        virtual ~Animal();
        
        Animal(std::string type);
        virtual void makeSound() const ;
        const std::string& getType() const;

};