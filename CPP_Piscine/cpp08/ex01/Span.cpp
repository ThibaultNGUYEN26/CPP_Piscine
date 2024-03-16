/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:05:10 by thibnguy          #+#    #+#             */
/*   Updated: 2024/03/07 14:06:48 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : N(0) {}

Span::Span(unsigned int N) : N(N) {}

Span::Span(const Span &other) : N(other.N) {}

Span::~Span() {}

Span Span::operator=(const Span &other) {
	if (this != &other) {
		this->N = other.N;
	}
	return *this;
}

void Span::addNumber(int nb) {
	span.push_back(nb);
}

int Span::shortestSpan() {
	if (span.size() < 2) {
		throw std::logic_error("Not enough elements for a span.");
	}
	std::sort(span.begin(), span.end());

	int minSpan = INT_MAX;
	for (size_t i = 0; i < span.size() - 1; ++i) {
		int currentSpan = span[i + 1] - span[i];
		if (currentSpan < minSpan) {
			minSpan = currentSpan;
		}
	}
	return minSpan;
}

int Span::longestSpan() {
	if (span.size() < 2) {
		throw std::logic_error("Not enough elements for a span.");
	}
	std::sort(span.begin(), span.end());

	int minElement = *std::min_element(span.begin(), span.end());
	int maxElement = *std::max_element(span.begin(), span.end());

	return maxElement - minElement;
}

void Span::printSpan() const {
	for (size_t i = 0; i < span.size(); ++i) {
		std::cout << span[i];
		if (i < span.size() - 1) {
			std::cout << ", ";
		}
	}
	std::cout << std::endl;
}
