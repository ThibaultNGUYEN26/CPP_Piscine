/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:56:48 by thibnguy          #+#    #+#             */
/*   Updated: 2024/03/05 13:31:55 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

struct Data {
	int	age;
	std::string	name;

	Data();
	Data(int age, std::string name);
	~Data();

	std::string getName() const;
	int getAge() const;
};

std::ostream& operator<<(std::ostream& os, const Data& d);
