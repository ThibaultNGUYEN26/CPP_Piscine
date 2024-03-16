/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:48:58 by thibnguy          #+#    #+#             */
/*   Updated: 2024/02/16 11:58:38 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {

public:

	PresidentialPardonForm(); // Default constructor
	PresidentialPardonForm(const std::string& target); // Parameterize constructor
	PresidentialPardonForm(const PresidentialPardonForm &other); // Copy constructor
	~PresidentialPardonForm(); // Destructor

	PresidentialPardonForm& operator=(const PresidentialPardonForm& other); // Assignment operator

	void execute(Bureaucrat const & executor) const;

	const std::string& getTarget() const;

private:

	std::string target;

};

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& p);

#endif
