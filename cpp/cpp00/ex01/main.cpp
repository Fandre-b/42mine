/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 00:31:07 by fandre-b          #+#    #+#             */
/*   Updated: 2025/04/05 22:32:13 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

int main()
{
    PhoneBook phoneBook;
    std::string command;

    while (1)
    {
        std::cout << std::endl << "Insert Command: ";
        std::getline(std::cin, command);
        if (std::cin.eof())
        {
            std::cerr << "ERROR: EOF detected" << std::endl;
            break;
        }
        else if (command == "ADD")
            phoneBook.addContact();
        else if (command == "SEARCH")
            phoneBook.searchContact();
        else if (command == "EXIT")
            break;
        else if (command.empty())
            std::cerr << "Invalid input: Empty command" << std::endl;
        else
            std::cerr << "Invalid input: Command not valid" << std::endl;
    }
    return 0;
}
