/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 23:48:19 by thibault          #+#    #+#             */
/*   Updated: 2023/12/07 00:29:08 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>
#include "../includes/Brain.hpp"

class AAnimal {

protected:

	std::string type;

public:

	AAnimal(const std::string type = "Generic Animal");
	AAnimal(const AAnimal& other);
	AAnimal& operator=(const AAnimal& other);
	virtual ~AAnimal();

	std::string getType() const;
	void setType(const std::string& type);
	Brain* getBrain(void) const;

	virtual void makeSound() const = 0;

};

#endif