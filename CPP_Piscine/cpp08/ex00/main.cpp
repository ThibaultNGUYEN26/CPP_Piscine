/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:04:55 by thibnguy          #+#    #+#             */
/*   Updated: 2024/03/07 13:47:49 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <iterator>
#include <vector>
#include <deque>
#include <list>

template<typename Container>
void printContainer(const Container& container, const std::string name) {
	std::cout << name << ": ";
	for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << "\n\n";
}

int main() {
	std::vector<int> vector;
	std::deque <int> deque;
	std::list<int> list;
	for (int i = 1; i < 43; ++i) {
		vector.push_back(i);
		deque.push_back(i * 2);
		list.push_back(i * 4);
	}

	printContainer(vector, "Vector");
	try {
		std::cout << "Element 38: index " << easyfind(vector, 38) << std::endl;
		std::cout << easyfind(vector, 50) << std::endl;
	} catch (const std::logic_error& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n";

	printContainer(deque, "Deque");
	try {
		std::cout << "Element 38: index " << easyfind(deque, 38) << std::endl;
		std::cout << easyfind(deque, 300) << std::endl;
	} catch (const std::logic_error& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n";

	printContainer(list, "List");
	try {
		std::cout << "Element 24: index " << easyfind(list, 24) << std::endl;
		std::cout << easyfind(list, 300) << std::endl;
	} catch (const std::logic_error& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
