/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 01:01:10 by thibault          #+#    #+#             */
/*   Updated: 2023/12/07 14:44:47 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "../includes/ICharacter.hpp"

class Character : public ICharacter {

private:

	std::string name;
	AMateria *inventory[4];

public:

	Character(const std::string &name);
	Character(const Character &other);
	Character &operator=(const Character &other);
	~Character();


	const std::string &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);

};

#endif