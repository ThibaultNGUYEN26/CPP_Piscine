/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:18:28 by thibnguy          #+#    #+#             */
/*   Updated: 2024/02/21 13:18:30 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Default Constructor
PresidentialPardonForm::PresidentialPardonForm() {
	std::cout << "\033[1;32mPresidentialPardonForm default created: " << this->getName() << "\033[0m" << std::endl;
}

// Parameterize constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 145, 137), target(target) {
		std::cout << "\033[1;32m" << "PresidentialPardonForm for target: " << target << " has been created.\033[0m" << std::endl;
}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), target(other.target) {
	std::cout << "\033[1;32m" << "PresidentialPardonForm copy created for target: " << target << ".\033[0m" << std::endl;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "\033[1;31m" << "PresidentialPardonForm for target: " << target << " has been destroyed.\033[0m" << std::endl;
}

// Assignement operator
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (!getIsSigned()) {
		throw NotSignedException();
	}
	if (executor.getGrade() > getGradeRequiredToExecute()) {
		throw GradeTooLowException();
	}
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

const std::string& PresidentialPardonForm::getTarget() const {
	return target;
}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& p) {
	os << "PresidentialPardonForm: [Target: " << p.getTarget() << ", Signed: " << (p.getIsSigned() ? "Yes" : "No") << ", Sign Grade: " << p.getGradeRequiredToSign() << ", Execute Grade: " << p.getGradeRequiredToExecute() << "]";
	return os;
}
