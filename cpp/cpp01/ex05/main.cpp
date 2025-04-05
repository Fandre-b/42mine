/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:24:47 by fandre-b          #+#    #+#             */
/*   Updated: 2025/04/02 16:47:58 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

// int main()
// {
//     Harl harl;
//     harl.complain("DEBUG");
//     std::cout << std::endl;
//     harl.complain("WARNING");
//     std::cout << std::endl;
//     harl.complain("INFO");
//     std::cout << std::endl;
//     harl.complain("ERROR");
//     std::cout << std::endl;
//     harl.complain("NOadadNE");
//     return 0;
// }

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./complain Levels: DEBUG, WARNING, INFO, ERROR" << std::endl;
        return 1;
    }
    Harl harl;
    harl.complain(argv[1]);
    return 0;
}