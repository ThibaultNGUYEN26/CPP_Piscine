/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 23:48:28 by thibault          #+#    #+#             */
/*   Updated: 2023/12/07 00:31:40 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "../includes/AAnimal.hpp"
#include "../includes/Brain.hpp"

class Dog : public AAnimal {

private:

	Brain* brain;

public:

	Dog();
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);
	~Dog();
	
	Brain *getBrain() const;
	virtual void makeSound() const;

};

#endif