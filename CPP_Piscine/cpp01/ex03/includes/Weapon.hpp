/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:42:01 by thibault          #+#    #+#             */
/*   Updated: 2023/11/28 15:17:36 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon {

public:

	Weapon(const std::string& initialType);
	~Weapon();
	const std::string& getType() const;
	void setType(const std::string& newType);

private:

	std::string _type;

};

#endif