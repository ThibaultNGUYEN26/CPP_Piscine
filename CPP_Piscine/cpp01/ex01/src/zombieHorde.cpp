/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:46:07 by thibault          #+#    #+#             */
/*   Updated: 2023/11/28 14:18:35 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	if (N < 1) {
		std::cout << RED "[ERROR] Not enough zombie to create a horde." EOC << std::endl;
		return NULL;
	}
	Zombie* horde = new Zombie[N];
	if (!horde) {
		std::cout << RED "[ERROR] Fail to allocate the horde." EOC << std::endl;
		return NULL;
	}

	for (int i = 0; i < N; ++i) {
		std::stringstream ss;
		ss << name << i;
		horde[i].set_name(ss.str());
	}

	return horde;
}