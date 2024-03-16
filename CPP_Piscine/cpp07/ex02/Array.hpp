/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:58:00 by thibnguy          #+#    #+#             */
/*   Updated: 2024/03/07 13:43:07 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdlib.h>
#include <time.h>

template <typename T>
class Array {

public:

	Array() : size(0), list(NULL) {}
	Array(unsigned int n) : size(n), list(new T[n]()) {}
	Array(const Array &other) : size(other.size), list(new T[size]) {
		for (size_t i = 0; i < this->size; ++i) {
			this->list[i] = other.list[i];
		}
	}
	~Array() { delete []list; }
	
	Array &operator=(const Array &other) {
		if (this != &other) {
			delete []this->list;
			this->size = other.size;
			this->list = new T[this->size];
			for (size_t i = 0; i < this->size; ++i) {
				this->list[i] = other.list[i];
			}
		}
		return *this;
	}
	
	T &operator[](int index) {
		if (index < 0 || index >= static_cast<int>(size)) {
			throw std::out_of_range("Index out of bounds");
		}
		return list[index];
	}

	const T &operator[](int index) const {
		if (index < 0 || index >= static_cast<int>(size)) {
			throw std::out_of_range("Index out of bounds");
		}
		return list[index];
	}

private:

	size_t	size;
	T		*list;

};
