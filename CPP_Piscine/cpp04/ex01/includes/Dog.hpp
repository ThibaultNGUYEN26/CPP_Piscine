/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 00:20:02 by thibault          #+#    #+#             */
/*   Updated: 2023/12/07 13:58:09 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "../includes/Animal.hpp"
#include "../includes/Brain.hpp"

class Dog : public Animal {

private:

	Brain* brain;

public:

	Dog();
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);
	~Dog();
	
	Brain *getBrain() const;
	void makeSound() const;

};

#endif