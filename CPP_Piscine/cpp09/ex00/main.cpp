/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:50:57 by thibnguy          #+#    #+#             */
/*   Updated: 2024/03/10 18:55:40 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "[Usage] ./btc {file}.txt" << std::endl;
		return 1;
	}

	std::string inputFilename = argv[1];

	// Container map where the key is a string for the date and the value is a double for the price
	std::map<std::string, double> bitcoinPrices = BitcoinExchange::setBitcoinPrices("data.csv");
	BitcoinExchange::parseInputFile(inputFilename, bitcoinPrices);

	return 0;
}
