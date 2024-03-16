/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:20:01 by thibault          #+#    #+#             */
/*   Updated: 2023/11/27 19:27:26 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

void Zombie::announce() const {
    std::cout << WHITE << this->_name << YELLOW " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie() {}

Zombie::Zombie(std::string name) : _name(name) {
    std::cout << WHITE << this->_name << GREEN " created" EOC << std::endl;
}

Zombie::~Zombie() {
    std::cout << WHITE << _name << RED " deleted" EOC << std::endl;
}