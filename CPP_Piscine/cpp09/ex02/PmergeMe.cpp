/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:49:42 by thibnguy          #+#    #+#             */
/*   Updated: 2024/03/15 18:26:43 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : vectorNumbers(0), dequeNumbers(0) {}

PmergeMe::~PmergeMe() {}

// Function to print a container
template <typename T>
static void printContainer(T &container) {
	for (size_t i = 0; i < container.size(); ++i) {
		std::cout << container[i] << " ";
	}
	std::cout << std::endl;
}

// Generates a vector of Jacobsthal numbers up to n
std::vector<long> generateJacobsthalNumbers(int n) {
	std::vector<long> jacobsthal(n + 1, 0);
	if (n >= 1) jacobsthal[1] = 1;
	for (int i = 2; i <= n; ++i) {
		long prev = jacobsthal[i - 1];
		long prev2 = jacobsthal[i - 2];

		// Check for potential overflow
		if (LONG_MAX - prev < 2 * prev2) {
			break;
		}
		jacobsthal[i] = prev + 2 * prev2;
	}
	return jacobsthal;
}

// Calculate the insertion order for elements based on Jacobsthal numbers.
std::vector<long> calculateInsertionOrder(int n) {
	std::vector<long> order;
	std::vector<long> jacobsthal = generateJacobsthalNumbers(n);
	for (int i = 0; i < n; ++i) {
		order.push_back(jacobsthal[i]);
	}
	return order;
}

// Find the right position to insert using binary search
template <typename T>
size_t findInsertPosition(const T& container, typename T::value_type value, size_t start, size_t end) {
	size_t mid, left = start, right = end;
	while (left < right) {
		mid = left + (right - left) / 2;
		if (value <= container[mid]) right = mid;
		else left = mid + 1;
	}
	return left;
}

// Insert the value in the right position
template <typename T>
void insertInOrder(T& container, typename T::value_type value, size_t position) {
	typename T::iterator it = container.begin();
	std::advance(it, position);
	container.insert(it, value);
}

// Sorting algorithm based on Ford Johnson algorithm
template <typename T>
double fordJohnsonSort(T &container) {
	clock_t startTime = clock();

	// No element to sort
	if (container.size() <= 1) {
		clock_t endTime = clock();
		return static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;
	}

	// Step 1: Sorts elements in pairs and separates them into larger and smaller elements.
	T largerElements, smallerElements;
	for (typename T::size_type i = 0; i < container.size() - 1; i += 2) {
		if (container[i] < container[i + 1]) {
			largerElements.push_back(container[i + 1]);
			smallerElements.push_back(container[i]);
		} else {
			largerElements.push_back(container[i]);
			smallerElements.push_back(container[i + 1]);
		}
	}

	// Handle the case of an odd number of elements
	if (container.size() % 2 != 0) {
		largerElements.push_back(container.back());
	}

	// Step 2: Recursively sorts the identified larger elements.
	fordJohnsonSort(largerElements); // Recursive sort for larger elements

	// Step 3: Reintegrates the larger elements back into the container, now in sorted order.
	container = largerElements;

	// Step 4: Inserts the smaller elements back into the sorted container at their correct positions.
	std::vector<long> insertionOrder = calculateInsertionOrder(smallerElements.size());
	for (size_t idx = 0; idx < insertionOrder.size(); ++idx) {
		size_t pos = findInsertPosition(container, smallerElements[idx], 0, container.size());
		insertInOrder(container, smallerElements[idx], pos);
	}

	clock_t endTime = clock();
	return static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;
}

// Call the Ford Johnson algorithm on two containers: vector and deque
void PmergeMe::sortContainer(int argc, char **argv) {
	vectorNumbers.reserve(argc - 1);

	/* clock_t startTime = clock();
	for (int i = 1; i < argc; ++i) {
		setNumbers.insert(std::atoi(argv[i]));
	}
	clock_t endTime = clock(); */
	
	for (int i = 1; i < argc; ++i) {
		vectorNumbers.push_back(std::atoi(argv[i]));
		dequeNumbers.push_back(std::atoi(argv[i]));
	}

	std::cout << "Before: ";
	printContainer(vectorNumbers);
	double vectorTime = fordJohnsonSort(vectorNumbers);
	std::cout << "After: ";
	printContainer(vectorNumbers);
	std::cout << std::fixed << std::setprecision(5) << "Time to process a range of " << vectorNumbers.size() << " elements with std::vector : " << vectorTime << " us" << std::endl;
	std::cout << std::fixed << std::setprecision(5) << "Time to process a range of " << dequeNumbers.size() << " elements with std::deque  : " << fordJohnsonSort(dequeNumbers) << " us" << std::endl;

	// std::cout << std::fixed << std::setprecision(5) << "Time to process a range of " << setNumbers.size() << " elements with std::set    : " << static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC << " us" << std::endl;
}
