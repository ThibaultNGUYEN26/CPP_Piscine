/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:21:46 by thibnguy          #+#    #+#             */
/*   Updated: 2024/03/10 19:37:50 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "[USAGE] : ./RPN \"{operations}\"" << std::endl;
	}

	std::string arg = argv[1];
	std::cout << RPN::parseExpression(arg) << std::endl;

	return 0;
}
