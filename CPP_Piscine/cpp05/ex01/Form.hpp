/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:24:27 by thibnguy          #+#    #+#             */
/*   Updated: 2024/02/13 10:34:44 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

public:

	Form(); // Default constructor
	Form(const std::string& name, int gradeRequiredToSign, int gradeRequiredToExecute); // Parameterize constructor
	Form(const Form &other); // Copy constructor
	~Form(); // Destructor

	Form& operator=(const Form& other); // Assignment operator

	const std::string& getName() const;
	bool getIsSigned() const;
	int getGradeRequiredToSign() const;
	int getGradeRequiredToExecute() const;

	void beSigned(const Bureaucrat &bureaucrat);

	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};

private:

	const std::string name;
	bool isSigned;
	const int gradeRequiredToSign;
	const int gradeRequiredToExecute;

};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif
