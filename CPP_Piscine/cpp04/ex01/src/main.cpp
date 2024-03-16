/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 23:48:50 by thibault          #+#    #+#             */
/*   Updated: 2023/12/07 00:16:47 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main()
{
	const int ANIMAL_COUNT = 10;
	
	if (ANIMAL_COUNT % 2 != 0) {
		std::cerr << "Error: ANIMAL_COUNT must be an even number" << std::endl;
		return 1;
	}

	Animal* animals[ANIMAL_COUNT];
	
	for (int i = 0; i < ANIMAL_COUNT / 2; ++i) {
		animals[i] = new Dog();
	}
	
	for (int i = ANIMAL_COUNT / 2; i < ANIMAL_COUNT; ++i) {
		animals[i] = new Cat();
	}

	std::cout << std::endl;

	Dog originalDog;
	originalDog.getBrain()->setIdea(0, "Chase the mailman");
	
	Dog copyDog(originalDog);
	std::cout << "Original Dog's first idea: " << originalDog.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy Dog's first idea: " << copyDog.getBrain()->getIdea(0) << std::endl;

	copyDog.getBrain()->setIdea(0, "Sleep on the couch");
	std::cout << "Original Dog's first idea (after copy's modification): " << originalDog.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy Dog's first idea (after modification): " << copyDog.getBrain()->getIdea(0) << std::endl;

	Cat originalCat;
	originalCat.getBrain()->setIdea(0, "Knock things off the table");
	
	Cat copyCat(originalCat);
	std::cout << "Original Cat's first idea: " << originalCat.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy Cat's first idea: " << copyCat.getBrain()->getIdea(0) << std::endl;

	copyCat.getBrain()->setIdea(0, "Chase the laser pointer");
	std::cout << "Original Cat's first idea (after copy's modification): " << originalCat.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy Cat's first idea (after modification): " << copyCat.getBrain()->getIdea(0) << std::endl;

	std::cout << std::endl;

	for (int i = 0; i < ANIMAL_COUNT; ++i) {
		delete animals[i];
	}

	return 0;
}