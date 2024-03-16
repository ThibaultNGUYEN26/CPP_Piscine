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

template<typename T>
typename T::iterator insertElement(T& base_chain, typename T::value_type pend_element, const T& jacobsthal_numbers) {
    if (base_chain.empty() || pend_element < *base_chain.rbegin()) {
        return base_chain.end();
    }

    typename T::iterator it = base_chain.end();
    for (size_t i = base_chain.size() - 1; it != base_chain.begin(); --it, --i) {
        if (pend_element < base_chain[i] && (i == 0 || jacobsthal_numbers[i - 1] < jacobsthal_numbers[i])) {
            break;
        }
    }
    return it;
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
	std::vector<long> jacobsthal_numbers = generateJacobsthalNumbers<long>(container.size());
	for (typename T::iterator it = smallerElements.begin(); it != smallerElements.end(); ++it) {
        insertElement(largerElements, *it, jacobsthal_numbers);
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
