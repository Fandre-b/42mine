/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 00:31:07 by fandre-b          #+#    #+#             */
/*   Updated: 2025/01/10 19:31:30 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

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

    std::cout << prompt << std::endl;
    std::getline(std::cin, command);
    if (std::cin.eof())
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the invalid input
        std::cin.clear(); // Clear the error state
        std::cerr << "Invalid input (EOF). Please enter a valid command:" << std::endl;
        command.clear();
        command = "";
    }
    else if (std::cin.fail()) // Check if input failure occurs
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the invalid input
        std::cin.clear(); // Clear the error state
        std::cerr << "Invalid input. Please enter a valid command:" << std::endl;
        command.clear();
        command = "";

    }
    else if (command.empty()) // Handle empty input (if applicable)
        std::cout << "Command cannot be empty. Please try again:" << std::endl;
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
