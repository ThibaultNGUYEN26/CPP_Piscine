/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:36:33 by thibnguy          #+#    #+#             */
/*   Updated: 2024/03/06 14:22:21 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

int main() {
	int array[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	Iter(array, 9, fun<int>);
	Iter(array, 9, fun2<int>);

	std::cout << "\n";

	const int array2[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	Iter(array2, 9, fun<const int>);
	Iter(array2, 9, fun2<const int>);
}
