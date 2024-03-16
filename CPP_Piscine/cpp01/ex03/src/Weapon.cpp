/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:42:34 by thibault          #+#    #+#             */
/*   Updated: 2023/11/28 15:18:22 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon(const std::string& initialType) : _type(initialType) {}

Weapon::~Weapon() {}

const std::string& Weapon::getType() const {
	return _type;
}

void Weapon::setType(const std::string& newType) {
	_type = newType;
}