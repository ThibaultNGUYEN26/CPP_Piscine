/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:25:23 by thibnguy          #+#    #+#             */
/*   Updated: 2024/02/21 15:50:22 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern {

public:

	Intern(); // Default constructor
	Intern(const Intern &other); // Copy constructor
	~Intern(); // Destructor

	Intern& operator=(const Intern& other); // Assignment operator

	struct FormCreator {
		const char* name;
		AForm* (*create)(const std::string&);
	};

	AForm* makeForm(const std::string& formName, const std::string& target) const;

};

#endif
