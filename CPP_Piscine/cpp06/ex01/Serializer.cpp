/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:28:18 by thibnguy          #+#    #+#             */
/*   Updated: 2024/03/05 13:32:05 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data* ptr) {
	std::cout << "The data is serialize." << std::endl;
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	std::cout << "The data is deserialize." << std::endl;
	return reinterpret_cast<Data*>(raw);
}
