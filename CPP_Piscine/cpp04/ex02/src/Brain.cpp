/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 23:49:25 by thibault          #+#    #+#             */
/*   Updated: 2023/12/07 00:18:46 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain() {
	for (int i = 0; i < 100; ++i) {
		ideas[i] = "Idea " + std::string(1, '0' + i);
	}
	std::cout << "A brain has been created." << std::endl;
}

Brain::Brain(const Brain& other) {
    for (int i = 0; i < 100; ++i) {
        ideas[i] = other.ideas[i];
    }
	std::cout << "A brain has been copied." << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
    if (this != &other) {
        for (int i = 0; i < 100; ++i) {
            ideas[i] = other.ideas[i];
        }
    }
	std::cout << "A brain has been assigned." << std::endl;
    return *this;
}

Brain::~Brain() {
    std::cout << "A brain has been destroyed." << std::endl;;
}

void Brain::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100) {
        ideas[index] = idea;
    }
	std::cout << "An idea has been set." << std::endl;
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100) {
        return ideas[index];
    }
    return "";
}