/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:59:00 by fandre-b          #+#    #+#             */
/*   Updated: 2024/12/15 16:06:31 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void replaceOccurrences(const std::string& file_name, const std::string& s1, const std::string& s2) {
    // Open the file
    std::ifstream File_in(file_name.c_str());
    if (!File_in.is_open()) {
        std::cerr << "Error: Could not open file " << file_name << std::endl;
        return;
    }

    // Read the entire content of the file into a string
    std::string content((std::istreambuf_iterator<char>(File_in)), std::istreambuf_iterator<char>());
    File_in.close();

    // Replace occurrences of s1 with s2
    std::string::size_type pos = 0;
    while ((pos = content.find(s1, pos)) != std::string::npos) {
        content.erase(pos, s1.length());
        content.insert(pos, s2);
        pos += s2.length();
    }

    // Open the output file
    std::ofstream outputFile((file_name + ".replace").c_str());
    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not create file " << file_name << ".replace" << std::endl;
        return;
    }

    // Write the modified content to the output file
    outputFile << content;
    outputFile.close();
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <file_name> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string file_name = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty()) {
        std::cerr << "Error: <s1> needs an string" << std::endl;
        return 1;
    }

    replaceOccurrences(file_name, s1, s2);

    return 0;
}