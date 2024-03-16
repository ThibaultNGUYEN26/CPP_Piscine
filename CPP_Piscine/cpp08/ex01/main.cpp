/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:05:45 by thibnguy          #+#    #+#             */
/*   Updated: 2024/03/07 14:35:23 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int main() {
	try {
		int nb = 10000;
		Span sp1 = Span(nb);
		for (int i = 0; i < nb; ++i) {
			sp1.addNumber(i);
		}
		sp1.printSpan();
		std::cout << "Shortest span: " << sp1.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp1.longestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n";

	try {
		Span sp = Span(5);
		srand(time(NULL));

		for(int i = 0; i < 5; ++i) {
			int randomNum = rand() % 100 + 1;
			sp.addNumber(randomNum);
		}
		sp.printSpan();
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "\n";

	try {
		Span sp3 = Span(1);
		sp3.addNumber(INT_MAX);
		sp3.printSpan();
		std::cout << sp3.shortestSpan() << std::endl;
		std::cout << sp3.longestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}
