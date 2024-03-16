/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 01:02:03 by thibault          #+#    #+#             */
/*   Updated: 2023/12/07 18:13:25 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"
#include "../includes/AMateria.hpp"

Character::Character(const std::string &name) : name(name) {
	for (int i = 0; i < 4; ++i) {
		inventory[i] = NULL;
	}
}

Character::Character(const Character &other) : name(other.name) {
	for (int i = 0; i < 4; ++i) {
		if (other.inventory[i]) {
			inventory[i] = other.inventory[i]->clone();
		} else {
			inventory[i] = NULL;
		}
	}
}

Character &Character::operator=(const Character &other) {
	if (this != &other) {
		name = other.name;
		for (int i = 0; i < 4; ++i) {
			delete inventory[i];
			if (other.inventory[i]) {
				inventory[i] = other.inventory[i]->clone();
			} else {
				inventory[i] = NULL;
			}
		}
	}
	return *this;
}

Character::~Character() {
	for (int i = 0; i < 4; ++i) {
		delete inventory[i];
		inventory[i] = NULL;
	}
}

const std::string &Character::getName() const {
	return name;
}

void Character::equip(AMateria *m) {
	if (!m) {
		return ;
	}
	for (int i = 0; i < 4; ++i) {
		if (!inventory[i]) {
			inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4) {
		inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter &target) {
	if (idx >= 0 && idx < 4 && inventory[idx]) {
		inventory[idx]->use(target);
	}
}