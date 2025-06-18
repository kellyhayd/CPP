
#include "PmergeMe.hpp"
#include <algorithm>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) 
	: _vector(other._vector), _list(other._list), _jacobsthalNumbers(other._jacobsthalNumbers) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		_vector = other._vector;
		_list = other._list;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

std::vector<int>	PmergeMe::jacobsthalNumbers(int maxElements) {
	std::vector<int>	jacobsthal;
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);

	for (int i = 2; i < maxElements; ++i) {
		int num = jacobsthal[i - 2] + 2 * jacobsthal[i - 1];
		jacobsthal.push_back(num);
	}
	return (jacobsthal);
}

void	PmergeMe::addNumber(int number) {
	_vector.push_back(number);
	_list.push_back(number);
}

std::vector<int>	PmergeMe::getVector() const { return _vector; }

std::list<int>	PmergeMe::getList() const { return _list; }

int	PmergeMe::getJacobsthal(int n) const {
		if (n < 0 || static_cast<size_t>(n) >= _jacobsthalNumbers.size()) {
			throw std::out_of_range("Jacobsthal index out of precomputed range.");
		}
		return (_jacobsthalNumbers[n]);
}

void	PmergeMe::setJacobsthal(int maxElements) {
	_jacobsthalNumbers = jacobsthalNumbers(maxElements);
}

void	PmergeMe::printResults() {
	std::cout << "Before: ";
	printContainer(_vector);

	sortVector(_vector);
	// sortList();

	std::cout << "After: ";
	printContainer(_vector);

	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector: " \
		/*tempo do vetor*/ << std::endl;
	std::cout << "Time to process a range of " << _list.size() << " elements with std::list: " \
		/*tempo da lista*/ << std::endl;
}


void	PmergeMe::sortVector(std::vector<int>& _vector) {
	if (_vector.size() <= 1) {
		return;
	}

	std::vector<int>	lastElements;
	bool	remnant = (_vector.size() % 2 != 0);
	if (remnant) {
		lastElements.push_back( _vector.back());
		_vector.pop_back();
	}

	std::vector<int>	main;
	std::vector<int>	pend;
	for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it += 2) {
		if (*it > *(it + 1)) {
			main.push_back(*it);
			pend.push_back(*(it + 1));
		} else {
			main.push_back(*(it + 1));
			pend.push_back(*it);
		}
	}
	sortVector(main);
	insertSorted(pend, main);
	if (remnant) {
		int remnantValue = lastElements[0];
		std::vector<int>::iterator it = std::upper_bound(main.begin(), main.end(), remnantValue);
		main.insert(it, remnantValue);
	}

	_vector = main; 
}


void	PmergeMe::insertSorted(std::vector<int>& pend, std::vector<int>& main) {
	std::vector<bool> pendInserted(pend.size(), false);
	if (!pend.empty()) {
		main.insert(main.begin(), pend[0]);
		pendInserted[0] = true;
	}


	int prevJacobsthal = 0;
	int k = 1;
	while (true) {
		if (static_cast<size_t>(k) >= _jacobsthalNumbers.size()) {
			break; 
		}
		int currentJacobsthal = getJacobsthal(k);
		int currentPend = currentJacobsthal - 1;

		if (static_cast<size_t>(currentPend) >= pend.size()) {
			break; 
		}

		if (!pendInserted[currentPend]) {
			int valueToInsert = pend[currentPend];
			std::vector<int>::iterator it = std::upper_bound(main.begin(), main.end(), valueToInsert);
			main.insert(it, valueToInsert);
			pendInserted[currentPend] = true;
		}

		for (int i = currentPend - 1; i >= prevJacobsthal; --i) {
			if (i >= 0 && static_cast<size_t>(i) < pend.size() && !pendInserted[i]) {
				int valueToInsert = pend[i];
				std::vector<int>::iterator it = std::upper_bound(main.begin(), main.end(), valueToInsert);
				main.insert(it, valueToInsert);
				pendInserted[i] = true;
			}
		}
			
		prevJacobsthal = currentJacobsthal;
		k++;

		for (int i = pend.size() - 1; i >= 0; --i) {
			if (!pendInserted[i]) {
				int valueToInsert = pend[i];
				std::vector<int>::iterator it = std::upper_bound(main.begin(), main.end(), valueToInsert);
				main.insert(it, valueToInsert);
				pendInserted[i] = true;
			}
		}
	}
}

