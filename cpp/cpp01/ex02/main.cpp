/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:51:46 by fandre-b          #+#    #+#             */
/*   Updated: 2024/12/15 11:52:23 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Address of the string : " << &str << std::endl;
	std::cout << "    using stringPTR " << stringPTR << std::endl;
	std::cout << "    using stringREF " << &stringREF << std::endl;
	std::cout << "Content of the string : " << str << std::endl;
	std::cout << "    using stringPTR " << *stringPTR << std::endl;
	std::cout << "    using stringREF " << stringREF << std::endl;

	return (0);
}