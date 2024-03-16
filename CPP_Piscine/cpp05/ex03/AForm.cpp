/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:18:06 by thibnguy          #+#    #+#             */
/*   Updated: 2024/02/21 13:18:07 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Default constructor
AForm::AForm() : name("Default"), isSigned(false), gradeRequiredToSign(1), gradeRequiredToExecute(1) {
	std::cout << "\033[1;32m" << *this << " has been created.\033[0m" << std::endl;
}

// Parameterized constructor
AForm::AForm(const std::string& name, int gradeRequiredToSign, int gradeRequiredToExecute) : name(name), isSigned(false), gradeRequiredToSign(gradeRequiredToSign), gradeRequiredToExecute(gradeRequiredToExecute) {
	if (gradeRequiredToSign < 1 || gradeRequiredToExecute < 1) {
		throw GradeTooHighException();
	}
	if (gradeRequiredToSign > 150 || gradeRequiredToExecute > 150) {
		throw GradeTooLowException();
	}
	std::cout << *this << " has been created." << std::endl;
}

// Copy constructor
AForm::AForm(const AForm &other) : name(other.name), isSigned(other.isSigned), gradeRequiredToSign(other.gradeRequiredToSign), gradeRequiredToExecute(other.gradeRequiredToExecute) {
	std::cout << *this << " has been copied." << std::endl;
}

// Destructor
AForm::~AForm() {
	std::cout << "\033[1;31m" << *this << " has been destroyed.\033[0m" << std::endl;
}

// Assignement operator
AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		isSigned = other.isSigned;
	}
	return *this;
}

const std::string& AForm::getName() const {
	return name;
}

bool AForm::getIsSigned() const {
	return isSigned;
}

int AForm::getGradeRequiredToSign() const {
	return gradeRequiredToSign;
}

int AForm::getGradeRequiredToExecute() const {
	return gradeRequiredToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->gradeRequiredToSign) {
		throw GradeTooLowException();
	}
	this->isSigned = true;
	std::cout << "AForm " << name << " has been signed." << std::endl;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade too high.";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade too low.";
}

const char* AForm::NotSignedException::what() const throw() {
	return "Form not signed.";
}

std::ostream& operator<<(std::ostream &os, const AForm &aform) {
	os << "AForm " << aform.getName() << " (Sign: " << (aform.getIsSigned() ? "Yes" : "No") << ", Sign grade: " << aform.getGradeRequiredToSign() << ", Execute grade: " << aform.getGradeRequiredToExecute() << ")";
	return os;
}
