#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>

class PmergeMe {
private:
	std::vector<int>	_vector;
	std::list<int>		_list;
	static std::vector<int>	_jacobsthalNumbers;

public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	static void	generateJacobsthalNumbers(int maxElements);
	void	addNumber(int number);
	void	printResults();
	void	sortVector(std::vector<int>& vec);
	void	sortList(std::list<int>& lst);
	void	insertSortedVector(std::vector<int>& pend, std::vector<int>& main);
	void	insertSortedList(std::list<int>& pend, std::list<int>& main);
	std::list<int>::iterator	advanceListIterator(std::list<int>::iterator it, size_t n) const;


	std::vector<int>	getVector() const;
	std::list<int>		getList() const;
	int	getJacobsthal(int n) const;

	template <typename T>
	void	printContainer(const T& container) const {
		for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
};

#endif