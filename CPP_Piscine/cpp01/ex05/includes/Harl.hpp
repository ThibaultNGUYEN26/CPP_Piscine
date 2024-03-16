/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:21:08 by thibault          #+#    #+#             */
/*   Updated: 2023/11/29 18:21:04 by thibault         ###   ########.fr       */
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
	void complain(std::string level);

private:
	
	struct LogFunction {
        std::string level;
        void (Harl::*func)();
    };
	
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
	
	LogFunction logFunctions[4];
};

#endif