/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:19:59 by thibault          #+#    #+#             */
/*   Updated: 2023/11/27 19:07:40 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int main() {
    Zombie* zombie1 = newZombie("Alice");
    zombie1->announce();
    delete zombie1;

    randomChump("Bob");

    return 0;
}