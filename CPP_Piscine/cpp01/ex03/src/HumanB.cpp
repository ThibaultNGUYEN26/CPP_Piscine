/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:42:36 by thibault          #+#    #+#             */
/*   Updated: 2023/11/29 16:19:28 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"

HumanB::HumanB(const std::string& name) : _name(name), _weapon(NULL) {
	std::cout << GREEN << _name << " created." EOC << std::endl;
}

void HumanB::setWeapon(Weapon& weapon) {
	_weapon = &weapon;
}

void HumanB::attack() const {
	if (_weapon == NULL || _weapon->getType().empty()) {
		std::cout << WHITE << _name << " attacks with " YELLOW "\"bare hands\"" EOC << std::endl;
	} else {
		std::cout << WHITE <<  _name << " attacks with " YELLOW "\"" << _weapon->getType() << "\"" EOC << std::endl;
	}
}

HumanB::~HumanB() {
	std::cout << RED << _name << " deleted." EOC << std::endl;
}