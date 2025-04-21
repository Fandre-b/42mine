/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:58:54 by fandre-b          #+#    #+#             */
/*   Updated: 2025/04/20 20:16:20 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAAnimal
{
    private:
    protected:
    public:
        WrongCat();
        WrongCat(const WrongCat& src);
        WrongCat &operator=(const WrongCat &src);
        virtual ~WrongCat();
        WrongCat(std::string _type);

        void makeSound() const;
        const std::string& getType() const;
};