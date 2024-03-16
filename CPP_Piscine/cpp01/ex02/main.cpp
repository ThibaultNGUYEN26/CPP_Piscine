/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:26:47 by thibault          #+#    #+#             */
/*   Updated: 2023/11/29 17:48:43 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#define GREEN	"\033[1;32m"
#define MAGENTA	"\033[1;35m"
#define BLUE	"\033[1;36m"
#define WHITE	"\033[1;37m"
#define EOC		"\033[0;0m"

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;
	
	std::cout << BLUE "This is the string		" WHITE ": " << str << std::endl;
	std::cout << std::endl;
	std::cout << MAGENTA "This is the string address	" WHITE ": " << &str << std::endl;
	std::cout << MAGENTA "This is the pointer address	" WHITE ": " << stringPTR << std::endl;
	std::cout << MAGENTA "This is the reference address	" WHITE ": " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << GREEN "This is the string value	" WHITE ": " << str << std::endl;
	std::cout << GREEN "This is the pointer value	" WHITE ": " << *stringPTR << std::endl;
	std::cout << GREEN "This is the reference value	" WHITE ": " << stringREF << EOC << std::endl;

	return 0;
}