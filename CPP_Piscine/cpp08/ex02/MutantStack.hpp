/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:18:56 by thibnguy          #+#    #+#             */
/*   Updated: 2024/03/07 14:19:24 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <iostream>
#include <iterator>
#include <list>

template<typename T>
class MutantStack : public std::stack<T> {

public:

	using std::stack<T>::c;

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	iterator begin() { return c.begin(); }
	iterator end() { return c.end(); }

	const_iterator begin() const { return c.begin(); }
	const_iterator end() const { return c.end(); }

};
