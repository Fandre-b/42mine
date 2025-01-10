/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 00:04:13 by fandre-b          #+#    #+#             */
/*   Updated: 2025/01/10 10:33:14 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
# include <iomanip>
#include <limits> 

PhoneBook::PhoneBook()
{
    std::cout << "PhoneBook has started" << std::endl;
    _printMenu();
    for (int i = 0; i < 8; ++i)
        _contacts[i] = NULL;
}

PhoneBook::~PhoneBook()
{
    for (int i = 0; i < 8; ++i)
        delete _contacts[i];
    std::cout << "PhoneBook has ended" << std::endl;
    std::cout << "All data has been deleted, Goodbye!" << std::endl;
}

void PhoneBook::_printMenu()
{
    std::cout << "Commands: ADD, SEARCH, EXIT" << std::endl;
}
    
void PhoneBook::addContact()
{
    int i = 0;
    while (_contacts[i] != NULL && i < 8)
        i++;
    if (i == 8)
    {
        _removeContact(0);
        i = 7;
    }
    _contacts[i] = new Contact();
    printAllContacts();
}

void PhoneBook::_removeContact(int i)
{
    delete _contacts[i];
    _shiftContacts(i);
}

void PhoneBook::_shiftContacts(int i)
{
    for (int j = i; j < 7; j++)
        _contacts[j] = _contacts[j + 1];
    _contacts[7] = NULL;
}

std::string formatField(const std::string& field)
{
    if (field.length() > 10)
        return field.substr(0, 9) + ".";
    return field;
}

void PhoneBook::_printContact(Contact* _contact, int i)
{
    if (_contact == NULL)
        return;
    std::cout << std::setw(10) << std::right << i << "|";
    std::cout << std::setw(10) << std::right << formatField(_contact->getFirstName()) << "|";
    std::cout << std::setw(10) << std::right << formatField(_contact->getLastName()) << "|";
    std::cout << std::setw(10) << std::right << formatField(_contact->getNickName()) << "|";
    std::cout << std::setw(10) << std::right << formatField(_contact->getPhoneNumber()) << "|";
    std::cout << std::setw(10) << std::right << formatField(_contact->getDarkSecret());
    std::cout << std::endl;
}

void PhoneBook::printAllContacts()
{
    std::cout << "     index|first name| last name|  nickname" << std::endl;
    for (int i = 0; i < 8; i++)
        _printContact(_contacts[i], i);
}

void PhoneBook::searchContact()
{
    int index;

    index = -1;
    while (true)
    {
        std::cout << "Enter the index to search [0 - 7]: " << std::endl;
        std::cin >> index;
        if (std::cin.fail())
        {
            std::cin.clear(); // Clear the error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the invalid input
            std::cerr << "Invalid input. Please enter a number between 0 and 7." << std::endl;
        }
        else
            break;
    }
    if (index > 7 || index < 0)
    {
        std::cout << "Invalid index [0 - 7]" << std::endl;
        return;
    }
    if (_contacts[index] == NULL)
        std::cout << "No contact at index " << index << std::endl;
    else
    {
        std::cout << "     index|first name| last name|  nickname" << std::endl;
        _printContact(_contacts[index], index);
    }
    //TODO one field per line
}

