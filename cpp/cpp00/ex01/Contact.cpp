/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 00:04:08 by fandre-b          #+#    #+#             */
/*   Updated: 2025/04/09 17:15:41 by fandre-b         ###   ########.fr       */
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

std::string Contact::getFieldLine(std::string info)
{
	std::string command;
	if (std::cin.eof())
		return "";
	while (1)
	{
		std::cout << info;
        std::getline(std::cin, command);
        if (std::cin.eof())
        {
			std::cout << std::endl;
            std::cerr << "ERROR: EOF detected" << std::endl;
            break;
        }
        else if (command.empty())
		{
			std::cout << std::endl;
            std::cerr << "Invalid input: Field can't be empty" << std::endl;
		}
		else
			break;
	}
	return command;
}

void Contact::SetContact()
{
	std::cout << std::endl << "Enter the contact details: " << std::endl << std::endl;
	this->_firstName = getFieldLine("First name: ");
	this->_lastName = getFieldLine("Last name: ");
	this->_nickName = getFieldLine("Nickname: ");
	this->_phoneNumber = getFieldLine("Phone number: ");
	this->_darkSecret = getFieldLine("Darkest secret: ");
	std::cout << std::endl;
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

void Contact::getContact()
{
        std::cout << "first name: " << this->_firstName << std::endl;
        std::cout << "last name: " << this->_lastName << std::endl;
        std::cout << "nickname: " << this->_nickName << std::endl;
        std::cout << "phone number: " << this->_phoneNumber << std::endl;
        std::cout << "darkest secret: " << this->_darkSecret << std::endl;
}

void Contact::printContact()
{
	if (this->_firstName.empty())
		return;
	std::cout << std::setw(10) << std::right << formatField(this->_firstName) << "|";
	std::cout << std::setw(10) << std::right << formatField(this->_lastName) << "|";
	std::cout << std::setw(10) << std::right << formatField(this->_nickName);
	std::cout << std::endl;
}

std::string Contact::formatField(const std::string& field)
{
    if (field.length() > 10)
        return field.substr(0, 9) + ".";
    return field;
}
