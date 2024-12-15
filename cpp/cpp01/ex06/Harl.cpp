/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:30:03 by fandre-b          #+#    #+#             */
/*   Updated: 2024/12/15 19:42:31 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <string>
#include <iostream>

Harl::Harl()
{
    _levels[0] = "DEBUG";
    _levels[1] = "WARNING";
    _levels[2] = "INFO";
    _levels[3] = "ERROR";
    _levels[4] = "NONE";
    _functions[0] = &Harl::_debug;
    _functions[1] = &Harl::_info;
    _functions[2] = &Harl::_warning;
    _functions[3] = &Harl::_error;
    _functions[4] = &Harl::_none;
}

Harl::~Harl(){}

void Harl::complain(std::string level)
{
    int i = -1;
    while (++i < 4 && level.compare(_levels[i]));
    (this->*_functions[i])();
    
}

void Harl::harlFilter(std::string level)
{
    int i = -1;
    while (++i < 4 && level.compare(_levels[i]));
    while (i < 4)
    {
        std::cout << "[ " << _levels[i] << " ]" << std::endl;
        (this->*_functions[i++])();
        std::cout << std::endl;
    }
}

void Harl::_debug()
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
    std::cout << "I really do!" << std::endl;
    }

void Harl::_warning()
{
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
    std::cout << "You didn’t put enough bacon in my burger!" << std::endl;
    std::cout << "If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::_info()
{
    std::cout << "I think I deserve to have some extra bacon for free. " << std::endl;
    std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::_error()
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::_none(){}



