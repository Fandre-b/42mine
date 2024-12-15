/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 22:55:10 by fandre-b          #+#    #+#             */
/*   Updated: 2024/12/14 23:04:41 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

void print_argument(char *argument)
{
	while (*argument)
	{
		if (std::isalpha(*argument))
			std::cout << (char)std::toupper(*argument);
		else
			std::cout << *argument;
		argument++;
	}
}

int main(int argc, char **argv)
{
	char **args;

	args = ++argv;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (*args)
            print_argument(*(args++));
		std::cout << std::endl;
	}
	return (0);
}