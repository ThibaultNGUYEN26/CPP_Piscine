/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 23:20:31 by thibault          #+#    #+#             */
/*   Updated: 2023/12/06 23:34:54 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(const std::string type) : type(type) {
	std::cout << "A wrong animal has been created." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
	std::cout << "A wrong animal has been copied." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other) {
		type = other.type;
	}
	std::cout << "A wrong animal has been assigned." << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "An animal of type " << type << " has been destroyed." << std::endl;
}

std::string WrongAnimal::getType() const {
	return type;
}

void WrongAnimal::setType(const std::string& type) {
	std::cout << "A wrong animal has been set to " << type << std::endl;
	this->type = type;
}

void WrongAnimal::makeSound() const {
	std::cout << "Incorrect animal sound!" << std::endl;
}