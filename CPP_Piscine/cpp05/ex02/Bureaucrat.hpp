/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:43:06 by thibnguy          #+#    #+#             */
/*   Updated: 2024/02/13 18:43:45 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include <fstream>
# include "AForm.hpp"

class AForm;

class Bureaucrat {

public:

	Bureaucrat(); // Default constructor
	Bureaucrat(const std::string& name, int grade); // Parameterize constructor
	Bureaucrat(const Bureaucrat &src); // Copy constructor
	~Bureaucrat(); // Destructor

	Bureaucrat& operator=(const Bureaucrat& other); // Assignment operator

	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};

	const std::string&	getName() const;
	int					getGrade() const;
	
	void				incrementGrade();
	void				decrementGrade();

	void				signForm(AForm& aform);
	void				executeForm(AForm const & Form);

private:

	const std::string	name;
	int					grade;

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
