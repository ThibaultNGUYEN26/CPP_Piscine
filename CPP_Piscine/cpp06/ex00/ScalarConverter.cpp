/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:59:37 by thibnguy          #+#    #+#             */
/*   Updated: 2024/03/07 13:44:30 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::~ScalarConverter() {}

static int cppPrintf(const std::string &str) {
	std::cout << str << std::endl;
	return str.length();
}

static bool isInt(const std::string& str) {
	std::istringstream iss(str);
	int num;
	iss >> num;
	return iss.eof() && !iss.fail();
}

static bool isDouble(const std::string& str) {
	std::istringstream iss(str);
	double num;
	iss >> num;
	return iss.eof() && !iss.fail();
}

int ScalarConverter::convert(std::string value) {
	if (value != "nan" && value != "nanf" && value != "+inf" && value != "+inff" && value != "-inf" && value != "-inff") {
		if (value.length() == 1 && static_cast<int>(value[0]) >= 0 && static_cast<int>(value[0]) <= 128) {
			std::cout << "char: ";
			if (static_cast<int>(value[0]) < 32 || static_cast<int>(value[0]) > 126) {
				std::cout << "Non displayable" << std::endl;
			} else {
				std::cout << "'" << value[0] << "'" << std::endl;
			}
			std::cout << "int: " << static_cast<int>(value[0]) << std::endl;
			std::cout << std::fixed << std::setprecision(1);
			std::cout << "float: " << static_cast<float>(value[0]) << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(value[0]) << std::endl;
			return 0;
		}
		if (!value.empty() && value[value.size() - 1] == 'f') {
			value = value.substr(0, value.size() - 1);
		}
		if (!isInt(value) && !isDouble(value)) {
			return cppPrintf("[Error] Value must be an integer, float or double.");
		}
	}
	convertToChar(value);
	convertToNumber(value);
	return 0;
}

int ScalarConverter::convertToChar(std::string &value) {
	std::stringstream ss(value);
	int num = 0;
	ss >> num;

	if (num >= 32 && num <= 126) {
		std::cout << "char: \'" << static_cast<char>(num) << "\'" << std::endl;
		return 0;
	}
	return cppPrintf(num >= 0 && num <= 127 && !(ss.fail())? "char: Non displayable" : "char: impossible");
}

int ScalarConverter::convertToNumber(std::string& value) {
	if (value == "nan" || value == "+inf" || value == "-inf") {
		return cppPrintf("int: impossible\nfloat: " + value + "f\ndouble: " + value);
	} else if (value == "nanf" || value == "+inff" || value == "-inff") {
		return cppPrintf("int: impossible\nfloat: " + value + "\ndouble: " + value.substr(0, value.length() - 1));
	}

	std::stringstream ss(value);
	double num;
	ss >> num;

	if (!ss.fail()) {
		std::cout << std::fixed << std::setprecision(1);
		if (num >= INT_MIN && num <= INT_MAX) {
			std::cout << "int: " << static_cast<int>(num) << std::endl;
		} else {
			std::cout << "int: impossible" << std::endl;
		}

		std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(num) << std::endl;

		return 0;
	}
	return cppPrintf("int: impossible\nfloat: impossible\ndouble: impossible");
}
