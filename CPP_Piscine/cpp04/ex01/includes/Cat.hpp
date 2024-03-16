/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 23:48:23 by thibault          #+#    #+#             */
/*   Updated: 2023/12/07 13:58:06 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "../includes/Animal.hpp"
#include "../includes/Brain.hpp"

class Cat : public Animal {

private:

	Brain* brain;

public:

	Cat();
	Cat(const Cat& other);
	Cat& operator=(const Cat& other);
	~Cat();

	Brain *getBrain() const;
	void makeSound() const;

};

#endif