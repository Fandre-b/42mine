/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:58:54 by fandre-b          #+#    #+#             */
/*   Updated: 2025/04/20 18:30:49 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
    private:
    protected:
    public:
        Cat();
        Cat(const Cat& src);
        Cat &operator=(const Cat &src);
        virtual ~Cat();
        Cat(std::string _type);

        void makeSound() const;
        const std::string& getType() const;
};