/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 00:04:13 by fandre-b          #+#    #+#             */
/*   Updated: 2025/04/09 17:18:42 by fandre-b         ###   ########.fr       */
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

bool PhoneBook::IsNumber(std::string input)
{
    for (size_t i = 0; i < input.length(); i++)
        if (!isdigit(input[i]))
            return false;
    return true;
}

void PhoneBook::searchContact()
{
    std::string input;
    int         index;

    printAllContacts();
    while (true)
    {
        std::cout << std::endl << "Enter index [1 - 8]: ";
        std::getline(std::cin, input);
        if (std::cin.eof())
            return;
        index = atoi(input.c_str());
        if (!IsNumber(input))
        {
            std::cout << "Invalid input: Not an valid number" << std::endl;
        }
        else if (index >= 1 && index <= 8)
        {
            index--;
            break;
        }
        else
            std::cout << "Invalid input: Out of range [1 - 8]" << std::endl;
    }
    if (_contacts[index].IsEmpty())
        std::cout << "ERROR: No contact at index " << index + 1 << std::endl;
    else
    {
        std::cout << std::endl << "index|first name| last name|  nickname" << std::endl;
        std::cout << "index: " << index + 1 << std::endl;
        _contacts[index].getContact();
    }
}

void PhoneBook::addContact() 
{
    int i;   
    
    i = 0;
    while (!_contacts[i].IsEmpty() && i < 8)
        i++;
    if (i == 8) {
        _removeContact(0);
        i = 7;
    }
    _contacts[i].SetContact();
    if (_contacts[i].IsEmpty())
    {
        _removeContact(i);
        return ;
    }
    std::cout << "Contact added, at index: " << i + 1 << std::endl;
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

void PhoneBook::printAllContacts()
{
    std::cout << "     index|first name| last name|  nickname" << std::endl << std::endl;
    for (int i = 0; i < 8; i++)
    {
        if (_contacts[i].IsEmpty())
            continue;
        std::cout << std::setw(10) << std::right << i + 1 << "|";
        _contacts[i].printContact();
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
