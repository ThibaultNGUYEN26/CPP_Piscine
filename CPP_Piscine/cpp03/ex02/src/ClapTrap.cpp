/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:26:25 by thibault          #+#    #+#             */
/*   Updated: 2023/12/07 15:16:13 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap named " << _name << " created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    std::cout << "ClapTrap named " << other._name << " copied!" << std::endl;
    _name = other._name + "_copied";
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other) {
		_name = other._name + "_assigned";
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << "ClapTrap named " << _name << " has been assigned!" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap named " << _name << " destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (_hitPoints > 0 && _energyPoints > 0) {
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	} else {
		std::cout << "ClapTrap " << _name << " cannot attack due to lack of hit points or energy points!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints > 0) {
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
		_hitPoints -= amount;
	} else {
		std::cout << "ClapTrap " << _name << " has no hit points left!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints > 0 && _energyPoints > 0) {
		std::cout << "ClapTrap " << _name << " is repaired and gains " << amount << " hit points!" << std::endl;
		_hitPoints += amount;
		_energyPoints--;
	} else {
		std::cout << "ClapTrap " << _name << " cannot be repaired due to lack of hit points or energy points!" << std::endl;
	}
}

void ClapTrap::info() {
	std::cout << _name << " has " << _hitPoints << " hit points left and " <<  _energyPoints << " energy points left." << std::endl;
}