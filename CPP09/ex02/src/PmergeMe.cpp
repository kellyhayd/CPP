
#include "PmergeMe.hpp"
#include <algorithm>
#include <cmath>
#include <limits>

std::vector<int> PmergeMe::_jacobsthalNumbers;

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) 
	: _vector(other._vector), _list(other._list) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		_vector = other._vector;
		_list = other._list;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void	PmergeMe::generateJacobsthalNumbers(int maxElements) {
	_jacobsthalNumbers.clear();
	
	_jacobsthalNumbers.push_back(0);
	_jacobsthalNumbers.push_back(1);

	if (maxElements <= 1) {
		return;
	}

	for (int i = 2; i < maxElements; ++i) {
		long long nextJ = static_cast<long long>(_jacobsthalNumbers[i - 1]) + 2LL * _jacobsthalNumbers[i - 2];

		if (nextJ > std::numeric_limits<int>::max()) {
			break; 
		}
		_jacobsthalNumbers.push_back(static_cast<int>(nextJ));
	}
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

void	PmergeMe::printResults() {
	std::cout << "Before: ";
	printContainer(_vector);

	PmergeMe::generateJacobsthalNumbers(static_cast<int>(_vector.size() / 2.0) + 2);
	sortVector(_vector);
	sortList(_list);

	std::cout << "After: ";
	printContainer(_vector);
	printContainer(_list);

	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector: " \
		/*tempo do vetor*/ << std::endl;
	std::cout << "Time to process a range of " << _list.size() << " elements with std::list: " \
		/*tempo da lista*/ << std::endl;
}


void	PmergeMe::sortVector(std::vector<int>& vec) {
	if (vec.size() <= 1) {
		return;
	}

	std::vector<int>	lastElements;
	bool	remnant = (vec.size() % 2 != 0);
	if (remnant) {
		lastElements.push_back( vec.back());
		vec.pop_back();
	}

	std::vector<int>	main;
	std::vector<int>	pend;
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it += 2) {
		if (*it > *(it + 1)) {
			main.push_back(*it);
			pend.push_back(*(it + 1));
		} else {
			main.push_back(*(it + 1));
			pend.push_back(*it);
		}
	}
	sortVector(main);
	insertSortedVector(pend, main);
	if (remnant) {
		int remnantValue = lastElements[0];
		std::vector<int>::iterator it = std::upper_bound(main.begin(), main.end(), remnantValue);
		main.insert(it, remnantValue);
	}

	vec = main; 
}

void PmergeMe::insertSortedVector(std::vector<int>& pend, std::vector<int>& main) {
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
	}

	for (int i = pend.size() - 1; i >= 0; --i) {
		if (!pendInserted[i]) {
			int valueToInsert = pend[i];
			std::vector<int>::iterator it = std::upper_bound(main.begin(), main.end(), valueToInsert);
			main.insert(it, valueToInsert);
		}
	}
}

std::list<int>::iterator PmergeMe::advanceListIterator(std::list<int>::iterator it, size_t n) const {
	for (size_t i = 0; i < n; ++i) {
		++it; 
	}
	return (it);
}

void	PmergeMe::sortList(std::list<int>& lst) {
	if (lst.size() <= 1) {
		return;
	}

	int remnantValue = -1;
	bool hasRemnant = (lst.size() % 2 != 0);
	if (hasRemnant) {
		remnantValue = lst.back();
		lst.pop_back();
	}

	std::list<int> main;
	std::list<int> pend;
	std::list<int>::iterator it = lst.begin();
	while (it != lst.end()) {
		std::list<int>::iterator nextIt = it;
		++nextIt;
		if (nextIt == lst.end()) {
			break;
		}

		int first = *it;
		int second = *nextIt;

		if (first > second) {
			main.push_back(first);
			pend.push_back(second);
		} else {
			main.push_back(second);
			pend.push_back(first);
		}
		++it;
		++it;
	}
	sortList(main);
	insertSortedList(pend, main);

	if (hasRemnant) {
		std::list<int>::iterator it = std::upper_bound(main.begin(), main.end(), remnantValue);
		main.insert(it, remnantValue);
	}
	lst = main;
}

void PmergeMe::insertSortedList(std::list<int>& pend, std::list<int>& main) {
	if (pend.empty()) {
		return;
	}

	std::vector<bool> pendInserted(pend.size(), false);

	main.insert(main.begin(), pend.front());
	pendInserted[0] = true;

	int prevJacobsthalVal = 0;
	int k = 1;

	while (true) {
		if (static_cast<size_t>(k) >= _jacobsthalNumbers.size()) {
			break;
		}

		int currentJacobsthalVal = getJacobsthal(k);
		int currentPendIdx = currentJacobsthalVal - 1;

		if (static_cast<size_t>(currentPendIdx) >= pend.size()) {
			break;
		}

		if (!pendInserted[currentPendIdx]) {
			std::list<int>::iterator pend_it_to_value = pend.begin();
			pend_it_to_value = advanceListIterator(pend_it_to_value, currentPendIdx);

			int valueToInsert = *pend_it_to_value;

			std::list<int>::iterator pos = std::upper_bound(main.begin(), main.end(), valueToInsert);
			main.insert(pos, valueToInsert);
			pendInserted[currentPendIdx] = true;
		}

		for (int i = currentPendIdx - 1; i >= prevJacobsthalVal; --i) {
			if (i >= 0 && static_cast<size_t>(i) < pend.size() && !pendInserted[i]) {
				std::list<int>::iterator pend_it_to_value = pend.begin();
				pend_it_to_value = advanceListIterator(pend_it_to_value, i);

				int valueToInsert = *pend_it_to_value;

				std::list<int>::iterator pos = std::upper_bound(main.begin(), main.end(), valueToInsert);
				main.insert(pos, valueToInsert);
				pendInserted[i] = true;
			}
		}

		prevJacobsthalVal = currentJacobsthalVal;
		k++;
	}

	for (int i = pend.size() - 1; i >= 0; --i) {
		if (!pendInserted[i]) {
			std::list<int>::iterator pend_it_to_value = pend.begin();
			pend_it_to_value = advanceListIterator(pend_it_to_value, i);

			int valueToInsert = *pend_it_to_value;

			std::list<int>::iterator pos = std::upper_bound(main.begin(), main.end(), valueToInsert);
			main.insert(pos, valueToInsert);
		}
	}
}