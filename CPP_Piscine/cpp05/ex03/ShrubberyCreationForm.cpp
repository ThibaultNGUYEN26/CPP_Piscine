/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:18:45 by thibnguy          #+#    #+#             */
/*   Updated: 2024/02/21 13:18:47 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Default Constructor
ShrubberyCreationForm::ShrubberyCreationForm() {
	std::cout << "\033[1;32mShrubberyCreationForm default created: " << this->getName() << "\033[0m" << std::endl;
}

// Parameterize constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {
		std::cout << "\033[1;32m" << "ShrubberyCreationForm for target: " << target << " has been created.\033[0m" << std::endl;
}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), target(other.target) {
	std::cout << "\033[1;32m" << "ShrubberyCreationForm copy created for target: " << target << ".\033[0m" << std::endl;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "\033[1;31m" << "ShrubberyCreationForm for target: " << target << " has been destroyed.\033[0m" << std::endl;
}

// Assignement operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (!getIsSigned()) {
		throw AForm::NotSignedException();
	}
	if (executor.getGrade() > getGradeRequiredToExecute()) {
		throw AForm::GradeTooLowException();
	}

	std::ofstream outfile((target + "_shrubbery").c_str());

	if (!outfile) {
		throw std::runtime_error("File could not be created");
	}

	// ASCII art for trees
	outfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣤⡾⠋⠷⣤⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	outfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⡆⣠⡰⡞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	outfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⢿⠏⣿⠗⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	outfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣿⣤⣘⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	outfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣴⡿⠁⢉⣟⠛⢷⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	outfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣟⣹⠉⠀⠈⣿⣌⡏⠀⢈⣹⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	outfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠰⣿⡥⢤⣆⣀⣵⣄⣑⣦⢬⣽⡷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	outfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣾⣁⣬⣽⣶⠿⢋⡬⣍⠀⠻⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	outfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣜⣿⠟⠛⠉⢉⣅⠀⠀⢸⣢⣸⠇⠀⠈⢽⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	outfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⡩⡓⠁⠀⠈⣯⣈⡟⠀⠀⠀⠀⠀⠀⠀⠀⠉⣽⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	outfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡟⠟⣀⣠⠀⢉⡀⠁⢀⠀⠀⡀⠀⢠⣀⠈⢻⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	outfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⢉⡿⠹⠷⠒⡿⠤⡖⠋⠓⠦⠽⠗⠺⠏⢻⡍⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	outfile << "⠀⠀⠀⠀⠀⠀⠀⠀⢠⣀⣠⢾⢷⣶⣤⣄⣀⣀⣀⣀⣀⣀⣀⣤⣴⣶⡾⠿⣦⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	outfile << "⠀⠀⠀⠀⠀⠀⠀⠀⢈⣿⢆⠅⠀⢀⣉⣉⠓⠛⠛⠛⠓⠒⡏⠉⠉⠀⠀⠀⠰⣿⡃⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	outfile << "⠀⠀⠀⠀⠀⠀⣤⡴⠞⠕⠁⠀⠀⢺⣿⣿⠆⠀⠀⠀⠐⡞⡙⡖⠀⠀⠀⠀⠀⠈⠛⠦⣤⡄⠀⠀⠀⠀⠀" << std::endl;
	outfile << "⠀⠀⠀⠀⠀⠀⠈⢛⣶⠞⢀⡀⠀⢀⠉⠁⠀⠀⠀⢀⠀⠋⠉⠃⠀⡀⠀⠀⣀⠘⢶⡞⠛⠀⠀⠀⠀⠀⠀" << std::endl;
	outfile << "⠀⠀⠀⠀⠀⠀⠀⣤⡿⠻⠿⠒⠚⠿⠴⠖⣯⠤⠔⠋⠳⣤⣼⡖⠦⠽⠓⠒⠾⠿⠻⣇⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	outfile << "⠀⠀⠀⠀⢰⣞⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣻⡀⠀⠀⣠⠾⢧⠀⠀⠈⠙⢓⣶⠀⠀⠀⠀" << std::endl;
	outfile << "⢠⡴⠶⠚⠋⠋⠁⠀⠀⠀⠀⠀⣴⠛⣦⠄⠀⠀⠀⣀⣀⠀⢻⣧⠀⠀⠻⣤⡼⠁⠀⠀⠀⠀⠉⠛⠲⢶⣤" << std::endl;
	outfile << "⠀⠙⠓⢷⡶⠂⠀⠀⠀⠀⠀⠀⠸⠒⠗⠀⠀⠀⢸⡁⢈⡇⠈⢿⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⢲⣖⠖⠛⠁" << std::endl;
	outfile << "⠀⠀⠀⠾⠷⣶⣏⣀⣀⣤⠆⠀⡀⠀⠀⠀⢠⠀⢀⣩⡉⠀⣄⠀⠻⣷⣄⡀⠀⢦⣄⣀⣘⣷⣶⠿⠀⠀⠀" << std::endl;
	outfile << "⠀⠀⠀⠀⠀⠉⠉⠉⠙⠛⠛⣿⣥⣤⠴⠾⠿⢾⡿⢿⣿⣷⠾⠗⢶⢬⣿⣿⠛⠚⠋⠉⠉⠉⠁⠀⠀⠀⠀" << std::endl;
	outfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠁⠀⠙⣿⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	outfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	outfile << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠒⠒⠒⠛⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;

	outfile.close();
	std::cout << "Shrubbery Creation Form executed by " << executor.getName() << std::endl;
}

const std::string& ShrubberyCreationForm::getTarget() const {
	return target;
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& s) {
	os << "ShrubberyCreationForm: [Target: " << s.getTarget() << ", Signed: " << (s.getIsSigned() ? "Yes" : "No") << ", Sign Grade: " << s.getGradeRequiredToSign() << ", Execute Grade: " << s.getGradeRequiredToExecute() << "]";
	return os;
}
