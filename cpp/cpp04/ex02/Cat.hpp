/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
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

class Cat : public AAnimal
{
    private:
        Brain *_brain;
    protected:
    public:
        Cat();
        Cat(const Cat& src);
        Cat &operator=(const Cat &src);
        virtual ~Cat();
        
        Cat(std::string _type);

        void makeSound() const;
        const std::string& getType() const;

        virtual void getIdeas(void) const;
        virtual void setIdea(int i, std::string idea);
};