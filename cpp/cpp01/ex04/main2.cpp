/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:09:05 by fandre-b          #+#    #+#             */
/*   Updated: 2025/03/21 12:43:47 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#define ARGS 0
#define INPUT 1
#define OUTPUT 2

int	printError(int err)
{
	if (err == ARGS)
		std::cerr << "Error : wrong number of arguments, use ./replace file s1 s2" << std::endl;
	else if (err == INPUT)
		std::cerr << "Error : input file" << std::endl;
	else if (err == OUTPUT)
		std::cerr << "Error : output file" << std::endl;
	return (1);
}

void	replaceStrings(std::ofstream &fileOut, std::string s1, std::string s2, std::string input)
{
	size_t	pos;
	size_t	toSkip;

	pos = input.find(s1);
	if (pos == std::string::npos)
	{
		fileOut << input;
		return ;
	}
	else
	{
		fileOut << input.substr(0, pos);
		fileOut << s2;
		toSkip = pos + s1.length();
		replaceStrings(fileOut, s1, s2, input.substr(toSkip));
	}
}

int	main(int argc, char **argv)
{
	std::ifstream	fileIn;
	std::ofstream	fileOut;
	std::string		s1;
	std::string		s2;
	std::string		buff;
	std::string		file;
	std::string		fileReplace;

	if (argc != 4)
		return (printError(ARGS));
	
	s1 = argv[2];
	s2 = argv[3];
	
	file = argv[1];
	fileIn.open(file.c_str());
	if (fileIn.good() == false)
		return (printError(INPUT));
	
	fileReplace = file + ".replace";
	fileOut.open(fileReplace.c_str());
	if (fileOut.good() == false)
	{
		fileIn.close();
		return (printError(OUTPUT));
	}

	while (getline(fileIn, buff))
		replaceStrings(fileOut, s1, s2, buff + '\n');
	
	fileIn.close();
	fileOut.close();
	return (0);
}