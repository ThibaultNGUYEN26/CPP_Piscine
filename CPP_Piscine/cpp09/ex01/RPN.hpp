/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:21:22 by thibnguy          #+#    #+#             */
/*   Updated: 2024/03/10 19:16:19 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cstdlib>
#include <stdexcept>

class RPN {

public:

	~RPN();

	static double parseExpression(const std::string& expression);

private:

	RPN();
	RPN(const RPN &);
	RPN operator=(const RPN &);

};
