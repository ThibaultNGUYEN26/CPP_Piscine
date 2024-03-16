/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 23:48:47 by thibault          #+#    #+#             */
/*   Updated: 2023/12/07 13:56:21 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog() : AAnimal("Dog"), brain(new Brain()) {
	std::cout << "A dog has been created." << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other), brain(new Brain(*(other.brain))) {
	std::cout << "A dog has been copied." << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		AAnimal::operator=(other);
		brain = new Brain(*(other.brain));
	}
	std::cout << "A dog has been assigned." << std::endl;
	return *this;
}

Dog::~Dog() {
	delete brain;
	std::cout << "A dog has been destroyed." << std::endl;
}

Brain* Dog::getBrain(void) const {
	return (brain);
}

void Dog::makeSound() const {
	std::cout << "Woof!" << std::endl;
}