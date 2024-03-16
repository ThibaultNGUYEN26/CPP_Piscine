/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:50:36 by thibnguy          #+#    #+#             */
/*   Updated: 2024/03/14 10:50:50 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <climits>
#include <iomanip>
#include <string>

class BitcoinExchange {

public:

	~BitcoinExchange();

	static std::map<std::string, double> setBitcoinPrices(const std::string &filename);
	static void parseInputFile(const std::string& filename, const std::map<std::string, double>& prices);

private:

	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &);
	BitcoinExchange &operator=(const BitcoinExchange &);

};

