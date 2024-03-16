/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:20:08 by thibnguy          #+#    #+#             */
/*   Updated: 2024/02/12 14:37:18 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat highRank("Alice", 1);
		std::cout << "\033[1;32m"
				  << "Success: Created " << highRank.getName() 
				  << " with grade " << highRank.getGrade() << ".\n"
				  << "\033[0m";
		
		highRank.incrementGrade();
	} catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << "Exception caught: " << e.what() << " - Attempted to increment grade beyond limit.\n";
	}

	std::cout << "\n";

	try {
		Bureaucrat lowRank("Bob", 150);
		std::cout << "\033[1;32m"
				  << "Success: Created " << lowRank.getName() 
				  << " with grade " << lowRank.getGrade() << ".\n"
				  << "\033[0m";
		
		lowRank.decrementGrade();
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << "Exception caught: " << e.what() << " - Attempted to decrement grade below limit.\n";
	}

	std::cout << "\n";

	try {
		Bureaucrat normal("Charlie", 75);
		std::cout << "\033[1;32m"
				  << "Success: Created " << normal.getName() 
				  << " with grade " << normal.getGrade() << ".\n"
				  << "\033[0m";
		normal.incrementGrade();
		std::cout << "After increment, " << normal << ".\n";
		
		normal.decrementGrade();
		std::cout << "After decrement, " << normal << ".\n";
	} catch (const std::exception& e) {
		std::cerr << "\033[1;31mUnexpected exception: " << e.what() << "\033[0m\n";
	}

	std::cout << "\n";

	Bureaucrat copyTarget("CopyTarget", 50);
	Bureaucrat copy(copyTarget);
	std::cout << copy << std::endl;
	Bureaucrat assignment("Assignment", 100);
	assignment = copyTarget;
	std::cout << assignment << std::endl;

	std::cout << "\n";
	Bureaucrat test;
	test = copyTarget;
	std::cout << test << std::endl;
	std::cout << "\n";

	return 0;
}
