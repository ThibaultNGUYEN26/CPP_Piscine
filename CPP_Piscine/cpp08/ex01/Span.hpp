/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:05:18 by thibnguy          #+#    #+#             */
/*   Updated: 2024/03/07 14:35:18 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <exception>

class Span {

public:

	Span();
	Span(unsigned int N);
	Span(const Span &other);
	~Span();

	Span operator=(const Span &other);

	void addNumber(int nb);
	int shortestSpan();
	int longestSpan();

	void printSpan() const;

private:

	unsigned int N;
	std::vector<int> span;

};
