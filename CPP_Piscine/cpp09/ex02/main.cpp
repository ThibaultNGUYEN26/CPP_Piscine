/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:18:50 by thibnguy          #+#    #+#             */
/*   Updated: 2024/03/13 16:06:10 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	PmergeMe merge;
	if (argc < 2) {
		std::cerr << "[Usage] ./PmergeMe {integers}" << std::endl;
	} else {
		merge.sortContainer(argc, argv);
	}
	return 0;
}
