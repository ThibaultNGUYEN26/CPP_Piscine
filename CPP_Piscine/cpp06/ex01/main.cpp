/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:59:18 by thibnguy          #+#    #+#             */
/*   Updated: 2024/02/24 17:55:13 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

bool isNumber(const char* str) {
	int i = 0;

	if (str[0] == '-') {
		++i;
	} while(str[++i] != '\0') {
		if (!std::isdigit(str[i])) {
			return false;
		}
	}
	return true;
}

int main(int argc, char *argv[]) {
	if (argc != 3 || !isNumber(argv[2])) {
		std::cerr << "[Usage] ./serialize {name} {age}" << std::endl;
	} else {
		std::cout << "argv[1]: " << argv[1] << ", argv[2]: " << argv[2] << std::endl;
		Data data(atoi(argv[2]), argv[1]);
		Data *data2 = Serializer::deserialize(Serializer::serialize(&data));
		std::cout << std::endl;
		std::cout << *data2 << std::endl;
	}
	return 0;
}
