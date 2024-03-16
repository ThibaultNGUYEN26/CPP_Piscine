/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 23:48:19 by thibault          #+#    #+#             */
/*   Updated: 2023/12/07 00:25:21 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>
#include "../includes/Brain.hpp"

class Animal {

protected:

	std::string type;

public:

	Animal(const std::string type = "Generic Animal");
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);
	virtual ~Animal();

	std::string getType() const;
	void setType(const std::string& type);
	Brain *getBrain() const;

	virtual void makeSound() const;

};

#endif