/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:31:20 by thibnguy          #+#    #+#             */
/*   Updated: 2024/03/04 14:14:45 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Form.hpp"

class Form;

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

	void				signForm(Form& form);

private:

	const std::string	name;
	int					grade;

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
