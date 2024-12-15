/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:24:47 by fandre-b          #+#    #+#             */
/*   Updated: 2024/12/15 19:40:27 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    Harl    harl;
    
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] <<  " <level>" << std::endl;
        return 1;
    }
    harl.harlFilter(argv[1]);
    return 0;
}