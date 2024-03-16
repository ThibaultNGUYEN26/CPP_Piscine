/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:08:57 by thibault          #+#    #+#             */
/*   Updated: 2024/03/14 10:43:31 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

Harl::LogFunction Harl::logFunctions[] = {
	{"DEBUG", &Harl::debug},
	{"INFO", &Harl::info},
	{"WARNING", &Harl::warning},
	{"ERROR", &Harl::error},
};

Harl::Harl() {
	std::cout << WHITE "Harl " GREEN "created" EOC << std::endl;
}

Harl::~Harl() {
	std::cout << WHITE "Harl " RED "deleted" EOC << std::endl;
}

void Harl::debug() {
	std::cout << YELLOW "[ DEBUG ]\n" WHITE " I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" EOC << std::endl;
}

void Harl::info() {
	std::cout << YELLOW "[ INFO ]\n" WHITE " I cannot believe adding extra bacon costs more money.\nYou didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" EOC << std::endl;
}

void Harl::warning() {
	std::cout << YELLOW "[ WARNING ]\n" WHITE " I think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month." EOC << std::endl;
}

void Harl::error() {
	std::cout << YELLOW "[ ERROR ]\n" WHITE " This is unacceptable! I want to speak to the manager now." EOC << std::endl;
}

void Harl::complain(const std::string& level) {
	int start = 0;
	for (; start < 4; ++start) {
		if (logFunctions[start].level == level) {
			break;
		}
	}

	for (int i = start; i < 4; ++i) {
		(this->*(logFunctions[i].func))();
	}

	if (start == 4) {
		std::cout << WHITE "[ Probably complaining about insignificant problems ]" EOC << std::endl;
	}
}