/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:20:27 by thibault          #+#    #+#             */
/*   Updated: 2023/11/27 19:32:36 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define WHITE		"\033[1;37m"
# define EOC		"\033[0;0m"

class Zombie {

public:

	Zombie();
	Zombie(std::string name);
	~Zombie();
	void announce() const;

private:

	const std::string _name;

};

Zombie* newZombie( std::string name );

void randomChump(std::string name);

#endif