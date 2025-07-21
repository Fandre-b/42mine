/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:22:15 by fandre-b          #+#    #+#             */
/*   Updated: 2024/12/15 19:34:00 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# include <string>

class Harl
{
private:
    std::string *complaints;
    void _debug();
    void _warning(); 
    void _info();
    void _error();
    void _none();
    std::string _levels[5];
    void (Harl::* _functions[5]) ();
public:
    Harl();
    ~Harl();
    void complain(std::string level);
};

#endif