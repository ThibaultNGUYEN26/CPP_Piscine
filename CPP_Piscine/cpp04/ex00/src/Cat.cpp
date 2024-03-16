/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:43:49 by thibault          #+#    #+#             */
/*   Updated: 2023/12/07 13:57:02 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "A cat has been created." << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "A cat has been copied." << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		Animal::operator=(other);
	}
	std::cout << "A cat has been assigned." << std::endl;
	return *this;
}

Cat::~Cat() {
	std::cout << "A cat has been destroyed." << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}