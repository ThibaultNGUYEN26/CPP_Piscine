/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:05:18 by thibault          #+#    #+#             */
/*   Updated: 2023/12/06 23:45:22 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main() {
    Animal* myAnimal = new Animal();
    myAnimal->makeSound();
    delete myAnimal;

    std::cout << std::endl;

    Animal* myDog = new Dog();
    myDog->makeSound();
    delete myDog;

    std::cout << std::endl;

    Animal* myCat = new Cat();
    myCat->makeSound();
    delete myCat;

    std::cout << std::endl;

    WrongAnimal* myWrongAnimal = new WrongAnimal();
    myWrongAnimal->makeSound();
    delete myWrongAnimal;

    std::cout << std::endl;

    WrongCat* myWrongCat = new WrongCat();
    myWrongCat->makeSound();
    delete myWrongCat;

    std::cout << std::endl;

    WrongAnimal* myWrongAnimalCat = new WrongCat();
    myWrongAnimalCat->makeSound();
    delete myWrongAnimalCat;

    std::cout << std::endl;

    return 0;
}