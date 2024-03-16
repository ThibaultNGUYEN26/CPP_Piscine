/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:35:47 by thibnguy          #+#    #+#             */
/*   Updated: 2024/03/04 14:23:38 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	Bureaucrat highGradeBureaucrat("HighGrade", 1);
	Bureaucrat lowGradeBureaucrat("LowGrade", 150);
	ShrubberyCreationForm shrubberyForm("Garden");
	RobotomyRequestForm robotomyForm("Employee");
	PresidentialPardonForm pardonForm("Criminal");
	
	std::cout << "\n";

	try {
		highGradeBureaucrat.signForm(shrubberyForm);
		highGradeBureaucrat.executeForm(shrubberyForm);
	} catch (std::exception& e) {
		std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;
	}

	try {
		highGradeBureaucrat.signForm(robotomyForm);
		highGradeBureaucrat.executeForm(robotomyForm);
	} catch (std::exception& e) {
		std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;
	}

	try {
		highGradeBureaucrat.signForm(pardonForm);
		highGradeBureaucrat.executeForm(pardonForm);
	} catch (std::exception& e) {
		std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;
	}

	std::cout << "\n";

	return 0;
}