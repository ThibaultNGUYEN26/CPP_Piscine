/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:42:05 by thibault          #+#    #+#             */
/*   Updated: 2023/11/29 15:45:40 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <iostream>
#include <fstream>
#include <string>

# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define WHITE		"\033[1;37m"
# define EOC		"\033[0;0m"

bool isStringInFile(const std::string& filename, const std::string& s);
void replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2);

#endif