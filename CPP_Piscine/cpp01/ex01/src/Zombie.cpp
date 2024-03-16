/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:36:21 by thibault          #+#    #+#             */
/*   Updated: 2023/11/28 14:04:08 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie() {
	std::cout << WHITE << _name << RED " deleted" EOC << std::endl;
}

void Zombie::announce() const {
	std::cout << WHITE << this->_name << YELLOW " BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name(std::string name) {
	this->_name = name;
	std::cout << WHITE << this->_name << GREEN " created" EOC << std::endl;
}