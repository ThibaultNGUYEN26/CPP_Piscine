/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 23:48:40 by thibault          #+#    #+#             */
/*   Updated: 2023/12/07 00:30:31 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AAnimal.hpp"

AAnimal::AAnimal(const std::string type) : type(type) {
	std::cout << "A generic abstract animal has been created." << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : type(other.type) {
	std::cout << "A generic abstract animal has been copied." << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
	if (this != &other) {
		type = other.type;
	}
	std::cout << "A generic abstract animal has been assigned." << std::endl;
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "An abstract animal of type " << type << " has been destroyed." << std::endl;
}

std::string AAnimal::getType() const {
	return type;
}

void AAnimal::setType(const std::string& type) {
	std::cout << "A generic abstract animal has been set to " << type << std::endl;
	this->type = type;
}

Brain* AAnimal::getBrain(void) const {
	return (NULL);
}

void AAnimal::makeSound() const {
	std::cout << "Some generic animal sound" << std::endl;
}