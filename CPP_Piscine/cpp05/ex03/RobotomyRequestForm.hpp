/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:18:41 by thibnguy          #+#    #+#             */
/*   Updated: 2024/02/21 13:18:42 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm : public AForm {

public:

	RobotomyRequestForm(); // Default constructor
	RobotomyRequestForm(const std::string& target); // Parameterize constructor
	RobotomyRequestForm(const RobotomyRequestForm &other); // Copy constructor
	~RobotomyRequestForm(); // Destructor

	RobotomyRequestForm& operator=(const RobotomyRequestForm& other); // Assignment operator

	void execute(Bureaucrat const & executor) const;

	const std::string& getTarget() const;

private:

	std::string target;

};

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& r);

#endif
