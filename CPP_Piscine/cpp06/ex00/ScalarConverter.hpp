/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:59:39 by thibnguy          #+#    #+#             */
/*   Updated: 2024/03/05 13:32:54 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <iostream>
# include <iomanip>
# include <limits.h>
# include <sstream>
# include <cmath>

class ScalarConverter {

public:

	static int convert(std::string value);
	~ScalarConverter();

private:

	ScalarConverter();
	ScalarConverter(ScalarConverter &other);
	ScalarConverter operator=(ScalarConverter &other);
	static int convertToChar(std::string &value);
	static int convertToNumber(std::string& value);
	

};
