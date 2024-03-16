/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:43:03 by thibault          #+#    #+#             */
/*   Updated: 2023/11/29 15:43:21 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/replace.hpp"

bool isStringInFile(const std::string& filename, const std::string& s) {
    std::ifstream file(filename.c_str());
    if (!file) {
        std::cerr << RED "[ERROR] Unable to open input file" WHITE ": " << filename << EOC << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.find(s) != std::string::npos) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

void replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2) {
    std::ifstream inputFile(filename.c_str());

    std::string content, line;
    while (std::getline(inputFile, line)) {
        content += line + '\n';
    }
    inputFile.close();

    size_t startPos = 0;
    while ((startPos = content.find(s1, startPos)) != std::string::npos) {
        content = content.substr(0, startPos) + s2 + content.substr(startPos + s1.length());
        startPos += s2.length();
    }

    std::ofstream outputFile((filename + ".replace").c_str());
    if (!outputFile) {
        std::cerr << RED "[ERROR] Unable to create output file" WHITE ": " << filename << EOC << std::endl;
        return;
    }

    outputFile << content;
    outputFile.close();

    std::cout << GREEN "File replaced successfully in " << filename << ".replace!" << EOC << std::endl;
}