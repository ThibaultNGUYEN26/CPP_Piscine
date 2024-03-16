/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:36:21 by thibnguy          #+#    #+#             */
/*   Updated: 2024/03/06 14:20:38 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T, typename F>
void Iter(T *array, const size_t &len, const F fun) {
	for (size_t i = 0; i < len; ++i) {
		fun(array[i]);
	}
}

template <typename T>
void fun(const T &el) {
	std::cout << el << std::endl;
}

template <typename T>
void fun2(T &el) {
	std::cout << el << std::endl;
}
