/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 23:48:43 by thibault          #+#    #+#             */
/*   Updated: 2023/12/07 13:56:41 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat() : Animal("Cat"), brain(new Brain) {
	std::cout << "A cat has been created." << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain (*(other.brain))) {
	std::cout << "A cat has been copied." << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		Animal::operator=(other);
		brain = new Brain(*(other.brain));
	}
	std::cout << "A cat has been assigned." << std::endl;
	return *this;
}

Cat::~Cat() {
	delete brain;
	std::cout << "A cat has been destroyed." << std::endl;
}

Brain* Cat::getBrain(void) const {
	return (brain);
}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}