/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:36:22 by thibault          #+#    #+#             */
/*   Updated: 2023/11/28 14:25:23 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

void zombieHordeAnnounce(int N, std::string name) {
	Zombie* horde;
	horde = zombieHorde(N, name);
	for (int i = 0; i < N; ++i) {
		horde[i].announce();
	}
	delete[] horde;
}

int main()
{
	zombieHordeAnnounce(5, "Bob");
	zombieHordeAnnounce(1, "Alice");
	zombieHordeAnnounce(0, "Zombie");
	zombieHordeAnnounce(-10, "Thing");

	return 0;
}