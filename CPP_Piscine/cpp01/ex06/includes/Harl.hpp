/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:08:54 by thibault          #+#    #+#             */
/*   Updated: 2024/03/14 10:37:59 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define WHITE		"\033[1;37m"
# define EOC		"\033[0;0m"

class Harl {

public:

	Harl();
	~Harl();
	void complain(const std::string &level);

private:
	void debug();
	void info();
	void warning();
	void error();

	struct LogFunction {
		std::string level;
		void (Harl::*func)();
	};

	static LogFunction logFunctions[4];
};

#endif