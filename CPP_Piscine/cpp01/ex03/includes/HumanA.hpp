/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:42:08 by thibault          #+#    #+#             */
/*   Updated: 2023/11/29 16:17:09 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <string>
# include "../includes/Weapon.hpp"

# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define WHITE		"\033[1;37m"
# define EOC		"\033[0;0m"

class HumanA {
public:

	HumanA(const std::string& name, Weapon& weapon);
	~HumanA();
	void attack() const; 

private:

	std::string _name;
	Weapon& _weapon;

};

#endif