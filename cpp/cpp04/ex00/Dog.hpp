/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:58:54 by fandre-b          #+#    #+#             */
/*   Updated: 2025/04/20 18:21:27 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog : public Animal
{
    private:
    protected:
    public:
        Dog();
        Dog(const Dog& src);
        Dog &operator=(const Dog &src);
        virtual ~Dog();
        Dog(std::string _type);

        void makeSound() const;
        const std::string& getType() const;
};