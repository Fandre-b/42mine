/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:24:47 by fandre-b          #+#    #+#             */
/*   Updated: 2024/12/15 19:33:56 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main()
{
    Harl harl;
    harl.complain("DEBUG");
    std::cout << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl;
    harl.complain("INFO");
    std::cout << std::endl;
    harl.complain("ERROR");
    std::cout << std::endl;
    harl.complain("NOadadNE");
    return 0;
}