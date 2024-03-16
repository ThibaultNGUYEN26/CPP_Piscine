/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:10:58 by thibault          #+#    #+#             */
/*   Updated: 2023/12/07 13:56:59 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "A dog has been created." << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "A dog has been copied." << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		Animal::operator=(other);
	}
	std::cout << "A dog has been assigned." << std::endl;
	return *this;
}

Dog::~Dog() {
	std::cout << "A dog has been destroyed." << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof!" << std::endl;
}