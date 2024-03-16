/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:18:36 by thibnguy          #+#    #+#             */
/*   Updated: 2024/02/21 13:18:37 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Default Constructor
RobotomyRequestForm::RobotomyRequestForm() {
	std::cout << "\033[1;32mRobotomyRequestForm default created: " << this->getName() << "\033[0m" << std::endl;
}

// Parameterize constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 145, 137), target(target) {
		std::cout << "\033[1;32m" << "RobotomyRequestForm for target: " << target << " has been created.\033[0m" << std::endl;
}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), target(other.target) {
	std::cout << "\033[1;32m" << "RobotomyRequestForm copy created for target: " << target << ".\033[0m" << std::endl;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "\033[1;31m" << "RobotomyRequestForm for target: " << target << " has been destroyed.\033[0m" << std::endl;
}

// Assignement operator
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!getIsSigned()) {
		throw AForm::NotSignedException();
	}
	if (executor.getGrade() > getGradeRequiredToExecute()) {
		throw AForm::GradeTooLowException();
	}

	std::cout << "* drilling noises *" << std::endl;
	std::srand(std::time(0));
	if (std::rand() % 2) {
		std::cout << target << " has been robotomized successfully." << std::endl;
	} else {
		std::cout << "The robotomy on " << target << " failed." << std::endl;
	}
}

const std::string &RobotomyRequestForm::getTarget() const {
	return target;
}

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &r) {
	os << "RobotomyRequestForm: [Target: " << r.getTarget() << ", Signed: " << (r.getIsSigned() ? "Yes" : "No") << ", Sign Grade: " << r.getGradeRequiredToSign() << ", Execute Grade: " << r.getGradeRequiredToExecute() << "]";
	return os;
}
