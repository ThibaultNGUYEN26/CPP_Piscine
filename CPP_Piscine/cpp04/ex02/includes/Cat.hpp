/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 23:48:23 by thibault          #+#    #+#             */
/*   Updated: 2023/12/07 00:31:38 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "../includes/AAnimal.hpp"
#include "../includes/Brain.hpp"

class Cat : public AAnimal {

private:

	Brain* brain;

public:

	Cat();
	Cat(const Cat& other);
	Cat& operator=(const Cat& other);
	~Cat();

	Brain *getBrain() const;
	virtual void makeSound() const;

};

#endif