/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 00:31:07 by fandre-b          #+#    #+#             */
/*   Updated: 2024/12/15 02:51:48 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"
# include <iostream>
# include <limits>

int main()
{
    PhoneBook phoneBook;
    std::string command;

    while (1)
    {
        std::cout<< std::endl << "Enter a command: " << std::endl;
        if (!(std::cin >> command)) // Check for EOF or input failure
        {
            if (std::cin.eof()) // Check if EOF is reached
            {
                std::cin.clear(); // Clear the error state
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the invalid input
                std::cerr << "End of input detected. Please enter a valid command." << std::endl;
            }
            else if (std::cin.fail()) // Check if input failure occurs
            {
                std::cin.clear(); // Clear the error state
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the invalid input
                std::cerr << "Invalid input. Please enter a valid command." << std::endl;
            }
        }
        else if (command == "ADD")
            phoneBook.addContact();
        else if (command == "SEARCH")
            phoneBook.searchContact();
        else if (command == "EXIT")
            break;
        else
            std::cout << "Invalid command" << std::endl;
    }
    return 0;
}