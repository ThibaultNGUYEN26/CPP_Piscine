/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:42:14 by thibault          #+#    #+#             */
/*   Updated: 2023/11/29 16:17:13 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>
# include "../includes/Weapon.hpp"

# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define WHITE		"\033[1;37m"
# define EOC		"\033[0;0m"

class HumanB {

public:

	HumanB(const std::string& name);
	~HumanB();
	void setWeapon(Weapon& weapon);
	void attack() const;

private:
	std::string _name;
	Weapon* _weapon;

};

#endif