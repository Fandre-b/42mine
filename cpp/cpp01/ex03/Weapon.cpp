/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:57:55 by fandre-b          #+#    #+#             */
/*   Updated: 2024/12/15 14:57:09 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <string>

Weapon::Weapon(const std::string& type) : _type(type) {}

const std::string& Weapon::getType() const {
    return this->_type;
}

void Weapon::setType(const std::string& type) {
    this->_type = type;
}
