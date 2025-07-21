/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:51:46 by fandre-b          #+#    #+#             */
/*   Updated: 2025/04/03 17:27:22 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	//TODO makes sure its correct
	std::string	str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "Address of the string : " << &str << std::endl;
	std::cout << "    using string PTR :" << stringPTR << std::endl;
	std::cout << "    using string REF :" << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "Content of the string : " << str << std::endl;
	std::cout << "    using string PTR :" << *stringPTR << std::endl;
	std::cout << "    using string REF :" << stringREF << std::endl;

	return (0);
}