/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:18:06 by thibnguy          #+#    #+#             */
/*   Updated: 2024/02/26 15:59:07 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main() {
	srand(time(NULL));
	Base* ptr = Base::generate();

	Base::identify(ptr);
	Base::identify(*ptr);

	delete ptr;
	return 0;
}
