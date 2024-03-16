/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 00:49:55 by thibault          #+#    #+#             */
/*   Updated: 2023/12/07 16:31:08 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"
#include "../includes/ICharacter.hpp"

AMateria::AMateria(const std::string &type) : type(type) {}

AMateria::AMateria(const AMateria& other) : type(other.type) {}

AMateria &AMateria::operator=(const AMateria &other) {
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}

AMateria::~AMateria() {}

const std::string &AMateria::getType() const {
	return type;
}

void AMateria::use(ICharacter &target) {
	(void)target;
}