/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:18:14 by thibnguy          #+#    #+#             */
/*   Updated: 2024/03/04 14:29:53 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// Default constructor
Bureaucrat::Bureaucrat() : name("Default"), grade(1) {
	std::cout << "\033[1;32m" << *this << " has been created.\033[0m" << std::endl;
}

// Parameterize constructor
Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name) {
	if (grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	} else if (grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	this->grade = grade;
	std::cout << "\033[1;32m" << *this << " has been created.\033[0m" << std::endl;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {
	std::cout << "\033[1;32m" << *this << " has been copied.\033[0m" << std::endl;
}

// Destructor
Bureaucrat::~Bureaucrat() {
	std::cout << "\033[1;31m" << *this << " has been destroyed.\033[0m" << std::endl;
}

// Assignement operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		this->grade = other.grade;
	}
	return *this;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low.";
}

const std::string& Bureaucrat::getName() const {
	return name;
}

int Bureaucrat::getGrade() const {
	return grade;
}

void Bureaucrat::incrementGrade() {
	if (grade <= 1) {
		throw GradeTooHighException();
	}
	--grade;
}

void Bureaucrat::decrementGrade() {
	if (grade >= 150) {
		throw GradeTooLowException();
	}
	++grade;
}

void Bureaucrat::signForm(AForm& aform) {
	try {
		aform.beSigned(*this);
		std::cout << name << " signed " << aform.getName() << std::endl;
	} catch (std::exception& e) {
		std::cout << name << " couldn't sign " << aform.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) {
	try {
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	} catch (std::exception & e) {
		std::cerr << this->getName() << " couldn't execute " << form.getName()
				  << " because: " << e.what() << std::endl;
	}
}


std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}
