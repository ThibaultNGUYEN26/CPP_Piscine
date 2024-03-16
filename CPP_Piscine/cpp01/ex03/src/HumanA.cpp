/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:42:38 by thibault          #+#    #+#             */
/*   Updated: 2023/11/29 16:18:53 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon) : _name(name), _weapon(weapon) {
	std::cout << GREEN << _name << " created." EOC << std::endl;
}

void HumanA::attack() const {
	std::cout << WHITE << _name << " attacks with" YELLOW " \"" << _weapon.getType() << "\"" EOC << std::endl;
}

HumanA::~HumanA() {
	std::cout << RED <<  _name << " deleted." EOC << std::endl;
}