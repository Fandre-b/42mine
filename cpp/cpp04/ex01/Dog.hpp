/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:58:54 by fandre-b          #+#    #+#             */
/*   Updated: 2025/04/21 16:54:40 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
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

        virtual void getIdeas(void) const;
        virtual void setIdea(int i, std::string idea);
};
