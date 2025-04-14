/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled-1                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 23:58:59 by fandre-b          #+#    #+#             */
/*   Updated: 2025/04/13 23:58:59 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <fstream>
#include <string>

void copy_replace(std::ofstream &fileOut, std::ifstream &fileIn, std::string s1, std::string s2)
{
	std::string line;

	while (std::getline(fileIn, line)) 
	{
		std::string::size_type pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos) 
		{
			line.replace(pos, s1.length(), s2);
			pos += s2.length();
		}

		fileOut << line << std::endl;
	}
}

int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		std::cerr << "Usage: ./replace <filename> <Find string> <Replace string>" << std::endl;
		return (1);
	}
	std::ifstream fileIn(argv[1]);
	if (!fileIn.is_open() || fileIn.fail())
	{
		std::cerr << "Error: could not open file " << "fileIn" << std::endl;
		return 1;
	}
	std::string outputFileName = std::string(argv[1]) + ".replace";
	std::ofstream fileOut(outputFileName.c_str());
	if (!fileOut.is_open() || fileOut.fail())
	{
		std::cerr << "Error: could not open file " << "fileOut" << std::endl;
		return 1;
	}

	copy_replace(fileOut, fileIn, argv[2], argv[3]);

	fileIn.close();
	fileOut.close();
}