/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:18:23 by thibnguy          #+#    #+#             */
/*   Updated: 2024/03/04 14:36:18 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main() {
    Intern intern;

    Bureaucrat john("John Doe", 5);

    AForm* form1 = intern.makeForm("ShrubberyCreation", "Home");
    AForm* form2 = intern.makeForm("RobotomyRequest", "Bender");
    AForm* form3 = intern.makeForm("PresidentialPardon", "Zaphod Beeblebrox");

    if (form1) {
        john.signForm(*form1);
        john.executeForm(*form1);
        delete form1;
    }

    if (form2) {
        john.signForm(*form2);
        john.executeForm(*form2);
        delete form2;
    }

    if (form3) {
        john.signForm(*form3);
        john.executeForm(*form3);
        delete form3;
    }

    try {
        AForm* unknownForm = intern.makeForm("UnknownForm", "Nowhere");
        if (unknownForm) {
            john.signForm(*unknownForm);
            john.executeForm(*unknownForm);
            delete unknownForm;
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
