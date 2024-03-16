/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:15:03 by thibnguy          #+#    #+#             */
/*   Updated: 2024/03/15 18:15:54 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <ctime>
#include <iomanip>
#include <climits>

class PmergeMe {

public:

	PmergeMe();
	~PmergeMe();

	void sortContainer(int argc, char **argv);

private:

	PmergeMe(const PmergeMe &);
	PmergeMe operator=(const PmergeMe &);
	std::vector<int> vectorNumbers;
	std::deque<int> dequeNumbers;
	std::set<int> setNumbers;

};
