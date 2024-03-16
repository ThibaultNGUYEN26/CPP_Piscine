/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:50:50 by thibnguy          #+#    #+#             */
/*   Updated: 2024/03/10 18:56:11 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::~BitcoinExchange() {}

std::map<std::string, double> BitcoinExchange::setBitcoinPrices(const std::string &filename) {
	std::map<std::string, double> prices;
	std::ifstream file(filename.c_str());
	std::string line, date;
	double price;

	if (!file.is_open()) {
		std::cerr << "Error opening bitcoin prices file." << std::endl;
		std::exit(1);
	}

	std::getline(file, line);

	while (std::getline(file, line)) {
		std::istringstream iss(line);
		std::getline(iss, date, ',');
		iss >> price;
		prices.insert(std::make_pair(date, price));
	}

	return prices;
}

static bool isLeapYear(int year) {
	return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
}

static bool isValidDate(const std::string& date) {
	if (date.length() != 10) {
		return false;
	}

	int year, month, day;
	char dash1, dash2;

	std::istringstream dateStream(date);
	dateStream >> year >> dash1 >> month >> dash2 >> day;

	if (dash1 != '-' || dash2 != '-' || dateStream.fail()) {
		return false;
	}

	if (month < 1 || month > 12 || day < 1 || day > 31) {
		return false;
	}

	if (month == 2) {
		if (isLeapYear(year)) {
			if (day > 29) return false;
		} else {
			if (day > 28) return false;
		}
	}

	if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day > 30) {
			return false;
		}
	}

	return true;
}

void BitcoinExchange::parseInputFile(const std::string &filename, const std::map<std::string, double> &prices) {
	std::ifstream file(filename.c_str());
	std::string line, date;
	double value;

	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		std::exit(1);
	}

	// Check header
	std::getline(file, line);
	if (line.compare("date | value")) {
		std::cerr << "Error: wrong header file." << std::endl;
		std::exit(1);
	}
	
	while (std::getline(file, line)) {
		if (line.length() < 14 || line.compare(10, 3, " | ") != 0) {
			std::cerr << "Error: wrong format line." << std::endl;
			continue;
		}

		std::replace(line.begin(), line.end(), '|', ' ');
		std::istringstream iss(line);
		iss >> date >> value;

		if (value > 1000) {
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}

		if (value < 0) {
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}

		if (!isValidDate(date) || date < "2009-01-02") {
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}

		std::map<std::string, double>::const_iterator it = prices.lower_bound(date);
		if (it->first != date && it != prices.begin()) {
			--it;
		}

		if (it != prices.end()) {
			std::cout << std::fixed << std::setprecision(2) << date << " => " << value << " = " << (value * it->second) << std::endl;
		} else {
			std::cout << "No price available for " << date << std::endl;
		}
		
	}
}
