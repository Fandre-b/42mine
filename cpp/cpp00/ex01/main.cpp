/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 00:31:07 by fandre-b          #+#    #+#             */
/*   Updated: 2025/01/28 16:26:49 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"
#include <cstdio>

// std::string read_line(std::string ask_str)
// {
//     std::string input;
    
//     std::cout << ask_str << std::endl;
// 	std::getline(std::cin, input);
//     if (std::cin.eof()) 
//     {
//         std::cout << "EOF detected\n";
//         std::cin.clear(); // Clear the error state
//         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the invalid input
//         return("\n");
//     }
//     return input;    
// }

std::string read_line(const std::string& prompt)
{
    std::string command;

    // while (true) {
        std::cout << prompt;

        if (std::getline(std::cin, command)) {
            // Successfully read input
            if (!command.empty()) {
                std::cout << "You entered: " << command << '\n';
            } else {
                std::cerr << "Empty command. Please try again.\n";
            }
        } else {
            // Handle EOF or other errors
            if (std::cin.eof()) {

                // Clear the error and reset stdin
                // std::clearerr(stdin); // Reset file state
                // std::cerr << "\nEOF encountered. Reinitializing input stream...\n";
                std::cin.clear();       // Reset C++ stream state
                // Ignore any lingering input characters in the buffer
                std::freopen("/dev/tty", "r", stdin);
                // std::cin.clear();
                // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                std::cerr << "Input error. Resetting stream...\n";

                std::cin.clear(); // Reset C++ stream state
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    std::freopen("/dev/tty", "r", stdin);
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // }
    return command;
}


int main()
{
    PhoneBook phoneBook;
    std::string command;

    while (1)
    {
        std::cout<< std::endl;
        command = read_line("Enter a command: ");
        if (command == "ADD")
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
