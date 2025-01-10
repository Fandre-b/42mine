/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 00:04:08 by fandre-b          #+#    #+#             */
/*   Updated: 2025/01/09 18:26:58 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>

Contact::Contact()
{
	std::cout << "Enter the first name: " << std::endl;
	std::cin >> this->_firstName;
	std::cout << "Enter the last name: " << std::endl;
	std::cin >> this->_lastName;
	std::cout << "Enter the nickname: " << std::endl;
	std::cin >> this->_nickName;
}

Contact::~Contact()
{
}

void Contact::setFirstName(std::string _firstName)
{
	this->_firstName = _firstName;
}

void Contact::setLastName(std::string _lastName)
{
	this->_lastName = _lastName;
}

void Contact::setNickName(std::string _nickName)
{
	this->_nickName = _nickName;
}

std::string Contact::getFirstName()
{
	return this->_firstName;
}

std::string Contact::getLastName()
{
	return this->_lastName;
}

std::string Contact::getNickName()
{
	return this->_nickName;
}

void Contact::setPhoneNumber(std::string _phoneNumber)
{
	this->_phoneNumber = _phoneNumber;
}

void Contact::setDarkSecret(std::string _darkSecret)
{
	this->_darkSecret = _darkSecret;
}

std::string Contact::getPhoneNumber()
{
	return this->_phoneNumber;
}

std::string Contact::getDarkSecret()
{
	return this->_darkSecret;
}
