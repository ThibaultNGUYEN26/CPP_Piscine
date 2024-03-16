/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:21:32 by thibnguy          #+#    #+#             */
/*   Updated: 2024/03/12 14:42:10 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::~RPN() {}

static bool isOperator(const std::string& token) {
	return token == "+" || token == "-" || token == "*" || token == "/";
}

static double makeOperation(const double operand1, const double operand2, const char operation) {
	switch (operation) {
		case '+':
			return operand1 + operand2;
		case '-':
			return operand1 - operand2;
		case '*':
			return operand1 * operand2;
		case '/':
			if (operand2 == 0) {
				std::cerr << "Error: Division by zero." << std::endl;
				exit(EXIT_FAILURE);
			}
			return operand1 / operand2;
		default:
			std::cerr << "Error: Unknown operation '" << operation << "'." << std::endl;
			exit(EXIT_FAILURE);
	}
}

double RPN::parseExpression(const std::string& expression) {
	std::stack<double> stack;
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token) {
		if (isOperator(token)) {
			if (stack.size() < 2) {
				std::cout << "Error: invalid expression" << std::endl;
				exit(EXIT_FAILURE);
			}

			double operand2 = stack.top();
			stack.pop();
			double operand1 = stack.top();
			stack.pop();

			double result = makeOperation(operand1, operand2, token[0]);
			stack.push(result);
		} else {
			if (token.size() == 1 && isdigit(token[0])) {
				double number = token[0] - '0';
				stack.push(number);
			} else {
				std::cout << "Error: operand not a single digit." << std::endl;
				exit(EXIT_FAILURE);
			}
		}
	}

	if (stack.size() != 1)
	{
		std::cout << "Error: invalid expression" << std::endl;
		exit(EXIT_FAILURE);
	}

	return stack.top();
}
