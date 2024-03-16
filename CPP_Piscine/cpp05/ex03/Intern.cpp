/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:25:21 by thibnguy          #+#    #+#             */
/*   Updated: 2024/03/04 14:36:06 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// Default constructor
Intern::Intern() {
	std::cout << "\033[1;32mIntern has been created.\033[1;0m" << std::endl;
}

// Copy constructor
Intern::Intern(const Intern &other) {
	(void)other;
	std::cout << "\033[1;32mIntern has been copied.\033[1;0m" << std::endl;
}

// Destructor
Intern::~Intern() {
	std::cout << "\033[1;31mIntern has been destroyed.\033[1;0m" << std::endl;
}

// Assignment operator
Intern& Intern::operator=(const Intern& other) {
	(void)other;
	std::cout << "\033[1;32mIntern has been assigned.\033[1;0m" << std::endl;
	return *this;
}

static AForm* createShrubberyCreationForm(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomyRequestForm(const std::string& target) {
	return new RobotomyRequestForm(target);
}

static AForm* createPresidentialPardonForm(const std::string& target) {
	return new PresidentialPardonForm(target);
}

static Intern::FormCreator formCreators[] = {
	{"ShrubberyCreation", &createShrubberyCreationForm},
	{"RobotomyRequest", &createRobotomyRequestForm},
	{"PresidentialPardon", &createPresidentialPardonForm},
	{NULL, NULL} // Sentinel to mark the end of the array
};

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
	for (int i = 0; formCreators[i].name != NULL; ++i) {
		if (formName == formCreators[i].name) {
			std::cout << "\033[1;34mIntern creates " << formName << "\033[1;0m" << std::endl;
			return formCreators[i].create(target);
		}
	}

	throw std::runtime_error("Intern failed to create form because the specified form name is unknown.");
	return NULL;
}
