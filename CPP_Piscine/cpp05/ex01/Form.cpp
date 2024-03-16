/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:33:45 by thibnguy          #+#    #+#             */
/*   Updated: 2024/03/04 14:19:03 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Default constructor
Form::Form() : name("Default"), isSigned(false), gradeRequiredToSign(1), gradeRequiredToExecute(1) {
	std::cout << "\033[1;32m" << *this << " has been created.\033[0m" << std::endl;
}

// Parameterized constructor
Form::Form(const std::string& name, int gradeRequiredToSign, int gradeRequiredToExecute) : name(name), isSigned(false), gradeRequiredToSign(gradeRequiredToSign), gradeRequiredToExecute(gradeRequiredToExecute) {
	if (gradeRequiredToSign < 1 || gradeRequiredToExecute < 1) {
		throw GradeTooHighException();
	}
	if (gradeRequiredToSign > 150 || gradeRequiredToExecute > 150) {
		throw GradeTooLowException();
	}
	std::cout << *this << " has been created." << std::endl;
}

// Copy constructor
Form::Form(const Form &other) : name(other.name), isSigned(other.isSigned), gradeRequiredToSign(other.gradeRequiredToSign), gradeRequiredToExecute(other.gradeRequiredToExecute) {
	std::cout << *this << " has been copied." << std::endl;
}

// Destructor
Form::~Form() {
	std::cout << "\033[1;31m" << *this << " has been destroyed.\033[0m" << std::endl;
}

// Assignement operator
Form& Form::operator=(const Form& other) {
	if (this != &other) {
		isSigned = other.isSigned;
	}
	return *this;
}

const std::string& Form::getName() const {
	return name;
}

bool Form::getIsSigned() const {
	return isSigned;
}

int Form::getGradeRequiredToSign() const {
	return gradeRequiredToSign;
}

int Form::getGradeRequiredToExecute() const {
	return gradeRequiredToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->gradeRequiredToSign) {
		throw GradeTooLowException();
	}
	this->isSigned = true;
	std::cout << "\033[34mForm " << name << " has been signed.\033[0m" << std::endl;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade too high.";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade too low.";
}

std::ostream& operator<<(std::ostream &os, const Form &form) {
	os << "Form " << form.getName() << " (Sign: " << (form.getIsSigned() ? "Yes" : "No") << ", Sign grade: " << form.getGradeRequiredToSign() << ", Execute grade: " << form.getGradeRequiredToExecute() << ")";
	return os;
}
