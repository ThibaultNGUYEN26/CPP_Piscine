/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:57:26 by thibnguy          #+#    #+#             */
/*   Updated: 2024/03/05 13:32:38 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : age(0), name("Default") {}

Data::Data(int age, std::string name) : age(age), name(name) {}

Data::~Data() {}

std::string Data::getName() const {
	return name;
}

int Data::getAge() const {
	return age;
}

std::ostream& operator<<(std::ostream& os, const Data& d) {
	if (d.getAge() < 0) {
		os << d.getName() << " doesn't exist.";
	} else if (d.getAge() == 0) {
		os << d.getName() << " is not born yet.";
	} else if (d.getAge() > 115) {
		os << d.getName() << " is probably dead.";
	} else {
		d.getAge() == 1 ? os << d.getName() << " has " << d.getAge() << " year old." : os << d.getName() << " has " << d.getAge() << " years old.";
	}
	return os;
}
