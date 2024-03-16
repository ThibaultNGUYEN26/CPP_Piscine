/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:07:06 by thibault          #+#    #+#             */
/*   Updated: 2023/12/06 23:34:11 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal(const std::string type) : type(type) {
	std::cout << "A generic animal has been created." << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {
	std::cout << "A generic animal has been copied." << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
	if (this != &other) {
		type = other.type;
	}
	std::cout << "A generic animal has been assigned." << std::endl;
	return *this;
}

Animal::~Animal() {
	std::cout << "An animal of type " << type << " has been destroyed." << std::endl;
}

std::string Animal::getType() const {
	return type;
}

void Animal::setType(const std::string& type) {
	std::cout << "A generic animal has been set to " << type << std::endl;
	this->type = type;
}

void Animal::makeSound() const {
	std::cout << "Some generic animal sound" << std::endl;
}