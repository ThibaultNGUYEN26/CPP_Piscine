/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:13:31 by thibnguy          #+#    #+#             */
/*   Updated: 2024/02/27 17:33:47 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
void swap(T &a, T &b) {
	T temp;

	temp = a;
	a = b;
	b = temp;
}

template <typename T>
T min(T &a, T &b) {
	if (a == b) {
		return (b);
	} else if (a < b) {
		return a;
	}
	return b;
}

template <typename T>
T max(T &a, T &b) {
	if (a == b) {
		return (b);
	} else if (a > b) {
		return a;
	}
	return b;
}
