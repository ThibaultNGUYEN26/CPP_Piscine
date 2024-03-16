/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:00:06 by thibnguy          #+#    #+#             */
/*   Updated: 2024/02/24 19:03:33 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::Base() {
	std::cout << "Base default constructor called." << std::endl;
}

Base::~Base() {
	std::cout << "Base destructor called." << std::endl;
}

Base *Base::generate(void) {
	int nb = std::rand() % 3;

	switch (nb) {
		case 0: return new A();
		case 1: return new B();
		case 2: return new C();
		default: break;
	}

	return NULL;
}

void Base::identify(Base *p) {
	if (dynamic_cast<A*>(p) != NULL) {
		std::cout << "*p is of type A" << std::endl;
	} else if (dynamic_cast<B*>(p) != NULL) {
		std::cout << "*p is of type B" << std::endl;
	} else if (dynamic_cast<C*>(p) != NULL) {
		std::cout << "*p is of type C" << std::endl;
	} else {
		std::cout << "*p is of unknown type" << std::endl;
	}
}

void Base::identify(Base &p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "&p is of type A" << std::endl;
		return ;
	} catch (...) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "&p is of type B" << std::endl;
		return ;
	} catch (...) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "&p is of type C" << std::endl;
		return ;
	} catch (...) {
		std::cout << "&p is of unknown type" << std::endl;
	}
}
