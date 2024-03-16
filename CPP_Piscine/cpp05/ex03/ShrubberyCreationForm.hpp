/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:18:50 by thibnguy          #+#    #+#             */
/*   Updated: 2024/02/21 13:18:52 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

public:

	ShrubberyCreationForm(); // Default constructor
	ShrubberyCreationForm(const std::string& target); // Parameterize constructor
	ShrubberyCreationForm(const ShrubberyCreationForm &other); // Copy constructor
	~ShrubberyCreationForm(); // Destructor

	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other); // Assignment operator

	void execute(Bureaucrat const & executor) const;

	const std::string& getTarget() const;

private:

	std::string target;

};

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& s);

#endif
