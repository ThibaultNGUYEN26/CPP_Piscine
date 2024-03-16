/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:42:27 by thibault          #+#    #+#             */
/*   Updated: 2023/11/29 15:45:20 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/replace.hpp"

int main(int argc, char *argv[])
{
    std::string filename, s1, s2;

    if (argc != 4) {
        std::cout << YELLOW "[Usage] : ./replace <inputFile> <s1> <s2>" EOC << std::endl;
        return 0;
    }

    filename = argv[1];
    std::ifstream inputFile(filename.c_str());
    if (!inputFile) {
        std::cerr << RED "[ERROR] Unable to open input file" WHITE ": " << filename << EOC << std::endl;
        return 0;
    }

    s1 = argv[2];
    if (!isStringInFile(filename, s1)) {
        std::cerr << RED "[ERROR] The string " WHITE "'" << s1 << "'" RED " not found in file." EOC << std::endl;
        return 0;
    }

    s2 = argv[3];

    replaceInFile(filename, s1, s2);

    return 0;
}
