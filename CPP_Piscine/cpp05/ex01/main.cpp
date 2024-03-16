/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:54:22 by thibnguy          #+#    #+#             */
/*   Updated: 2024/03/04 14:16:56 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main() {
	Bureaucrat bob("Bob", 2);
	Form formA("FormA", 5, 3);
	bob.signForm(formA);

	std::cout << "\nTrying to sign a form with higher requirements...\n" << std::endl;

	Bureaucrat alice("Alice", 150);
	Form formB("FormB", 1, 1);
	alice.signForm(formB);

	std::cout << "\n";

	return 0;
}
