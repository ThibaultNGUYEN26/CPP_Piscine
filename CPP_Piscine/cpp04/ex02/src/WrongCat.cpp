/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 23:48:57 by thibault          #+#    #+#             */
/*   Updated: 2023/12/06 23:48:58 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	std::cout << "A wrong cat has been created." << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	std::cout << "A wrong cat has been copied." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	if (this != &other) {
		WrongAnimal::operator=(other);
	}
	std::cout << "A wrong cat has been assigned." << std::endl;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "A wrong cat has been destroyed." << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "Incorrect cat sound!" << std::endl;
}