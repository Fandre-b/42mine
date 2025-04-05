/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 00:04:08 by fandre-b          #+#    #+#             */
/*   Updated: 2025/03/18 21:50:01 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"


Contact::Contact() {}

Contact::~Contact()
{
	_firstName.clear();
    _lastName.clear();
    _nickName.clear();
    _phoneNumber.clear();
    _darkSecret.clear();
}

void Contact::SetContact()
{
	std::cout << std::endl << "Enter the contact details: " << std::endl;
	std::cout << "First name: ";
	std::getline(std::cin, this->_firstName);
	std::cout << "Last name: ";
	std::getline(std::cin, this->_lastName);
	std::cout << "Nickname: ";
	std::getline(std::cin, this->_nickName);
	std::cout << "Phone number: ";
	std::getline(std::cin, this->_phoneNumber);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, this->_darkSecret);
}

bool Contact::IsEmpty()
{
	if (this->_firstName.empty()
		|| this->_lastName.empty()
		|| this->_nickName.empty()
		|| this->_phoneNumber.empty()
		|| this->_darkSecret.empty())
		return true;
	return false;
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
