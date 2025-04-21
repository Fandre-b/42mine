/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:58:54 by fandre-b          #+#    #+#             */
/*   Updated: 2025/04/21 12:23:08 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
    private:
        Brain *_brain;
    protected:
    public:
        Dog();
        Dog(const Dog& src);
        Dog &operator=(const Dog &src);
        virtual ~Dog();
        
        Dog(std::string _type);

        void makeSound() const;
        const std::string& getType() const;

        void getIdeas(void) const;
        void setIdea(int i, std::string idead);
        
};
