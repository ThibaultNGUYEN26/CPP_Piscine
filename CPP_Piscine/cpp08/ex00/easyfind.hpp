/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:04:47 by thibnguy          #+#    #+#             */
/*   Updated: 2024/02/28 16:08:24 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdlib.h>
#include <algorithm>
#include <stdexcept>

template <typename T>
size_t easyfind(T &container, const int element) {
	typename T::iterator it = std::find(container.begin(), container.end(), element);
	if (it != container.end())
		return std::distance(container.begin(), it);
	throw std::logic_error("Can't find element in container");
}
