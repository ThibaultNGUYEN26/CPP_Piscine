/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:21:00 by thibault          #+#    #+#             */
/*   Updated: 2023/11/29 18:21:52 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

Harl::Harl() {
	logFunctions[0].level = "DEBUG";
	logFunctions[0].func = &Harl::debug;

	logFunctions[1].level = "INFO";
	logFunctions[1].func = &Harl::info;

	logFunctions[2].level = "WARNING";
	logFunctions[2].func = &Harl::warning;

	logFunctions[3].level = "ERROR";
	logFunctions[3].func = &Harl::error;

	std::cout << WHITE "Harl" GREEN " created" EOC <<  std::endl;
}

Harl::~Harl() {
	std::cout << WHITE "Harl" RED " deleted" EOC <<  std::endl;
}

void Harl::complain(std::string level) {
	for (int i = 0; i < 4; ++i) {
		if (logFunctions[i].level == level) {
			(this->*(logFunctions[i].func))();
			return;
		}
	}
	std::cout << RED "Unknown complaint level" WHITE ": " << level << EOC << std::endl;
}

void Harl::debug() {
	std::cout << YELLOW "DEBUG" WHITE ": I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" EOC << std::endl;
}

void Harl::info() {
	std::cout << YELLOW "INFO" WHITE ": I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" EOC << std::endl;
}

void Harl::warning() {
	std::cout << YELLOW "WARNING" WHITE ": I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." EOC << std::endl;
}

void Harl::error() {
	std::cout << YELLOW "ERROR" WHITE ": This is unacceptable! I want to speak to the manager now." EOC << std::endl;
}