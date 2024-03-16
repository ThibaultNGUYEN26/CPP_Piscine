/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:43:00 by thibnguy          #+#    #+#             */
/*   Updated: 2024/02/13 18:45:34 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

public:

	AForm(); // Default constructor
	AForm(const std::string& name, int gradeRequiredToSign, int gradeRequiredToExecute); // Parameterize constructor
	AForm(const AForm &other); // Copy constructor
	virtual ~AForm(); // Destructor

	AForm& operator=(const AForm& other); // Assignment operator

	virtual void execute(Bureaucrat const & executor) const = 0;

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

	class NotSignedException : public std::exception {
	public:
		const char* what() const throw();
	};

private:

	const std::string name;
	bool isSigned;
	const int gradeRequiredToSign;
	const int gradeRequiredToExecute;

};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
