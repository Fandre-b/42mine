/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 00:04:13 by fandre-b          #+#    #+#             */
/*   Updated: 2025/03/18 23:07:42 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    std::cout << "PhoneBook has started" << std::endl;
    std::cout << "Commands: ADD, SEARCH, EXIT" << std::endl;
}

PhoneBook::~PhoneBook()
{
    std::cout << "PhoneBook has ended" << std::endl;
    std::cout << "All data has been deleted, Goodbye!" << std::endl;
}

void PhoneBook::searchContact()
{
    std::string input;
    int         index;

    while (true)
    {
        std::cout << std::endl << "Enter index [0 - 7]: ";
        std::getline(std::cin, input);
        std::stringstream ss(input);
        if (ss >> index)
        {
            if (index >= 0 && index <= 7)
                break;        
            else
                std::cout << "Invalid input: Out of range [0 - 7]" << std::endl;
        }
        else if (std::cin.eof())
            return;
        else
            std::cout << "Invalid input: Not an number" << std::endl;
    }
    if (_contacts[index].getFirstName().empty())
        std::cout << "ERROR: No contact at index " << index << std::endl;
    else
    {
        std::cout << "index|first name| last name|  nickname" << std::endl;
        std::cout << "index: " << index << std::endl;
        std::cout << "first name: " << _contacts[index].getFirstName() << std::endl;
        std::cout << "last name: " << _contacts[index].getLastName() << std::endl;
        std::cout << "nickname: " << _contacts[index].getNickName() << std::endl;
        std::cout << "phone number: " << _contacts[index].getPhoneNumber() << std::endl;
        std::cout << "darkest secret: " << _contacts[index].getDarkSecret() << std::endl;
    }
}

void PhoneBook::addContact() 
{
    int i;   
    
    i = 0;
    while (!_contacts[i].IsEmpty() && i < 8)
        i++; 
    if (i == 8 && !_contacts[i].IsEmpty()) {
        _removeContact(0);
        i = 7;
    }
    _contacts[i].SetContact();
    if (_contacts[i].IsEmpty())
    {
        std::cout << "ERROR: Saved contact can’t have empty fields." << std::endl;
        _removeContact(i);
        return ;
    }
    printAllContacts();
}

void PhoneBook::_removeContact(int i)
{
    _contacts[i] = Contact();
    _shiftContacts(i);
}

void PhoneBook::_shiftContacts(int i)
{
    for (int j = i; j < 7; j++)
        _contacts[j] = _contacts[j + 1];
    _contacts[7] = Contact();
}


std::string formatField(const std::string& field)
{
    if (field.length() > 10)
        return field.substr(0, 9) + ".";
    return field;
}

void PhoneBook::printAllContacts()
{
    std::cout << "     index|first name| last name|  nickname" << std::endl;
    for (int i = 0; i < 8; i++)
    {
        if (_contacts[i].getFirstName().empty())
            continue;
        std::cout << std::setw(10) << std::right << i << "|";
        std::cout << std::setw(10) << std::right << formatField(_contacts[i].getFirstName()) << "|";
        std::cout << std::setw(10) << std::right << formatField(_contacts[i].getLastName()) << "|";
        std::cout << std::setw(10) << std::right << formatField(_contacts[i].getNickName());
    }
}


//      //C libraries:
//     // std::clearerr(stdin); // !!!This is C!!! Reset file state
//     // std::freopen("/dev/tty", "r", stdin); // Reopen stdin
//     // clearerr(stdin); // 

//     // CPP but cant clear lingering EOF flag
//     // std::cin.clear();       // Reset C++ stream state
//     // std::cin.sync(); // syncs the two buffers??? Clear the buffer only if loaded ctl+d doesnt work
//      // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
